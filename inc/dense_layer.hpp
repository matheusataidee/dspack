#ifndef DENSE_LAYER_HPP_
#define DENSE_LAYER_HPP_

#include "layer.hpp"

#include <vector>

using namespace std;

class DenseLayer : public Layer {
private:
    vector<vector<double> > m;
public:
    DenseLayer(int input_size, int output_size);
};

#endif // DENSE_LAYER_HPP_