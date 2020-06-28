#include "cnn.hpp"

#include <iostream>

int main() {
    CNN cnn = CNN();
    cnn.addLayer(24, 24);
    cnn.addLayer(24, 24);
    cnn.addLayer(24, 24);
    cout << cnn.getSize() << endl;
    return 0;
}