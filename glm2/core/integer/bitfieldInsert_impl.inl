/**
* @file     bitfieldInsert_impl.inl
* @brief    Implementation of bitfieldInsert function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename genIType>
inline genIType glm2::bitfieldInsert(genIType base, genIType insert, int32_t offset, int32_t bits)
{
    genIType ret;
    __m128i xmm0 = detail::core::integer::bitfieldInsert::_default_i32v(_mm_loadu_si32(&base), _mm_loadu_si32(&insert), offset, bits);
    _mm_storeu_si32(&ret, xmm0);
    return ret;
}

template<typename T> inline glm2::vec<2, T> glm2::bitfieldInsert(const vec<2, T>& base, const vec<2, T>& insert, int32_t offset, int32_t bits)
{
    return detail::core::integer::bitfieldInsert::_default_i32v(base.intrinEXT(), insert.intrinEXT(), offset, bits);
}
template<typename T> inline glm2::vec<3, T> glm2::bitfieldInsert(const vec<3, T>& base, const vec<3, T>& insert, int32_t offset, int32_t bits)
{
    return detail::core::integer::bitfieldInsert::_default_i32v(base.intrin(), insert.intrin(), offset, bits);
}
template<typename T> inline glm2::vec<4, T> glm2::bitfieldInsert(const vec<4, T>& base, const vec<4, T>& insert, int32_t offset, int32_t bits)
{
    return detail::core::integer::bitfieldInsert::_default_i32v(base.intrin(), insert.intrin(), offset, bits);
}
