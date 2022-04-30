/**
* @file     floatBitsToUint_impl.inl
* @brief    Implementation of floatBitsToUint function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline uint32_t glm2::floatBitsToUint(float v)
{
    return detail::core::common::floatBitsToUint::_default_u32(v);
}

template<> inline glm2::vec<2, uint32_t> glm2::floatBitsToUint(const vec<2, float>& v)
{
    return detail::core::common::floatBitsToUint::_default_u32v(v.si128());
}
template<> inline glm2::vec<3, uint32_t> glm2::floatBitsToUint(const vec<3, float>& v)
{
    return detail::core::common::floatBitsToUint::_default_u32v(v());
}
template<> inline glm2::vec<4, uint32_t> glm2::floatBitsToUint(const vec<4, float>& v)
{
    return detail::core::common::floatBitsToUint::_default_u32v(v());
}
