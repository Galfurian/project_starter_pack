/// @file approximath.hpp
/// @author Enrico Fraccaroli (enry.frak@gmail.com)
/// @brief
/// @version 0.1
/// @date 2021-03-23
///
/// @copyright Copyright (c) 2021
///

#include <Eigen/Dense>

namespace approximath
{

    template <typename DerivedA, typename DerivedB>
    typename DerivedA::Scalar squaredist(const Eigen::MatrixBase<DerivedA> &p1,
                                         const Eigen::MatrixBase<DerivedB> &p2)
    {
        return (p1 - p2).squaredNorm();
    }

} // namespace approximath
