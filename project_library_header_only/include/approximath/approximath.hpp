/// @file approximath.hpp
/// @author Enrico Fraccaroli (enry.frak@gmail.com)
/// @brief 
/// @version 0.1
/// @date 2021-03-23
/// 
/// @copyright Copyright (c) 2021
/// 

namespace approximath
{
    
/// @brief The following code is the fast inverse square root implementation
///        from Quake III Arena, stripped of C preprocessor directives, but 
///        including the exact original comment text.
///
/// @param x The input value x.
/// @return Returns 1 over the square-root of x.
/// @details
/// The advantages in speed offered by the fast inverse square root kludge 
/// came from treating the 32-bit floating-point word[note 2] as an integer, 
/// then subtracting it from a "magic" constant, 0x5F3759DF.
/// 
/// This integer subtraction and bit shift results in a bit pattern which, 
/// when re-cast as a floating-point number, is a rough approximation for 
/// the inverse square root of the input number. One iteration of Newton's 
/// method is performed to gain some accuracy, and the code is finished.
/// 
/// The algorithm generates reasonably accurate results using a unique first
/// approximation for Newton's method; however, it is much slower and less 
/// accurate than using the SSE instruction rsqrtss on x86 processors also
/// released in 1999.
inline double drsqrt(double x) {
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

/// @brief The same behaviour of drsqrt except that it works with float.
/// 
/// @param x The input value x.
/// @return Returns 1 over the square-root of x.
float frsqrt(float x) {
    return static_cast<float>(drsqrt(static_cast<double>(x)));
}
    
} // namespace approximath

