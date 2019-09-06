#include "ds4py.h"
#include "pybind11/include/pybind11/pybind11.h"


namespace py = pybind11;

PYBIND11_MODULE(ds4py, m) {
    m.doc() = "dual shock 4 listener for python";
    py::class_<DS4_util>(m, "DS4_util")
        .def(py::init())
        .def("DS4_init", &DS4_util::DS4_init, "A function which initializes ds4", py::arg("dir") = "/dev/input/js0")
        //.def("DS4_update", &DS4_util::DS4_update, "A function which updates ds4 axes and buttons")
        .def("DS4_GetDriverVersion", &DS4_util::DS4_GetDriverVersion, "A function which returns driver version")
        .def("DS4_GetDeviceName", &DS4_util::DS4_GetDeviceName, "A function which returns device name")
        .def("DS4_GetAxis", &DS4_util::DS4_GetAxis, "A function which returns value of each axis", py::arg("num"))
        .def("DS4_GetButton", &DS4_util::DS4_GetButton, "A function which returns value of each button", py::arg("num"))
        .def_property_readonly("axes", &DS4_util::DS4_GetNumAxes, "A function which returns number of axes")
        .def_property_readonly("buttons", &DS4_util::DS4_GetNumButtons, "A function which returns number of buttons");

}