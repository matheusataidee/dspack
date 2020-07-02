#include "model.hpp"

Model::Model() { }

void Model::addCNNLayer(int n, int h, int w) {
    CNNLayer* cnn_layer = new CNNLayer(n, h, w);
    layer.push_back(cnn_layer);
    layer_type.push_back(CONV2D);
}

void Model::addPoolingLayer(int h, int w) {
    PoolingLayer* pooling_layer = new PoolingLayer(h, w);
    layer.push_back(pooling_layer);
    layer_type.push_back(POOLING);
}

void Model::addFlattenLayer() {
    layer_type.push_back(FLATTEN);
}

void Model::addDenseLayer(int input_size, int output_size) {
    DenseLayer* dense_layer = new DenseLayer(input_size, output_size);
    layer.push_back(dense_layer);
    layer_type.push_back(DENSE);
}

int Model::getSize() {
    return layer_type.size();
}

Tensor Model::runConvolution(Tensor tensor, int cur) {
    CNNLayer* cnn_layer = (CNNLayer*) layer[cur];
    Tensor output = Tensor(cnn_layer->getN(),
                           tensor.n - (cnn_layer->getH() - 1),
                           tensor.m - (cnn_layer->getW() - 1));
    
    cout << output.l << " " << output.n << " " << output.m << endl;
    for (int k = 0; k < output.l; k++) {
        for (int i = 0; i < output.n; i++) {
            for (int j = 0; j < output.m; j++) {
                output.clean(k, i, j);
                for (int ii = 0; ii < cnn_layer->getH(); ii++) {
                    for (int jj = 0; jj < cnn_layer->getW(); jj++) {
                        output.addTo(k, i, j, cnn_layer->getVal(k, ii, jj) * 
                                              tensor.getVal(0, i + ii, j + jj));
                    }
                }
                output.relu(k, i, j);
            }
        }
    }

    return output;
}

Tensor Model::runPooling(Tensor tensor, int cur) {
    return tensor;
}

Tensor Model::runFlatten(Tensor tensor) {
    return tensor;
}

Tensor Model::runDense(Tensor tensor, int cur) {
    return tensor;
}

Tensor Model::apply(Tensor input) {
    int cur = 0;
    Tensor tensor = input;
    for (LayerNamesEnum layer_enum : layer_type) {
        switch (layer_enum) {
            case CONV2D:
                tensor = runConvolution(tensor, cur++);
                break;
            case POOLING:
                tensor = runPooling(tensor, cur++);
                break;
            case FLATTEN:
                tensor = runFlatten(tensor);
                break;
            case DENSE:
                tensor = runDense(tensor, cur++);
                break;
        }
    }
    return tensor;
}