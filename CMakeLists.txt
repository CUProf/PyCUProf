cmake_minimum_required(VERSION 3.16.3)
project(pycuprof)

# pybind11
set(PYBIND_DIR ${CMAKE_CURRENT_SOURCE_DIR}/CUProf/sanalyzer/py_frame/pybind11)
add_subdirectory(${PYBIND_DIR})
pybind11_add_module(pycuprof pycuprof.cpp)

# compute_sanitizer
set(COMPUTE_SANITIZER_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/CUProf/lib)
set(COMPUTE_SANITIZER_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/CUProf/include)
target_include_directories(pycuprof PRIVATE ${COMPUTE_SANITIZER_INCLUDE_DIR})
target_link_directories(pycuprof PRIVATE ${COMPUTE_SANITIZER_LIB_DIR})
target_link_libraries(pycuprof PRIVATE compute_sanitizer)
