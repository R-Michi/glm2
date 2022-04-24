#pragma once

inline int32_t glm2::detail::core::common::floatBitsToInt::_default_i32(float x)
{
    return util::bit_cast<int32_t, float>(x);
}

inline __m128i glm2::detail::core::common::floatBitsToInt::_default_i32v(__m128 x)
{
    return _mm_castps_si128(x);
}