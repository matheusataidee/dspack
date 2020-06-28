#ifndef CNN_HPP_
#define CNN_HPP_

#include "cnn_layer.hpp"

#include <vector>

using namespace std;

class CNN {
private:
    vector<CNNLayer> layer;

public:
    CNN();

    void addLayer(int h, int w);

    int getSize();
};

#endif // CNN_HPP_