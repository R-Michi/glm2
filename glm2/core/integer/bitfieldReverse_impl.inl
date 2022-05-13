/**
* @file     bitfieldReverse_impl.inl
* @brief    Implementation of bitfieldReverse function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename genIType>
inline genIType glm2::bitfieldReverse(genIType x)
{
    genIType ret;
    __m128 xmm0 = detail::core::integer::bitfieldReverse::_default_u32v(_mm_loadu_si32(&x));
    _mm_storeu_si32(&ret);
    return ret;
}

template<typename T> inline glm2::vec<2, T> glm2::bitfieldReverse(const vec<2, T>& x)
{
    return detail::core::integer::bitfieldReverse::_default_u32v(x.si128());
}
template<typename T> inline glm2::vec<3, T> glm2::bitfieldReverse(const vec<3, T>& x)
{
    return detail::core::integer::bitfieldReverse::_default_u32v(x());
}
template<typename T> inline glm2::vec<4, T> glm2::bitfieldReverse(const vec<4, T>& x)
{
    return detail::core::integer::bitfieldReverse::_default_u32v(x());
}
