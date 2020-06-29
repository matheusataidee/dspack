#ifndef CNN_LAYER_HPP_
#define CNN_LAYER_HPP_

#include "layer.hpp"

#include <vector>

using namespace std;

class CNNLayer : public Layer {
private:
    int n_, h_, w_;
    vector<vector<vector<double> > > m;
public:
    CNNLayer(int n, int h, int w);
};

#endif // CNN_LAYER_HPP_