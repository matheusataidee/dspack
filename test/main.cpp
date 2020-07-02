#include "model.hpp"

#include <iostream>

int main() {

    Model cnn = Model();
    cnn.addCNNLayer(32, 3, 3);
    cnn.addPoolingLayer(2, 2);
    cnn.addFlattenLayer();
    cnn.addDenseLayer(5408, 10);
    cout << cnn.getSize() << endl;
    for (int i = 0; i < cnn.getSize(); i++) {
        switch (cnn.layer_type[i]) {
            case CONV2D:
                cout << "CONV2D" << endl;
                break;
            case POOLING:
                cout << "POOLING" << endl;
                break;
            case DENSE:
                cout << "DENSE" << endl;
                break;
            case FLATTEN:
                cout << "FLATTEN" << endl;
                break;
        }
    }

    Tensor input = Tensor(1, 28, 28);
    cnn.apply(input);
    return 0;
}