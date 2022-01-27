//
// Created by bochao on 1/23/22.
//
#include "NN.h"

class Layer{
public:
    Layer(unsigned int output_dim, unsigned int input_dim, ActiveFnc);
private:
    unsigned int out_dim;
    unsigned int in_dim;
    ActiveFnc act_fnc;
    MatrixXd weights;
};

/**
 * Add a layer in neural network.
 * The input dimension of the layer should match the output dimension of the previous layer.
 * The first layer's input dimension should match the number of features.
 * The last layer's output dimension should be 1.
 *
 * @param output_dim output dimension of this layer
 * @param input_dim input dimension of this layer
 * @throws std::runtime_error Thrown if dimensions don't match
 */
void NN::addLayer(unsigned int output_dim, unsigned int input_dim, ActiveFnc) {

}

/**
 * Train a neural network.
 * The neural network should contain at least one layer.
 * The first layer's input dimension should match the number of features.
 *
 * @param examples training data points
 * @param labels corresponding labels of data points
 * @param iter_num limits of iterations
 * @throws std::runtime_error Thrown if dimensions don't match
 */
void NN::train(const vector<vector<int>> &examples, const vector<int> &labels, unsigned int iter_num) {

}

/**
 * 
 * @param unlabeled
 * @return
 */
vector<int> NN::predict(const vector<vector<int>> &unlabeled) {

}

const vector<double> &NN::getLoss() {

}

/**
 *
 */
void NN::forward() {

}

/**
 *
 */
void NN::backward() {

}

