import sys

sys.path.insert(0, '/Users/leskovec/Documents/Teaching/EuroCC2/pybind11/tutorial_II/install/pymodule')

import eigvals as ev


n=3
a = ev.get_my_eigvals(n)

print("matrix:")
for i in range(n):
    print(a.matrix[i][:])

print("eigenvalues:")
print(a.eigval)
