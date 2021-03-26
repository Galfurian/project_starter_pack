/// @file approximath.cpp
/// @author Enrico Fraccaroli (enry.frak@gmail.com)
/// @brief
/// @version 0.1
/// @date 2021-03-23
///
/// @copyright Copyright (c) 2021
///

#include "approximath/approximath.hpp"
#include <pybind11/pybind11.h>
#include <exception>

namespace approximath
{
double drsqrt(double x, unsigned iter)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = x * 0.5F;
    y  = x;
    i  = *(long *)&y;           // evil floating point bit level hacking
    i  = 0x5f3759df - (i >> 1); // what the fuck?
    y  = *(float *)&i;

    if ((iter == 0) || (iter > 100))
        iter = 1;
    for (unsigned citer = 0; citer < iter; ++citer)
        y *= (threehalfs - (x2 * y * y));

    return y;
}

float frsqrt(float x, unsigned iter)
{
    return static_cast<float>(drsqrt(static_cast<double>(x), iter));
}

} // namespace approximath

namespace py = pybind11;

PYBIND11_MODULE(approximath, m)
{
    m.doc() = "Approximated Math Library";
    m.def("drsqrt",
          &approximath::drsqrt,
          "Fast inverse square root implementation from Quake III Arena, for double values.\n\n"
          "Parameters\n"
          "----------\n"
          "    x    : The input value x.\n"
          "    iter : The number of internal iterations (seggestion: 0 > iter < 5).\n",
          py::arg("x"),
          py::arg("iter") = 1);
    m.def("frsqrt",
          &approximath::frsqrt,
          "Fast inverse square root implementation from Quake III Arena, for float values.\n\n"
          "Parameters\n"
          "----------\n"
          "    x    : The input value x.\n"
          "    iter : The number of internal iterations (seggestion: 0 > iter < 5).\n",
          py::arg("x"),
          py::arg("iter") = 1);
}