#include "cnn_layer.hpp"

CNNLayer::CNNLayer(int n, int h, int w) {
    n_ = n;
    h_ = h;
    w_ = w;
    m = vector<vector<vector<double> > >(n_, 
                                        vector<vector<double> >(h_, 
                                        vector<double>(w_)));
}