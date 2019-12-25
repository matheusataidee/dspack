#include "linear_regression.hpp"

LinearRegression::LinearRegression(int n_features, vector<vector<double> > dataset) {
    n_features_ = n_features;
    dataset_ = dataset;
    teta_0 = vector<double>(n_features);
    teta_1 = vector<double>(n_features);
}