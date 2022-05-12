#pragma once

inline __m128i glm2::detail::core::vector_relational::not_::_default(__m128i x)
{
    return _mm_xor_si128(x, _mm_set1_epi32(0xFFFFFFFF));
}
