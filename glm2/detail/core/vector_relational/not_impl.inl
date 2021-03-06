/**
* @file     not_impl.inl
* @brief    Detailed implementation of the not_ function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline __m128i glm2::detail::core::vector_relational::not_::_default(__m128i x)
{
    return _mm_xor_si128(x, _mm_set1_epi32(0xFFFFFFFF));
}
