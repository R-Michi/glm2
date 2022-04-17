/**
* @file     dmat3x2_impl.inl
* @brief    Implamentation of convert operators, extended mathematical operators 
            and extended constructors of a 3x2 double matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<3, 2, double>::col_type glm2::mat<3, 2, double>::operator* (const row_type& v) const
{
    __m256d ymm0;
    __m128d xmm0, xmm1, xmm2;
    ymm0 = v();
    xmm1 = _mm256_extractf128_pd(ymm0, 0x1);
    xmm0 = _mm256_castpd256_pd128(ymm0);
    xmm1 = _mm_permute_pd(xmm1, 0x00);
    xmm2 = _mm_permute_pd(xmm0, 0x00);
    xmm0 = _mm_permute_pd(xmm0, 0x03);
    xmm0 = _mm_mul_pd(xmm0, this->_M[1]());
    xmm0 = _mm_fmadd_pd(xmm1, this->_M[2](), xmm0);
    xmm0 = _mm_fmadd_pd(xmm2, this->_M[0](), xmm0);
    return col_type(xmm0);
}

inline glm2::mat<2, 2, double> glm2::mat<3, 2, double>::operator* (const mat<2, 3, double>& M) const
{
    mat<2, 2, double> res;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = M[0]();
    ymm1 = M[1]();
    ymm2 = _mm256_unpacklo_pd(ymm0, ymm1);
    ymm0 = _mm256_unpackhi_pd(ymm0, ymm1);
    ymm1 = _mm256_permute4x64_pd(ymm2, 0x50);
    ymm2 = _mm256_permute4x64_pd(ymm2, 0xFA);
    ymm0 = _mm256_permute4x64_pd(ymm0, 0x50);
    ymm3 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 0);
    ymm4 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 1);
    ymm5 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 2);
    ymm0 = _mm256_mul_pd(ymm0, ymm4);
    ymm0 = _mm256_fmadd_pd(ymm1, ymm3, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm2, ymm5, ymm0);
    _mm256_storeu_pd(mat<2, 2, double>::value_ptr(res), ymm0);
    return res;
}
inline glm2::mat<3, 2, double> glm2::mat<3, 2, double>::operator* (const mat<3, 3, double>& M) const
{
    mat _M = *this;
    _M *= M;
    return _M;
}
inline glm2::mat<4, 2, double> glm2::mat<3, 2, double>::operator* (const mat<4, 3, double>& M) const
{
    mat<4, 2, double> res;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 0);
    ymm1 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 1);
    ymm2 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 2);
    ymm3 = M[0]();
    ymm4 = M[1]();
    ymm5 = _mm256_unpacklo_pd(ymm3, ymm4);
    ymm3 = _mm256_unpackhi_pd(ymm3, ymm4);
    ymm4 = _mm256_permute4x64_pd(ymm5, 0x50);
    ymm5 = _mm256_permute4x64_pd(ymm5, 0xFA);
    ymm3 = _mm256_permute4x64_pd(ymm3, 0x50);
    ymm3 = _mm256_mul_pd(ymm3, ymm1);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm2, ymm3);
    ymm3 = _mm256_fmadd_pd(ymm4, ymm0, ymm3);
    _mm256_storeu_pd(mat<4, 2, double>::value_ptr(res) + 0, ymm3);
    ymm3 = M[2]();
    ymm4 = M[3]();
    ymm5 = _mm256_unpacklo_pd(ymm3, ymm4);
    ymm3 = _mm256_unpackhi_pd(ymm3, ymm4);
    ymm4 = _mm256_permute4x64_pd(ymm5, 0x50);
    ymm5 = _mm256_permute4x64_pd(ymm5, 0xFA);
    ymm3 = _mm256_permute4x64_pd(ymm3, 0x50);
    ymm3 = _mm256_mul_pd(ymm3, ymm1);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm2, ymm3);
    ymm0 = _mm256_fmadd_pd(ymm4, ymm0, ymm3);
    _mm256_storeu_pd(mat<4, 2, double>::value_ptr(res) + 4, ymm0);
    return res;
}

inline glm2::mat<3, 2, double>& glm2::mat<3, 2, double>::operator*= (const mat<3, 3, double>& M)
{
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    __m128d xmm0, xmm1, xmm2, xmm3, xmm4, xmm5;
    ymm0 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 0);
    ymm1 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 1);
    ymm2 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 2);
    ymm3 = M[0]();
    ymm4 = M[1]();
    ymm5 = _mm256_unpacklo_pd(ymm3, ymm4);
    ymm3 = _mm256_unpackhi_pd(ymm3, ymm4);
    ymm4 = _mm256_permute4x64_pd(ymm5, 0x50);
    ymm5 = _mm256_permute4x64_pd(ymm5, 0xFA);
    ymm3 = _mm256_permute4x64_pd(ymm3, 0x50);
    ymm3 = _mm256_mul_pd(ymm3, ymm1);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm2, ymm3);
    ymm3 = _mm256_fmadd_pd(ymm4, ymm0, ymm3);
    _mm256_storeu_pd(col_type::value_ptr(this->_M), ymm3);
    xmm0 = _mm256_castpd256_pd128(ymm0);
    xmm1 = _mm256_castpd256_pd128(ymm1);
    xmm2 = _mm256_castpd256_pd128(ymm2);
    ymm3 = M[2]();
    xmm4 = _mm256_extractf128_pd(ymm3, 0x01);
    xmm3 = _mm256_castpd256_pd128(ymm3);
    xmm5 = _mm_permute_pd(xmm3, 0x00);
    xmm3 = _mm_permute_pd(xmm3, 0x03);
    xmm4 = _mm_permute_pd(xmm4, 0x00);
    xmm0 = _mm_mul_pd(xmm5, xmm0);
    xmm0 = _mm_fmadd_pd(xmm3, xmm1, xmm0);
    xmm0 = _mm_fmadd_pd(xmm4, xmm2, xmm0);
    this->_M[2] = xmm0;
    return *this;
}

inline glm2::mat<3, 2, double>::operator glm2::mat<2, 2, float>(void) const
{
    mat<2, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<2, 3, float>(void) const
{
    mat<2, 3, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0]());
    res[1] = _mm_cvtpd_ps(this->_M[1]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<2, 4, float>(void) const
{
    mat<2, 4, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0]());
    res[1] = _mm_cvtpd_ps(this->_M[1]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<3, 2, float>(void) const
{
    mat<3, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    res[2] = (vec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<3, 3, float>(void) const
{
    mat<3, 3, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0]());
    res[1] = _mm_cvtpd_ps(this->_M[1]());
    res[2] = _mm_cvtpd_ps(this->_M[2]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<3, 4, float>(void) const
{
    mat<3, 4, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0]());
    res[1] = _mm_cvtpd_ps(this->_M[1]());
    res[2] = _mm_cvtpd_ps(this->_M[2]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<4, 2, float>(void) const
{
    mat<4, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    res[2] = (vec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<4, 3, float>(void) const
{
    mat<4, 3, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0]());
    res[1] = _mm_cvtpd_ps(this->_M[1]());
    res[2] = _mm_cvtpd_ps(this->_M[2]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<4, 4, float>(void) const
{
    mat<4, 4, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0]());
    res[1] = _mm_cvtpd_ps(this->_M[1]());
    res[2] = _mm_cvtpd_ps(this->_M[2]());
    return res;
}

inline glm2::mat<3, 2, double>::operator glm2::mat<2, 2, double>(void) const
{
    mat<2, 2, double> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<2, 3, double>(void) const
{
    mat<2, 3, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0]());
    res[1] = _mm256_castpd128_pd256(this->_M[1]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<2, 4, double>(void) const
{
    mat<2, 4, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0]());
    res[1] = _mm256_castpd128_pd256(this->_M[1]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<3, 3, double>(void) const
{
    mat<3, 3, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0]());
    res[1] = _mm256_castpd128_pd256(this->_M[1]());
    res[2] = _mm256_castpd128_pd256(this->_M[2]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<3, 4, double>(void) const
{   
    mat<3, 4, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0]());
    res[1] = _mm256_castpd128_pd256(this->_M[1]());
    res[2] = _mm256_castpd128_pd256(this->_M[2]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<4, 2, double>(void) const
{
    mat<4, 2, double> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    res[2] = this->_M[2];
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<4, 3, double>(void) const
{
    mat<4, 3, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0]());
    res[1] = _mm256_castpd128_pd256(this->_M[1]());
    res[2] = _mm256_castpd128_pd256(this->_M[2]());
    return res;
}
inline glm2::mat<3, 2, double>::operator glm2::mat<4, 4, double>(void) const
{
    mat<4, 4, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0]());
    res[1] = _mm256_castpd128_pd256(this->_M[1]());
    res[2] = _mm256_castpd128_pd256(this->_M[2]());
    return res;
}
