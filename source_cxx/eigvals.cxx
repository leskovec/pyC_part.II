

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <sstream>

#include "lib.h"

namespace py = pybind11;

PYBIND11_MODULE(eigvals, m) {
  m.doc() = "get eigenvalues from a positive definite random matrix";
  // add the results struct
  py::class_<result>(m, "result")
    .def(py::init<>())
    .def_readwrite("eigval", &result::eigval)
    .def_readwrite("matrix", &result::matrix);

  // add the get my evals function
  m.def("get_my_eigvals", &get_my_eigvals, "get eigenvalues from a positive definite random matrix", py::arg("n"),py::return_value_policy::reference);
}


