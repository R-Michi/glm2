/**
* @file     ldexp_impl.inl
* @brief    Implementation of ldexp function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename genType>
inline genType glm2::ldexp(genType x, int32_t& exp)
{
    genType fract;
    detail::core::common::ldexp::_default(&x, &fract, &exp, 1);
    return fract;
}

template<glm2::length_t L, typename T>
inline glm2::vec<L, T> glm2::ldexp(const vec<L, T>& x, vec<L, int32_t>& exp)
{
    vec<L, T> fract;
    detail::core::common::ldexp::_default(vec<L, T>::value_ptr(x), vec<L, T>::value_ptr(fract), vec<L, int32_t>::value_ptr(exp), L);
    return fract;
}
