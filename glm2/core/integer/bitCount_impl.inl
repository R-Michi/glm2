/**
* @file     bitCount_impl.inl
* @brief    Implementation of bitCount function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename genIType>
inline int32_t glm2::bitCount(genIType x)
{
    uint32_t ret;
    detail::core::integer::bitCount::_default_u32v(reinterpret_cast<const uint32_t*>(&x), &ret, 1);
    return detail::util::bit_cast<int32_t, uint32_t>(ret);
}

template<glm2::length_t L, typename T>
inline glm2::vec<L, int32_t> glm2::bitCount(const vec<L, T>& x)
{
    uint32_t ret[L];
    detail::core::integer::bitCount::_default_u32v(reinterpret_cast<const uint32_t*>(vec<L, T>::value_ptr(x)), ret, L);
    return vec<L, int32_t>(reinterpret_cast<int32_t*>(ret));
}
