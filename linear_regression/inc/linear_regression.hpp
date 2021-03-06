#ifndef LINEAR_REGRESSION_HPP_
#define LINEAR_REGRESSION_HPP_

#include <vector>

using namespace std;

class LinearRegression {
private:
    int n_features_;
    vector<vector<double> > dataset_;
    vector<double> y_;
    double step;

    vector<double> teta;
public:
    LinearRegression(int n_features, vector<vector<double> > dataset, vector<double> y);

    vector<vector<double> > getNormalizedDataset();
    void train(int n_iterations);
};

#endif // LINEAR_REGRESSION_HPP_