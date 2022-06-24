/**
* @file     mat4x2_impl.inl
* @brief    Implamentation of convert operators, extended mathematical operators 
            and extended constructors of a 4x2 float matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<4, 2, float>::col_type glm2::mat<4, 2, float>::operator* (const row_type& v) const
{
    __m128 xmm0, xmm1, xmm2, xmm3;
    xmm0 = v.intrin();                                             // x, y, z, w
    xmm1 = _mm_loadu_ps(col_type::value_ptr(this->_M + 0)); // a, e, b, f
    xmm2 = _mm_loadu_ps(col_type::value_ptr(this->_M + 2)); // c, g, d, h
    xmm3 = _mm_unpacklo_ps(xmm0, xmm0);                     // x, x, y, y
    xmm0 = _mm_unpackhi_ps(xmm0, xmm0);                     // z, z, w, w
    xmm1 = _mm_mul_ps(xmm3, xmm1);
    xmm0 = _mm_mul_ps(xmm0, xmm2);
    xmm2 = _mm_permute_ps(xmm1, 0x0E);
    xmm3 = _mm_permute_ps(xmm0, 0x0E);
    xmm1 = _mm_add_ps(xmm1, xmm2);
    xmm0 = _mm_add_ps(xmm0, xmm3);
    xmm0 = _mm_add_ps(xmm0, xmm1);
    return col_type(xmm0);
}

inline glm2::mat<2, 2, float> glm2::mat<4, 2, float>::operator* (const mat<2, 4, float>& M) const
{
    mat<2, 2, float> res;
    __m128 xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xmm8;
    xmm0 = _mm_loadu_ps(col_type::value_ptr(this->_M + 0));
    xmm1 = _mm_loadu_ps(col_type::value_ptr(this->_M + 2));
    xmm2 = M[0].intrin();
    xmm3 = M[1].intrin();
    xmm4 = _mm_movelh_ps(xmm0, xmm0);
    xmm0 = _mm_movehl_ps(xmm0, xmm0);
    xmm5 = _mm_movelh_ps(xmm1, xmm1);
    xmm1 = _mm_movehl_ps(xmm1, xmm1);
    xmm6 = _mm_shuffle_ps(xmm2, xmm3, 0x00);
    xmm7 = _mm_shuffle_ps(xmm2, xmm3, 0x55);
    xmm8 = _mm_shuffle_ps(xmm2, xmm3, 0xAA);
    xmm2 = _mm_shuffle_ps(xmm2, xmm3, 0xFF);
    xmm0 = _mm_mul_ps(xmm0, xmm7);
    xmm0 = _mm_fmadd_ps(xmm1, xmm2, xmm0);
    xmm0 = _mm_fmadd_ps(xmm5, xmm8, xmm0);
    xmm0 = _mm_fmadd_ps(xmm4, xmm6, xmm0);
    _mm_store_ps(mat<2, 2, float>::value_ptr(res), xmm0);
    return res;
}
inline glm2::mat<3, 2, float> glm2::mat<4, 2, float>::operator* (const mat<3, 4, float>& M) const
{
    mat<3, 2, float> res;
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7;
    __m128 xmm0, xmm1;
    ymm0 = _mm256_loadu_ps(mat<3, 4, float>::value_ptr(M));
    ymm1 = _mm256_castps128_ps256(M[2].intrin());
    ymm2 = _mm256_loadu_ps(col_type::value_ptr(this->_M));
    ymm3 = _mm256_permute2f128_ps(ymm0, ymm1, 0x20);
    ymm0 = _mm256_permute2f128_ps(ymm0, ymm1, 0x31);
    ymm1 = _mm256_shuffle_ps(ymm3, ymm0, 0x00);
    ymm4 = _mm256_shuffle_ps(ymm3, ymm0, 0x55);
    ymm5 = _mm256_shuffle_ps(ymm3, ymm0, 0xAA);
    ymm0 = _mm256_shuffle_ps(ymm3, ymm0, 0xFF);
    ymm3 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(1,0,1,0, 1,0,1,0));
    ymm6 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(3,2,3,2, 3,2,3,2));
    ymm7 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(5,4,5,4, 5,4,5,4));
    ymm2 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(7,6,7,6, 7,6,7,6));
    ymm0 = _mm256_mul_ps(ymm0, ymm2);
    ymm0 = _mm256_fmadd_ps(ymm5, ymm7, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm4, ymm6, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm1, ymm3, ymm0);
    xmm1 = _mm256_extractf128_ps(ymm0, 0x1);
    xmm0 = _mm256_castps256_ps128(ymm0);
    _mm_storeu_ps(mat<3, 2, float>::value_ptr(res), xmm0);
    res[2] = xmm1;
    return res;
}
inline glm2::mat<4, 2, float> glm2::mat<4, 2, float>::operator* (const mat<4, 4, float>& M) const
{
    mat _M = *this;
    _M *= M;
    return _M;
}

inline glm2::mat<4, 2, float>& glm2::mat<4, 2, float>::operator*= (const mat<4, 4, float>& M)
{
    __m256 ymm0, ymm1, ymm2, ymm3, ymm4, ymm5, ymm6, ymm7;
    __m128 xmm0, xmm1;
    ymm0 = _mm256_loadu_ps(mat<4, 4, float>::value_ptr(M) + 0);
    ymm1 = _mm256_loadu_ps(mat<4, 4, float>::value_ptr(M) + 8);
    ymm2 = _mm256_loadu_ps(col_type::value_ptr(this->_M));
    ymm3 = _mm256_permute2f128_ps(ymm0, ymm1, 0x20);
    ymm0 = _mm256_permute2f128_ps(ymm0, ymm1, 0x31);
    ymm1 = _mm256_shuffle_ps(ymm3, ymm0, 0x00);
    ymm4 = _mm256_shuffle_ps(ymm3, ymm0, 0x55);
    ymm5 = _mm256_shuffle_ps(ymm3, ymm0, 0xAA);
    ymm0 = _mm256_shuffle_ps(ymm3, ymm0, 0xFF);
    ymm3 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(1,0,1,0, 1,0,1,0));
    ymm6 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(3,2,3,2, 3,2,3,2));
    ymm7 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(5,4,5,4, 5,4,5,4));
    ymm2 = _mm256_permutevar8x32_ps(ymm2, _mm256_set_epi32(7,6,7,6, 7,6,7,6));
    ymm0 = _mm256_mul_ps(ymm0, ymm2);
    ymm0 = _mm256_fmadd_ps(ymm5, ymm7, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm4, ymm6, ymm0);
    ymm0 = _mm256_fmadd_ps(ymm1, ymm3, ymm0);
    _mm256_storeu_ps(col_type::value_ptr(this->_M), ymm0);
    return *this;
}

inline glm2::mat<4, 2, float>::operator glm2::mat<2, 2, float>(void) const
{
    mat<2, 2, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<2, 3, float>(void) const
{
    mat<2, 3, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<2, 4, float>(void) const
{
    mat<2, 4, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<3, 2, float>(void) const
{
    mat<3, 2, float> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    res[2] = this->_M[2];
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<3, 3, float>(void) const
{
    mat<3, 3, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    res[2] = this->_M[2].intrinEXT();
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<3, 4, float>(void) const 
{
    mat<3, 4, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    res[2] = this->_M[2].intrinEXT();
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<4, 3, float>(void) const
{
    mat<4, 3, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    res[2] = this->_M[2].intrinEXT();
    res[3] = this->_M[3].intrinEXT();
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<4, 4, float>(void) const
{
    mat<4, 4, float> res;
    res[0] = this->_M[0].intrinEXT();
    res[1] = this->_M[1].intrinEXT();
    res[2] = this->_M[2].intrinEXT();
    res[3] = this->_M[3].intrinEXT();
    return res;
}   

inline glm2::mat<4, 2, float>::operator glm2::mat<2, 2, double>(void) const
{
    mat<2, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<2, 3, double>(void) const
{
    mat<2, 3, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<2, 4, double>(void) const
{
    mat<2, 4, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<3, 2, double>(void) const
{
    mat<3, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<3, 3, double>(void) const
{
    mat<3, 3, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    res[2] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[2].intrinEXT())); 
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<3, 4, double>(void) const
{
    mat<3, 4, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    res[2] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[2].intrinEXT())); 
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<4, 2, double>(void) const
{
    mat<4, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    res[2] = (dvec2)this->_M[2];
    res[3] = (dvec2)this->_M[3];
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<4, 3, double>(void) const
{
    mat<4, 3, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    res[2] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[2].intrinEXT())); 
    res[3] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[3].intrinEXT())); 
    return res;
}
inline glm2::mat<4, 2, float>::operator glm2::mat<4, 4, double>(void) const
{
    mat<4, 4, double> res;
    res[0] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[0].intrinEXT()));
    res[1] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[1].intrinEXT()));  
    res[2] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[2].intrinEXT())); 
    res[3] = _mm256_castpd128_pd256(_mm_cvtps_pd(this->_M[3].intrinEXT())); 
    return res;
}

