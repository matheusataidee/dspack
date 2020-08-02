#include "tensor.hpp"

Tensor::Tensor(int l, int n, int m) : l(l), n(n), m(m) { 
    v = vector<double>(l * n * m);
}

void Tensor::setVal(int k, int i, int j, double val) {
    v[k * n * m + i * m + j] = val;
}

double Tensor::getVal(int k, int i, int j) {
    return v[k * n * m + i * m + j];
}

void Tensor::addTo(int k, int i, int j, double val) {
    v[k * n * m + i * m + j] += val;
}

void Tensor::clean(int k, int i, int j) {
    v[k * n * m + i * m + j] = 0.0;
}

void Tensor::relu(int k, int i, int j) {
    if (v[k * n * m + i * m + j] < 0.0) {
        clean(k, i, j);
    }
}