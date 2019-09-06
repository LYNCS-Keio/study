cmake_minimum_required(VERSION 3.0)

project(ds4py)
set(PYBIND11_CPP_STANDARD -std=c++11)
set(CMAKE_CXX_FLAGS "-Wall -O3 -pthread")
add_subdirectory(pybind11)

pybind11_add_module(ds4py SHARED ds4py.cpp ds4py_wrap.cpp)  