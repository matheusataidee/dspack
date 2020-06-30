#ifndef TENSOR_HPP_
#define TENSOR_HPP_

#include <vector>

using namespace std;

class Tensor {
public:
int n, m;
vector<double> v;

Tensor(int n, int m);

int getElement(int i, int j);

};

#endif // TENSOR_HPP_