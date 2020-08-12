#ifndef UTILS_HPP_
#define UTILS_HPP_

#include <vector>
#include <cmath>

using namespace std;

vector<double> multiplyVectorWithMatrix(const vector<double> v, 
                                        const vector<vector<double> > matrix);

vector<vector<double> > matTranspose(const vector<vector<double> >& matrix);

void dotMult(vector<vector<double> >& result, 
             const vector<double>& row, const vector<double>& col);

vector<int> getRandomPermutation(int size);

void addVectors(vector<double>& result, const vector<double>& adder);

void subtractVectors(vector<double>& result, const vector<double>& adder);

void multiplyVectors(vector<double>& result, const vector<double>& mul);

void addMatrix(vector<vector<double> >& result, const vector<vector<double> >& adder);

void addCube(vector<vector<vector<double> > >& result,
             const vector<vector<vector<double> > >& adder);

void applySigmoid(vector<double>& v);

void applySigmoidPrime(vector<double>& v);


#endif // UTILS_HPP_