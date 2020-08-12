#include "model.hpp"

Model::Model(const vector<pair<int, int> > layersSizes) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0.0,1.0);

    for (pair<int, int> layerSize : layersSizes) {
        vector<double> bias;
        vector<vector<double> > layer;
        for (int i = 0; i < layerSize.first; i++) {
            vector<double> row;
            for (int j = 0; j < layerSize.second; j++) {
                row.push_back(distribution(generator));
            }
            layer.push_back(row);
        }
        for (int j = 0; j < layerSize.second; j++) {
            bias.push_back(distribution(generator));
        }
        layers.push_back(layer);
        biases.push_back(bias);
    }
}

double Model::getLoss(const vector<vector<double> >& x, const vector<vector<double> >& y) {
    double loss = 0.0;
    int correct = 0;
    for (int i = 0; i < x.size(); i++) {
        vector<double> output = runInference(x[i]);

        int id = 0;
        int gt = 0;
        for (int j = 0; j < 10; j++) {
            if (y[i][j] > 0.9) gt = j;
            if (output[id] < output[j]) {
                id = j;
            }
        }
        if (id == gt) correct++;

        double inc = 0.0;
        for (int j = 0; j < 10; j++) {
            inc += (output[j] - y[i][j]) * (output[j] - y[i][j]);
        }
        inc /= 2;
        loss += inc;
    }
    loss /= (double)x.size();
    cout << correct << " ";
    return loss;
}

vector<double> Model::runInference(const vector<double> x) {
    vector<double> input = x;
    vector<double> output;

    for (int layerId = 0; layerId < layers.size(); layerId++) {
        output = multiplyVectorWithMatrix(input, layers[layerId]);
        addVectors(output, biases[layerId]);
        applySigmoid(output);

        input = output;

       /* cout << input.size() << endl;
        for (int i = 0; i < input.size(); i++) {
            cout << input[i] << " ";
        }
        cout << endl;*/
    }
    return output;
}

void Model::train(const vector<vector<double> >& xTrain,
                  const vector<vector<double> >& yTrain) {
    int numberOfEpochs = 10;
    int miniBatchSize = 10;

    for (int epoch = 1; epoch <= numberOfEpochs; epoch++) {
        cout << "Epoch " << epoch << " loss: " << getLoss(xTrain, yTrain) << endl;
        vector<int> permutation = getRandomPermutation(xTrain.size());
        for (int batchIt = 0; batchIt < xTrain.size(); batchIt += miniBatchSize) {
            vector<vector<double> > x = getSubSet(xTrain, permutation, batchIt, miniBatchSize);
            vector<vector<double> > y = getSubSet(yTrain, permutation, batchIt, miniBatchSize);
            backPropagationForBatch(x, y);
        }
    }
}

void Model::describe() {
    for (vector<vector<double> > layer : layers) {
        cout << "(" << layer.size() << " " << layer[0].size() << ")\n";
    }
}

vector<vector<double> > Model::getSubSet( const vector<vector<double> >& complete,
                      vector<int>& permutation, int startIndex, int size) {
    vector<vector<double> > subset;
    for (int i = startIndex; i < startIndex + size; i++) {
        subset.push_back(complete[permutation[i]]);
    }
    return subset;
}

vector<vector<vector<double> > > Model::copyWeightsDimensions() {
    vector<vector<vector<double> > > copy;
    for (int i = 0; i < layers.size(); i++) {
        copy.push_back(vector<vector<double> >(layers[i].size(), 
                                                 vector<double>(layers[i][0].size(), 0)));
    }
    return copy;
}

vector<vector<double> > Model::copyBiasDimensions() {
    vector<vector<double> > copy;
    for (int i = 0; i < biases.size(); i++) {
        copy.push_back(vector<double>(biases[i].size(), 0));
    }
    return copy;
}

void Model::backPropagationForBatch(const vector<vector<double> >& x,
                                    const vector<vector<double> >& y) {
    double learningStep = 3.0;

    vector<vector<vector<double> > > deltaW = copyWeightsDimensions();
    vector<vector<double> > deltaB = copyBiasDimensions();

    for (int i = 0; i < x.size(); i++) {
        backPropagation(deltaW, deltaB, x[i], y[i]);
    }
    for (int k = 0; k < layers.size(); k++) {
        for (int i = 0; i < layers[k].size(); i++) {
            for (int j = 0; j < layers[k][i].size(); j++) {
                layers[k][i][j] -= learningStep * (deltaW[k][i][j] / (double) x.size());
            }
        }
        for (int i = 0; i < biases[k].size(); i++) {
            biases[k][i] -= learningStep * (deltaB[k][i] / (double) x.size());
        }
    }
}

void Model::backPropagation(vector<vector<vector<double> > >& deltaW,
                            vector<vector<double> >& deltaB,
                            const vector<double>& x, const vector<double>& y) {

    vector<vector<vector<double> > > dw = copyWeightsDimensions();
    vector<vector<double> > db = copyBiasDimensions();

    vector<vector<double> > activations;
    vector<vector<double> > zs;

    vector<double> activation = x;
    vector<double> z;

    activations.push_back(activation);

    for (int layerId = 0; layerId < layers.size(); layerId++) {
        z = multiplyVectorWithMatrix(activation, layers[layerId]);
        addVectors(z, biases[layerId]);
        zs.push_back(z);

        activation = z;
        applySigmoid(activation);
        activations.push_back(activation);
    }

    int layerId = layers.size();
    vector<double> delta = activations[layerId];
    z = zs[layerId-1];

    applySigmoidPrime(z);
    subtractVectors(delta, y);
    multiplyVectors(delta, z);

    db[layerId-1] = delta;
    dotMult(dw[layerId-1], activations[layerId-1], delta);

    for (layerId = layerId - 1; layerId > 0; layerId--) {
        z = zs[layerId-1];
        applySigmoidPrime(z);

        vector<vector<double> > transposeW = matTranspose(layers[layerId-1]);
        vector<double> transformed = multiplyVectorWithMatrix(delta, transposeW);
        multiplyVectors(transformed, z);
        delta = transformed;

        db[layerId-1] = delta;
        dotMult(dw[layerId-1], activations[layerId-1], delta);
    }

    addCube(deltaW, dw);
    addMatrix(deltaB, db);
}