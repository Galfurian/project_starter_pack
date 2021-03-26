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
double drsqrt(double x, unsigned iter = 1);

/// @brief The same behaviour of drsqrt except that it works with float.
/// 
/// @param x The input value x.
/// @return Returns 1 over the square-root of x.
float frsqrt(float x, unsigned iter = 1);
    
} // namespace approximath

