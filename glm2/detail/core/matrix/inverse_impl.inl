/**
* @file     inverse_impl.inl
* @brief    Deailed implementation of the inverse function.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline void glm2::detail::core::matrix::inverse::_default_fm2x2(const __m64* M_in, __m128* M_out)
{
    __m128 xmm0, xmm1, xmm2;

    // calculate determinant
    xmm0 = _mm_loadu_ps(reinterpret_cast<const float*>(M_in));
    xmm1 = _mm_permute_ps(xmm0, 0x13);
    xmm2 = _mm_mul_ps(xmm0, xmm1);
    xmm1 = _mm_movehl_ps(xmm2, xmm2);
    xmm1 = _mm_sub_ss(xmm2, xmm1);
    xmm1 = _mm_broadcastss_ps(xmm1);

    // calculate adjoint matrix
    xmm0 = _mm_permute_ps(xmm0, 0x27);
    xmm2 = _mm_set_ps(+1.0f, -1.0f, -1.0f, +1.0f);
    xmm0 = _mm_mul_ps(xmm0, xmm2);

    // calculate inverse matrix
    M_out[0] = _mm_div_ps(xmm0, xmm1);
}

inline void glm2::detail::core::matrix::inverse::_default_fm3x3(const __m128* M_in, __m128* M_out)
{
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xmm8;

    // combute 6 base vectors
    xmm0 = _mm_shuffle_ps(M_in[1], M_in[0], 0x00);
    xmm1 = _mm_shuffle_ps(M_in[1], M_in[0], 0x55);
    xmm2 = _mm_shuffle_ps(M_in[1], M_in[0], 0xAA);
    xmm3 = _mm_shuffle_ps(M_in[2], M_in[1], 0x00);  // c, c, b, X
    xmm4 = _mm_shuffle_ps(M_in[2], M_in[1], 0x55);  // f, f, e, X
    xmm5 = _mm_shuffle_ps(M_in[2], M_in[1], 0xAA);  // i, i, h, X
    xmm0 = _mm_permute_ps(xmm0, 0x28);              // b, a, a, X           
    xmm1 = _mm_permute_ps(xmm1, 0x28);              // e, d, d, X
    xmm2 = _mm_permute_ps(xmm2, 0x28);              // h, g, g, X

    // combute adjoint matrix
    xmm6 = _mm_mul_ps(xmm4, xmm2);                  
    xmm7 = _mm_mul_ps(xmm3, xmm2);
    xmm8 = _mm_mul_ps(xmm3, xmm1);
    xmm6 = _mm_fmsub_ps(xmm1, xmm5, xmm6);          // a0, a1, a2, X = b0
    xmm7 = _mm_fmsub_ps(xmm0, xmm5, xmm7);          // a3, a4, a5, X = b1
    xmm8 = _mm_fmsub_ps(xmm0, xmm4, xmm8);          // a6, a7, a8, X = b2

    // combute 1 over determinant
    xmm0 = _mm_shuffle_ps(xmm0, xmm3, 0x01);        // a, b, c, X
    xmm0 = _mm_mul_ps(xmm0, xmm6);                  // a*a0, b*a1, c*a2 = x, y, z, X
    xmm1 = _mm_movehdup_ps(xmm0);                   // y, y, X, X
    xmm0 = _mm_sub_ss(xmm0, xmm1);                  // x-y, y, z, X
    xmm1 = _mm_movehl_ps(xmm0, xmm0);               // z, X, z, X
    xmm0 = _mm_add_ss(xmm0, xmm1);                  // x-y+z, y, z, X = det
    xmm1 = _mm_set_ss(1.0f);
    xmm0 = _mm_div_ps(xmm1, xmm0);                  // 1 / det
    xmm0 = _mm_broadcastss_ps(xmm0);                // 4x(1/det)

    // combute final inverse matrix
    xmm1 = _mm_mul_ps(xmm6, xmm0);
    xmm2 = _mm_mul_ps(xmm7, xmm0);
    xmm0 = _mm_mul_ps(xmm8, xmm0);
    xmm3 = _mm_set_ps(0.0f, +1.0f, -1.0f, +1.0f);
    xmm4 = _mm_set_ps(0.0f, -1.0f, +1.0f, -1.0f);
    M_out[0] = _mm_mul_ps(xmm1, xmm3);
    M_out[1] = _mm_mul_ps(xmm2, xmm4);
    M_out[2] = _mm_mul_ps(xmm0, xmm3);
}

inline void glm2::detail::core::matrix::inverse::_default_fm4x4(const __m128* M_in, __m128* M_out)
{
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xmm8, xmm9, xmm10, xmm11, xmm12, xmm13, xmm14;
    
    // combute transpose
    xmm0 = _mm_unpacklo_ps(M_in[0], M_in[1]);   // a, b, e, f
    xmm1 = _mm_unpacklo_ps(M_in[2], M_in[3]);   // c, d, g, h
    xmm2 = _mm_unpackhi_ps(M_in[0], M_in[1]);   // i, j, m, n
    xmm3 = _mm_unpackhi_ps(M_in[2], M_in[3]);   // k, l, o, p
    xmm4 = _mm_movelh_ps(xmm0, xmm1);           // a, b, c, d
    xmm0 = _mm_movehl_ps(xmm1, xmm0);           // e, f, g, h
    xmm1 = _mm_movelh_ps(xmm2, xmm3);           // i, j, k, l
    xmm2 = _mm_movehl_ps(xmm3, xmm2);           // m, n, o, p

    // combute adjoint matrix
    xmm3 = _mm_permute_ps(xmm4, 0x5A);          // c, c, b, b
    xmm5 = _mm_permute_ps(xmm4, 0xBF);          // d, d, d, c
    xmm6 = _mm_permute_ps(xmm0, 0x5A);          // g, g, f, f
    xmm7 = _mm_permute_ps(xmm0, 0xBF);          // h, h, h, g
    xmm8 = _mm_permute_ps(xmm1, 0x5A);          // k, k, j, j
    xmm9 = _mm_permute_ps(xmm1, 0xBF);          // l, l, l, k
    xmm10 = _mm_permute_ps(xmm2, 0x5A);         // o, o, n, n
    xmm11 = _mm_permute_ps(xmm2, 0xBF);         // p, p, p, o

    xmm12 = _mm_mul_ps(xmm9, xmm10);
    xmm12 = _mm_fmsub_ps(xmm8, xmm11, xmm12);   // b0
    xmm13 = _mm_mul_ps(xmm7, xmm8);
    xmm13 = _mm_fmsub_ps(xmm6, xmm9, xmm13);    // b2
    xmm14 = _mm_mul_ps(xmm5, xmm8);
    xmm14 = _mm_fmsub_ps(xmm3, xmm9, xmm14);    // b4
    xmm8 = _mm_mul_ps(xmm7, xmm10);
    xmm8 = _mm_fmsub_ps(xmm6, xmm11, xmm8);     // b1
    xmm9 = _mm_mul_ps(xmm5, xmm10);
    xmm9 = _mm_fmsub_ps(xmm3, xmm11, xmm9);     // b3
    xmm10 = _mm_mul_ps(xmm5, xmm6);
    xmm3 = _mm_fmsub_ps(xmm3, xmm7, xmm10);     // b5

    // combute one over determinant and final inverse matrix
    xmm4 = _mm_permute_ps(xmm4, 0x01);          // c0
    xmm0 = _mm_permute_ps(xmm0, 0x01);          // c1
    xmm1 = _mm_permute_ps(xmm1, 0x01);          // c2
    xmm2 = _mm_permute_ps(xmm2, 0x01);          // c3

    xmm5 = _mm_mul_ps(xmm1, xmm8);
    xmm5 = _mm_fmsub_ps(xmm0, xmm12, xmm5);
    xmm5 = _mm_fmadd_ps(xmm2, xmm13, xmm5);     // c3*b2 + c1*b0 - c2*b1 = d0
    xmm6 = _mm_mul_ps(xmm1, xmm9);
    xmm6 = _mm_fmsub_ps(xmm4, xmm12, xmm6);
    xmm6 = _mm_fmadd_ps(xmm2, xmm14, xmm6);     // c3*b4 + c0*b0 - c2*b3 = d1
    xmm7 = _mm_mul_ps(xmm0, xmm9);
    xmm7 = _mm_fmsub_ps(xmm4, xmm8, xmm7);
    xmm7 = _mm_fmadd_ps(xmm2, xmm3, xmm7);      // c3*b5 + c0*b1 - c1*b3 = d2
    xmm2 = _mm_mul_ps(xmm0, xmm14);
    xmm2 = _mm_fmsub_ps(xmm4, xmm13, xmm2);
    xmm0 = _mm_fmadd_ps(xmm1, xmm3, xmm2);      // c2*b5 + c0*b2 - c1*b4 = d3

    xmm1 = _mm_set_ps(-1.0f, +1.0f, -1.0f, +1.0f);
    xmm2 = _mm_set_ps(+1.0f, -1.0f, +1.0f, -1.0f);
    xmm3 = _mm_mul_ps(xmm5, xmm1);      // I0
    xmm4 = _mm_mul_ps(xmm7, xmm1);      // I2
    xmm1 = _mm_mul_ps(xmm6, xmm2);      // I1
    xmm0 = _mm_mul_ps(xmm0, xmm2);      // I3

    xmm2 = _mm_unpacklo_ps(xmm3, xmm1); // Ia, Ib, X, X
    xmm5 = _mm_unpacklo_ps(xmm4, xmm0); // Ic, Id, X, X
    xmm2 = _mm_movelh_ps(xmm2, xmm5);   // Ia, Ib, Ic, Id
    xmm2 = _mm_mul_ps(xmm2, M_in[0]);   // f

    xmm5 = _mm_movehdup_ps(xmm2);
    xmm2 = _mm_add_ps(xmm2, xmm5);
    xmm5 = _mm_unpackhi_ps(xmm2, xmm2);
    xmm2 = _mm_add_ss(xmm2, xmm5);      // h = fx + fy + fz + fw

    xmm5 = _mm_set_ss(1.0f);
    xmm2 = _mm_div_ss(xmm5, xmm2);      // 1 / h
    xmm2 = _mm_broadcastss_ps(xmm2);    // 4x (1/h)

    M_out[0] = _mm_mul_ps(xmm3, xmm2);
    M_out[1] = _mm_mul_ps(xmm1, xmm2);
    M_out[2] = _mm_mul_ps(xmm4, xmm2);
    M_out[3] = _mm_mul_ps(xmm0, xmm2);
}

inline void glm2::detail::core::matrix::inverse::_default_dm2x2(const __m128d* M_in, __m256d* M_out)
{    
    __m128d xmm0, xmm1;
    __m256d ymm0, ymm1, ymm2;

    // calculate one over determinant
    xmm0 = _mm_set_sd(M_in[1][0]);
    xmm1 = _mm_set_sd(M_in[0][0]);
    xmm0 = _mm_mul_sd(xmm0, _mm_set_sd(M_in[0][1]));
    xmm0 = _mm_fmsub_sd(xmm1, _mm_set_sd(M_in[1][1]), xmm0);
    xmm1 = _mm_set_sd(1.0);
    xmm0 = _mm_div_sd(xmm1, xmm0);
    ymm0 = _mm256_broadcastsd_pd(xmm0);

    // calculate adjoint matrix
    ymm1 = _mm256_loadu_pd(reinterpret_cast<const double*>(M_in));
    ymm1 = _mm256_permute4x64_pd(ymm1, 0x27);
    ymm2 = _mm256_set_pd(+1.0, -1.0, -1.0, +1.0);
    ymm1 = _mm256_mul_pd(ymm1, ymm2);

    // calculate inverse matrix
    M_out[0] = _mm256_mul_pd(ymm0, ymm1);
}

inline void glm2::detail::core::matrix::inverse::_default_dm3x3(const __m256d* M_in, __m256d* M_out)
{
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7, ymm8;
    __m128d xmm3, xmm4;

    // combute 6 base vectors
    ymm0 = _mm256_unpacklo_pd(M_in[0], M_in[1]);        // a, b, g, h
    ymm1 = _mm256_unpackhi_pd(M_in[0], M_in[1]);        // d, e, X, X
    ymm2 = _mm256_unpacklo_pd(M_in[2], M_in[1]);        // c, b, i, h
    ymm3 = _mm256_unpackhi_pd(M_in[1], M_in[2]);        // e, f, X, X
    ymm4 = _mm256_permute2f128_pd(ymm0, ymm2, 0x20);    // a, b, c, b
    ymm5 = _mm256_permute4x64_pd(ymm0, 0x01);           // b, a, a, a
    ymm0 = _mm256_permute4x64_pd(ymm0, 0xAB);           // h, g, g, g
    ymm1 = _mm256_permute4x64_pd(ymm1, 0x01);           // e, d, d, d
    ymm6 = _mm256_permute4x64_pd(ymm2, 0x50);           // c, c, b, b
    ymm2 = _mm256_permute4x64_pd(ymm2, 0xFA);           // i, i, h, h
    ymm3 = _mm256_permute4x64_pd(ymm3, 0x05);           // f, f, e, e

    // combute adjoint matrix
    ymm7 = _mm256_mul_pd(ymm3, ymm0);
    ymm0 = _mm256_mul_pd(ymm6, ymm0);
    ymm6 = _mm256_mul_pd(ymm6, ymm1);
    ymm1 = _mm256_fmsub_pd(ymm1, ymm2, ymm7);           // a0, a1, a2, X = b0
    ymm0 = _mm256_fmsub_pd(ymm5, ymm2, ymm0);           // a3, a4, a5, X = b1
    ymm2 = _mm256_fmsub_pd(ymm5, ymm3, ymm6);           // a6, a7, a8, X = b2

    // combute 1 over determinant
    ymm3 = _mm256_mul_pd(ymm4, ymm1);           // a*a0, b*a1, c*a2 = x, y, z, w
    ymm4 = _mm256_unpackhi_pd(ymm3, ymm3);      // y, y, w, w
    ymm4 = _mm256_sub_pd(ymm3, ymm4);           // x-y, y-y, z-w, w-w
    xmm3 = _mm256_extractf128_pd(ymm3, 0x01);   // z, w, 0, 0
    xmm4 = _mm256_castpd256_pd128(ymm4);        // x-y, y-y
    xmm3 = _mm_add_sd(xmm4, xmm3);              // x-y+z = det
    xmm4 = _mm_set_sd(1.0);
    xmm3 = _mm_div_sd(xmm4, xmm3);              // 1 / det
    ymm3 = _mm256_broadcastsd_pd(xmm3);         // 4x (1 / det)

    // combute final inverse matrix
    ymm1 = _mm256_mul_pd(ymm1, ymm3);
    ymm0 = _mm256_mul_pd(ymm0, ymm3);
    ymm2 = _mm256_mul_pd(ymm2, ymm3);
    ymm3 = _mm256_set_pd(0.0, +1.0, -1.0, +1.0);
    ymm4 = _mm256_set_pd(0.0, -1.0, +1.0, -1.0);
    M_out[0] = _mm256_mul_pd(ymm1, ymm3);
    M_out[1] = _mm256_mul_pd(ymm0, ymm4);
    M_out[2] = _mm256_mul_pd(ymm2, ymm3);
}

inline void glm2::detail::core::matrix::inverse::_default_dm4x4(const __m256d* M_in, __m256d* M_out)
{
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7, ymm8, ymm9, ymm10, ymm11, ymm12, ymm13, ymm14, ymm15;
    __m128d xmm2, xmm3;
    ymm0 = _mm256_unpacklo_pd(M_in[0], M_in[1]);
    ymm1 = _mm256_unpackhi_pd(M_in[0], M_in[1]);
    ymm2 = _mm256_unpacklo_pd(M_in[2], M_in[3]);
    ymm3 = _mm256_unpackhi_pd(M_in[2], M_in[3]);
    ymm4 = _mm256_permute2f128_pd(ymm0, ymm2, 0x20);    // a, b, c, d
    ymm0 = _mm256_permute2f128_pd(ymm0, ymm2, 0x31);    // i, j, k, l   ymm1
    ymm2 = _mm256_permute2f128_pd(ymm1, ymm3, 0x20);    // e, f, g, h   ymm0
    ymm1 = _mm256_permute2f128_pd(ymm1, ymm3, 0x31);    // m, n, o, p   ymm2
    ymm3 = M_in[0];                                     // a, e, i, m

    // combute adjoint matrix
    ymm5 = _mm256_permute4x64_pd(ymm4, 0x5A);           // c, c, b, b
    ymm6 = _mm256_permute4x64_pd(ymm4, 0xBF);           // d, d, d, c
    ymm7 = _mm256_permute4x64_pd(ymm2, 0x5A);           // g, g, f, f
    ymm8 = _mm256_permute4x64_pd(ymm2, 0xBF);           // h, h, h, g
    ymm9 = _mm256_permute4x64_pd(ymm0, 0x5A);           // k, k, j, j
    ymm10 = _mm256_permute4x64_pd(ymm0, 0xBF);          // l, l, l, k
    ymm11 = _mm256_permute4x64_pd(ymm1, 0x5A);          // o, o, n, n
    ymm12 = _mm256_permute4x64_pd(ymm1, 0xBF);          // p, p, p, o

    ymm13 = _mm256_mul_pd(ymm10, ymm11);
    ymm13 = _mm256_fmsub_pd(ymm9, ymm12, ymm13);        // b0
    ymm14 = _mm256_mul_pd(ymm8, ymm9);
    ymm14 = _mm256_fmsub_pd(ymm7, ymm10, ymm14);        // b2
    ymm15 = _mm256_mul_pd(ymm6, ymm9);
    ymm15 = _mm256_fmsub_pd(ymm5, ymm10, ymm15);        // b4
    ymm9 = _mm256_mul_pd(ymm8, ymm11);
    ymm9 = _mm256_fmsub_pd(ymm7, ymm12, ymm9);          // b1
    ymm10 = _mm256_mul_pd(ymm6, ymm11);
    ymm10 = _mm256_fmsub_pd(ymm5, ymm12, ymm10);        // b3
    ymm11 = _mm256_mul_pd(ymm6, ymm7);
    ymm5 = _mm256_fmsub_pd(ymm5, ymm8, ymm11);          // b5

    // combute one over determinant and final inverse matrix
    ymm4 = _mm256_permute4x64_pd(ymm4, 0x01);           // c0
    ymm2 = _mm256_permute4x64_pd(ymm2, 0x01);           // c1
    ymm0 = _mm256_permute4x64_pd(ymm0, 0x01);           // c2
    ymm1 = _mm256_permute4x64_pd(ymm1, 0x01);           // c3

    ymm6 = _mm256_mul_pd(ymm0, ymm9);
    ymm6 = _mm256_fmsub_pd(ymm2, ymm13, ymm6);
    ymm6 = _mm256_fmadd_pd(ymm1, ymm14, ymm6);          // c3*b2 + c1*b0 - c2*b1 = d0
    ymm7 = _mm256_mul_pd(ymm0, ymm10);
    ymm7 = _mm256_fmsub_pd(ymm4, ymm13, ymm7);
    ymm7 = _mm256_fmadd_pd(ymm1, ymm15, ymm7);          // c3*b4 + c0*b0 - c2*b3 = d1
    ymm8 = _mm256_mul_pd(ymm2, ymm10);
    ymm8 = _mm256_fmsub_pd(ymm4, ymm9, ymm8);
    ymm8 = _mm256_fmadd_pd(ymm1, ymm5, ymm8);           // c3*b5 + c0*b1 - c1*b3 = d2
    ymm2 = _mm256_mul_pd(ymm2, ymm15);
    ymm2 = _mm256_fmsub_pd(ymm4, ymm14, ymm2);
    ymm0 = _mm256_fmadd_pd(ymm0, ymm5, ymm2);           // c2*b5 + c0*b2 - c1*b4 = d3

    ymm1 = _mm256_set_pd(-1.0, +1.0, -1.0, +1.0);
    ymm2 = _mm256_set_pd(+1.0, -1.0, +1.0, -1.0);
    ymm4 = _mm256_mul_pd(ymm6, ymm1);                   // I0
    ymm5 = _mm256_mul_pd(ymm8, ymm1);                   // I2
    ymm1 = _mm256_mul_pd(ymm7, ymm2);                   // I1
    ymm0 = _mm256_mul_pd(ymm0, ymm2);                   // I3

    ymm2 = _mm256_unpacklo_pd(ymm4, ymm1);                                  // Ia, Ib, X, X
    ymm6 = _mm256_unpacklo_pd(ymm5, ymm0);                                  // Ic, Id, X, X
    ymm2 = _mm256_insertf128_pd(ymm2, _mm256_castpd256_pd128(ymm6), 0x01);  // Ia, Ib, Ic, Id
    ymm2 = _mm256_mul_pd(ymm2, ymm3);                                       // fx, fy, fz, fw
    
    ymm3 = _mm256_unpackhi_pd(ymm2, ymm2);                                  // fy, fy, fw, fw
    ymm2 = _mm256_add_pd(ymm2, ymm3);                                       // fx+fy, X, fz+fw, X
    xmm3 = _mm256_extractf128_pd(ymm2, 0x01);                               // fz+fw, X
    xmm2 = _mm256_castpd256_pd128(ymm2);                                    // fx+fy, X
    xmm2 = _mm_add_sd(xmm2, xmm3);                                          // det(M), X
    xmm3 = _mm_set_sd(1.0);
    xmm2 = _mm_div_sd(xmm3, xmm2);                                          // 1 / det(M)
    ymm2 = _mm256_broadcastsd_pd(xmm2);                                     // 4x (1 / det(M))

    M_out[0] = _mm256_mul_pd(ymm4, ymm2);
    M_out[1] = _mm256_mul_pd(ymm1, ymm2);
    M_out[2] = _mm256_mul_pd(ymm5, ymm2);
    M_out[3] = _mm256_mul_pd(ymm0, ymm2);
}
