/**
* @file     dmat2x2_impl.inl
* @brief    Implamentation of convert operators, extended mathematical operators 
            and extended constructors of a 2x2 double matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<2, 2, double>::col_type glm2::mat<2, 2, double>::operator* (const row_type& v) const
{
    __m256d ymm0, ymm1;
    __m128d xmm0, xmm1;
    ymm0 = _mm256_loadu_pd(row_type::value_ptr(this->_M));
    ymm1 = _mm256_castpd128_pd256(v.intrin());
    ymm1 = _mm256_permute4x64_pd(ymm1, 0x50);
    ymm0 = _mm256_mul_pd(ymm0, ymm1);
    xmm1 = _mm256_extractf128_pd(ymm0, 0x01);
    xmm0 = _mm256_castpd256_pd128(ymm0);
    xmm0 = _mm_add_pd(xmm0, xmm1);
    return col_type(xmm0);
}
inline glm2::mat<2, 2, double>::col_type glm2::mat<2, 2, double>::operator/ (const row_type& v) const
{
    __m256d I[1];
    detail::core::matrix::inverse::_default_dm2x2(col_type::intrin_ptr(this->_M), I);
    return (mat(I) * v);
}

inline glm2::mat<3, 2, double> glm2::mat<2, 2, double>::operator* (const mat<3, 2, double>& M) const
{
    mat<3, 2, double> res;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = _mm256_loadu_pd(mat<3, 2, double>::value_ptr(M));
    ymm1 = _mm256_castpd128_pd256(M[2].intrin());
    ymm2 = _mm256_permute_pd(ymm0, 0x00);
    ymm0 = _mm256_permute_pd(ymm0, 0x0F);
    ymm3 = _mm256_permute_pd(ymm1, 0x00);
    ymm1 = _mm256_permute_pd(ymm1, 0x0F);
    ymm4 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 0);
    ymm5 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 1);
    ymm0 = _mm256_mul_pd(ymm5, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm4, ymm2, ymm0);
    ymm1 = _mm256_mul_pd(ymm5, ymm1);
    ymm1 = _mm256_fmadd_pd(ymm4, ymm3, ymm1);
    _mm256_storeu_pd(mat<3, 2, double>::value_ptr(res), ymm0);
    res[2] = _mm256_castpd256_pd128(ymm1);
    return res;
}
inline glm2::mat<4, 2, double> glm2::mat<2, 2, double>::operator* (const mat<4, 2, double>& M) const
{
    mat<4, 2, double> res;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = _mm256_loadu_pd(mat<4, 2, double>::value_ptr(M) + 0);
    ymm1 = _mm256_loadu_pd(mat<4, 2, double>::value_ptr(M) + 4);
    ymm2 = _mm256_permute_pd(ymm0, 0x00);
    ymm0 = _mm256_permute_pd(ymm0, 0x0F);
    ymm3 = _mm256_permute_pd(ymm1, 0x00);
    ymm1 = _mm256_permute_pd(ymm1, 0x0F);
    ymm4 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 0);
    ymm5 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 1);
    ymm0 = _mm256_mul_pd(ymm5, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm4, ymm2, ymm0);
    ymm1 = _mm256_mul_pd(ymm5, ymm1);
    ymm1 = _mm256_fmadd_pd(ymm4, ymm3, ymm1);
    _mm256_storeu_pd(mat<4, 2, double>::value_ptr(res) + 0, ymm0);
    _mm256_storeu_pd(mat<4, 2, double>::value_ptr(res) + 4, ymm1);
    return res;
}
inline glm2::mat<2, 2, double> glm2::mat<2, 2, double>::operator* (const mat& M) const
{
    mat _M = *this;
    _M *= M;
    return _M;
}
inline glm2::mat<2, 2, double> glm2::mat<2, 2, double>::operator/ (const mat& M) const
{
    mat _M = *this;
    _M /= M;
    return _M;
}

inline glm2::mat<2, 2, double>& glm2::mat<2, 2, double>::operator*= (const mat& M)
{
    __m256d ymm0, ymm1, ymm2, ymm3;
    ymm0 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 0);
    ymm1 = _mm256_broadcast_pd(col_type::intrin_ptr(this->_M) + 1);
    ymm2 = _mm256_loadu_pd(col_type::value_ptr(M._M));
    ymm3 = _mm256_unpacklo_pd(ymm2, ymm2);
    ymm2 = _mm256_unpackhi_pd(ymm2, ymm2);
    ymm0 = _mm256_mul_pd(ymm0, ymm3);
    ymm0 = _mm256_fmadd_pd(ymm1, ymm2, ymm0);
    _mm256_storeu_pd(col_type::value_ptr(this->_M), ymm0);
    return *this;
}
inline glm2::mat<2, 2, double>& glm2::mat<2, 2, double>::operator/= (const mat& M)
{
    __m256d I[1];
    detail::core::matrix::inverse::_default_dm2x2(col_type::intrin_ptr(M._M), I);
    return (*this *= mat(I));
}

inline glm2::mat<2, 2, double>::operator glm2::mat<2, 2, float>(void) const
{
    mat<2, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<2, 3, float>(void) const
{
    mat<2, 3, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0].intrin());
    res[1] = _mm_cvtpd_ps(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<2, 4, float>(void) const
{
    mat<2, 4, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0].intrin());
    res[1] = _mm_cvtpd_ps(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<3, 2, float>(void) const
{
    mat<3, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<3, 3, float>(void) const
{
    mat<3, 3, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0].intrin());
    res[1] = _mm_cvtpd_ps(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<3, 4, float>(void) const
{
    mat<3, 4, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0].intrin());
    res[1] = _mm_cvtpd_ps(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<4, 2, float>(void) const
{
    mat<4, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<4, 3, float>(void) const
{
    mat<4, 3, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0].intrin());
    res[1] = _mm_cvtpd_ps(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<4, 4, float>(void) const
{
    mat<4, 4, float> res;
    res[0] = _mm_cvtpd_ps(this->_M[0].intrin());
    res[1] = _mm_cvtpd_ps(this->_M[1].intrin());
    return res;
}

inline glm2::mat<2, 2, double>::operator glm2::mat<2, 3, double>(void) const
{
    mat<2, 3, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0].intrin());
    res[1] = _mm256_castpd128_pd256(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<2, 4, double>(void) const
{
    mat<2, 4, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0].intrin());
    res[1] = _mm256_castpd128_pd256(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<3, 2, double>(void) const
{
    mat<3, 2, double> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<3, 3, double>(void) const
{
    mat<3, 3, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0].intrin());
    res[1] = _mm256_castpd128_pd256(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<3, 4, double>(void) const
{
    mat<3, 4, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0].intrin());
    res[1] = _mm256_castpd128_pd256(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<4, 2, double>(void) const
{
    mat<4, 2, double> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<4, 3, double>(void) const
{
    mat<4, 3, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0].intrin());
    res[1] = _mm256_castpd128_pd256(this->_M[1].intrin());
    return res;
}
inline glm2::mat<2, 2, double>::operator glm2::mat<4, 4, double>(void) const
{
    mat<4, 4, double> res;
    res[0] = _mm256_castpd128_pd256(this->_M[0].intrin());
    res[1] = _mm256_castpd128_pd256(this->_M[1].intrin());
    return res;
}
