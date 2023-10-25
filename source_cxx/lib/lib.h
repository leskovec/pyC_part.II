#pragma once

#include <iostream>

// eigen: matrix and eigenvalues
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>

// gsl: random number generator
#include <GSL/gsl_rng.h>

// struct to store the result
struct result {
    std::vector<double> eigval;
    std::vector<std::vector<double>> matrix;
};

// wrapper function that does all the work
result get_my_eigvals(const int n);