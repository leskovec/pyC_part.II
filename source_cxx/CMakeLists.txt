cmake_minimum_required(VERSION 3.20)
project(GSLandEigen)

# compiler stuff, like standards and flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS  " ${CMAKE_CXX_FLAGS} -O2 -fvisibility=hidden ")
set(CMAKE_EXE_LINKER_FLAGS  " ${CMAKE_EXE_LINKER_FLAGS} -O2 -fvisibility=hidden ")

# external libraries
find_package(GSL REQUIRED)
find_package(Eigen3 3.4 REQUIRED)

# my libraries - where I have the code that uses these libraries
add_library(lib STATIC "")
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
# and the pybind11 libraries
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../pybind11
                ${CMAKE_CURRENT_BINARY_DIR}/pybind11)

# the main program 
add_executable(main.exe  main.cxx)  
target_link_libraries(main.exe PUBLIC lib Eigen3::Eigen GSL::gsl GSL::gslcblas)
target_include_directories(main.exe PUBLIC  
                        "${CMAKE_SOURCE_DIR}/lib/" 
                        Eigen3::Eigen
                        GSL::gsl GSL::gslcblas)

# install the executable
install(TARGETS main.exe RUNTIME DESTINATION bin)


# add the Pybind11 module
pybind11_add_module(eigvals eigvals.cxx)

target_include_directories(eigvals PRIVATE "${CMAKE_SOURCE_DIR}/lib" Eigen3::Eigen GSL::gsl GSL::gslcblas)
target_link_libraries(eigvals PRIVATE lib pybind11::module Eigen3::Eigen GSL::gsl GSL::gslcblas )

# install the plot module to the install path
# install(TARGETS module LIBRARY DESTINATION module)
install(TARGETS eigvals DESTINATION ${CMAKE_INSTALL_PREFIX}/pymodule)