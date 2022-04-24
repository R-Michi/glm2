#pragma once

inline bool glm2::detail::core::common::isinf::_default_f(float x)
{
    return std::isinf(x);
}

inline bool glm2::detail::core::common::isinf::_default_d(double x)
{
    return std::isinf(x);
}

inline __m128i glm2::detail::core::common::isinf::_default_fv(__m128 x)
{
    __m128i xmm0, xmm1, xmm2;
    xmm0 = _mm_castps_si128(x);
    xmm1 = _mm_set1_epi32(0x7F800000);  // inf 32bit
    xmm2 = _mm_cmpeq_epi32(xmm0, xmm1);
    xmm1 = _mm_set1_epi32(0xFF800000);  // -inf
    xmm0 = _mm_cmpeq_epi32(xmm0, xmm1);
    return _mm_or_si128(xmm0, xmm2);
}

inline __m128i glm2::detail::core::common::isinf::_default_dv2(__m128d x)
{
    __m128i xmm0, xmm1, xmm2;
    xmm0 = _mm_castpd_si128(x);
    xmm1 = _mm_set1_epi64x(0x7FF0000000000000); // inf 64bit
    xmm2 = _mm_cmpeq_epi64(xmm0, xmm1);
    xmm1 = _mm_set1_epi64x(0xFFF0000000000000); // -inf 64bit
    xmm0 = _mm_cmpeq_epi32(xmm0, xmm1);
    return _mm_or_si128(xmm0, xmm2);
}

inline __m128i glm2::detail::core::common::isinf::_default_dv(__m256d x)
{
    __m256i ymm0, ymm1, ymm2;
    ymm0 = _mm256_castpd_si256(x);
    ymm1 = _mm256_set1_epi64x(0x7FF0000000000000);
    ymm2 = _mm256_cmpeq_epi32(ymm0, ymm1);
    ymm1 = _mm256_set1_epi64x(0xFFF0000000000000);
    ymm0 = _mm256_cmpeq_epi32(ymm0, ymm1);
    ymm0 = _mm256_or_si256(ymm0, ymm2);
    ymm1 = _mm256_set_epi32(0, 0, 0, 0, 6, 4, 2, 0);
    ymm0 = _mm256_permutevar8x32_epi32(ymm0, ymm1);
    return _mm256_castsi256_si128(ymm0);
}
