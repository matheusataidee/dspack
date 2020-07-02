#ifndef CNN_LAYER_HPP_
#define CNN_LAYER_HPP_

#include "layer.hpp"

#include <vector>

using namespace std;

class CNNLayer : public Layer {
private:
    int n, h, w;
    vector<vector<vector<double> > > v;
public:
    CNNLayer(int n, int h, int w);

    int getN();

    int getH();

    int getW();

    double getVal(int k, int i, int j);
};

#endif // CNN_LAYER_HPP_