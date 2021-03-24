/// @file main.cpp
/// @author Enrico Fraccaroli (enry.frak@gmail.com)

#include "approximath/approximath.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

#include <Eigen/Dense>

using Eigen::MatrixXd;

int main(int argc, char *argv[])
{
    MatrixXd m1(2, 2);
    m1(0, 0) = 3;
    m1(1, 0) = 2.5;
    m1(0, 1) = -1;
    m1(1, 1) = m1(1, 0) + m1(0, 1);

    std::cout << "m1 :\n" << m1 << "\n\n";

    MatrixXd m2(3, 3);
    m2 << 1, 2, 3,
        4, 5, 6,
        7, 8, 9;
    MatrixXd m3(3, 3);
    m2 << 56, 2, 3,
        4, 7, 6,
        7, 9, 3;

    std::cout << "m2 :\n" << m1 << "\n";
    std::cout << "m3 :\n" << m1 << "\n";
    std::cout << "squaredist(m2, m3) :\n" << approximath::squaredist(m2, m3) << "\n";

    return 0;
}