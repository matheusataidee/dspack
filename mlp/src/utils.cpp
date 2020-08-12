#include "utils.hpp"

vector<double> multiplyVectorWithMatrix(const vector<double> v, 
                                               const vector<vector<double> > matrix) {
    vector<double> output(matrix[0].size(), 0);

    for (int j = 0; j < matrix[0].size(); j++) {
        for (int i = 0; i < matrix.size(); i++) {
            output[j] += v[i] * matrix[i][j];
        }
    }

    return output;
}

vector<vector<double> > matTranspose(const vector<vector<double> >& matrix) {
    vector<vector<double> > output(matrix[0].size(), vector<double>(matrix.size()));

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            output[j][i] = matrix[i][j];
        }
    }

    return output;
}

void dotMult(vector<vector<double> >& result, 
             const vector<double>& row, const vector<double>& col) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            result[i][j] = row[i] * col[j];
        }
    }
}

vector<int> getRandomPermutation(int size) {
    vector<int> permutation(size);
    for (int i = 0; i < size; i++) permutation[i] = i;
    for (int i = 0; i < size; i++) {
        int id = rand() % (size - i);
        swap(permutation[i], permutation[i + id]);
    }
    return permutation;
}

void addVectors(vector<double>& result, const vector<double>& adder) {
    for (int i = 0; i < result.size(); i++) {
        result[i] += adder[i];
    }
}

void subtractVectors(vector<double>& result, const vector<double>& sub) {
    for (int i = 0; i < result.size(); i++) {
        result[i] -= sub[i];
    }
}

void multiplyVectors(vector<double>& result, const vector<double>& mul) {
    for (int i = 0; i < result.size(); i++) {
        result[i] *= mul[i];
    }
}

void addMatrix(vector<vector<double> >& result, const vector<vector<double> >& adder) {
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            result[i][j] += adder[i][j];
        }
    }
}

void addCube(vector<vector<vector<double> > >& result,
             const vector<vector<vector<double> > >& adder) {

    for (int k = 0; k < result.size(); k++) {
        for (int i = 0; i < result[k].size(); i++) {
            for (int j = 0; j < result[k][i].size(); j++) {
                result[k][i][j] += adder[k][i][j];
            }
        }
    }
}

double sigmoid(double val) {
    return (double)1 / (double)((double)1 + exp(-val));
}

void applySigmoid(vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        v[i] = sigmoid(v[i]);
    }
}

void applySigmoidPrime(vector<double>& v) {
    for (int i = 0; i < v.size(); i++) {
        double sig = sigmoid(v[i]);
        v[i] = sig * (1 - sig);
    }
}