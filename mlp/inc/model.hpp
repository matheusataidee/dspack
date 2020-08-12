#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <iostream>
#include <vector>
#include <random>


#include "utils.hpp"

using namespace std;

class Model {
    vector<vector<vector<double> > > layers;
    vector<vector<double> > biases;

public:
    Model(const vector<pair<int, int> > layersSizes);

    vector<double> runInference(const vector<double> x);

    void train(const vector<vector<double> >& x, const vector<vector<double> >& y);

    double getLoss(const vector<vector<double> >& x, const vector<vector<double> >& y);

    void describe();
private:
    vector<vector<double> > getSubSet(const vector<vector<double> >& complete,
                                      vector<int>& permutation, int startIndex, int size);

    vector<vector<vector<double> > > copyWeightsDimensions();

    vector<vector<double> > copyBiasDimensions();

    void backPropagationForBatch(const vector<vector<double> >& x,
                                 const vector<vector<double> >& y);

    void backPropagation(vector<vector<vector<double> > >& deltaW,
                         vector<vector<double> >& deltaB,
                         const vector<double>& x, const vector<double>& y);
};

#endif // MODEL_HPP_