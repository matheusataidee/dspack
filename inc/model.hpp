#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <iostream>
#include <cmath>
#include <algorithm>

#include "cnn_layer.hpp"
#include "pooling_layer.hpp"
#include "dense_layer.hpp"
#include "tensor.hpp"

#include <vector>

using namespace std;

enum LayerNamesEnum {
    CONV2D,
    POOLING,
    FLATTEN,
    DENSE
};

class Model {
private:
    vector<Layer*> layer;

    Tensor runConvolution(Tensor tensor, int cur);

    Tensor runPooling(Tensor tensor, int cur);

    Tensor runFlatten(Tensor tensor);

    Tensor runDense(Tensor tensor, int cur);

public:
    vector<LayerNamesEnum> layer_type;

    Model();

    void addCNNLayer(int n, int h, int w);

    void addPoolingLayer(int h, int w);

    void addFlattenLayer();

    void addDenseLayer(int input_size, int output_size);

    Tensor apply(Tensor input);

    int getSize();
};

#endif // MODEL_HPP_