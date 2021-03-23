/// @file main.cpp
/// @author Enrico Fraccaroli (enry.frak@gmail.com)

#include "approximath.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage:\n";
        std::cout << "    " << argv[0] << " <dataset.txt>\n";
        return 1;
    }
    std::ifstream input(argv[1], std::ios_base::in);

    if (!input)
    {
        std::cerr << "Can't open " << argv[1] << "!\n";
        return 1;
    }
    std::cout << "| " << std::setw(12) << "x"
              << " | " << std::setw(12) << "1/sqrt(x)"
              << " |\n";

    float input_value;
    while (!input.eof())
    {
        input >> input_value;
        std::cout << "| " << std::setw(12) << input_value << " | " << std::setw(12) << approximath::frsqrt(input_value) << " |\n";
    }
    return 0;
}