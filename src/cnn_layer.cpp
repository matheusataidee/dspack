#include "cnn_layer.hpp"

CNNLayer::CNNLayer(int h, int w) {
    h_ = h;
    w_ = w;
    m = vector<vector<double> >(h_, vector<double>(w_));
}