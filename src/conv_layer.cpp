#include "conv_layer.hpp"

ConvLayer::ConvLayer(int n, int h, int w) : n(n), h(h), w(w) {
    v = vector<vector<vector<double> > >(n, 
                                        vector<vector<double> >(h, 
                                        vector<double>(w)));
}

int ConvLayer::getN() {
    return n;
}

int ConvLayer::getH() {
    return h;
}

int ConvLayer::getW() {
    return w;
}

double ConvLayer::getVal(int k, int i, int j) {
    return v[k][i][j];
}