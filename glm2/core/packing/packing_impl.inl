/**
* @file     packing_impl.inl
* @brief    Implementation of all packing functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

#include "packing_base.h"
#include "../../detail/core/packing/packing.h"

inline double glm2::packDouble2x32(const vec<2, uint32_t>& x)
{
    return detail::core::packing::packDouble2x32::_default(x.si128());
}

inline uint32_t glm2::packHalf2x16(const vec<2, float>& x)
{
    return detail::core::packing::packHalf2x16::_default(x.si128());
}

inline uint32_t glm2::packSnorm2x16(const vec<2, float>& x)
{
    return detail::core::packing::packSnorm2x16::_default(x.si128());
}

inline uint32_t glm2::packSnorm4x8(const vec<4, float>& x)
{
    return detail::core::packing::packSnorm4x8::_default(x());
}

inline uint32_t glm2::packUnorm2x16(const vec<2, float>& x)
{
    return detail::core::packing::packUnorm2x16::_default(x.si128());
}

inline uint32_t glm2::packUnorm4x8(const vec<4, float>& x)
{
    return detail::core::packing::packUnorm4x8::_default(x());
}

inline glm2::vec<2, uint32_t> glm2::unpackDouble2x32(double x)
{
    return detail::core::packing::unpackDouble2x32::_default(x);
}

inline glm2::vec<2, float> glm2::unpackHalf2x16(uint32_t x)
{
    return detail::core::packing::unpackHalf2x16::_default(x);
}

inline glm2::vec<2, float> glm2::unpackSnorm2x16(uint32_t x)
{
    return detail::core::packing::unpackSnorm2x16::_default(x);
}

inline glm2::vec<4, float> glm2::unpackSnorm4x8(uint32_t x)
{
    return detail::core::packing::unpackSnorm4x8::_default(x);
}

inline glm2::vec<2, float> glm2::unpackUnorm2x16(uint32_t x)
{
    return detail::core::packing::unpackUnorm2x16::_default(x);
}

inline glm2::vec<4, float> glm2::unpackUnorm4x8(uint32_t x)
{
    return detail::core::packing::unpackUnorm4x8::_default(x);
}
