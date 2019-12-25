#include "linear_regression.hpp"

LinearRegression::LinearRegression(int n_features, vector<vector<double> > dataset) {
    n_features_ = n_features;
    teta_0 = vector<double>(n_features_);
    teta_1 = vector<double>(n_features_);

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