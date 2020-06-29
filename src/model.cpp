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