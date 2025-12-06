cmake_minimum_required(VERSION 3.10)
project(NumericalCalculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(NumericalCalculator 
    src/main.cpp
    src/algorithm/interpolation/interpolation.cpp
    src/algorithm/inverse/naive_inverse.cpp
    src/algorithm/regression/regression.cpp
    src/algorithm/non_linear_equation/bisection.cpp
    src/algorithm/non_linear_equation/falsi.cpp
)