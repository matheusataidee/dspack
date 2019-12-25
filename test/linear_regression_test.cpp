#include "linear_regression.hpp"

using namespace std;

int main() {
    vector<vector<double> > dataset;
    int n_features = 1;
    LinearRegression model(n_features, dataset);
    return 0;
}