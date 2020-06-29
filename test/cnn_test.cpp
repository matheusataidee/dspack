#include "model.hpp"

#include <iostream>

int main() {

    Model cnn = Model();
    cnn.addCNNLayer(32, 3, 3);
    cnn.addPoolingLayer(2, 2);
    cout << cnn.getSize() << endl;
    return 0;
}