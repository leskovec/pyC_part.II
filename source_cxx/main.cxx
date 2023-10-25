#include "lib.h"
#include <iostream>

int main(int argc, char* argv[]){
    
    if (argc < 2 ){
      std::cout << "Usage: " << argv[0] << " n" << std::endl;
      std::cout << "n: number of eigenvalues to compute" << std::endl;
      return 1;
    }

    int n = atoi(argv[1]);
    std::cout<< "computing eigenvalues of a " << n << "x" << n << " matrix" << std::endl;
    result r = get_my_eigvals(n);
    std::cout << "eigenvalues: ";
    for(int i=0; i<n; ++i){
      std::cout<< r.eigval[i];
    } 
    std::cout << std::endl;
    return 0;
}
