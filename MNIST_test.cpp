/*
 * Training set:
 * 1. x: mxn MatrixXd, where m is the number of features, n is the size of training set
 * 2. y: nx1 vector. y_i represent the corresponding y-value for i-th columns of x.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <filesystem>

#include "Eigen/Dense"

#define NUM_FEATURES 64

using std::cout;
using std::endl;
using std::string;
using std::vector;

using Eigen::MatrixXd;
using Eigen::VectorXd;

void readMNIST(const string& filename, MatrixXd& x, MatrixXd& y) {
    std::ifstream fin;
    string path = string(std::filesystem::current_path().parent_path()) + "/datasets/";
    fin.open(path + filename, std::ios::in);
    // readfile not found
    if (!fin.is_open()) {
        cout << filename << " does not exist under the directory " << path << endl;
        return;
    }

    vector<string> lines;
    string curLine, tmp;

    // while we are not at the end of file
    while(fin >> tmp) {
        // read the entire line
        getline(fin, curLine);
        // store it to lines
        lines.push_back(tmp);
    }

    // reshape the x,y
    x.resize(NUM_FEATURES, lines.size());
    y.resize(lines.size(), 1);

    // break every line
    std::stringstream ss;
    string col;
    for (int i = 0; i < lines.size(); ++i) {
        ss << lines[i];
        for (int j = 0; j < NUM_FEATURES; ++j) {
            getline(ss, col, ',');
            int col_dat = std::stoi(col);
            assert(col_dat >= 0 && col_dat <= 16);
            x(j, i) = col_dat;
        }
        // the last column is the label digit
        getline(ss, col, ',');
        int col_dat = std::stoi(col);
        assert(col_dat >= 0 && col_dat <= 10);
        y(i,0) = col_dat;
        ss.clear();
    }
}

int main() {
    MatrixXd mat(3,2);
    mat << 1,2,3,4,5,6;
    Eigen::Vector3d vec;
    vec << 1,2,3;
    cout << mat << endl;
    cout << vec << endl;
    cout << mat.transpose() * vec << endl;
    MatrixXd x,y;
    readMNIST("optdigits.tra", x, y);
    cout << "The training set is" << endl;
    cout << x << endl;
    cout << "The y-label is" << endl;
    cout << y << endl;
}
