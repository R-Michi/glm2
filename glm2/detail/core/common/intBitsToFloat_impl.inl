#pragma once

inline float glm2::detail::core::common::intBitsToFloat::_default_f(int32_t x)
{
    return util::bit_cast<float, int32_t>(x);
}

inline __m128 glm2::detail::core::common::intBitsToFloat::_default_fv(__m128i x)
{
    return _mm_castsi128_ps(x);
}