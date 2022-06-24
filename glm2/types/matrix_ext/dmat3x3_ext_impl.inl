/**
* @file     dmat3x3_impl.inl
* @brief    Implamentation of convert operators, extended mathematical operators 
            and extended constructors of a 3x3 double matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<3, 3, double>::col_type glm2::mat<3, 3, double>::operator* (const row_type& v) const
{
    __m256d ymm0, ymm1, ymm2;
    ymm0 = _mm256_permute4x64_pd(v.intrin(), 0x00);    // x, x, x, x
    ymm1 = _mm256_permute4x64_pd(v.intrin(), 0x55);    // y, y, y, y
    ymm2 = _mm256_permute4x64_pd(v.intrin(), 0xAA);    // z, z, z, z
    ymm0 = _mm256_mul_pd(ymm0, this->_M[0].intrin());
    ymm0 = _mm256_fmadd_pd(ymm1, this->_M[1].intrin(), ymm0);
    ymm0 = _mm256_fmadd_pd(ymm2, this->_M[2].intrin(), ymm0);
    return col_type(ymm0);
}
inline glm2::mat<3, 3, double>::col_type glm2::mat<3, 3, double>::operator/ (const row_type& v) const
{
    mat I;
    detail::core::matrix::inverse::_default_dm3x3(col_type::intrin_ptr(this->_M), col_type::intrin_ptr(I._M));
    return (I * v);
}

inline glm2::mat<2, 3, double> glm2::mat<3, 3, double>::operator* (const mat<2, 3, double>& M) const
{
    mat<2, 3, double> res;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = this->_M[0].intrin();
    ymm1 = this->_M[1].intrin();
    ymm2 = this->_M[2].intrin();
    ymm3 = _mm256_broadcast_sd(mat<2, 3, double>::value_ptr(M) + 0);
    ymm4 = _mm256_broadcast_sd(mat<2, 3, double>::value_ptr(M) + 1);
    ymm5 = _mm256_broadcast_sd(mat<2, 3, double>::value_ptr(M) + 2);
    ymm3 = _mm256_mul_pd(ymm3, ymm0);
    ymm3 = _mm256_fmadd_pd(ymm4, ymm1, ymm3);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm2, ymm3);
    res[0] = ymm3;
    ymm3 = _mm256_broadcast_sd(mat<2, 3, double>::value_ptr(M) + 4);
    ymm4 = _mm256_broadcast_sd(mat<2, 3, double>::value_ptr(M) + 5);
    ymm5 = _mm256_broadcast_sd(mat<2, 3, double>::value_ptr(M) + 6);
    ymm0 = _mm256_mul_pd(ymm3, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm4, ymm1, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm5, ymm2, ymm0);
    res[1] = ymm0;
    return res;
}
inline glm2::mat<4, 3, double> glm2::mat<3, 3, double>::operator* (const mat<4, 3, double>& M) const
{
    mat<4, 3, double> res;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = this->_M[0].intrin();
    ymm1 = this->_M[1].intrin();
    ymm2 = this->_M[2].intrin();
    ymm3 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 0);
    ymm4 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 1);
    ymm5 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 2);
    ymm3 = _mm256_mul_pd(ymm3, ymm0);
    ymm3 = _mm256_fmadd_pd(ymm4, ymm1, ymm3);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm2, ymm3);
    res[0] = ymm3;
    ymm3 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 4);
    ymm4 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 5);
    ymm5 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 6);
    ymm3 = _mm256_mul_pd(ymm3, ymm0);
    ymm3 = _mm256_fmadd_pd(ymm4, ymm1, ymm3);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm2, ymm3);
    res[1] = ymm3;
    ymm3 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 8);
    ymm4 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 9);
    ymm5 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 10);
    ymm3 = _mm256_mul_pd(ymm3, ymm0);
    ymm3 = _mm256_fmadd_pd(ymm4, ymm1, ymm3);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm2, ymm3);
    res[2] = ymm3;
    ymm3 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 12);
    ymm4 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 13);
    ymm5 = _mm256_broadcast_sd(mat<4, 3, double>::value_ptr(M) + 14);
    ymm0 = _mm256_mul_pd(ymm3, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm4, ymm1, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm5, ymm2, ymm0);
    res[3] = ymm0;
    return res;
}
inline glm2::mat<3, 3, double> glm2::mat<3, 3, double>::operator* (const mat& M) const
{
    mat _M = *this;
    _M *= M;
    return _M;
}
inline glm2::mat<3, 3, double> glm2::mat<3, 3, double>::operator/ (const mat& M) const
{
    mat _M = *this;
    _M /= M;
    return _M;
}

inline glm2::mat<3, 3, double>& glm2::mat<3, 3, double>::operator*= (const mat& M)
{
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = this->_M[0].intrin();
    ymm1 = this->_M[1].intrin();
    ymm2 = this->_M[2].intrin();
    ymm3 = _mm256_broadcast_sd(mat::value_ptr(M) + 0);
    ymm4 = _mm256_broadcast_sd(mat::value_ptr(M) + 1);
    ymm5 = _mm256_broadcast_sd(mat::value_ptr(M) + 2);
    ymm3 = _mm256_mul_pd(ymm3, ymm0);
    ymm3 = _mm256_fmadd_pd(ymm4, ymm1, ymm3);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm2, ymm3);
    this->_M[0] = ymm3;
    ymm3 = _mm256_broadcast_sd(mat::value_ptr(M) + 4);
    ymm4 = _mm256_broadcast_sd(mat::value_ptr(M) + 5);
    ymm5 = _mm256_broadcast_sd(mat::value_ptr(M) + 6);
    ymm3 = _mm256_mul_pd(ymm3, ymm0);
    ymm3 = _mm256_fmadd_pd(ymm4, ymm1, ymm3);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm2, ymm3);
    this->_M[1] = ymm3;
    ymm3 = _mm256_broadcast_sd(mat::value_ptr(M) + 8);
    ymm4 = _mm256_broadcast_sd(mat::value_ptr(M) + 9);
    ymm5 = _mm256_broadcast_sd(mat::value_ptr(M) + 10);
    ymm0 = _mm256_mul_pd(ymm3, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm4, ymm1, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm5, ymm2, ymm0);
    this->_M[2] = ymm0;
    return *this;
}
inline glm2::mat<3, 3, double>& glm2::mat<3, 3, double>::operator/= (const mat& M)
{
    mat I;
    detail::core::matrix::inverse::_default_dm3x3(col_type::intrin_ptr(M._M), col_type::intrin_ptr(I._M));
    return (*this *= I);
}

inline glm2::mat<3, 3, double>::operator glm2::mat<2, 2, float>(void) const
{
    mat<2, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<2, 3, float>(void) const
{
    mat<2, 3, float> res;
    res[0] = (vec3)this->_M[0];
    res[1] = (vec3)this->_M[1];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<2, 4, float>(void) const
{
    mat<2, 4, float> res;
    res[0] = _mm256_castps256_ps128(_mm256_castpd_ps(this->_M[0].intrin()));
    res[1] = _mm256_castps256_ps128(_mm256_castpd_ps(this->_M[1].intrin()));
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<3, 2, float>(void) const
{
    mat<3, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    res[2] = (vec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<3, 3, float>(void) const
{
    mat<3, 3, float> res;
    res[0] = (vec3)this->_M[0];
    res[1] = (vec3)this->_M[1];
    res[2] = (vec3)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<3, 4, float>(void) const
{
    mat<3, 4, float> res;
    res[0] = _mm256_castps256_ps128(_mm256_castpd_ps(this->_M[0].intrin()));
    res[1] = _mm256_castps256_ps128(_mm256_castpd_ps(this->_M[1].intrin()));
    res[2] = _mm256_castps256_ps128(_mm256_castpd_ps(this->_M[2].intrin()));
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<4, 2, float>(void) const
{
    mat<4, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    res[2] = (vec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<4, 3, float>(void) const
{
    mat<4, 3, float> res;
    res[0] = (vec3)this->_M[0];
    res[1] = (vec3)this->_M[1];
    res[2] = (vec3)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<4, 4, float>(void) const
{
    mat<4, 4, float> res;
    res[0] = _mm256_castps256_ps128(_mm256_castpd_ps(this->_M[0].intrin()));
    res[1] = _mm256_castps256_ps128(_mm256_castpd_ps(this->_M[1].intrin()));
    res[2] = _mm256_castps256_ps128(_mm256_castpd_ps(this->_M[2].intrin()));
    return res;
}

inline glm2::mat<3, 3, double>::operator glm2::mat<2, 2, double>(void) const
{
    mat<2, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<2, 3, double>(void) const
{
    mat<2, 3, double> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<2, 4, double>(void) const
{
    mat<2, 4, double> res;
    res[0] = this->_M[0].intrin();
    res[1] = this->_M[1].intrin();
    return res;
}   
inline glm2::mat<3, 3, double>::operator glm2::mat<3, 2, double>(void) const
{
    mat<3, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<3, 4, double>(void) const
{
    mat<3, 4, double> res;
    res[0] = this->_M[0].intrin();
    res[1] = this->_M[1].intrin();
    res[2] = this->_M[2].intrin();
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<4, 2, double>(void) const
{
    mat<4, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<4, 3, double>(void) const
{
    mat<4, 3, double> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    res[2] = this->_M[2];
    return res;
}
inline glm2::mat<3, 3, double>::operator glm2::mat<4, 4, double>(void) const
{
    mat<4, 4, double> res;
    res[0] = this->_M[0].intrin();
    res[1] = this->_M[1].intrin();
    res[2] = this->_M[2].intrin();
    return res;
}
