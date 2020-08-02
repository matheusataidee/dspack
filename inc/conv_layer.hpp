#ifndef CONV_LAYER_HPP_
#define CONV_LAYER_HPP_

#include "layer.hpp"

#include <vector>

using namespace std;

class ConvLayer : public Layer {
private:
    int n, h, w;
    vector<vector<vector<double> > > v;
public:
    ConvLayer(int n, int h, int w);

    int getN();

    int getH();

    int getW();

    double getVal(int k, int i, int j);
};

#endif // CONV_LAYER_HPP_