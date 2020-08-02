#include "linear_regression.hpp"

LinearRegression::LinearRegression(int n_features, vector<vector<double> > dataset, vector<double> y) {
    step = 0.01; // TODO: Make it changeable
    n_features_ = n_features;
    teta = vector<double>(n_features_ + 1);
    y_ = y;

    dataset_ = vector<vector<double> >(dataset.size(), vector<double>(n_features_));
    // Normalization of dataset features
    for (int j = 0; j < n_features_; j++) {
        double sum = 0.0;
        double mini = dataset[0][j];
        double maxi = dataset[0][j];
        for (int i = 0; i < dataset.size(); i++) {
            sum += dataset[i][j];
            mini = min(mini, dataset[i][j]);
            maxi = max(maxi, dataset[i][j]);
        }
        double avg = sum / (double)dataset.size();
        double div = max(maxi - avg, avg - mini);

        // Values get in range (-1, +1)
        for (int i = 0; i < dataset.size(); i++)
            dataset_[i][j] = (dataset[i][j] - avg) / (div);
    }
}

vector<vector<double> > LinearRegression::getNormalizedDataset() {
    return dataset_;
}

void LinearRegression::train(int n_iterations) {
    for (int k = 0; k < n_iterations; k++) {
        vector<double> dif(n_features_ + 1);
        for (int i = 0; i < (int)dataset_.size(); i++) {
            double prediction = teta[0];
            for (int j = 1; j <= n_features_; j++) {
                prediction += teta[j] * dataset_[i][j-1];
            }
            dif[0] += prediction - y_[i];
            for (int j = 1; j <= n_features_; j++) {
                dif[j] += (prediction - y_[i]) * dataset_[i][j-1];
            }
        }
        for (int i = 0; i <= n_features_; i++) {
            teta[i] -= (step / (double)dataset_.size()) * dif[i];
        }
    }
}