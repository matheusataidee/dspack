#include "model.hpp"

Model::Model() { }

void Model::addCNNLayer(int n, int h, int w) {
    CNNLayer* cnn_layer = new CNNLayer(n, h, w);
    layer.push_back(cnn_layer);
}

void Model::addPoolingLayer(int h, int w) {
    PoolingLayer* pooling_layer = new PoolingLayer(h, w);
    layer.push_back(pooling_layer);
}

int Model::getSize() {
    return layer.size();
}