#pragma once

inline float glm2::detail::core::common::uintBitsToFloat::_default_f(uint32_t x)
{
    return util::bit_cast<float, uint32_t>(x);
}

inline __m128 glm2::detail::core::common::uintBitsToFloat::_default_fv(__m128i x)
{
    return _mm_castsi128_ps(x);
}