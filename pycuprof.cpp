#include <pybind11/pybind11.h>
#include "compute_sanitizer.h"

#include <iostream>
#include <cstdlib>

static bool pycuprof_initialized = false;

void cuprof_init() {
    pycuprof_initialized = true;
    enable_compute_sanitizer(false);
}
void cuprof_start() {
    if (!pycuprof_initialized) {
        std::cerr << "error: PyCUProf is not initialized. Please call cuprof_init() first." << std::endl;
        std::exit(1);
    }
    std::cout << "[PYCUPROF INFO] Start CUProf profiling" << std::endl;
    std::cout.flush();
    enable_compute_sanitizer(true);
}
void cuprof_stop() {
    if (!pycuprof_initialized) {
        std::cerr << "error: PyCUProf is not initialized. Please call cuprof_init() first." << std::endl;
        std::exit(1);
    }
    std::cout << "[PYCUPROF INFO] Stop CUProf profiling" << std::endl;
    std::cout.flush();
    enable_compute_sanitizer(false);
}

PYBIND11_MODULE(pycuprof, m) {
    m.doc() = "Python interface of CUProf";

    // Call cuprof_init automatically during import
    cuprof_init();

    // m.def("init", &cuprof_init, "Initialize CUProf (must be called at the very beginning)");
    m.def("start", &cuprof_start, "Start CUProf, start profiling");
    m.def("stop", &cuprof_stop, "Stop CUProf, stop profiling");
}
