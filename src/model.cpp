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
    return tensor;
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