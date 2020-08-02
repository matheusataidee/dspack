#ifndef POOLING_LAYER_HPP_
#define POOLING_LAYER_HPP_

#include "layer.hpp"

using namespace std;

class PoolingLayer : public Layer {
private:
    int h_, w_;
public:
    PoolingLayer(int h, int w);

    int getH();

    int getW();
};

#endif // POOLING_LAYER_HPP_