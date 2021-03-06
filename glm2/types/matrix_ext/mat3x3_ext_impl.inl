/**
* @file     mat3x3_impl.inl
* @brief    Implamentation of convert operators, extended mathematical operators 
            and extended constructors of a 3x3 float matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<3, 3, float>::col_type glm2::mat<3, 3, float>::operator* (const row_type& v) const
{
    __m128 xmm0, xmm1, xmm2;
    xmm0 = _mm_broadcast_ss(row_type::value_ptr(v) + 0);
    xmm1 = _mm_broadcast_ss(row_type::value_ptr(v) + 1);
    xmm2 = _mm_broadcast_ss(row_type::value_ptr(v) + 2);
    xmm0 = _mm_mul_ps(xmm0, this->_M[0].intrin());
    xmm0 = _mm_fmadd_ps(xmm1, this->_M[1].intrin(), xmm0);
    xmm0 = _mm_fmadd_ps(xmm2, this->_M[2].intrin(), xmm0);
    return col_type(xmm0);
}
inline glm2::mat<3, 3, float>::col_type glm2::mat<3, 3, float>::operator/ (const row_type& v) const
{
    mat I;
    detail::core::matrix::inverse::_default_fm3x3(col_type::intrin_ptr(this->_M), col_type::intrin_ptr(I._M));
    return (I * v);
}

inline glm2::mat<2, 3, float> glm2::mat<3, 3, float>::operator* (const mat<2, 3, float>& M) const
{
    mat<2, 3, float> res;
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = _mm256_loadu_ps(mat<2, 3, float>::value_ptr(M));         
    ymm1 = _mm256_permute_ps(ymm0, 0x00);                           
    ymm2 = _mm256_permute_ps(ymm0, 0x55);                           
    ymm0 = _mm256_permute_ps(ymm0, 0xAA);                           
    ymm3 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 0); 
    ymm4 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 1); 
    ymm5 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 2); 
    ymm0 = _mm256_mul_ps(ymm5, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm4, ymm2, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm3, ymm1, ymm0);
    _mm256_storeu_ps(mat<2, 3, float>::value_ptr(res), ymm0);
    return res;
}
inline glm2::mat<4, 3, float> glm2::mat<3, 3, float>::operator* (const mat<4, 3, float>& M) const
{
    mat<4, 3, float> res;
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = _mm256_loadu_ps(mat<4, 3, float>::value_ptr(M) + 0);
    ymm1 = _mm256_permute_ps(ymm0, 0x00);
    ymm2 = _mm256_permute_ps(ymm0, 0x55);
    ymm0 = _mm256_permute_ps(ymm0, 0xAA);
    ymm3 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 0);
    ymm4 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 1);
    ymm5 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 2);
    ymm0 = _mm256_mul_ps(ymm5, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm4, ymm2, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm3, ymm1, ymm0);
    _mm256_storeu_ps(mat<4, 3, float>::value_ptr(res) + 0, ymm0);
    ymm0 = _mm256_loadu_ps(mat<4, 3, float>::value_ptr(M) + 8);
    ymm1 = _mm256_permute_ps(ymm0, 0x00);
    ymm2 = _mm256_permute_ps(ymm0, 0x55);
    ymm0 = _mm256_permute_ps(ymm0, 0xAA);
    ymm0 = _mm256_mul_ps(ymm5, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm4, ymm2, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm3, ymm1, ymm0);
    _mm256_storeu_ps(mat<4, 3, float>::value_ptr(res) + 8, ymm0);
    return res;
}
inline glm2::mat<3, 3, float> glm2::mat<3, 3, float>::operator* (const mat& M) const
{
    mat _M = *this;
    _M *= M;
    return _M;
}
inline glm2::mat<3, 3, float> glm2::mat<3, 3, float>::operator/ (const mat& M) const
{
    mat _M = *this;
    _M /= M;
    return _M;
}

inline glm2::mat<3, 3, float>& glm2::mat<3, 3, float>::operator*= (const mat& M)
{
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5;
    ymm0 = _mm256_loadu_ps(col_type::value_ptr(M._M));
    ymm1 = _mm256_permute_ps(ymm0, 0x00);
    ymm2 = _mm256_permute_ps(ymm0, 0x55);
    ymm0 = _mm256_permute_ps(ymm0, 0xAA);
    ymm3 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 0);
    ymm4 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 1);
    ymm5 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 2);
    ymm0 = _mm256_mul_ps(ymm5, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm4, ymm2, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm3, ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M), ymm0);
    xmm0 = _mm_broadcast_ss(mat::value_ptr(M) + 8);
    xmm1 = _mm_broadcast_ss(mat::value_ptr(M) + 9);
    xmm2 = _mm_broadcast_ss(mat::value_ptr(M) + 10);
    xmm3 = _mm256_castps256_ps128(ymm3);
    xmm4 = _mm256_castps256_ps128(ymm4);
    xmm5 = _mm256_castps256_ps128(ymm5);
    xmm0 = _mm_mul_ps(xmm3, xmm0);
    xmm0 = _mm_fmadd_ps(xmm4, xmm1, xmm0);
    xmm0 = _mm_fmadd_ps(xmm5, xmm2, xmm0);
    this->_M[2] = xmm0;
    return *this;
}
inline glm2::mat<3, 3, float>& glm2::mat<3, 3, float>::operator/= (const mat& M)
{
    mat I;
    detail::core::matrix::inverse::_default_fm3x3(col_type::intrin_ptr(M._M), col_type::intrin_ptr(I._M));
    return (*this *= I);
}

inline glm2::mat<3, 3, float>::operator glm2::mat<2, 2, float>(void) const
{
    mat<2, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<2, 3, float>(void) const
{
    mat<2, 3, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<2, 4, float>(void) const
{
    mat<2, 4, float> res;
    res[0] = this->_M[0].intrin();
    res[1] = this->_M[1].intrin();
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<3, 2, float>(void) const
{
    mat<3, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    res[2] = (vec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<3, 4, float>(void) const
{
    mat<3, 4, float> res;
    res[0] = this->_M[0].intrin();
    res[1] = this->_M[1].intrin();
    res[2] = this->_M[2].intrin();
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<4, 2, float>(void) const
{
    mat<4, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    res[2] = (vec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<4, 3, float>(void) const
{
    mat<4, 3, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    res[2] = this->_M[2];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<4, 4, float>(void) const
{
    mat<4, 4, float> res;
    res[0] = this->_M[0].intrin();
    res[1] = this->_M[1].intrin();
    res[2] = this->_M[2].intrin();
    return res;
}

inline glm2::mat<3, 3, float>::operator glm2::mat<2, 2, double>(void) const
{
    mat<2, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<2, 3, double>(void) const
{
    mat<2, 3, double> res;
    res[0] = (dvec3)this->_M[0];
    res[1] = (dvec3)this->_M[1];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<2, 4, double>(void) const
{
    mat<2, 4, double> res;
    res[0] = _mm256_cvtps_pd(this->_M[0].intrin());
    res[1] = _mm256_cvtps_pd(this->_M[1].intrin());
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<3, 2, double>(void) const
{
    mat<3, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<3, 3, double>(void) const
{
    mat<3, 3, double> res;
    res[0] = (dvec3)this->_M[0];
    res[1] = (dvec3)this->_M[1];
    res[2] = (dvec3)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<3, 4, double>(void) const
{
    mat<3, 4, double> res;
    res[0] = _mm256_cvtps_pd(this->_M[0].intrin());
    res[1] = _mm256_cvtps_pd(this->_M[1].intrin());
    res[2] = _mm256_cvtps_pd(this->_M[2].intrin());
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<4, 2, double>(void) const
{
    mat<4, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<4, 3, double>(void) const
{
    mat<4, 3, double> res;
    res[0] = (dvec3)this->_M[0];
    res[1] = (dvec3)this->_M[1];
    res[2] = (dvec3)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, float>::operator glm2::mat<4, 4, double>(void) const
{
    mat<4, 4, double> res;
    res[0] = _mm256_cvtps_pd(this->_M[0].intrin());
    res[1] = _mm256_cvtps_pd(this->_M[1].intrin());
    res[2] = _mm256_cvtps_pd(this->_M[2].intrin());
    return res;
}
