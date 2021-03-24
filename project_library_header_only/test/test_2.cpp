/// @file test_2.cpp
/// @author Enrico Fraccaroli (enry.frak@gmail.com)

#include "approximath/approximath.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

float dataset[] = {
    1.0,
    0.0,
    0.0,
    1.0,
    0.5,
    1.5,
    2.3,
    1.1,
    1.7,
    3.3,
    0.1,
    0.4
};
size_t dataset_size = 13;

int main(int argc, char *argv[])
{
    for (size_t i = 0; i < dataset_size; ++i) {
        float input_value = dataset[i];
        std::cout << "| " << std::setw(12) << input_value << " | " << std::setw(12) << approximath::frsqrt(input_value) << " |\n";
    }
    return 0;
}