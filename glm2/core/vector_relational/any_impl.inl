/**
* @file     any_impl.inl
* @brief    Implementation of any function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<glm2::length_t L> inline bool glm2::any(const vec<L, bool32_t>& x)
{
    return detail::core::vector_relational::any::_default(vec<L, bool32_t>::value_ptr(x), L);
}
