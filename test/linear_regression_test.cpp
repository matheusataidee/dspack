#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include "linear_regression.hpp"

using namespace std;

int main() {
    vector<vector<double> > dataset;
    int n_features = 3;
    int n_samples = 200;

    dataset = vector<vector<double> >(n_samples, vector<double>(n_features));
    for (int i = 0; i < n_samples; i++) {
        for (int j = 0; j < n_features; j++) {
            dataset[i][j] = rand() % 1000;
            if ((rand() % 100) < 50) dataset[i][j] *= -1;
        }
    }


    LinearRegression model(n_features, dataset);

    vector<vector<double> > norm_dataset = model.getNormalizedDataset();

    assert((int)norm_dataset.size() == n_samples);
    for (int i = 0; i < n_samples; i++) {
        assert((int)norm_dataset[i].size() == n_features);
        for (int j = 0; j < n_features; j++) {
            // Verifying if values are in norm range
            assert(norm_dataset[i][j] >= -1.0);
            assert(norm_dataset[i][j] <= 1.0);
        }
    }
    cout << "Test passed" << endl;
    return 0;
}