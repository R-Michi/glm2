/**
* @file     dmat2x4_impl.inl
* @brief    Implamentation of convert operators, extended mathematical operators 
            and extended constructors of a 2x4 double matrix.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

inline glm2::mat<2, 4, double>::col_type glm2::mat<2, 4, double>::operator* (const row_type& v) const
{
    __m256d ymm0, ymm1;
    ymm0 = _mm256_broadcast_sd(row_type::value_ptr(v) + 0);
    ymm1 = _mm256_broadcast_sd(row_type::value_ptr(v) + 1);
    ymm0 = _mm256_mul_pd(ymm0, this->_M[0]());
    ymm0 = _mm256_fmadd_pd(ymm1, this->_M[1](), ymm0);
    return col_type(ymm0);
}

inline glm2::mat<2, 4, double> glm2::mat<2, 4, double>::operator* (const mat<2, 2, double>& M) const
{
    mat _M = *this;
    _M *= M;
    return _M;
}
inline glm2::mat<3, 4, double> glm2::mat<2, 4, double>::operator* (const mat<3, 2, double>& M) const
{
    mat<3, 4, double> res;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = this->_M[0]();
    ymm1 = this->_M[1]();
    ymm2 = _mm256_broadcast_sd(mat<3, 2, double>::value_ptr(M) + 0);
    ymm3 = _mm256_broadcast_sd(mat<3, 2, double>::value_ptr(M) + 1);
    ymm4 = _mm256_broadcast_sd(mat<3, 2, double>::value_ptr(M) + 2);
    ymm5 = _mm256_broadcast_sd(mat<3, 2, double>::value_ptr(M) + 3);
    ymm2 = _mm256_mul_pd(ymm2, ymm0);
    ymm2 = _mm256_fmadd_pd(ymm3, ymm1, ymm2);
    ymm3 = _mm256_mul_pd(ymm4, ymm0);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm1, ymm3);
    res[0] = ymm2;
    res[1] = ymm3;
    ymm2 = _mm256_broadcast_sd(mat<3, 2, double>::value_ptr(M) + 4);
    ymm3 = _mm256_broadcast_sd(mat<3, 2, double>::value_ptr(M) + 5);
    ymm0 = _mm256_mul_pd(ymm2, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm3, ymm1, ymm0);
    res[2] = ymm0;
    return res;
}
inline glm2::mat<4, 4, double> glm2::mat<2, 4, double>::operator* (const mat<4, 2, double>& M) const
{
    mat<4, 4, double> res;
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = this->_M[0]();
    ymm1 = this->_M[1]();
    ymm2 = _mm256_broadcast_sd(mat<4, 2, double>::value_ptr(M) + 0);
    ymm3 = _mm256_broadcast_sd(mat<4, 2, double>::value_ptr(M) + 1);
    ymm4 = _mm256_broadcast_sd(mat<4, 2, double>::value_ptr(M) + 2);
    ymm5 = _mm256_broadcast_sd(mat<4, 2, double>::value_ptr(M) + 3);
    ymm2 = _mm256_mul_pd(ymm2, ymm0);
    ymm2 = _mm256_fmadd_pd(ymm3, ymm1, ymm2);
    ymm3 = _mm256_mul_pd(ymm4, ymm0);
    ymm3 = _mm256_fmadd_pd(ymm5, ymm1, ymm3);
    res[0] = ymm2;
    res[1] = ymm3;
    ymm2 = _mm256_broadcast_sd(mat<4, 2, double>::value_ptr(M) + 4);
    ymm3 = _mm256_broadcast_sd(mat<4, 2, double>::value_ptr(M) + 5);
    ymm4 = _mm256_broadcast_sd(mat<4, 2, double>::value_ptr(M) + 6);
    ymm5 = _mm256_broadcast_sd(mat<4, 2, double>::value_ptr(M) + 7);
    ymm2 = _mm256_mul_pd(ymm2, ymm0);
    ymm2 = _mm256_fmadd_pd(ymm3, ymm1, ymm2);
    ymm0 = _mm256_mul_pd(ymm4, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm5, ymm1, ymm0);
    res[2] = ymm2;
    res[3] = ymm0;
    return res;
}

inline glm2::mat<2, 4, double>& glm2::mat<2, 4, double>::operator*= (const mat<2, 2, double>& M)
{
    __m256d ymm0, ymm1, ymm2, ymm3, ymm4, ymm5;
    ymm0 = this->_M[0]();
    ymm1 = this->_M[1]();
    ymm2 = _mm256_broadcast_sd(mat<2, 2, double>::value_ptr(M) + 0);
    ymm3 = _mm256_broadcast_sd(mat<2, 2, double>::value_ptr(M) + 1);
    ymm4 = _mm256_broadcast_sd(mat<2, 2, double>::value_ptr(M) + 2);
    ymm5 = _mm256_broadcast_sd(mat<2, 2, double>::value_ptr(M) + 3);
    ymm2 = _mm256_mul_pd(ymm2, ymm0);
    ymm2 = _mm256_fmadd_pd(ymm3, ymm1, ymm2);
    ymm0 = _mm256_mul_pd(ymm4, ymm0);
    ymm0 = _mm256_fmadd_pd(ymm5, ymm1, ymm0);
    this->_M[0] = ymm2;
    this->_M[1] = ymm0;
    return *this;
}

inline glm2::mat<2, 4, double>::operator glm2::mat<2, 2, float>(void) const
{
    mat<2, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<2, 3, float>(void) const
{
    mat<2, 3, float> res;
    res[0] = (vec3)this->_M[0];
    res[1] = (vec3)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<2, 4, float>(void) const
{
    mat<2, 4, float> res;
    res[0] = (vec4)this->_M[0];
    res[1] = (vec4)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<3, 2, float>(void) const
{   
    mat<3, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<3, 3, float>(void) const
{
    mat<3, 3, float> res;
    res[0] = (vec3)this->_M[0];
    res[1] = (vec3)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<3, 4, float>(void) const
{
    mat<3, 4, float> res;
    res[0] = (vec4)this->_M[0];
    res[1] = (vec4)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<4, 2, float>(void) const
{
    mat<4, 2, float> res;
    res[0] = (vec2)this->_M[0];
    res[1] = (vec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<4, 3, float>(void) const
{
    mat<4, 3, float> res;
    res[0] = (vec3)this->_M[0];
    res[1] = (vec3)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<4, 4, float>(void) const
{
    mat<4, 4, float> res;
    res[0] = (vec4)this->_M[0];
    res[1] = (vec4)this->_M[1];
    return res;
}

inline glm2::mat<2, 4, double>::operator glm2::mat<2, 2, double>(void) const
{
    mat<2, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<2, 3, double>(void) const
{   
    mat<2, 3, double> res;
    res[0] = (dvec3)this->_M[0];
    res[1] = (dvec3)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<3, 2, double>(void) const
{
    mat<3, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<3, 3, double>(void) const
{
    mat<3, 3, double> res;
    res[0] = (dvec3)this->_M[0];
    res[1] = (dvec3)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<3, 4, double>(void) const
{
    mat<3, 4, double> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<4, 2, double>(void) const
{
    mat<4, 2, double> res;
    res[0] = (dvec2)this->_M[0];
    res[1] = (dvec2)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<4, 3, double>(void) const
{
    mat<4, 3, double> res;
    res[0] = (dvec3)this->_M[0];
    res[1] = (dvec3)this->_M[1];
    return res;
}
inline glm2::mat<2, 4, double>::operator glm2::mat<4, 4, double>(void) const
{
    mat<4, 4, double> res;
    res[0] = this->_M[0];
    res[1] = this->_M[1];
    return res;
}
