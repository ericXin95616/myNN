//
// Created by bochao on 1/23/22.
//

#ifndef MYNN_NN_H
#define MYNN_NN_H
#include <vector>

#include "../Eigen/Dense"

using std::vector;
using Eigen::MatrixXd;
using Eigen::VectorXd;

enum class ActiveFnc {
    RELU,
    SIGMOID,
    LINEAR
};

class Layer{
public:
    Layer(unsigned int output_dim, unsigned int input_dim, ActiveFnc);
private:
    unsigned int out_dim;
    unsigned int in_dim;
    ActiveFnc act_fnc;
    MatrixXd weights;
};

class NN {
public:
    NN();
    void addLayer(unsigned int output_dim, unsigned int input_dim, ActiveFnc);
    void train(const vector<vector<int>>& examples, const vector<int>& labels, unsigned int iter_num); // we use MSE loss by default
    vector<int> predict(const vector<vector<int>>& unlabeled);
    const vector<double>& getLoss();
private:
    void forward();
    void backward();

    int trn_set_size;
    MatrixXd dat_pts; // row is the number of features, col == trn_set_size
    VectorXd dat_labels; // len == trn_set_size
    vector<Layer> layers;
};
#endif //MYNN_NN_H
