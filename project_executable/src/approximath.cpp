/// @file approximath.cpp
/// @author Enrico Fraccaroli (enry.frak@gmail.com)
/// @brief 
/// @version 0.1
/// @date 2021-03-23
/// 
/// @copyright Copyright (c) 2021
/// 

#include "approximath/approximath.hpp"

namespace approximath
{
    
double drsqrt(double x) {
    long i;
	float x2, y;
	const float threehalfs = 1.5F;

	x2 = x * 0.5F;
	y  = x;
	i  = * ( long * ) &y;                       // evil floating point bit level hacking
	i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
	y  = * ( float * ) &i;
	y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
//	y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

	return y;
}
    
float frsqrt(float x) {
    return static_cast<float>(drsqrt(static_cast<double>(x)));
}
    
} // namespace approximath

