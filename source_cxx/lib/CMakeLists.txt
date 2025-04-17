

target_sources(lib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/lib.h"
    "${CMAKE_CURRENT_SOURCE_DIR}/lib.cxx"
)

find_package(Eigen3 3.4 REQUIRED NO_MODULE)
target_link_libraries(lib PUBLIC Eigen3::Eigen)

find_package(GSL REQUIRED)
target_link_libraries(lib PUBLIC GSL::gsl GSL::gslcblas)

target_include_directories(lib PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}" 
                                       "${Eigen_INCLUDE_DIRS}"  
                                       "${GSL_INCLUDE_DIRS}")
target_compile_definitions(lib PUBLIC BASE_VERSION=1.0)


