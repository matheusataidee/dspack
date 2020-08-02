#include "pooling_layer.hpp"

PoolingLayer::PoolingLayer(int h, int w) {
    h_ = h;
    w_ = w;
}

int PoolingLayer::getH() {
    return h_;
}

int PoolingLayer::getW() {
    return w_;
}