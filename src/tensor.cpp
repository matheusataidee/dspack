#include "tensor.hpp"

Tensor::Tensor(int n, int m) : n(n), m(m) { 
    v = vector<double>(n * m);
}

int Tensor::getElement(int i, int j) {
    return v[i * m + j];
}