cmake_minimum_required(VERSION 3.10)
project(NumericalCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(NumericalCalculator 
    src/main.cpp
    src/algorithm/interpolation/interpolation.cpp
    src/algorithm/naive_inverse/naive_inverse.cpp
    src/algorithm/regression/regression.cpp
    src/algorithm/bisection/bisection.cpp
    src/algorithm/differentiation_forward/differentiation_forward.cpp
    src/algorithm/differentiation_backward/differentiation_backward.cpp
    src/algorithm/falsi/falsi.cpp
    src/algorithm/newton_raphson/newton_raphson.cpp
    src/algorithm/secant/secant.cpp   
    src/algorithm/gauss_elimination/gauss_elimination.cpp
    src/algorithm/gauss_jordan/gauss_jordan.cpp
    src/algorithm/lu_decomposition/lu_decomposition.cpp
    src/algorithm/rk_method/rk.cpp
    src/algorithm/simpson_one_third/simpson_one_third.cpp
    src/algorithm/simpson_three_eight/simpson_three_eight.cpp
)
