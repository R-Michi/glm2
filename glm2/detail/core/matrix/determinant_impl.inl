/**
* @file     determinant_impl.inl
* @brief    Detailed implementation of the determinant function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline float glm2::detail::core::matrix::determinant::_default_fm2x2(const __m64* M_in)
{
    float f;
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(reinterpret_cast<const float*>(M_in));
    xmm1 = _mm_permute_ps(xmm0, 0x13);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    xmm1 = _mm_movehl_ps(xmm0, xmm0);
    xmm0 = _mm_sub_ss(xmm0, xmm1);
    _mm_store_ss(&f, xmm0);
    return f;
}

inline float glm2::detail::core::matrix::determinant::_default_fm3x3(const __m128* M_in)
{
    float det;
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6;
    xmm0 = _mm_set_ss(M_in[0][1]);    // d
    xmm1 = _mm_set_ss(M_in[0][2]);    // g
    xmm2 = _mm_set_ss(M_in[1][1]);    // e
    xmm3 = _mm_set_ss(M_in[1][2]);    // h
    xmm4 = _mm_set_ss(M_in[2][1]);    // f
    xmm5 = _mm_set_ss(M_in[2][2]);    // i
    xmm6 = _mm_mul_ss(xmm4, xmm3);
    xmm4 = _mm_mul_ss(xmm4, xmm1);
    xmm1 = _mm_mul_ss(xmm2, xmm1);
    xmm2 = _mm_fmsub_ss(xmm2, xmm5, xmm6);  // a0
    xmm5 = _mm_fmsub_ss(xmm0, xmm5, xmm4);  // a1
    xmm0 = _mm_fmsub_ss(xmm0, xmm3, xmm1);  // a2
    xmm5 = _mm_mul_ss(_mm_set_ss(M_in[1][0]), xmm5);
    xmm1 = _mm_fmsub_ss(_mm_set_ss(M_in[0][0]), xmm2, xmm5);
    xmm0 = _mm_fmadd_ss(_mm_set_ss(M_in[2][0]), xmm0, xmm1);
    _mm_store_ss(&det, xmm0);
    return det;
}

inline float glm2::detail::core::matrix::determinant::_default_fm4x4(const __m128* M_in)
{
    float det;
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xmm8, xmm9, xmm10, xmm11;
    xmm0 = _mm_set_ss(M_in[0][2]);          // i
    xmm1 = _mm_set_ss(M_in[0][3]);          // m
    xmm2 = _mm_set_ss(M_in[1][2]);          // j
    xmm3 = _mm_set_ss(M_in[1][3]);          // n
    xmm4 = _mm_set_ss(M_in[2][2]);          // k
    xmm5 = _mm_set_ss(M_in[2][3]);          // o
    xmm6 = _mm_set_ss(M_in[3][2]);          // l
    xmm7 = _mm_set_ss(M_in[3][3]);          // p
    xmm8 = _mm_mul_ss(xmm6, xmm5);          // l * o -> x0
    xmm9 = _mm_mul_ss(xmm6, xmm3);          // l * n -> x1
    xmm6 = _mm_mul_ss(xmm6, xmm1);          // l * m -> x3
    xmm10 = _mm_mul_ss(xmm4, xmm1);         // k * m -> x4
    xmm1 = _mm_mul_ss(xmm2, xmm1);          // j * m -> x5
    xmm11 = _mm_mul_ss(xmm4, xmm3);         // k * n -> x2
    xmm4 = _mm_fmsub_ss(xmm4, xmm7, xmm8);  // x0
    xmm8 = _mm_fmsub_ss(xmm2, xmm7, xmm9);  // x1
    xmm2 = _mm_fmsub_ss(xmm2, xmm5, xmm11); // x2
    xmm6 = _mm_fmsub_ss(xmm0, xmm7, xmm6);  // x3
    xmm7 = _mm_fmsub_ss(xmm0, xmm5, xmm10); // x4
    xmm0 = _mm_fmsub_ss(xmm0, xmm3, xmm1);  // x5
    xmm1 = _mm_set_ss(M_in[0][1]);          // e;
    xmm3 = _mm_set_ss(M_in[1][1]);          // f;
    xmm5 = _mm_set_ss(M_in[2][1]);          // g;
    xmm9 = _mm_set_ss(M_in[3][1]);          // h;
    xmm10 = _mm_mul_ss(xmm5, xmm8);
    xmm10 = _mm_fmsub_ss(xmm3, xmm4, xmm10);
    xmm10 = _mm_fmadd_ss(xmm9, xmm2, xmm10);    // y0
    xmm11 = _mm_mul_ss(xmm5, xmm6);
    xmm4 = _mm_fmsub_ss(xmm1, xmm4, xmm11);
    xmm4 = _mm_fmadd_ss(xmm9, xmm7, xmm4);      // y1
    xmm6 = _mm_mul_ss(xmm3, xmm6);
    xmm6 = _mm_fmsub_ss(xmm1, xmm8, xmm6);
    xmm6 = _mm_fmadd_ss(xmm9, xmm0, xmm6);      // y2
    xmm3 = _mm_mul_ss(xmm3, xmm7);
    xmm1 = _mm_fmsub_ss(xmm1, xmm2, xmm3);
    xmm0 = _mm_fmadd_ss(xmm5, xmm0, xmm1);      // y3
    xmm0 = _mm_mul_ss(xmm0, _mm_set_ss(M_in[3][0]));
    xmm0 = _mm_fmsub_ss(xmm6, _mm_set_ss(M_in[2][0]), xmm0);
    xmm0 = _mm_fnmadd_ss(xmm4, _mm_set_ss(M_in[1][0]), xmm0);
    xmm0 = _mm_fmadd_ss(xmm10, _mm_set_ss(M_in[0][0]), xmm0);
    _mm_store_ss(&det, xmm0);
    return det;
}

inline double glm2::detail::core::matrix::determinant::_default_dm2x2(const __m128d* M_in)
{
    double det;
    __m128d xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_set_sd(M_in[0][0]);
    xmm1 = _mm_set_sd(M_in[0][1]);
    xmm1 = _mm_mul_sd(xmm1, _mm_set_sd(M_in[1][0]));
    xmm0 = _mm_fmsub_sd(xmm0, _mm_set_sd(M_in[1][1]), xmm1);
    _mm_store_sd(&det, xmm0);
    return det;
}

inline double glm2::detail::core::matrix::determinant::_default_dm3x3(const __m256d* M_in)
{
    double det;
    __m128d xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6;
    xmm0 = _mm_set_sd(M_in[0][1]);    // d
    xmm1 = _mm_set_sd(M_in[0][2]);    // g
    xmm2 = _mm_set_sd(M_in[1][1]);    // e
    xmm3 = _mm_set_sd(M_in[1][2]);    // h
    xmm4 = _mm_set_sd(M_in[2][1]);    // f
    xmm5 = _mm_set_sd(M_in[2][2]);    // i
    xmm6 = _mm_mul_sd(xmm4, xmm3);
    xmm4 = _mm_mul_sd(xmm4, xmm1);
    xmm1 = _mm_mul_sd(xmm2, xmm1);
    xmm2 = _mm_fmsub_sd(xmm2, xmm5, xmm6);  // a0
    xmm5 = _mm_fmsub_sd(xmm0, xmm5, xmm4);  // a1
    xmm0 = _mm_fmsub_sd(xmm0, xmm3, xmm1);  // a2
    xmm5 = _mm_mul_sd(_mm_set_sd(M_in[1][0]), xmm5);
    xmm1 = _mm_fmsub_sd(_mm_set_sd(M_in[0][0]), xmm2, xmm5);
    xmm0 = _mm_fmadd_sd(_mm_set_sd(M_in[2][0]), xmm0, xmm1);
    _mm_store_sd(&det, xmm0);
    return det;
}

inline double glm2::detail::core::matrix::determinant::_default_dm4x4(const __m256d* M_in)
{
    double det;
    __m128d xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xmm8, xmm9, xmm10, xmm11;
    xmm0 = _mm_set_sd(M_in[0][2]);          // i
    xmm1 = _mm_set_sd(M_in[0][3]);          // m
    xmm2 = _mm_set_sd(M_in[1][2]);          // j
    xmm3 = _mm_set_sd(M_in[1][3]);          // n
    xmm4 = _mm_set_sd(M_in[2][2]);          // k
    xmm5 = _mm_set_sd(M_in[2][3]);          // o
    xmm6 = _mm_set_sd(M_in[3][2]);          // l
    xmm7 = _mm_set_sd(M_in[3][3]);          // p
    xmm8 = _mm_mul_sd(xmm6, xmm5);          // l * o -> x0
    xmm9 = _mm_mul_sd(xmm6, xmm3);          // l * n -> x1
    xmm6 = _mm_mul_sd(xmm6, xmm1);          // l * m -> x3
    xmm10 = _mm_mul_sd(xmm4, xmm1);         // k * m -> x4
    xmm1 = _mm_mul_sd(xmm2, xmm1);          // j * m -> x5
    xmm11 = _mm_mul_sd(xmm4, xmm3);         // k * n -> x2
    xmm4 = _mm_fmsub_sd(xmm4, xmm7, xmm8);  // x0
    xmm8 = _mm_fmsub_sd(xmm2, xmm7, xmm9);  // x1
    xmm2 = _mm_fmsub_sd(xmm2, xmm5, xmm11); // x2
    xmm6 = _mm_fmsub_sd(xmm0, xmm7, xmm6);  // x3
    xmm7 = _mm_fmsub_sd(xmm0, xmm5, xmm10); // x4
    xmm0 = _mm_fmsub_sd(xmm0, xmm3, xmm1);  // x5
    xmm1 = _mm_set_sd(M_in[0][1]);          // e;
    xmm3 = _mm_set_sd(M_in[1][1]);          // f;
    xmm5 = _mm_set_sd(M_in[2][1]);          // g;
    xmm9 = _mm_set_sd(M_in[3][1]);          // h;
    xmm10 = _mm_mul_sd(xmm5, xmm8);
    xmm10 = _mm_fmsub_sd(xmm3, xmm4, xmm10);
    xmm10 = _mm_fmadd_sd(xmm9, xmm2, xmm10);    // y0
    xmm11 = _mm_mul_sd(xmm5, xmm6);
    xmm4 = _mm_fmsub_sd(xmm1, xmm4, xmm11);
    xmm4 = _mm_fmadd_sd(xmm9, xmm7, xmm4);      // y1
    xmm6 = _mm_mul_sd(xmm3, xmm6);
    xmm6 = _mm_fmsub_sd(xmm1, xmm8, xmm6);
    xmm6 = _mm_fmadd_sd(xmm9, xmm0, xmm6);      // y2
    xmm3 = _mm_mul_sd(xmm3, xmm7);
    xmm1 = _mm_fmsub_sd(xmm1, xmm2, xmm3);
    xmm0 = _mm_fmadd_sd(xmm5, xmm0, xmm1);      // y3
    xmm0 = _mm_mul_sd(xmm0, _mm_set_sd(M_in[3][0]));
    xmm0 = _mm_fmsub_sd(xmm6, _mm_set_sd(M_in[2][0]), xmm0);
    xmm0 = _mm_fnmadd_sd(xmm4, _mm_set_sd(M_in[1][0]), xmm0);
    xmm0 = _mm_fmadd_sd(xmm10, _mm_set_sd(M_in[0][0]), xmm0);
    _mm_store_sd(&det, xmm0);
    return det;
}

inline float glm2::detail::core::matrix::determinant::_alternative_fm4x4(const __m128* M_in)
{
    float det;
    __m256i ymm0;
    __m256 ymm1, ymm2, ymm3, ymm4, ymm5;
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5;

    // combute transpose matrix
    ymm0 = _mm256_set_epi32(7, 3, 5, 1, 6, 2, 4, 0);
    ymm1 = _mm256_permutevar8x32_ps(_mm256_loadu_ps(reinterpret_cast<const float*>(M_in + 0)), ymm0);
    ymm2 = _mm256_permutevar8x32_ps(_mm256_loadu_ps(reinterpret_cast<const float*>(M_in + 2)), ymm0);
    ymm3 = _mm256_shuffle_ps(ymm1, ymm2, 0x44);     // a, b, c, d, e, f, g, h
    ymm1 = _mm256_shuffle_ps(ymm1, ymm2, 0xEE);     // i, j, k, l, m, n, o, p

    // calculate the 6 base (2x2) determinants; X = dont care
    ymm0 = _mm256_set_epi32(0, 0, 0, 0, 0, 1, 1, 2);
    ymm2 = _mm256_permutevar8x32_ps(ymm1, ymm0);    // k, j, j, i, i, i, X, X
    ymm0 = _mm256_set_epi32(0, 0, 5, 6, 7, 6, 7, 7);
    ymm4 = _mm256_permutevar8x32_ps(ymm1, ymm0);    // p, p, o, p, o, n, X, X
    ymm0 = _mm256_set_epi32(0, 0, 1, 2, 3, 2, 3, 3);
    ymm5 = _mm256_permutevar8x32_ps(ymm1, ymm0);    // l, l, k, l, k, j, X, X
    ymm0 = _mm256_set_epi32(0, 0, 4, 4, 4, 5, 5, 6);
    ymm1 = _mm256_permutevar8x32_ps(ymm1, ymm0);    // o, n, n, m, m, m, X, X
    ymm1 = _mm256_mul_ps(ymm5, ymm1);
    ymm1 = _mm256_fmsub_ps(ymm2, ymm4, ymm1);       // x0, x1, x2, x3, x4, x5, X, X

    // calculate first 2 3x3 sub matrix determinants
    ymm0 = _mm256_set_epi32(5, 5, 6, 6, 4, 4, 4, 5);
    ymm2 = _mm256_permutevar8x32_ps(ymm3, ymm0);    // f, e, e, e, g, g, f, f
    ymm0 = _mm256_set_epi32(4, 3, 3, 1, 2, 1, 0, 0);
    ymm4 = _mm256_permutevar8x32_ps(ymm1, ymm0);    // x0, x0, x1, x2, x1, x3, x3, x4
    ymm2 = _mm256_mul_ps(ymm2, ymm4);               // y0, y1, y2, y3, y4, y5, y6, y7

    // calculate 3. 3x3 sub matrix determinant
    ymm0 = _mm256_set_epi32(0, 0, 0, 0, 6, 7, 7, 7);
    ymm4 = _mm256_permutevar8x32_ps(ymm3, ymm0);    // h, h, h, g, X, X, X, X
    ymm0 = _mm256_set_epi32(0, 0, 0, 0, 5, 5, 4, 2);
    ymm5 = _mm256_permutevar8x32_ps(ymm1, ymm0);    // x2, x4, x5, x5, X, X, X, X
    
    /* !!! There is no need for 256 bit vectors anymore. !!! */
    // these operations are only for the compiler and won't invoke any instructions
    xmm3 = _mm256_castps256_ps128(ymm3);            // a, b, c, d
    xmm2 = _mm256_castps256_ps128(ymm2);            // y0, y1, y2, y3
    xmm4 = _mm256_castps256_ps128(ymm4);            // h, h, h, g
    xmm5 = _mm256_castps256_ps128(ymm5);            // x2, x4, x5, x5

    // separate y0-y3 from y4-y7 as they must be subtracted from each other,
    xmm0 = _mm256_extractf128_ps(ymm2, 0x1);        // y4, y5, y6, y7
    xmm0 = _mm_sub_ps(xmm2, xmm0);
    xmm0 = _mm_fmadd_ps(xmm4, xmm5, xmm0);          // z0, z1, z2, z3

    // 4x4 matrix determinant
    xmm0 = _mm_mul_ps(xmm3, xmm0);              // a*y0, b*y1, c*y2, d*y3 = x, y, z, w
    xmm1 = _mm_movehdup_ps(xmm0);               // y, y, w, w
    xmm0 = _mm_sub_ps(xmm0, xmm1);              // x-y, y-y, z-w, w-w
    xmm1 = _mm_unpackhi_ps(xmm0, xmm0);         // z-w, z-w, w-w, w-w
    xmm0 = _mm_add_ss(xmm0, xmm1);              // x-y+z-w, z-w, w-w, w-w = det(M_in), z-w, w-w, w-w
    _mm_store_ss(&det, xmm0);
    return det;
}

inline double glm2::detail::core::matrix::determinant::_alternative_dm3x3(const __m256d* M_in)
{
    double det;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4;
    __m128d xmm0, xmm1, xmm2;

    // combute 3 base 2x2 matrix determinants
    ymm0 = _mm256_unpackhi_pd(M_in[0], M_in[1]);        // d, e, X, X
    ymm1 = _mm256_unpacklo_pd(M_in[0], M_in[1]);        // a, b, g, h
    ymm2 = _mm256_unpackhi_pd(M_in[1], M_in[2]);        // e, f, X, X
    ymm3 = _mm256_unpacklo_pd(M_in[2], M_in[1]);        // c, b, i, h
    ymm4 = _mm256_permute2f128_pd(ymm1, ymm3, 0x20);    // a, b, c, f
    ymm0 = _mm256_permute4x64_pd(ymm0, 0x01);           // e, d, d, d
    ymm1 = _mm256_permute4x64_pd(ymm1, 0xAB);           // h, g, g, g
    ymm2 = _mm256_permute4x64_pd(ymm2, 0x05);           // f, f, e, e
    ymm3 = _mm256_permute4x64_pd(ymm3, 0xFA);           // i, i, h, h
    ymm1 = _mm256_mul_pd(ymm2, ymm1);
    ymm0 = _mm256_fmsub_pd(ymm0, ymm3, ymm1);           // x0, x1, x2, X

    // combute 3x3 matrix determinant
    ymm0 = _mm256_mul_pd(ymm0, ymm4);                   // a*x0, b*x1, c*x2, X = x, y, z, X
    ymm1 = _mm256_unpackhi_pd(ymm0, ymm0);              // y, y, X, X
    ymm2 = _mm256_sub_pd(ymm0, ymm1);                   // x-y, y-y, X, X
    xmm1 = _mm256_extractf128_pd(ymm0, 0x01);           // z, X
    xmm2 = _mm256_castpd256_pd128(ymm2);                // x-y, y-y
    xmm0 = _mm_add_sd(xmm2, xmm1);                      // x-y+z = det(M)
    _mm_store_sd(&det, xmm0);
    return det;
}

inline double glm2::detail::core::matrix::determinant::_alternative_dm4x4(const __m256d* M_in)
{
    double det;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7, ymm8;
    __m128d xmm0, xmm1;

    // combute transpose matrix, whereas the last 2 vectors are reversed
    ymm0 = _mm256_permute2f128_pd(M_in[0], M_in[2], 0x20);  // a, e, c, g
    ymm1 = _mm256_permute2f128_pd(M_in[1], M_in[2], 0x13);  // k, o, j, n
    ymm2 = _mm256_permute2f128_pd(M_in[1], M_in[3], 0x20);  // b, f, d, h
    ymm3 = _mm256_permute2f128_pd(M_in[0], M_in[3], 0x13);  // l, p, i, m
    ymm4 = _mm256_unpacklo_pd(ymm0, ymm2);                  // a, b, c, d
    ymm0 = _mm256_unpackhi_pd(ymm0, ymm2);                  // e, f, g, h
    ymm2 = _mm256_unpacklo_pd(ymm3, ymm1);                  // l, k, i, j
    ymm1 = _mm256_unpackhi_pd(ymm3, ymm1);                  // p, o, m, n

    // calculate the 6 base (2x2) determinants; X = dont care
    ymm5 = _mm256_permute4x64_pd(ymm1, 0x40);               // p, p, p, o
    ymm6 = _mm256_permute4x64_pd(ymm1, 0xF5);               // o, o, n, n
    ymm7 = _mm256_permute4x64_pd(ymm2, 0x40);               // l, l, l, k
    ymm8 = _mm256_permute4x64_pd(ymm2, 0xF5);               // k, k, j, j
    ymm6 = _mm256_mul_pd(ymm6, ymm7);
    ymm5 = _mm256_fmsub_pd(ymm5, ymm8, ymm6);               // x0, x0, x1, x2
    ymm6 = _mm256_permute4x64_pd(ymm1, 0xAA);               // m, m, m, m
    ymm7 = _mm256_permute4x64_pd(ymm2, 0xAA);               // i, i, i, i
    ymm2 = _mm256_mul_pd(ymm2, ymm6);
    ymm1 = _mm256_fmsub_pd(ymm1, ymm7, ymm2);               // x3, x4, X, x5

    // calculate 3x3 sub determinants
    ymm2 = _mm256_permute4x64_pd(ymm0, 0x01);               // f, e, e, e
    ymm3 = _mm256_permute4x64_pd(ymm0, 0x5A);               // g, g, f, f
    ymm0 = _mm256_permute4x64_pd(ymm0, 0xBF);               // h, h, h, g
    ymm6 = _mm256_permute2f128_pd(ymm5, ymm1, 0x21);        // x1, x2, x3, x4
    ymm1 = _mm256_unpackhi_pd(ymm6, ymm1);                  // x2, x4, x4, x5
    ymm6 = _mm256_permute4x64_pd(ymm6, 0xE8);               // x1, x3, x3, x4
    ymm1 = _mm256_permute_pd(ymm1, 0x0E);                   // x2, x4, x5, x5
    ymm3 = _mm256_mul_pd(ymm3, ymm6);
    ymm2 = _mm256_fmsub_pd(ymm2, ymm5, ymm3);
    ymm0 = _mm256_fmadd_pd(ymm0, ymm1, ymm2);               // y0, y1, y2, y3 = x, y, z, w

    // calculate 4x4 determinant
    ymm0 = _mm256_mul_pd(ymm0, ymm4);                       // a*x, b*y, c*z, d*w
    ymm1 = _mm256_unpackhi_pd(ymm0, ymm0);                  // b*y, b*y, d*w, d*w
    ymm0 = _mm256_sub_pd(ymm0, ymm1);                       // a*x - b*w, X, c*z - d*w, X
    xmm1 = _mm256_extractf128_pd(ymm0, 0x1);                // c*z - d*w
    xmm0 = _mm256_castpd256_pd128(ymm0);                    // a*x - b*w
    xmm0 = _mm_add_sd(xmm0, xmm1);                          // det(M)
    _mm_store_sd(&det, xmm0);
    return det;
}
