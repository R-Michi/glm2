#pragma once

inline __m128i glm2::detail::core::vector_relational::greaterThanEqual::_default_fv(__m128 x, __m128 y)
{
    return _mm_castps_si128(_mm_cmpge_ps(x, y));
}
inline __m128i glm2::detail::core::vector_relational::greaterThanEqual::_default_dv(__m256d x, __m256d y)
{
    __m256i ymm0, ymm1;
    ymm0 = _mm256_castpd_si256(_mm256_cmp_pd(x, y, _CMP_GE_OQ));
    ymm1 = _mm256_set_epi32(0, 0, 0, 0, 6, 4, 2, 0);
    ymm0 = _mm256_permutevar8x32_epi32(ymm0, ymm1);
    return _mm256_castsi256_si128(ymm0);
}
inline __m128i glm2::detail::core::vector_relational::greaterThanEqual::_default_i32v(__m128i x, __m128i y)
{
    __m128i xmm0, xmm1;
    xmm0 = _mm_cmpgt_epi32(x, y);
    xmm1 = _mm_cmpeq_epi32(x, y);
    return _mm_or_si128(xmm0, xmm1);
}
