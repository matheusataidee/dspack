#ifndef CNN_LAYER_HPP_
#define CNN_LAYER_HPP_

#include <vector>

using namespace std;

class CNNLayer {
private:
    int h_, w_;
    vector<vector<double> > m;
public:
    CNNLayer(int h, int w);
};

#endif // CNN_LAYER_HPP_