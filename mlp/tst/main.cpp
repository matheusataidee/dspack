#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "model.hpp"

using namespace std;

int main() {

    vector<vector<double> > x;
    vector<vector<double> > y;

    ifstream fin("mnist_train.csv");

    string line;
    getline(fin, line);
    while (getline(fin, line)) {
        vector<double> xNew;
        vector<double> yNew(10, 0.0);

        stringstream ss(line);
        string num;
        getline(ss, num, ',');
        yNew[stoi(num)] = 1.0;

        while (getline(ss, num, ',')) {
            int iNum = stoi(num);
            double fNum = iNum / (double)256;
            xNew.push_back(fNum);
        }
        x.push_back(xNew);
        y.push_back(yNew);
    }
    fin.close();
    
    cout << "x.size(): " << x.size() << endl;
    cout << "y.size(): " << y.size() << endl;

    vector<pair<int, int> > layerSizes;
    layerSizes.push_back({784, 30});
    layerSizes.push_back({30, 10});

    Model model = Model(layerSizes);
    model.train(x, y);

    for (int i = 0; i < 5; i++) {
        vector<double> result = model.runInference(x[i]);
        for (int j = 0; j < 10; j++) {
            cout << j << ": " << y[i][j] << ", ";
        }
        cout << endl;
        for (int j = 0; j < 10; j++) {
            cout << j << ": " << result[j] << ", ";
        }
        cout << endl << endl;
    }
    model.describe();

    return 0;
}