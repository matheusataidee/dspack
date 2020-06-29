#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "cnn_layer.hpp"
#include "pooling_layer.hpp"
#include "dense_layer.hpp"

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

public:
    vector<LayerNamesEnum> layer_type;

    Model();

    void addCNNLayer(int n, int h, int w);

    void addPoolingLayer(int h, int w);

    void addFlattenLayer();

    void addDenseLayer(int input_size, int output_size);

    int getSize();
};

#endif // MODEL_HPP_