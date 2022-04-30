/**
* @file     intBitsToFloat_impl.inl
* @brief    Detailed implementation of the intBitsToFloat function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::common::intBitsToFloat::_default_f(int32_t x)
{
    return util::bit_cast<float, int32_t>(x);
}

inline __m128 glm2::detail::core::common::intBitsToFloat::_default_fv(__m128i x)
{
    return _mm_castsi128_ps(x);
}
