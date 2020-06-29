#include "dense_layer.hpp"

DenseLayer::DenseLayer(int input_size, int output_size) {
    m = vector<vector<double> >(input_size, vector<double>(output_size));
}