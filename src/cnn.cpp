#include "cnn.hpp"

CNN::CNN() { }

void CNN::addLayer(int h, int w) {
    layer.push_back(CNNLayer(h, w));
}

int CNN::getSize() {
    return layer.size();
}