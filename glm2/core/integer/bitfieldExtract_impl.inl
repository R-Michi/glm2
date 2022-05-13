/**
* @file     bitfieldExtract_impl.inl
* @brief    Implementation of bitfieldExtract function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<> inline int32_t glm2::bitfieldExtract(int32_t value, int32_t offset, int32_t bits)
{
    int32_t ret;
    __m128i xmm0 = detail::core::integer::bitfieldExtract::_default_i32v(_mm_loadu_si32(&value), offset, bits);
    _mm_storeu_si32(&ret, xmm0);
    return ret;
}
template<> inline uint32_t glm2::bitfieldExtract(uint32_t value, int32_t offset, int32_t bits)
{
    uint32_t ret;
    __m128i xmm0 = detail::core::integer::bitfieldExtract::_default_u32v(_mm_loadu_si32(&value), offset, bits);
    _mm_storeu_si32(&ret, xmm0);
    return ret;
}

template<> inline glm2::vec<2, int32_t> glm2::bitfieldExtract(const vec<2, int32_t>& value, int32_t offset, int32_t bits)
{
    return detail::core::integer::bitfieldExtract::_default_i32v(value.si128(), offset, bits);
}
template<> inline glm2::vec<3, int32_t> glm2::bitfieldExtract(const vec<3, int32_t>& value, int32_t offset, int32_t bits)
{
    return detail::core::integer::bitfieldExtract::_default_i32v(value(), offset, bits);
}
template<> inline glm2::vec<4, int32_t> glm2::bitfieldExtract(const vec<4, int32_t>& value, int32_t offset, int32_t bits)
{
    return detail::core::integer::bitfieldExtract::_default_i32v(value(), offset, bits);
}

template<> inline glm2::vec<2, uint32_t> glm2::bitfieldExtract(const vec<2, uint32_t>& value, int32_t offset, int32_t bits)
{
    return detail::core::integer::bitfieldExtract::_default_u32v(value.si128(), offset, bits);
}
template<> inline glm2::vec<3, uint32_t> glm2::bitfieldExtract(const vec<3, uint32_t>& value, int32_t offset, int32_t bits)
{
    return detail::core::integer::bitfieldExtract::_default_u32v(value(), offset, bits);
}
template<> inline glm2::vec<4, uint32_t> glm2::bitfieldExtract(const vec<4, uint32_t>& value, int32_t offset, int32_t bits)
{
    return detail::core::integer::bitfieldExtract::_default_u32v(value(), offset, bits);
}
