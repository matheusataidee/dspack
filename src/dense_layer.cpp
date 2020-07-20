#include "dense_layer.hpp"

DenseLayer::DenseLayer(int input_size, int output_size) : n(input_size), m(output_size) {
    v = vector<vector<double> >(n, vector<double>(m));
}