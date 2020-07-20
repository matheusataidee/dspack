#ifndef DENSE_LAYER_HPP_
#define DENSE_LAYER_HPP_

#include "layer.hpp"

#include <vector>

using namespace std;

class DenseLayer : public Layer {
public:
    int n, m;
    vector<vector<double> > v;

    DenseLayer(int input_size, int output_size);
};

#endif // DENSE_LAYER_HPP_