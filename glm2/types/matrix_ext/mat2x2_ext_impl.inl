/**
* @file     mat2x2_impl.inl
* @brief    Implamentation of convert operators, extended mathematical operators 
            and extended constructors of a 2x2 float matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<2, 2, float>::col_type glm2::mat<2, 2, float>::operator* (const row_type& v) const
{
    __m128 xmm0, xmm1;
    xmm0 = _mm_loadu_ps(row_type::value_ptr(this->_M));
    xmm1 = v.si128();
    xmm1 = _mm_unpacklo_ps(xmm1, xmm1);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    xmm1 = _mm_movehl_ps(xmm0, xmm0);
    xmm0 = _mm_add_ps(xmm0, xmm1);
    return col_type(xmm0);
}
inline glm2::mat<2, 2, float>::col_type glm2::mat<2, 2, float>::operator/ (const row_type& v) const
{
    __m128 I[1];
    detail::core::matrix::inverse::_default_fm2x2(col_type::intrin_ptr(this->_M), I);
    return (mat(I) * v);
}

inline glm2::mat<3, 2, float> glm2::mat<2, 2, float>::operator* (const mat<3, 2, float>& M) const
{
    mat<3, 2, float> res;
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm1 = _mm_loadu_ps(mat<3, 2, float>::value_ptr(M));
    xmm2 = M[2].si128();
    xmm3 = _mm_permute_ps(xmm0, 0x44);
    xmm0 = _mm_permute_ps(xmm0, 0xEE);
    xmm4 = _mm_moveldup_ps(xmm1);
    xmm1 = _mm_movehdup_ps(xmm1);
    xmm5 = _mm_moveldup_ps(xmm2);
    xmm2 = _mm_movehdup_ps(xmm2);
    xmm2 = _mm_mul_ps(xmm0, xmm2);
    xmm0 = _mm_mul_ps(xmm0, xmm1);
    xmm1 = _mm_fmadd_ps(xmm5, xmm3, xmm2);
    xmm0 = _mm_fmadd_ps(xmm4, xmm3, xmm0);
    _mm_storeu_ps(mat<3, 2, float>::value_ptr(res), xmm0);
    res[2] = xmm1;
    return res;
}
inline glm2::mat<4, 2, float> glm2::mat<2, 2, float>::operator* (const mat<4, 2, float>& M) const
{
    mat<4, 2, float> res;
    __m256 ymm0, ymm1, ymm2, ymm3;
    ymm0 = _mm256_loadu_ps(mat<4, 2, float>::value_ptr(M));
    ymm1 = _mm256_moveldup_ps(ymm0);
    ymm0 = _mm256_movehdup_ps(ymm0);
    ymm2 = _mm256_castpd_ps(_mm256_broadcast_sd(reinterpret_cast<const double*>(this->_M) + 0));
    ymm3 = _mm256_castpd_ps(_mm256_broadcast_sd(reinterpret_cast<const double*>(this->_M) + 1));
    ymm0 = _mm256_mul_ps(ymm3, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm2, ymm1, ymm0);
    _mm256_storeu_ps(mat<4, 2, float>::value_ptr(res), ymm0);
    return res;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator* (const mat& M) const
{
    mat _M = *this;
    _M *= M;
    return _M;
}
inline glm2::mat<2, 2, float> glm2::mat<2, 2, float>::operator/ (const mat& M) const
{
    mat _M = *this;
    _M /= M;
    return _M;
}

inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator*= (const mat& M)
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(M._M));
    xmm1 = _mm_moveldup_ps(xmm0);
    xmm0 = _mm_movehdup_ps(xmm0);
    xmm2 = _mm_loadu_ps(col_type::value_ptr(this->_M));
    xmm3 = _mm_permute_ps(xmm2, 0x44);
    xmm2 = _mm_permute_ps(xmm2, 0xEE);
    xmm0 = _mm_mul_ps(xmm2, xmm0);
    xmm0 = _mm_fmadd_ps(xmm3, xmm1, xmm0);
    _mm_storeu_ps(col_type::value_ptr(this->_M), xmm0);
    return *this;
}
inline glm2::mat<2, 2, float>& glm2::mat<2, 2, float>::operator/= (const mat& M)
{
    __m128 I[1];
    detail::core::matrix::inverse::_default_fm2x2(col_type::intrin_ptr(M._M), I);
    return (*this *= mat(I));
}

inline glm2::mat<2, 2, float>::operator glm2::mat<2, 3, float>(void) const
{
    mat<2, 3, float> res;
    res[0] = this->_M[0].si128();
    res[1] = this->_M[1].si128();
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<2, 4, float>(void) const
{
    mat<2, 4, float> res;
    res[0] = this->_M[0].si128();
    res[1] = this->_M[1].si128();
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<3, 2, float>(void) const
{
    mat<3, 2, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<3, 3, float>(void) const
{
    mat<3, 3, float> res;
    res[0] = this->_M[0].si128();
    res[1] = this->_M[1].si128();
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<3, 4, float>(void) const
{
    mat<3, 4, float> res;
    res[0] = this->_M[0].si128();
    res[1] = this->_M[1].si128();
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<4, 2, float>(void) const
{
    mat<4, 2, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<4, 3, float>(void) const
{
    mat<4, 3, float> res;
    res[0] = this->_M[0].si128();
    res[1] = this->_M[1].si128();
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<4, 4, float>(void) const
{
    mat<4, 4, float> res;
    res[0] = this->_M[0].si128();
    res[1] = this->_M[1].si128();
    return res;
}

inline glm2::mat<2, 2, float>::operator glm2::mat<2, 2, double>(void) const
{
    mat<2, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<2, 3, double>(void) const
{
    mat<2, 3, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].si128()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].si128()));  
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<2, 4, double>(void) const
{
    mat<2, 4, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].si128()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].si128()));  
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<3, 2, double>(void) const
{
    mat<3, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<3, 3, double>(void) const
{
    mat<3, 3, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].si128()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].si128()));  
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<3, 4, double>(void) const
{
    mat<3, 4, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].si128()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].si128()));  
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<4, 2, double>(void) const
{
    mat<4, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<4, 3, double>(void) const
{
    mat<4, 3, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].si128()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].si128()));  
    return res;
}
inline glm2::mat<2, 2, float>::operator glm2::mat<4, 4, double>(void) const
{
    mat<4, 4, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].si128()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].si128()));  
    return res;
}
