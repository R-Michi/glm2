/**
* @file     abs_impl.inl
* @brief    Implementation of abs function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline float glm2::abs(float x)
{
    return detail::core::common::abs::_default_f(x);
}
template<> inline double glm2::abs(double x)
{
    return detail::core::common::abs::_default_d(x);
}
template<> inline int32_t glm2::abs(int32_t x)
{
    return detail::core::common::abs::_default_i32(x);
}

template<typename genType>
inline genType glm2::abs(genType x)
{
    static_assert(std::is_floating_point<genType>::value || (std::is_integral<genType>::value && std::is_signed<genType>::value), 
    "[glm2::abs]: " GLM2_ASSERT_MSG_FLOAT_SIGNED);
    return detail::core::common::abs::_default<genType>(x);
}


template<> inline glm2::vec<2, float> glm2::abs(const vec<2, float>& x)
{
    return detail::core::common::abs::_default_fv(x.intrinEXT());
}
template<> inline glm2::vec<3, float> glm2::abs(const vec<3, float>& x)
{
    return detail::core::common::abs::_default_fv(x.intrin());
}
template<> inline glm2::vec<4, float> glm2::abs(const vec<4, float>& x)
{
    return detail::core::common::abs::_default_fv(x.intrin());
}

template<> inline glm2::vec<2, double> glm2::abs(const vec<2, double>& x)
{
    return detail::core::common::abs::_default_dv2(x.intrin());
}
template<> inline glm2::vec<3, double> glm2::abs(const vec<3, double>& x)
{
    return detail::core::common::abs::_default_dv(x.intrin());
}
template<> inline glm2::vec<4, double> glm2::abs(const vec<4, double>& x)
{
    return detail::core::common::abs::_default_dv(x.intrin());
}

template<> inline glm2::vec<2, int32_t> glm2::abs(const vec<2, int32_t>& x)
{
    return detail::core::common::abs::_default_i32v(x.intrinEXT());
}
template<> inline glm2::vec<3, int32_t> glm2::abs(const vec<3, int32_t>& x)
{
    return detail::core::common::abs::_default_i32v(x.intrin());
}
template<> inline glm2::vec<4, int32_t> glm2::abs(const vec<4, int32_t>& x)
{
    return detail::core::common::abs::_default_i32v(x.intrin());
}
