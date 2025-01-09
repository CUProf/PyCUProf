#include <pybind11/pybind11.h>
#include "compute_sanitizer.h"

static bool pycuprof_initialized = false;

void cuprof_init() {
    pycuprof_initialized = true;
    enable_compute_sanitizer(false);
}
void cuprof_start() {
    if (!pycuprof_initialized) {
        throw std::runtime_error("CUProf is not initialized. Please call cuprof_init first.");
    }
    enable_compute_sanitizer(true);
}
void cuprof_stop() {
    if (!pycuprof_initialized) {
        throw std::runtime_error("CUProf is not initialized. Please call cuprof_init first.");
    }
    enable_compute_sanitizer(false);
}

PYBIND11_MODULE(pycuprof, m) {
    m.doc() = "Python interface of CUProf";

    m.def("init", &cuprof_init, "Initialize CUProf (must be called at the very beginning)");
    m.def("start", &cuprof_start, "Start CUProf (start profiling, must be called after cuprof_init)");
    m.def("stop", &cuprof_stop, "Stop CUProf (stop profiling, must be called after cuprof_start)");
}
