/**
* @file     findLSB_impl.inl
* @brief    Implementation of findLSB function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

template<typename genIType>
inline int32_t glm2::findLSB(genIType x)
{
    return detail::core::integer::findLSB::_default_u32(static_cast<uint32_t>(x));
}

template<typename T> inline glm2::vec<2, int32_t> glm2::findLSB(const vec<2, T>& x)
{
    return detail::core::integer::findLSB::_default_u32v(x.intrinEXT());
}
template<typename T> inline glm2::vec<3, int32_t> glm2::findLSB(const vec<3, T>& x)
{
    return detail::core::integer::findLSB::_default_u32v(x.intrin());
}
template<typename T> inline glm2::vec<4, int32_t> glm2::findLSB(const vec<4, T>& x)
{
    return detail::core::integer::findLSB::_default_u32v(x.intrin());
}
