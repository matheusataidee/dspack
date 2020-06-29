#ifndef MODEL_HPP_
#define MODEL_HPP_

#include "cnn_layer.hpp"
#include "pooling_layer.hpp"

#include <vector>

using namespace std;

class Model {
private:
    vector<Layer*> layer;

public:
    Model();

    void addCNNLayer(int n, int h, int w);

    void addPoolingLayer(int h, int w);

    int getSize();
};

#endif // MODEL_HPP_