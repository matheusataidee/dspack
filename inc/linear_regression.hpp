#ifndef LINEAR_REGRESSION_HPP_
#define LINEAR_REGRESSION_HPP_

#include <vector>

using namespace std;

class LinearRegression {
private:
    int n_features_;
    vector<vector<double> > dataset_;

    vector<double> teta_0;
    vector<double> teta_1;
public:
    LinearRegression(int n_features, vector<vector<double> > dataset);
};

#endif // LINEAR_REGRESSION_HPP_