#ifndef TENSOR_HPP_
#define TENSOR_HPP_

#include <vector>

using namespace std;

class Tensor {
public:
int n, m, l;
vector<double> v;

Tensor(int l, int n, int m);

void clean(int k, int i, int j);

void relu(int k, int i, int j);

void setVal(int k, int i, int j, double val);

double getVal(int k, int i, int j);

void addTo(int k, int i, int j, double val);

};

#endif // TENSOR_HPP_