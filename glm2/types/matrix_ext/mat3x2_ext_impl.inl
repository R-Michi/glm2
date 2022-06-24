/**
* @file     mat3x2_impl.inl
* @brief    Implamentation of convert operators, extended mathematical operators 
            and extended constructors of a 3x2 float matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<3, 2, float>::col_type glm2::mat<3, 2, float>::operator* (const row_type& v) const
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = v.intrin();                                             // x, y, z, X
    xmm1 = _mm_loadu_ps(col_type::value_ptr(this->_M));     // a, d, b, e,
    xmm2 = this->_M[2].intrinEXT();                             // c, f, X, X
    xmm3 = _mm_permute_ps(xmm0, 0x50);                      // x, x, y, y
    xmm0 = _mm_permute_ps(xmm0, 0xFA);                      // z, z, X, X
    xmm1 = _mm_mul_ps(xmm1, xmm3);
    xmm3 = _mm_permute_ps(xmm1, 0x0E);
    xmm1 = _mm_add_ps(xmm1, xmm3);
    xmm0 = _mm_fmadd_ps(xmm0, xmm2, xmm1);
    return col_type(xmm0);
}

inline glm2::mat<2, 2, float> glm2::mat<3, 2, float>::operator* (const mat<2, 3, float>& M) const
{
    mat<2, 2, float> res;
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5;
    xmm0 = M[0].intrin();                                          // g, i, k, X
    xmm1 = M[1].intrin();                                          // h, j, l, X
    xmm2 = _mm_loadu_ps(col_type::value_ptr(this->_M));     // a, d, b, e
    xmm3 = this->_M[2].intrinEXT();                             // c, f, X, X
    xmm4 = _mm_shuffle_ps(xmm0, xmm1, 0x00);                // g, g, h, h
    xmm5 = _mm_shuffle_ps(xmm0, xmm1, 0x55);                // i, i, j, j
    xmm0 = _mm_shuffle_ps(xmm0, xmm1, 0xAA);                // k, k, l, l
    xmm1 = _mm_movelh_ps(xmm2, xmm2);                       // a, d, a, d
    xmm2 = _mm_movehl_ps(xmm2, xmm2);                       // b, e, b, e
    xmm3 = _mm_movelh_ps(xmm3, xmm3);                       // c, f, c, f
    xmm0 = _mm_mul_ps(xmm0, xmm3);
    xmm0 = _mm_fmadd_ps(xmm5, xmm2, xmm0);
    xmm0 = _mm_fmadd_ps(xmm4, xmm1, xmm0);
    _mm_storeu_ps(mat<2, 2, float>::value_ptr(res), xmm0);
    return res;
}
inline glm2::mat<3, 2, float> glm2::mat<3, 2, float>::operator* (const mat<3, 3, float>& M) const
{
    mat _M = *this;
    _M *= M;
    return _M;
}
inline glm2::mat<4, 2, float> glm2::mat<3, 2, float>::operator* (const mat<4, 3, float>& M) const
{
    mat<4, 2, float> res;
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = _mm256_loadu_ps(mat<4, 3, float>::value_ptr(M) + 0);                 // g, k, o, X, h, l, p, X
    ymm1 = _mm256_loadu_ps(mat<4, 3, float>::value_ptr(M) + 8);                 // i, m, q, X, j, n, r, X
    ymm2 = _mm256_castps128_ps256(_mm_loadu_ps(col_type::value_ptr(this->_M))); // a, d, b, e, X, X, X, X
    ymm3 = _mm256_castps128_ps256(this->_M[2].intrinEXT());                         // c, f, X, X, X, X, X, X
    ymm4 = _mm256_permute2f128_ps(ymm0, ymm1, 0x20);                            // g, k, o, X, i, m, q, X
    ymm0 = _mm256_permute2f128_ps(ymm0, ymm1, 0x31);                            // h, l, p, X, j, n, r, X
    ymm1 = _mm256_shuffle_ps(ymm4, ymm0, 0x00);                                 // g, g, h, h, i, i, j, j
    ymm5 = _mm256_shuffle_ps(ymm4, ymm0, 0x55);                                 // k, k, l, l, m, m, n, n
    ymm0 = _mm256_shuffle_ps(ymm4, ymm0, 0xAA);                                 // o, o, q, q, p, p, r, r
    ymm4 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(1,0,1,0, 1,0,1,0));  // a, d, a, d, a, d, a, d
    ymm2 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(3,2,3,2, 3,2,3,2));  // b, e, b, e, b, e, b, e
    ymm3 = _mm256_permutevar8x32_ps(ymm3, _mm256_set_epi32(1,0,1,0, 1,0,1,0));  // c, f, c, f, c, f, c, f
    ymm0 = _mm256_mul_ps(ymm0, ymm3);
    ymm0 = _mm256_fmadd_ps(ymm5, ymm2, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm1, ymm4, ymm0);
    _mm256_storeu_ps(mat<4, 2, float>::value_ptr(res), ymm0);
    return res;
}   

inline glm2::mat<3, 2, float>& glm2::mat<3, 2, float>::operator*= (const mat<3, 3, float>& M)
{
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    __m128 xmm0, xmm1;
    ymm0 = _mm256_loadu_ps(mat<3, 3, float>::value_ptr(M));                     // g, j, m, X, h, k, n, X
    ymm1 = _mm256_castps128_ps256(M[2].intrin());                                      // i, l, o, X, X, X, X, X
    ymm2 = _mm256_castps128_ps256(_mm_loadu_ps(col_type::value_ptr(this->_M))); // a, d, b, e, X, X, X, X
    ymm3 = _mm256_castps128_ps256(this->_M[2].intrinEXT());                         // c, f, X, X, X, X, X, X
    ymm4 = _mm256_permute2f128_ps(ymm0, ymm1, 0x20);                            // g, j, m, X, i, l, o, X
    ymm0 = _mm256_permute2f128_ps(ymm0, ymm1, 0x31);                            // h, k, n, X, X, X, X, X
    ymm1 = _mm256_shuffle_ps(ymm4, ymm0, 0x00);                                 // g, g, h, h, i, i, X, X
    ymm5 = _mm256_shuffle_ps(ymm4, ymm0, 0x55);                                 // j, j, k, k, l, l, X, X
    ymm0 = _mm256_shuffle_ps(ymm4, ymm0, 0xAA);                                 // m, m, n, n, o, o, X, X
    ymm4 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(1,0,1,0, 1,0,1,0));  // a, d, a, d, a, d, a, d
    ymm2 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(3,2,3,2, 3,2,3,2));  // b, e, b, e, b, e, b, e
    ymm3 = _mm256_permutevar8x32_ps(ymm3, _mm256_set_epi32(1,0,1,0, 1,0,1,0));  // c, f, c, f, c, f, c, f
    ymm0 = _mm256_mul_ps(ymm0, ymm3);
    ymm0 = _mm256_fmadd_ps(ymm5, ymm2, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm1, ymm4, ymm0);
    xmm1 = _mm256_extractf128_ps(ymm0, 0x1);
    xmm0 = _mm256_castps256_ps128(ymm0);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    this->_M[2] = xmm1;
    return *this;
}

inline glm2::mat<3, 2, float>::operator glm2::mat<2, 2, float>(void) const
{
    mat<2, 2, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<2, 3, float>(void) const
{
    mat<2, 3, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<2, 4, float>(void) const
{
    mat<2, 4, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<3, 3, float>(void) const
{
    mat<3, 3, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    res[2] = this->_M[2].intrinEXT();
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<3, 4, float>(void) const
{
    mat<3, 4, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    res[2] = this->_M[2].intrinEXT();
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<4, 2, float>(void) const
{
    mat<4, 2, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    res[2] = this->_M[2];
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<4, 3, float>(void) const
{
    mat<4, 3, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    res[2] = this->_M[2].intrinEXT();
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<4, 4, float>(void) const
{
    mat<4, 4, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    res[2] = this->_M[2].intrinEXT();
    return res;
}

inline glm2::mat<3, 2, float>::operator glm2::mat<2, 2, double>(void) const
{
    mat<2, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<2, 3, double>(void) const
{
    mat<2, 3, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<2, 4, double>(void) const
{
    mat<2, 4, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<3, 2, double>(void) const
{
    mat<3, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<3, 3, double>(void) const
{
    mat<3, 3, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    res[2] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[2].intrinEXT())); 
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<3, 4, double>(void) const
{
    mat<3, 4, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    res[2] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[2].intrinEXT())); 
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<4, 2, double>(void) const
{
    mat<4, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<4, 3, double>(void) const
{
    mat<4, 3, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    res[2] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[2].intrinEXT())); 
    return res;
}
inline glm2::mat<3, 2, float>::operator glm2::mat<4, 4, double>(void) const
{
    mat<4, 4, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    res[2] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[2].intrinEXT())); 
    return res;
}
