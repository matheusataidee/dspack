#include "cnn_layer.hpp"

CNNLayer::CNNLayer(int n, int h, int w) : n(n), h(h), w(w) {
    v = vector<vector<vector<double> > >(n, 
                                        vector<vector<double> >(h, 
                                        vector<double>(w)));
}

int CNNLayer::getN() {
    return n;
}

int CNNLayer::getH() {
    return h;
}

int CNNLayer::getW() {
    return w;
}

double CNNLayer::getVal(int k, int i, int j) {
    return v[k][i][j];
}