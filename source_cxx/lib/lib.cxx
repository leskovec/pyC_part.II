

#include "lib.h"


result get_my_eigvals(const int n){
    Eigen::MatrixXd A = Eigen::MatrixXd::Zero(n,n);

    // use GSL to generate random numbers
    gsl_rng * r = gsl_rng_alloc (gsl_rng_taus);
    gsl_rng_set(r, 1);

    // populate A with random numbers from GSL
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            A(i,j) = gsl_rng_uniform (r);
        }
    }

    // make a self-adjoint matrix
    Eigen::MatrixXd B = A.transpose()*A;

    // solve the eigensystem
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigsys(B);

    // store the eigenvalues and the matrix to result and return
    // note, python won't know what to do with Eigen Vectors and Matrices,
    // but it can handle stl containers like std::vector

    result res;
    res.eigval.resize(n);
    for(int i=0; i<n; ++i){
      res.eigval[i] = eigsys.eigenvalues()(i);
    }
    res.matrix.resize(n);
    for(int i=0; i<n; ++i){
      res.matrix[i].resize(n);
      for(int j=0; j<n; ++j){
        res.matrix[i][j] = B(i,j);
      }
    }

    return res;
}



