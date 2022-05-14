/**
* @file     findMSB_impl.inl
* @brief    Implementation of findMSB function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename genIType>
inline int32_t glm2::findMSB(genIType x)
{
    int32_t ret;
    __m128 xmm0 = detail::core::integer::findMSB::_default_u32v(_mm_loadu_si32(&x), 1);
    _mm_storeu_si32(&ret, xmm0);
    return ret;
}

template<typename T> inline glm2::vec<2, int32_t> glm2::findMSB(const vec<2, T>& x)
{
    return detail::core::integer::findMSB::_default_u32v(x.si128(), 2);
}
template<typename T> inline glm2::vec<3, int32_t> glm2::findMSB(const vec<3, T>& x)
{
    return detail::core::integer::findMSB::_default_u32v(x(), 3);
}
template<typename T> inline glm2::vec<4, int32_t> glm2::findMSB(const vec<4, T>& x)
{
    return detail::core::integer::findMSB::_default_u32v(x(), 4);
}