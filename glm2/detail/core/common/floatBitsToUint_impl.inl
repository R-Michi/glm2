#pragma once

inline uint32_t glm2::detail::core::common::floatBitsToUint::_default_u32(float x)
{
    return util::bit_cast<uint32_t, float>(x);
}

inline __m128i glm2::detail::core::common::floatBitsToUint::_default_i32v(__m128 x)
{
    return _mm_castps_si128(x);
}