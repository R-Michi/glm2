/**
* @file     floatBitsToInt_impl.inl
* @brief    Detailed implementation of the floatBitsToInt function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/


#pragma once

inline int32_t glm2::detail::core::common::floatBitsToInt::_default_i32(float x)
{
    return util::bit_cast<int32_t, float>(x);
}

inline __m128i glm2::detail::core::common::floatBitsToInt::_default_i32v(__m128 x)
{
    return _mm_castps_si128(x);
}
