/**
* @file     mat4x4_impl.inl
* @brief    Implamentation of convert operators, extended mathematical operators 
            and extended constructors of a 4x4 float matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<4, 4, float>::col_type glm2::mat<4, 4, float>::operator* (const row_type& v) const
{
    __m256 ymm0, ymm1;
    __m128 xmm0;
    ymm0 = _mm256_broadcastsi128_si256(_mm_castps_si128(v()));
    ymm1 = _mm256_permutevar_ps(ymm0, _mm256_set_epi32(1,1,1,1, 0,0,0,0));
    ymm0 = _mm256_permutevar_ps(ymm0, _mm256_set_epi32(3,3,3,3, 2,2,2,2));
    ymm1 = _mm256_mul_ps(ymm1, _mm256_loadu_ps(col_type::value_ptr(this->_M + 0)));
    ymm1 = _mm256_fmadd_ps(ymm0, _mm256_loadu_ps(col_type::value_ptr(this->_M + 2)), ymm1);
    xmm0 = _mm256_extractf128_ps(ymm1, 0x1);
    xmm0 = _mm_add_ps(xmm0, _mm256_castps256_ps128(ymm1));
    return col_type(xmm0);
}
inline glm2::mat<4, 4, float>::col_type glm2::mat<4, 4, float>::operator/ (const row_type& v) const
{
    mat I;
    detail::core::matrix::inverse::_default_fm4x4(col_type::intrin_ptr(this->_M), col_type::intrin_ptr(I._M));
    return (I * v);
}

inline glm2::mat<2, 4, float> glm2::mat<4, 4, float>::operator* (const mat<2, 4, float>& M) const
{
    mat<2, 4, float> res;
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7;
    ymm0 = _mm256_loadu_ps(mat<2, 4, float>::value_ptr(M));
    ymm1 = _mm256_permute_ps(ymm0, 0x00);
    ymm2 = _mm256_permute_ps(ymm0, 0x55);
    ymm3 = _mm256_permute_ps(ymm0, 0xAA);
    ymm0 = _mm256_permute_ps(ymm0, 0xFF);
    ymm4 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 0);
    ymm5 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 1);
    ymm6 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 2);
    ymm7 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 3);
    ymm0 = _mm256_mul_ps(ymm0, ymm7);
    ymm0 = _mm256_fmadd_ps(ymm3, ymm6, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm2, ymm5, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm1, ymm4, ymm0);
    _mm256_storeu_ps(mat<2, 4, float>::value_ptr(res), ymm0);
    return res;
}
inline glm2::mat<3, 4, float> glm2::mat<4, 4, float>::operator* (const mat<3, 4, float>& M) const
{
    mat<3, 4, float> res;
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7;
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7;
    ymm0 = _mm256_loadu_ps(mat<3, 4, float>::value_ptr(M));
    ymm1 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 0);
    ymm2 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 1);
    ymm3 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 2);
    ymm4 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 3);
    ymm5 = _mm256_permute_ps(ymm0, 0x00);
    ymm6 = _mm256_permute_ps(ymm0, 0x55);
    ymm7 = _mm256_permute_ps(ymm0, 0xAA);
    ymm0 = _mm256_permute_ps(ymm0, 0xFF);
    ymm0 = _mm256_mul_ps(ymm0, ymm4);
    ymm0 = _mm256_fmadd_ps(ymm7, ymm3, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm6, ymm2, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm5, ymm1, ymm0);
    _mm256_storeu_ps(mat<3, 4, float>::value_ptr(res), ymm0);
    xmm1 = _mm256_castps256_ps128(ymm1);
    xmm2 = _mm256_castps256_ps128(ymm2);
    xmm3 = _mm256_castps256_ps128(ymm3);
    xmm4 = _mm256_castps256_ps128(ymm4);
    xmm5 = _mm_broadcast_ss(mat<3, 4, float>::value_ptr(M) + 8);
    xmm6 = _mm_broadcast_ss(mat<3, 4, float>::value_ptr(M) + 9);
    xmm7 = _mm_broadcast_ss(mat<3, 4, float>::value_ptr(M) + 10);
    xmm0 = _mm_broadcast_ss(mat<3, 4, float>::value_ptr(M) + 11);
    xmm0 = _mm_mul_ps(xmm0, xmm4);
    xmm0 = _mm_fmadd_ps(xmm7, xmm3, xmm0);
    xmm0 = _mm_fmadd_ps(xmm6, xmm2, xmm0);
    xmm0 = _mm_fmadd_ps(xmm5, xmm1, xmm0);
    res[2] = xmm0;
    return res;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator* (const mat& M) const
{
    mat _M = *this;
    _M *= M;
    return _M;
}
inline glm2::mat<4, 4, float> glm2::mat<4, 4, float>::operator/ (const mat& M) const
{
    mat _M = *this;
    _M /= M;
    return _M;
}

inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator*= (const mat& M)
{
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7;
    ymm0 = _mm256_loadu_ps(col_type::value_ptr(M._M) + 0);
    ymm1 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 0);
    ymm2 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 1);
    ymm3 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 2);
    ymm4 = _mm256_broadcast_ps(col_type::intrin_ptr(this->_M) + 3);
    ymm5 = _mm256_permute_ps(ymm0, 0x00);
    ymm6 = _mm256_permute_ps(ymm0, 0x55);
    ymm7 = _mm256_permute_ps(ymm0, 0xAA);
    ymm0 = _mm256_permute_ps(ymm0, 0xFF);
    ymm0 = _mm256_mul_ps(ymm0, ymm4);
    ymm0 = _mm256_fmadd_ps(ymm7, ymm3, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm6, ymm2, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm5, ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 0), ymm0);
    ymm0 = _mm256_loadu_ps(col_type::value_ptr(M._M) + 8);
    ymm5 = _mm256_permute_ps(ymm0, 0x00);
    ymm6 = _mm256_permute_ps(ymm0, 0x55);
    ymm7 = _mm256_permute_ps(ymm0, 0xAA);
    ymm0 = _mm256_permute_ps(ymm0, 0xFF);
    ymm0 = _mm256_mul_ps(ymm0, ymm4);
    ymm0 = _mm256_fmadd_ps(ymm7, ymm3, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm6, ymm2, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm5, ymm1, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M + 2), ymm0);
    return *this;
}
inline glm2::mat<4, 4, float>& glm2::mat<4, 4, float>::operator/= (const mat& M)
{
    mat I;
    detail::core::matrix::inverse::_default_fm4x4(col_type::intrin_ptr(M._M), col_type::intrin_ptr(I._M));
    return (*this *= I);
}

inline glm2::mat<4, 4, float>::operator glm2::mat<2, 2, float>(void) const
{
    mat<2, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<2, 3, float>(void) const
{
    mat<2, 3, float> res;
    res[0] = (vec3)this->_M[0];
    res[1] = (vec3)this->_M[1];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<2, 4, float>(void) const
{
    mat<2, 4, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<3, 2, float>(void) const
{
    mat<3, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    res[2] = (vec2)this->_M[2];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<3, 3, float>(void) const
{
    mat<3, 3, float> res;
    res[0] = (vec3)this->_M[0];
    res[1] = (vec3)this->_M[1];
    res[2] = (vec3)this->_M[2];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<3, 4, float>(void) const
{
    mat<3, 4, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    res[2] = this->_M[2];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<4, 2, float>(void) const
{
    mat<4, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    res[2] = (vec2)this->_M[2];
    res[3] = (vec2)this->_M[3];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<4, 3, float>(void) const
{
    mat<4, 3, float> res;
    res[0] = (vec3)this->_M[0];
    res[1] = (vec3)this->_M[1];
    res[2] = (vec3)this->_M[2];
    res[3] = (vec3)this->_M[3];
    return res;
}

inline glm2::mat<4, 4, float>::operator glm2::mat<2, 2, double>(void) const
{
    mat<2, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<2, 3, double>(void) const
{
    mat<2, 3, double> res;
    res[0] = (dvec3)this->_M[0];
    res[1] = (dvec3)this->_M[1];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<2, 4, double>(void) const
{
    mat<2, 4, double> res;
    res[0] = (dvec4)this->_M[0];
    res[1] = (dvec4)this->_M[1];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<3, 2, double>(void) const
{
    mat<3, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<3, 3, double>(void) const
{
    mat<3, 3, double> res;
    res[0] = (dvec3)this->_M[0];
    res[1] = (dvec3)this->_M[1];
    res[2] = (dvec3)this->_M[2];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<3, 4, double>(void) const
{
    mat<3, 4, double> res;
    res[0] = (dvec4)this->_M[0];
    res[1] = (dvec4)this->_M[1];
    res[2] = (dvec4)this->_M[2];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<4, 2, double>(void) const
{   
    mat<4, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    res[3] = (dvec2)this->_M[3];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<4, 3, double>(void) const
{
    mat<4, 3, double> res;
    res[0] = (dvec3)this->_M[0];
    res[1] = (dvec3)this->_M[1];
    res[2] = (dvec3)this->_M[2];
    res[3] = (dvec3)this->_M[3];
    return res;
}
inline glm2::mat<4, 4, float>::operator glm2::mat<4, 4, double>(void) const
{
    mat<4, 4, double> res;
    res[0] = (dvec4)this->_M[0];
    res[1] = (dvec4)this->_M[1];
    res[2] = (dvec4)this->_M[2];
    res[3] = (dvec4)this->_M[3];
    return res;
}
