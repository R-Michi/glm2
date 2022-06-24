/**
* @file     test.cpp
* @brief    All functions are tested here.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include "test.h"

#define DOUBLE_INFINITY ((double)(INFINITY))
#define DOUBLE_NAN ((double)(NAN))

//#define GLM2_TEST_VECTOR_ARITHMETIC_OPERATORS
//#define GLM2_TEST_VECTOR_CMP_OPERATORS
//#define GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_MAT2
//#define GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_MAT3
//#define GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_MAT4
//#define GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_DMAT2
//#define GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_DMAT3
//#define GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_DMAT4
//#define GLM2_TEST_MATRIX_CMP_OPERATORS
//#define GLM2_TEST_MATRIX_EXT_ARITHMETIC
//#define GLM2_TEST_COMMON
//#define GLM2_TEST_EXPONENTIAL
//#define GLM2_TEST_TRIGONOMETRIC
//#define GLM2_TEST_GEOMETRIC
//#define GLM2_TEST_MATRIX
#define GLM2_TEST_INTEGER
//#define GLM2_TEST_PACKING
//#define GLM2_TEST_VECTOR_RELATIONAL
//#define GLM2_TEST_MATRIX_TRANSFORMATION

namespace glm2
{
    namespace test
    {
        int count_true = 0, count_false = 0;
    }
}

float f1[5] = {
    1.69578f,
    -8.926f,
    -0.421f,
    0.5f
};
double d1[5] = {
    1.69578f,
    -8.926f,
    -0.421f,
    0.5f
};
int32_t i321[5] = {
    10,
    -10,
    0,
    -1265872039
};
uint32_t u321[5] = {
    10,
    4294967286, // -10
    0,
    3029095257
};
bool b1[3] = {
    true,
    false
};
float f2[5] = {
    1.69578f,
    -8.926f,
    -0.421f,
    0.5f
};
double d2[5] = {
    1.69578f,
    -8.926f,
    -0.421f,
    0.5f
};
int32_t i322[5] = {
    10,
    -10,
    0,
    -1265872039
};
uint32_t u322[5] = {
    10,
    4294967286, // -10
    0,
    3029095257
};
glm2::bool32_t b2[3] = {
    GLM2_TRUE,
    GLM2_FALSE
};

glm::vec2 v12f[5] = {
    {0.707f, -0.707f},
    {0.0f, 1.0f},
    {-3.5f, -4.8f},
    {0.5f, 0.6f}
};
glm::vec3 v13f[5] = {
    {0.577f, -0.577f, 0.577f},
    {0.0f, 1.0f, 0.0f},
    {-3.5f, -4.8f, 2.3f},
    {0.5f, 0.6f, 0.8f}
};
glm::vec4 v14f[5] = {
    {0.5f, -0.5f, 0.5f, -0.5f},
    {0.0f, 1.0f, 0.0f, 0.0f},
    {-3.5f, -4.8f, 2.3f, -6.1f},
    {0.5f, 0.6f, 0.8f, 0.2f}
};
glm::mat2x2 m122f[4] = {
    {1,2,  3,4},
    {5,6,  7,8},
    {8,9,  2,6}
};
glm::mat2x3 m123f[4] = {
    {1,2,3, 4,5,6},
    {7,8,9, 10,11,12}
};
glm::mat2x4 m124f[4] = {
    {1,2,3,4, 5,6,7,8},
    {9,10,11,12, 13,14,15,16}
};
glm::mat3x2 m132f[4] = {
    {1,2, 3,4, 5,6},
    {7,8, 9,10, 11,12}
};
glm::mat3x3 m133f[4] = {
    {1,2,3, 4,5,6, 7,8,9},
    {10,11,12, 13,14,15, 16,17,18},
    {0,1,2, 3,2,1, 1,1,0}
};
glm::mat3x4 m134f[4] = {
    {1,2,3,4, 5,6,7,8, 9,10,11,12},
    {13,14,15,16, 17,18,19,20, 21,22,23,24}
};
glm::mat4x2 m142f[4] = {
    {1,2, 3,4, 5,6, 7,8},
    {9,10, 11,12, 13,14, 15,16}
};
glm::mat4x3 m143f[4] = {
    {1,2,3, 4,5,6, 7,8,9, 10,11,12},
    {13,14,15, 16,17,18, 19,20,21, 22,23,24}
};
glm::mat4x4 m144f[4] = {
    {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16},
    {17,18,19,20, 21,22,23,24, 25,26,27,28, 29,30,31,32},
    {10,5,9,3, 7,11,6,6, 14,23,1,16, 0,17,21,3}
};
glm::dvec2 v12d[5] = {
    {0.707, -0.707},
    {0.0, 1.0},
    {-3.5, -4.8},
    {0.5, 0.6}
};
glm::dvec3 v13d[5] = {
    {0.577, -0.577, 0.577},
    {0.0, 1.0, 0.0},
    {-3.5, -4.8, 2.3},
    {0.5, 0.6, 0.8}
};
glm::dvec4 v14d[5] = {
    {0.5, -0.5, 0.5, -0.5},
    {0.0, 1.0, 0.0, 0.0},
    {-3.5, -4.8, 2.3, -6.1},
    {0.5, 0.6, 0.8, 0.2}
};
glm::dmat2x2 m122d[4] = {
    {1,2,  3,4},
    {5,6,  7,8},
    {8,9,  2,6}
};
glm::dmat2x3 m123d[4] = {
    {1,2,3, 4,5,6},
    {7,8,9, 10,11,12}
};
glm::dmat2x4 m124d[4] = {
    {1,2,3,4, 5,6,7,8},
    {9,10,11,12, 13,14,15,16}
};
glm::dmat3x2 m132d[4] = {
    {1,2, 3,4, 5,6},
    {7,8, 9,10, 11,12}
};
glm::dmat3x3 m133d[4] = {
    {1,2,3, 4,5,6, 7,8,9},
    {10,11,12, 13,14,15, 16,17,18},
    {0,1,2, 3,2,1, 1,1,0}
};
glm::dmat3x4 m134d[4] = {
    {1,2,3,4, 5,6,7,8, 9,10,11,12},
    {13,14,15,16, 17,18,19,20, 21,22,23,24}
};
glm::dmat4x2 m142d[4] = {
    {1,2, 3,4, 5,6, 7,8},
    {9,10, 11,12, 13,14, 15,16}
};
glm::dmat4x3 m143d[4] = {
    {1,2,3, 4,5,6, 7,8,9, 10,11,12},
    {13,14,15, 16,17,18, 19,20,21, 22,23,24}
};
glm::dmat4x4 m144d[4] = {
    {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16},
    {17,18,19,20, 21,22,23,24, 25,26,27,28, 29,30,31,32},
    {10,5,9,3, 7,11,6,6, 14,23,1,16, 0,17,21,3}
};
glm::ivec2 v12i32[5] = {
    {-10, 10},
    {0, 0},
    {-256, 4964265},
    {578895, -186962364}
};
glm::ivec3 v13i32[5] = {
    {-10, 10, -10},
    {0, 0, 0},
    {-256, 4964265, -95236},
    {578895, -186962364, 45856564}
};
glm::ivec4 v14i32[5] = {
    {-10, 10, -10, 10},
    {0, 0, 0, 0},
    {-256, 4964265, -95236, 844556564},
    {578895, -186962364, 45856564, -334564566}
};
glm::uvec2 v12u32[5] = {
    {4294967286, 10},
    {0, 0},
    {0xFFFFFF00, 4964265},
    {578895, 0xF4DB2E44}
};
glm::uvec3 v13u32[5] = {
    {4294967286, 10, 4294967286},
    {0, 0, 0},
    {0xFFFFFF00, 4964265, 0xFFF6ADCA},
    {578895, 0xF4DB2E44, 45856564}
};
glm::uvec4 v14u32[5] = {
    {4294967286, 10, 4294967286, 10},
    {0, 0, 0, 0},
    {0xFFFFFF00, 4964265, 0xFFF6ADCA, 844556564},
    {578895, 0xF4DB2E44, 45856564, 0xEC0EF32A}
};
glm::bvec2 v12b[5] = {
    {true, false},
    {true, true},
    {false, false}
};
glm::bvec3 v13b[5] = {
    {true, false, true},
    {true, true, true},
    {false, false, false}
};
glm::bvec4 v14b[5] = {
    {true, false, true, false},
    {true, true, true, true},
    {false, false, false, false}
};

glm2::vec2 v22f[5] = {
    {0.707f, -0.707f},
    {0.0f, 1.0f},
    {-3.5f, -4.8f},
    {0.5f, 0.6f}
};
glm2::vec3 v23f[5] = {
    {0.577f, -0.577f, 0.577f},
    {0.0f, 1.0f, 0.0f},
    {-3.5f, -4.8f, 2.3f},
    {0.5f, 0.6f, 0.8f}
};
glm2::vec4 v24f[5] = {
    {0.5f, -0.5f, 0.5f, -0.5f},
    {0.0f, 1.0f, 0.0f, 0.0f},
    {-3.5f, -4.8f, 2.3f, -6.1f},
    {0.5f, 0.6f, 0.8f, 0.2f}
};
glm2::mat2x2 m222f[4] = {
    {1,2,  3,4},
    {5,6,  7,8},
    {8,9,  2,6}
};
glm2::mat2x3 m223f[4] = {
    {1,2,3, 4,5,6},
    {7,8,9, 10,11,12}
};
glm2::mat2x4 m224f[4] = {
    {1,2,3,4, 5,6,7,8},
    {9,10,11,12, 13,14,15,16}
};
glm2::mat3x2 m232f[4] = {
    {1,2, 3,4, 5,6},
    {7,8, 9,10, 11,12}
};
glm2::mat3x3 m233f[4] = {
    {1,2,3, 4,5,6, 7,8,9},
    {10,11,12, 13,14,15, 16,17,18},
    {0,1,2, 3,2,1, 1,1,0}
};
glm2::mat3x4 m234f[4] = {
    {1,2,3,4, 5,6,7,8, 9,10,11,12},
    {13,14,15,16, 17,18,19,20, 21,22,23,24}
};
glm2::mat4x2 m242f[4] = {
    {1,2, 3,4, 5,6, 7,8},
    {9,10, 11,12, 13,14, 15,16}
};
glm2::mat4x3 m243f[4] = {
    {1,2,3, 4,5,6, 7,8,9, 10,11,12},
    {13,14,15, 16,17,18, 19,20,21, 22,23,24}
};
glm2::mat4x4 m244f[4] = {
    {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16},
    {17,18,19,20, 21,22,23,24, 25,26,27,28, 29,30,31,32},
    {10,5,9,3, 7,11,6,6, 14,23,1,16, 0,17,21,3}
};
glm2::dvec2 v22d[5] = {
    {0.707, -0.707},
    {0.0, 1.0},
    {-3.5, -4.8},
    {0.5, 0.6}
};
glm2::dvec3 v23d[5] = {
    {0.577, -0.577, 0.577},
    {0.0, 1.0, 0.0},
    {-3.5, -4.8, 2.3},
    {0.5, 0.6, 0.8}
};
glm2::dvec4 v24d[5] = {
    {0.5, -0.5, 0.5, -0.5},
    {0.0, 1.0, 0.0, 0.0},
    {-3.5, -4.8, 2.3, -6.1},
    {0.5, 0.6, 0.8, 0.2}
};
glm2::dmat2x2 m222d[4] = {
    {1,2,  3,4},
    {5,6,  7,8},
    {8,9,  2,6}
};
glm2::dmat2x3 m223d[4] = {
    {1,2,3, 4,5,6},
    {7,8,9, 10,11,12}
};
glm2::dmat2x4 m224d[4] = {
    {1,2,3,4, 5,6,7,8},
    {9,10,11,12, 13,14,15,16}
};
glm2::dmat3x2 m232d[4] = {
    {1,2, 3,4, 5,6},
    {7,8, 9,10, 11,12}
};
glm2::dmat3x3 m233d[4] = {
    {1,2,3, 4,5,6, 7,8,9},
    {10,11,12, 13,14,15, 16,17,18},
    {0,1,2, 3,2,1, 1,1,0}
};
glm2::dmat3x4 m234d[4] = {
    {1,2,3,4, 5,6,7,8, 9,10,11,12},
    {13,14,15,16, 17,18,19,20, 21,22,23,24}
};
glm2::dmat4x2 m242d[4] = {
    {1,2, 3,4, 5,6, 7,8},
    {9,10, 11,12, 13,14, 15,16}
};
glm2::dmat4x3 m243d[4] = {
    {1,2,3, 4,5,6, 7,8,9, 10,11,12},
    {13,14,15, 16,17,18, 19,20,21, 22,23,24}
};
glm2::dmat4x4 m244d[4] = {
    {1,2,3,4, 5,6,7,8, 9,10,11,12, 13,14,15,16},
    {17,18,19,20, 21,22,23,24, 25,26,27,28, 29,30,31,32},
    {10,5,9,3, 7,11,6,6, 14,23,1,16, 0,17,21,3}
};
glm2::ivec2 v22i32[5] = {
    {-10, 10},
    {0, 0},
    {-256, 4964265},
    {578895, -186962364}
};
glm2::ivec3 v23i32[5] = {
    {-10, 10, -10},
    {0, 0, 0},
    {-256, 4964265, -95236},
    {578895, -186962364, 45856564}
};
glm2::ivec4 v24i32[5] = {
    {-10, 10, -10, 10},
    {0, 0, 0, 0},
    {-256, 4964265, -95236, 844556564},
    {578895, -186962364, 45856564, -334564566}
};
glm2::uvec2 v22u32[5] = {
    {4294967286, 10},
    {0, 0},
    {0xFFFFFF00, 4964265},
    {578895, 0xF4DB2E44}
};
glm2::uvec3 v23u32[5] = {
    {4294967286, 10, 4294967286},
    {0, 0, 0},
    {0xFFFFFF00, 4964265, 0xFFF6ADCA},
    {578895, 0xF4DB2E44, 45856564}
};
glm2::uvec4 v24u32[5] = {
    {4294967286, 10, 4294967286, 10},
    {0, 0, 0, 0},
    {0xFFFFFF00, 4964265, 0xFFF6ADCA, 844556564},
    {578895, 0xF4DB2E44, 45856564, 0xEC0EF32A}
};
glm2::bvec2 v22b[5] = {
    {GLM2_TRUE, GLM2_FALSE},
    {GLM2_TRUE, GLM2_TRUE},
    {GLM2_FALSE, GLM2_FALSE}
};
glm2::bvec3 v23b[5] = {
    {GLM2_TRUE, GLM2_FALSE, GLM2_TRUE},
    {GLM2_TRUE, GLM2_TRUE, GLM2_TRUE},
    {GLM2_FALSE, GLM2_FALSE, GLM2_FALSE}
};
glm2::bvec4 v24b[5] = {
    {GLM2_TRUE, GLM2_FALSE, GLM2_TRUE, GLM2_FALSE},
    {GLM2_TRUE, GLM2_TRUE, GLM2_TRUE, GLM2_TRUE},
    {GLM2_FALSE, GLM2_FALSE, GLM2_FALSE, GLM2_FALSE}
};

void glm2::test::run_test(void)
{

    // ================== TEST LOAD VECTOR ==================
    float arr_src_f[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    float arr_dst_f[16];
    double arr_src_d[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    double arr_dst_d[16];
    int32_t arr_src_i[4] = {1, 2, 3, 4};
    int32_t arr_dst_i[4];

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    vec2 v2f_dst;
    v2f_dst.load(arr_src_f);
    v2f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    vec3 v3f_dst;
    v3f_dst.load(arr_src_f);
    v3f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    vec4 v4f_dst;
    v4f_dst.load(arr_src_f);
    v4f_dst.store(arr_dst_f);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dvec2 v2d_dst;
    v2d_dst.load(arr_src_d);
    v2d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dvec3 v3d_dst;
    v3d_dst.load(arr_src_d);
    v3d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dvec4 v4d_dst;
    v4d_dst.load(arr_src_d);
    v4d_dst.store(arr_dst_d);

    memset(arr_dst_i, 0, sizeof(arr_dst_i));
    ivec2 v2i_dst;
    v2i_dst.load(arr_src_i);
    v2i_dst.store(arr_dst_i);

    ivec3 v3i_dst;
    v3i_dst.load(arr_src_i);
    v3i_dst.store(arr_dst_i);

    ivec4 v4i_dst;
    v4i_dst.load(arr_src_i);
    v4i_dst.store(arr_dst_i);

    // ================== TEST LOAD MATRIX ==================

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    mat2x2 m22f_dst;
    m22f_dst.load(arr_src_f);
    m22f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    mat2x3 m23f_dst;
    m23f_dst.load(arr_src_f);
    m23f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    mat2x4 m24f_dst;
    m24f_dst.load(arr_src_f);
    m24f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    mat3x2 m32f_dst;
    m32f_dst.load(arr_src_f);
    m32f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    mat3x3 m33f_dst;
    m33f_dst.load(arr_src_f);
    m33f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    mat3x4 m34f_dst;
    m34f_dst.load(arr_src_f);
    m34f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    mat4x2 m42f_dst;
    m42f_dst.load(arr_src_f);
    m42f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    mat4x3 m43f_dst;
    m43f_dst.load(arr_src_f);
    m43f_dst.store(arr_dst_f);

    memset(arr_dst_f, 0, sizeof(arr_dst_f));
    mat4x4 m44f_dst;
    m44f_dst.load(arr_src_f);
    m44f_dst.store(arr_dst_f);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dmat2x2 m22d_dst;
    m22d_dst.load(arr_src_d);
    m22d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dmat2x3 m23d_dst;
    m23d_dst.load(arr_src_d);
    m23d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dmat2x4 m24d_dst;
    m24d_dst.load(arr_src_d);
    m24d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dmat3x2 m32d_dst;
    m32d_dst.load(arr_src_d);
    m32d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dmat3x3 m33d_dst;
    m33d_dst.load(arr_src_d);
    m33d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dmat3x4 m34d_dst;
    m34d_dst.load(arr_src_d);
    m34d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dmat4x2 m42d_dst;
    m42d_dst.load(arr_src_d);
    m42d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dmat4x3 m43d_dst;
    m43d_dst.load(arr_src_d);
    m43d_dst.store(arr_dst_d);

    memset(arr_dst_d, 0, sizeof(arr_dst_d));
    dmat4x4 m44d_dst;
    m44d_dst.load(arr_src_d);
    m44d_dst.store(arr_dst_d);


#ifdef GLM2_TEST_VECTOR_ARITHMETIC_OPERATORS
    // vec2
    {
        glm::vec2 tmp1; vec2 tmp2;
        print_vec<2, float>((v12f[0] + f1[0]), (v22f[0] + f2[0]), "vec2 adds");
        print_vec<2, float>((v12f[0] - f1[0]), (v22f[0] - f2[0]), "vec2 subs");
        print_vec<2, float>((v12f[0] * f1[0]), (v22f[0] * f2[0]), "vec2 muls");
        print_vec<2, float>((v12f[0] / f1[0]), (v22f[0] / f2[0]), "vec2 divs");
        print_vec<2, float>((v12f[0] + v12f[3]), (v22f[0] + v22f[3]), "vec2 addv");
        print_vec<2, float>((v12f[0] - v12f[3]), (v22f[0] - v22f[3]), "vec2 subv");
        print_vec<2, float>((v12f[0] * v12f[3]), (v22f[0] * v22f[3]), "vec2 mulv");
        print_vec<2, float>((v12f[0] / v12f[3]), (v22f[0] / v22f[3]), "vec2 divv");
        print_vec<2, float>((+v12f[0]), (+v22f[0]), "vec2 pos");
        print_vec<2, float>((-v12f[0]), (-v22f[0]), "vec2 neg");
        tmp1 = v12f[0];
        tmp2 = v22f[0];
        v12f[4] = ++tmp1;
        v22f[4] = ++tmp2;
        print_vec<2, float>(v12f[4], v22f[4], "vec2 preinc_res");
        print_vec<2, float>(tmp1, tmp2, "vec2 preinc_param");
        tmp1 = v12f[0];
        tmp2 = v22f[0];
        v12f[4] = tmp1++;
        v22f[4] = tmp2++;
        print_vec<2, float>(v12f[4], v22f[4], "vec2 postinc_res");
        print_vec<2, float>(tmp1, tmp2, "vec2 postinc_param");
        tmp1 = v12f[0];
        tmp2 = v22f[0];
        v12f[4] = --tmp1;
        v22f[4] = --tmp2;
        print_vec<2, float>(v12f[4], v22f[4], "vec2 predec_res");
        print_vec<2, float>(tmp1, tmp2, "vec2 predec_param");
        tmp1 = v12f[0];
        tmp2 = v22f[0];
        v12f[4] = tmp1--;
        v22f[4] = tmp2--;
        print_vec<2, float>(v12f[4], v22f[4], "vec2 postdec_res");
        print_vec<2, float>(tmp1, tmp2, "vec2 postdec_param");
    }

    // vec3
    {
        glm::vec3 tmp1; vec3 tmp2;
        print_vec<3, float>((v13f[0] + f1[0]), (v23f[0] + f2[0]), "vec3 adds");
        print_vec<3, float>((v13f[0] - f1[0]), (v23f[0] - f2[0]), "vec3 subs");
        print_vec<3, float>((v13f[0] * f1[0]), (v23f[0] * f2[0]), "vec3 muls");
        print_vec<3, float>((v13f[0] / f1[0]), (v23f[0] / f2[0]), "vec3 divs");
        print_vec<3, float>((v13f[0] + v13f[3]), (v23f[0] + v23f[3]), "vec3 addv");
        print_vec<3, float>((v13f[0] - v13f[3]), (v23f[0] - v23f[3]), "vec3 subv");
        print_vec<3, float>((v13f[0] * v13f[3]), (v23f[0] * v23f[3]), "vec3 mulv");
        print_vec<3, float>((v13f[0] / v13f[3]), (v23f[0] / v23f[3]), "vec3 divv");
        print_vec<3, float>((+v13f[0]), (+v23f[0]), "vec3 pos");
        print_vec<3, float>((-v13f[0]), (-v23f[0]), "vec3 neg");
        tmp1 = v13f[0];
        tmp2 = v23f[0];
        v13f[4] = ++tmp1;
        v23f[4] = ++tmp2;
        print_vec<3, float>(v13f[4], v23f[4], "vec3 preinc_res");
        print_vec<3, float>(tmp1, tmp2, "vec3 preinc_param");
        tmp1 = v13f[0];
        tmp2 = v23f[0];
        v13f[4] = tmp1++;
        v23f[4] = tmp2++;
        print_vec<3, float>(v13f[4], v23f[4], "vec3 postinc_res");
        print_vec<3, float>(tmp1, tmp2, "vec3 postinc_param");
        tmp1 = v13f[0];
        tmp2 = v23f[0];
        v13f[4] = --tmp1;
        v23f[4] = --tmp2;
        print_vec<3, float>(v13f[4], v23f[4], "vec3 predec_res");
        print_vec<3, float>(tmp1, tmp2, "vec3 predec_param");
        tmp1 = v13f[0];
        tmp2 = v23f[0];
        v13f[4] = tmp1--;
        v23f[4] = tmp2--;
        print_vec<3, float>(v13f[4], v23f[4], "vec3 postdec_res");
        print_vec<3, float>(tmp1, tmp2, "vec3 postdec_param");
    }

    // vec4
    {
        glm::vec4 tmp1; vec4 tmp2;
        print_vec<4, float>((v14f[0] + f1[0]), (v24f[0] + f2[0]), "vec4 adds");
        print_vec<4, float>((v14f[0] - f1[0]), (v24f[0] - f2[0]), "vec4 subs");
        print_vec<4, float>((v14f[0] * f1[0]), (v24f[0] * f2[0]), "vec4 muls");
        print_vec<4, float>((v14f[0] / f1[0]), (v24f[0] / f2[0]), "vec4 divs");
        print_vec<4, float>((v14f[0] + v14f[3]), (v24f[0] + v24f[3]), "vec4 addv");
        print_vec<4, float>((v14f[0] - v14f[3]), (v24f[0] - v24f[3]), "vec4 subv");
        print_vec<4, float>((v14f[0] * v14f[3]), (v24f[0] * v24f[3]), "vec4 mulv");
        print_vec<4, float>((v14f[0] / v14f[3]), (v24f[0] / v24f[3]), "vec4 divv");
        print_vec<4, float>((+v14f[0]), (+v24f[0]), "vec4 pos");
        print_vec<4, float>((-v14f[0]), (-v24f[0]), "vec4 neg");
        tmp1 = v14f[0];
        tmp2 = v24f[0];
        v14f[4] = ++tmp1;
        v24f[4] = ++tmp2;
        print_vec<4, float>(v14f[4], v24f[4], "vec4 preinc_res");
        print_vec<4, float>(tmp1, tmp2, "vec4 preinc_param");
        tmp1 = v14f[0];
        tmp2 = v24f[0];
        v14f[4] = tmp1++;
        v24f[4] = tmp2++;
        print_vec<4, float>(v14f[4], v24f[4], "vec4 postinc_res");
        print_vec<4, float>(tmp1, tmp2, "vec4 postinc_param");
        tmp1 = v14f[0];
        tmp2 = v24f[0];
        v14f[4] = --tmp1;
        v24f[4] = --tmp2;
        print_vec<4, float>(v14f[4], v24f[4], "vec4 predec_res");
        print_vec<4, float>(tmp1, tmp2, "vec4 predec_param");
        tmp1 = v14f[0];
        tmp2 = v24f[0];
        v14f[4] = tmp1--;
        v24f[4] = tmp2--;
        print_vec<4, float>(v14f[4], v24f[4], "vec4 postdec_res");
        print_vec<4, float>(tmp1, tmp2, "vec4 postdec_param");
    }

    // dvec2
    {
        glm::dvec2 tmp1; dvec2 tmp2;
        print_vec<2, double>((v12d[0] + d1[0]), (v22d[0] + d2[0]), "dvec2 adds");
        print_vec<2, double>((v12d[0] - d1[0]), (v22d[0] - d2[0]), "dvec2 subs");
        print_vec<2, double>((v12d[0] * d1[0]), (v22d[0] * d2[0]), "dvec2 muls");
        print_vec<2, double>((v12d[0] / d1[0]), (v22d[0] / d2[0]), "dvec2 divs");
        print_vec<2, double>((v12d[0] + v12d[3]), (v22d[0] + v22d[3]), "dvec2 addv");
        print_vec<2, double>((v12d[0] - v12d[3]), (v22d[0] - v22d[3]), "dvec2 subv");
        print_vec<2, double>((v12d[0] * v12d[3]), (v22d[0] * v22d[3]), "dvec2 mulv");
        print_vec<2, double>((v12d[0] / v12d[3]), (v22d[0] / v22d[3]), "dvec2 divv");
        print_vec<2, double>((+v12d[0]), (+v22d[0]), "dvec2 pos");
        print_vec<2, double>((-v12d[0]), (-v22d[0]), "dvec2 neg");
        tmp1 = v12d[0];
        tmp2 = v22d[0];
        v12d[4] = ++tmp1;
        v22d[4] = ++tmp2;
        print_vec<2, double>(v12d[4], v22d[4], "dvec2 preinc_res");
        print_vec<2, double>(tmp1, tmp2, "dvec2 preinc_param");
        tmp1 = v12d[0];
        tmp2 = v22d[0];
        v12d[4] = tmp1++;
        v22d[4] = tmp2++;
        print_vec<2, double>(v12d[4], v22d[4], "dvec2 postinc_res");
        print_vec<2, double>(tmp1, tmp2, "dvec2 postinc_param");
        tmp1 = v12d[0];
        tmp2 = v22d[0];
        v12d[4] = --tmp1;
        v22d[4] = --tmp2;
        print_vec<2, double>(v12d[4], v22d[4], "dvec2 predec_res");
        print_vec<2, double>(tmp1, tmp2, "dvec2 predec_param");
        tmp1 = v12d[0];
        tmp2 = v22d[0];
        v12d[4] = tmp1--;
        v22d[4] = tmp2--;
        print_vec<2, double>(v12d[4], v22d[4], "dvec2 postdec_res");
        print_vec<2, double>(tmp1, tmp2, "dvec2 postdec_param");
    }

    // dvec3
    {
        glm::dvec3 tmp1; dvec3 tmp2;
        print_vec<2, double>((v13d[0] + d1[0]), (v23d[0] + d2[0]), "dvec3 adds");
        print_vec<2, double>((v13d[0] - d1[0]), (v23d[0] - d2[0]), "dvec3 subs");
        print_vec<2, double>((v13d[0] * d1[0]), (v23d[0] * d2[0]), "dvec3 muls");
        print_vec<2, double>((v13d[0] / d1[0]), (v23d[0] / d2[0]), "dvec3 divs");
        print_vec<2, double>((v13d[0] + v13d[3]), (v23d[0] + v23d[3]), "dvec3 addv");
        print_vec<2, double>((v13d[0] - v13d[3]), (v23d[0] - v23d[3]), "dvec3 subv");
        print_vec<2, double>((v13d[0] * v13d[3]), (v23d[0] * v23d[3]), "dvec3 mulv");
        print_vec<2, double>((v13d[0] / v13d[3]), (v23d[0] / v23d[3]), "dvec3 divv");
        print_vec<2, double>((-v13d[0]), (-v23d[0]), "dvec3 neg");
        print_vec<2, double>((+v13d[0]), (+v23d[0]), "dvec3 pos");
        tmp1 = v13d[0];
        tmp2 = v23d[0];
        v13d[4] = ++tmp1;
        v23d[4] = ++tmp2;
        print_vec<2, double>(v13d[4], v23d[4], "dvec3 preinc_res");
        print_vec<2, double>(tmp1, tmp2, "dvec3 preinc_param");
        tmp1 = v13d[0];
        tmp2 = v23d[0];
        v13d[4] = tmp1++;
        v23d[4] = tmp2++;
        print_vec<2, double>(v13d[4], v23d[4], "dvec3 postinc_res");
        print_vec<2, double>(tmp1, tmp2, "dvec3 postinc_param");
        tmp1 = v13d[0];
        tmp2 = v23d[0];
        v13d[4] = --tmp1;
        v23d[4] = --tmp2;
        print_vec<2, double>(v13d[4], v23d[4], "dvec3 predec_res");
        print_vec<2, double>(tmp1, tmp2, "dvec3 predec_param");
        tmp1 = v13d[0];
        tmp2 = v23d[0];
        v13d[4] = tmp1--;
        v23d[4] = tmp2--;
        print_vec<2, double>(v13d[4], v23d[4], "dvec3 postdec_res");
        print_vec<2, double>(tmp1, tmp2, "dvec3 postdec_param");
    }

    // dvec4
    {
        glm::dvec4 tmp1; dvec4 tmp2;
        print_vec<2, double>((v14d[0] + d1[0]), (v24d[0] + d2[0]), "dvec4 adds");
        print_vec<2, double>((v14d[0] - d1[0]), (v24d[0] - d2[0]), "dvec4 subs");
        print_vec<2, double>((v14d[0] * d1[0]), (v24d[0] * d2[0]), "dvec4 muls");
        print_vec<2, double>((v14d[0] / d1[0]), (v24d[0] / d2[0]), "dvec4 divs");
        print_vec<2, double>((v14d[0] + v14d[3]), (v24d[0] + v24d[3]), "dvec4 addv");
        print_vec<2, double>((v14d[0] - v14d[3]), (v24d[0] - v24d[3]), "dvec4 subv");
        print_vec<2, double>((v14d[0] * v14d[3]), (v24d[0] * v24d[3]), "dvec4 mulv");
        print_vec<2, double>((v14d[0] / v14d[3]), (v24d[0] / v24d[3]), "dvec4 divv");
        print_vec<2, double>((+v14d[0]), (+v24d[0]), "dvec4 pos");
        print_vec<2, double>((-v14d[0]), (-v24d[0]), "dvec4 neg");
        tmp1 = v14d[0];
        tmp2 = v24d[0];
        v14d[4] = ++tmp1;
        v24d[4] = ++tmp2;
        print_vec<2, double>(v14d[4], v24d[4], "dvec4 preinc_res");
        print_vec<2, double>(tmp1, tmp2, "dvec4 preinc_param");
        tmp1 = v14d[0];
        tmp2 = v24d[0];
        v14d[4] = tmp1++;
        v24d[4] = tmp2++;
        print_vec<2, double>(v14d[4], v24d[4], "dvec4 postinc_res");
        print_vec<2, double>(tmp1, tmp2, "dvec4 postinc_param");
        tmp1 = v14d[0];
        tmp2 = v24d[0];
        v14d[4] = --tmp1;
        v24d[4] = --tmp2;
        print_vec<2, double>(v14d[4], v24d[4], "dvec4 predec_res");
        print_vec<2, double>(tmp1, tmp2, "dvec4 predec_param");
        tmp1 = v14d[0];
        tmp2 = v24d[0];
        v14d[4] = tmp1--;
        v24d[4] = tmp2--;
        print_vec<2, double>(v14d[4], v24d[4], "dvec4 postdec_res");
        print_vec<2, double>(tmp1, tmp2, "dvec4 postdec_param");
    }

    // ivec2
    {
        glm::ivec2 tmp1; ivec2 tmp2;
        print_vec<2, int32_t>((v12i32[0] + i321[0]), (v22i32[0] + i322[0]), "ivec2 adds");
        print_vec<2, int32_t>((v12i32[0] - i321[0]), (v22i32[0] - i322[0]), "ivec2 subs");
        print_vec<2, int32_t>((v12i32[0] * i321[0]), (v22i32[0] * i322[0]), "ivec2 muls");
        print_vec<2, int32_t>((v12i32[0] / i321[0]), (v22i32[0] / i322[0]), "ivec2 divs");
        print_vec<2, int32_t>((v12i32[2] % i321[0]), (v22i32[2] % i322[0]), "ivec2 mods");
        print_vec<2, int32_t>((v12i32[0] + v12i32[3]), (v22i32[0] + v22i32[3]), "ivec2 addv");
        print_vec<2, int32_t>((v12i32[0] - v12i32[3]), (v22i32[0] - v22i32[3]), "ivec2 subv");
        print_vec<2, int32_t>((v12i32[0] * v12i32[3]), (v22i32[0] * v22i32[3]), "ivec2 mulv");
        print_vec<2, int32_t>((v12i32[0] / v12i32[3]), (v22i32[0] / v22i32[3]), "ivec2 divv");
        print_vec<2, int32_t>((v12i32[0] % v12i32[3]), (v22i32[0] % v22i32[3]), "ivec2 modv");
        print_vec<2, int32_t>((+v12i32[0]), (+v22i32[0]), "ivec2 pos");
        print_vec<2, int32_t>((-v12i32[0]), (-v22i32[0]), "ivec2 neg");
        tmp1 = v12i32[0];
        tmp2 = v22i32[0];
        v12i32[4] = ++tmp1;
        v22i32[4] = ++tmp2;
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 preinc_res");
        print_vec<2, int32_t>(tmp1, tmp2, "ivec2 preinc_param");
        tmp1 = v12i32[0];
        tmp2 = v22i32[0];
        v12i32[4] = tmp1++;
        v22i32[4] = tmp2++;
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 postinc_res");
        print_vec<2, int32_t>(tmp1, tmp2, "ivec2 postinc_param");
        tmp1 = v12i32[0];
        tmp2 = v22i32[0];
        v12i32[4] = --tmp1;
        v22i32[4] = --tmp2;
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 predec_res");
        print_vec<2, int32_t>(tmp1, tmp2, "ivec2 predec_param");
        tmp1 = v12i32[0];
        tmp2 = v22i32[0];
        v12i32[4] = tmp1--;
        v22i32[4] = tmp2--;
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 postdec_res");
        print_vec<2, int32_t>(tmp1, tmp2, "ivec2 postdec_param");
        print_vec<2, int32_t>((~v12i32[0]), (~v22i32[0]), "ivec2 invert");
        print_vec<2, int32_t>((v12i32[0] & i321[1]), (v22i32[0] & i322[1]), "ivec2 ands");
        print_vec<2, int32_t>((v12i32[0] | i321[1]), (v22i32[0] | i322[1]), "ivec2 ors");
        print_vec<2, int32_t>((v12i32[0] ^ i321[1]), (v22i32[0] ^ i322[1]), "ivec2 xors");
        print_vec<2, int32_t>((v12i32[0] << 12), (v22i32[0] << 12), "ivec2 lss");
        print_vec<2, int32_t>((v12i32[0] >> 12), (v22i32[0] >> 12), "ivec2 rss");
        print_vec<2, int32_t>((v12i32[0] & v12i32[2]), (v22i32[0] & v22i32[2]), "ivec2 andv");
        print_vec<2, int32_t>((v12i32[0] | v12i32[2]), (v22i32[0] | v22i32[2]), "ivec2 orv");
        print_vec<2, int32_t>((v12i32[0] ^ v12i32[2]), (v22i32[0] ^ v22i32[2]), "ivec2 xorv");
        print_vec<2, int32_t>((v12i32[0] << glm::ivec2(2, 4)), (v22i32[0] << glm2::ivec2(2, 4)), "ivec2 lsv");
        print_vec<2, int32_t>((v12i32[0] >> glm::ivec2(2, 4)), (v22i32[0] >> glm2::ivec2(2, 4)), "ivec2 rsv");
    }

    // ivec3
    {
        glm::ivec3 tmp1; ivec3 tmp2;
        print_vec<3, int32_t>((v13i32[0] + i321[0]), (v23i32[0] + i322[0]), "ivec3 adds");
        print_vec<3, int32_t>((v13i32[0] - i321[0]), (v23i32[0] - i322[0]), "ivec3 subs");
        print_vec<3, int32_t>((v13i32[0] * i321[0]), (v23i32[0] * i322[0]), "ivec3 muls");
        print_vec<3, int32_t>((v13i32[0] / i321[0]), (v23i32[0] / i322[0]), "ivec3 divs");
        print_vec<3, int32_t>((v13i32[2] % i321[0]), (v23i32[2] % i322[0]), "ivec3 mods");
        print_vec<3, int32_t>((v13i32[0] + v13i32[3]), (v23i32[0] + v23i32[3]), "ivec3 addv");
        print_vec<3, int32_t>((v13i32[0] - v13i32[3]), (v23i32[0] - v23i32[3]), "ivec3 subv");
        print_vec<3, int32_t>((v13i32[0] * v13i32[3]), (v23i32[0] * v23i32[3]), "ivec3 mulv");
        print_vec<3, int32_t>((v13i32[0] / v13i32[3]), (v23i32[0] / v23i32[3]), "ivec3 divv");
        print_vec<3, int32_t>((v13i32[0] % v13i32[3]), (v23i32[0] % v23i32[3]), "ivec3 modv");
        print_vec<3, int32_t>((+v13i32[0]), (+v23i32[0]), "ivec3 pos");
        print_vec<3, int32_t>((-v13i32[0]), (-v23i32[0]), "ivec3 neg");
        tmp1 = v13i32[0];
        tmp2 = v23i32[0];
        v13i32[4] = ++tmp1;
        v23i32[4] = ++tmp2;
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 preinc_res");
        print_vec<3, int32_t>(tmp1, tmp2, "ivec3 preinc_param");
        tmp1 = v13i32[0];
        tmp2 = v23i32[0];
        v13i32[4] = tmp1++;
        v23i32[4] = tmp2++;
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 postinc_res");
        print_vec<3, int32_t>(tmp1, tmp2, "ivec3 postinc_param");
        tmp1 = v13i32[0];
        tmp2 = v23i32[0];
        v13i32[4] = --tmp1;
        v23i32[4] = --tmp2;
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 predec_res");
        print_vec<3, int32_t>(tmp1, tmp2, "ivec3 predec_param");
        tmp1 = v13i32[0];
        tmp2 = v23i32[0];
        v13i32[4] = tmp1--;
        v23i32[4] = tmp2--;
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 postdec_res");
        print_vec<3, int32_t>(tmp1, tmp2, "ivec3 postdec_param");
        print_vec<3, int32_t>((~v13i32[0]), (~v23i32[0]), "ivec3 invert");
        print_vec<3, int32_t>((v13i32[0] & i321[1]), (v23i32[0] & i322[1]), "ivec3 ands");
        print_vec<3, int32_t>((v13i32[0] | i321[1]), (v23i32[0] | i322[1]), "ivec3 ors");
        print_vec<3, int32_t>((v13i32[0] ^ i321[1]), (v23i32[0] ^ i322[1]), "ivec3 xors");
        print_vec<3, int32_t>((v13i32[0] << 12), (v23i32[0] << 12), "ivec3 lss");
        print_vec<3, int32_t>((v13i32[0] >> 12), (v23i32[0] >> 12), "ivec3 rss");
        print_vec<3, int32_t>((v13i32[0] & v13i32[2]), (v23i32[0] & v23i32[2]), "ivec3 andv");
        print_vec<3, int32_t>((v13i32[0] | v13i32[2]), (v23i32[0] | v23i32[2]), "ivec3 orv");
        print_vec<3, int32_t>((v13i32[0] ^ v13i32[2]), (v23i32[0] ^ v23i32[2]), "ivec3 xorv");
        print_vec<3, int32_t>((v13i32[0] << glm::ivec3(2, 4, 8)), (v23i32[0] << glm2::ivec3(2, 4, 8)), "ivec3 lsv");
        print_vec<3, int32_t>((v13i32[0] >> glm::ivec3(2, 4, 8)), (v23i32[0] >> glm2::ivec3(2, 4, 8)), "ivec3 rsv");
    }

    // ivec4
    {
        glm::ivec4 tmp1; ivec4 tmp2;
        print_vec<4, int32_t>((v14i32[0] + i321[0]), (v24i32[0] + i322[0]), "ivec4 adds");
        print_vec<4, int32_t>((v14i32[0] - i321[0]), (v24i32[0] - i322[0]), "ivec4 subs");
        print_vec<4, int32_t>((v14i32[0] * i321[0]), (v24i32[0] * i322[0]), "ivec4 muls");
        print_vec<4, int32_t>((v14i32[0] / i321[0]), (v24i32[0] / i322[0]), "ivec4 divs");
        print_vec<4, int32_t>((v14i32[2] % i321[0]), (v24i32[2] % i322[0]), "ivec4 mods");
        print_vec<4, int32_t>((v14i32[0] + v14i32[3]), (v24i32[0] + v24i32[3]), "ivec4 addv");
        print_vec<4, int32_t>((v14i32[0] - v14i32[3]), (v24i32[0] - v24i32[3]), "ivec4 subv");
        print_vec<4, int32_t>((v14i32[0] * v14i32[3]), (v24i32[0] * v24i32[3]), "ivec4 mulv");
        print_vec<4, int32_t>((v14i32[0] / v14i32[3]), (v24i32[0] / v24i32[3]), "ivec4 divv");
        print_vec<4, int32_t>((v14i32[0] % v14i32[3]), (v24i32[0] % v24i32[3]), "ivec4 modv");
        print_vec<4, int32_t>((+v14i32[0]), (+v24i32[0]), "ivec4 pos");
        print_vec<4, int32_t>((-v14i32[0]), (-v24i32[0]), "ivec4 neg");
        tmp1 = v14i32[0];
        tmp2 = v24i32[0];
        v14i32[4] = ++tmp1;
        v24i32[4] = ++tmp2;
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 preinc_res");
        print_vec<4, int32_t>(tmp1, tmp2, "ivec4 preinc_param");
        tmp1 = v14i32[0];
        tmp2 = v24i32[0];
        v14i32[4] = tmp1++;
        v24i32[4] = tmp2++;
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 postinc_res");
        print_vec<4, int32_t>(tmp1, tmp2, "ivec4 postinc_param");
        tmp1 = v14i32[0];
        tmp2 = v24i32[0];
        v14i32[4] = --tmp1;
        v24i32[4] = --tmp2;
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 predec_res");
        print_vec<4, int32_t>(tmp1, tmp2, "ivec4 predec_param");
        tmp1 = v14i32[0];
        tmp2 = v24i32[0];
        v14i32[4] = tmp1--;
        v24i32[4] = tmp2--;
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 postdec_res");
        print_vec<4, int32_t>(tmp1, tmp2, "ivec4 postdec_param");
        print_vec<4, int32_t>((~v14i32[0]), (~v24i32[0]), "ivec4 invert");
        print_vec<4, int32_t>((v14i32[0] & i321[1]), (v24i32[0] & i322[1]), "ivec4 ands");
        print_vec<4, int32_t>((v14i32[0] | i321[1]), (v24i32[0] | i322[1]), "ivec4 ors");
        print_vec<4, int32_t>((v14i32[0] ^ i321[1]), (v24i32[0] ^ i322[1]), "ivec4 xors");
        print_vec<4, int32_t>((v14i32[0] << 12), (v24i32[0] << 12), "ivec4 lss");
        print_vec<4, int32_t>((v14i32[0] >> 12), (v24i32[0] >> 12), "ivec4 rss");
        print_vec<4, int32_t>((v14i32[0] & v14i32[2]), (v24i32[0] & v24i32[2]), "ivec4 andv");
        print_vec<4, int32_t>((v14i32[0] | v14i32[2]), (v24i32[0] | v24i32[2]), "ivec4 orv");
        print_vec<4, int32_t>((v14i32[0] ^ v14i32[2]), (v24i32[0] ^ v24i32[2]), "ivec4 xorv");
        print_vec<4, int32_t>((v14i32[0] << glm::ivec4(2, 4, 8, 16)), (v24i32[0] << glm2::ivec4(2, 4, 8, 16)), "ivec4 lsv");
        print_vec<4, int32_t>((v14i32[0] >> glm::ivec4(2, 4, 8, 16)), (v24i32[0] >> glm2::ivec4(2, 4, 8, 16)), "ivec4 rsv");
    }

    // uvec2
    {
        glm::uvec2 tmp1; uvec2 tmp2;
        print_vec<2, uint32_t>((v12u32[0] + u321[0]), (v22u32[0] + u322[0]), "uvec2 adds");
        print_vec<2, uint32_t>((v12u32[0] - u321[0]), (v22u32[0] - u322[0]), "uvec2 subs");
        print_vec<2, uint32_t>((v12u32[0] * u321[0]), (v22u32[0] * u322[0]), "uvec2 muls");
        print_vec<2, uint32_t>((v12u32[0] / u321[0]), (v22u32[0] / u322[0]), "uvec2 divs");
        print_vec<2, uint32_t>((v12u32[0] % u321[0]), (v22u32[0] % u322[0]), "uvec2 mods");
        print_vec<2, uint32_t>((v12u32[0] + v12u32[3]), (v22u32[0] + v22u32[3]), "uvec2 addv");
        print_vec<2, uint32_t>((v12u32[0] - v12u32[3]), (v22u32[0] - v22u32[3]), "uvec2 subv");
        print_vec<2, uint32_t>((v12u32[0] * v12u32[3]), (v22u32[0] * v22u32[3]), "uvec2 mulv");
        print_vec<2, uint32_t>((v12u32[0] / v12u32[3]), (v22u32[0] / v22u32[3]), "uvec2 divv");
        print_vec<2, uint32_t>((v12u32[0] % v12u32[3]), (v22u32[0] % v22u32[3]), "uvec2 modv");
        print_vec<2, uint32_t>((+v12u32[0]), (+v22u32[0]), "uvec2 pos");
        print_vec<2, uint32_t>((-v12u32[0]), (-v22u32[0]), "uvec2 neg");
        tmp1 = v12u32[0];
        tmp2 = v22u32[0];
        v12u32[4] = ++tmp1;
        v22u32[4] = ++tmp2;
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 preinc_res");
        print_vec<2, uint32_t>(tmp1, tmp2, "uvec2 preinc_param");
        tmp1 = v12u32[0];
        tmp2 = v22u32[0];
        v12u32[4] = tmp1++;
        v22u32[4] = tmp2++;
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 postinc_res");
        print_vec<2, uint32_t>(tmp1, tmp2, "uvec2 postinc_param");
        tmp1 = v12u32[0];
        tmp2 = v22u32[0];
        v12u32[4] = --tmp1;
        v22u32[4] = --tmp2;
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 predec_res");
        print_vec<2, uint32_t>(tmp1, tmp2, "uvec2 predec_param");
        tmp1 = v12u32[0];
        tmp2 = v22u32[0];
        v12u32[4] = tmp1--;
        v22u32[4] = tmp2--;
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 postdec_res");
        print_vec<2, uint32_t>(tmp1, tmp2, "uvec2 postdec_param");
        print_vec<2, uint32_t>((~v12u32[0]), (~v22u32[0]), "uvec2 invert");
        print_vec<2, uint32_t>((v12u32[0] & u321[1]), (v22u32[0] & u322[1]), "uvec2 ands");
        print_vec<2, uint32_t>((v12u32[0] | u321[1]), (v22u32[0] | u322[1]), "uvec2 ors");
        print_vec<2, uint32_t>((v12u32[0] ^ u321[1]), (v22u32[0] ^ u322[1]), "uvec2 xors");
        print_vec<2, uint32_t>((v12u32[0] << 12u), (v22u32[0] << 12u), "uvec2 lss");
        print_vec<2, uint32_t>((v12u32[0] >> 12u), (v22u32[0] >> 12u), "uvec2 rss");
        print_vec<2, uint32_t>((v12u32[0] & v12u32[2]), (v22u32[0] & v22u32[2]), "uvec2 andv");
        print_vec<2, uint32_t>((v12u32[0] | v12u32[2]), (v22u32[0] | v22u32[2]), "uvec2 orv");
        print_vec<2, uint32_t>((v12u32[0] ^ v12u32[2]), (v22u32[0] ^ v22u32[2]), "uvec2 xorv");
        print_vec<2, uint32_t>((v12u32[0] << glm::uvec2(2, 4)), (v22u32[0] << glm2::uvec2(2, 4)), "uvec2 lsv");
        print_vec<2, uint32_t>((v12u32[0] >> glm::uvec2(2, 4)), (v22u32[0] >> glm2::uvec2(2, 4)), "uvec2 rsv");
    }

    // uvec3
    {
        glm::uvec3 tmp1; uvec3 tmp2;
        print_vec<3, uint32_t>((v13u32[0] + u321[0]), (v23u32[0] + u322[0]), "uvec3 adds");
        print_vec<3, uint32_t>((v13u32[0] - u321[0]), (v23u32[0] - u322[0]), "uvec3 subs");
        print_vec<3, uint32_t>((v13u32[0] * u321[0]), (v23u32[0] * u322[0]), "uvec3 muls");
        print_vec<3, uint32_t>((v13u32[0] / u321[0]), (v23u32[0] / u322[0]), "uvec3 divs");
        print_vec<3, uint32_t>((v13u32[0] % u321[0]), (v23u32[0] % u322[0]), "uvec3 mods");
        print_vec<3, uint32_t>((v13u32[0] + v13u32[3]), (v23u32[0] + v23u32[3]), "uvec3 addv");
        print_vec<3, uint32_t>((v13u32[0] - v13u32[3]), (v23u32[0] - v23u32[3]), "uvec3 subv");
        print_vec<3, uint32_t>((v13u32[0] * v13u32[3]), (v23u32[0] * v23u32[3]), "uvec3 mulv");
        print_vec<3, uint32_t>((v13u32[0] / v13u32[3]), (v23u32[0] / v23u32[3]), "uvec3 divv");
        print_vec<3, uint32_t>((v13u32[0] % v13u32[3]), (v23u32[0] % v23u32[3]), "uvec3 modv");
        print_vec<3, uint32_t>((+v13u32[0]), (+v23u32[0]), "uvec3 pos");
        print_vec<3, uint32_t>((-v13u32[0]), (-v23u32[0]), "uvec3 neg");
        tmp1 = v13u32[0];
        tmp2 = v23u32[0];
        v13u32[4] = ++tmp1;
        v23u32[4] = ++tmp2;
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 preinc_res");
        print_vec<3, uint32_t>(tmp1, tmp2, "uvec3 preinc_param");
        tmp1 = v13u32[0];
        tmp2 = v23u32[0];
        v13u32[4] = tmp1++;
        v23u32[4] = tmp2++;
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 postinc_res");
        print_vec<3, uint32_t>(tmp1, tmp2, "uvec3 postinc_param");
        tmp1 = v13u32[0];
        tmp2 = v23u32[0];
        v13u32[4] = --tmp1;
        v23u32[4] = --tmp2;
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 predec_res");
        print_vec<3, uint32_t>(tmp1, tmp2, "uvec3 predec_param");
        tmp1 = v13u32[0];
        tmp2 = v23u32[0];
        v13u32[4] = tmp1--;
        v23u32[4] = tmp2--;
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 postdec_res");
        print_vec<3, uint32_t>(tmp1, tmp2, "uvec3 postdec_param");
        print_vec<3, uint32_t>((~v13u32[0]), (~v23u32[0]), "uvec3 invert");
        print_vec<3, uint32_t>((v13u32[0] & u321[1]), (v23u32[0] & u322[1]), "uvec3 ands");
        print_vec<3, uint32_t>((v13u32[0] | u321[1]), (v23u32[0] | u322[1]), "uvec3 ors");
        print_vec<3, uint32_t>((v13u32[0] ^ u321[1]), (v23u32[0] ^ u322[1]), "uvec3 xors");
        print_vec<3, uint32_t>((v13u32[0] << 12u), (v23u32[0] << 12u), "uvec3 lss");
        print_vec<3, uint32_t>((v13u32[0] >> 12u), (v23u32[0] >> 12u), "uvec3 rss");
        print_vec<3, uint32_t>((v13u32[0] & v13u32[2]), (v23u32[0] & v23u32[2]), "uvec3 andv");
        print_vec<3, uint32_t>((v13u32[0] | v13u32[2]), (v23u32[0] | v23u32[2]), "uvec3 orv");
        print_vec<3, uint32_t>((v13u32[0] ^ v13u32[2]), (v23u32[0] ^ v23u32[2]), "uvec3 xorv");
        print_vec<3, uint32_t>((v13u32[0] << glm::uvec3(2, 4, 8)), (v23u32[0] << glm2::uvec3(2, 4, 8)), "uvec3 lsv");
        print_vec<3, uint32_t>((v13u32[0] >> glm::uvec3(2, 4, 8)), (v23u32[0] >> glm2::uvec3(2, 4, 8)), "uvec3 rsv");
    }

    // uvec4
    {
        glm::uvec4 tmp1; uvec4 tmp2;
        print_vec<4, uint32_t>((v14u32[0] + u321[0]), (v24u32[0] + u322[0]), "uvec4 adds");
        print_vec<4, uint32_t>((v14u32[0] - u321[0]), (v24u32[0] - u322[0]), "uvec4 subs");
        print_vec<4, uint32_t>((v14u32[0] * u321[0]), (v24u32[0] * u322[0]), "uvec4 muls");
        print_vec<4, uint32_t>((v14u32[0] / u321[0]), (v24u32[0] / u322[0]), "uvec4 divs");
        print_vec<4, uint32_t>((v14u32[0] % u321[0]), (v24u32[0] % u322[0]), "uvec4 mods");
        print_vec<4, uint32_t>((v14u32[0] + v14u32[3]), (v24u32[0] + v24u32[3]), "uvec4 addv");
        print_vec<4, uint32_t>((v14u32[0] - v14u32[3]), (v24u32[0] - v24u32[3]), "uvec4 subv");
        print_vec<4, uint32_t>((v14u32[0] * v14u32[3]), (v24u32[0] * v24u32[3]), "uvec4 mulv");
        print_vec<4, uint32_t>((v14u32[0] / v14u32[3]), (v24u32[0] / v24u32[3]), "uvec4 divv");
        print_vec<4, uint32_t>((v14u32[0] % v14u32[3]), (v24u32[0] % v24u32[3]), "uvec4 modv");
        print_vec<4, uint32_t>((+v14u32[0]), (+v24u32[0]), "uvec4 pos");
        print_vec<4, uint32_t>((-v14u32[0]), (-v24u32[0]), "uvec4 neg");
        tmp1 = v14u32[0];
        tmp2 = v24u32[0];
        v14u32[4] = ++tmp1;
        v24u32[4] = ++tmp2;
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 preinc_res");
        print_vec<4, uint32_t>(tmp1, tmp2, "uvec4 preinc_param");
        tmp1 = v14u32[0];
        tmp2 = v24u32[0];
        v14u32[4] = tmp1++;
        v24u32[4] = tmp2++;
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 postinc_res");
        print_vec<4, uint32_t>(tmp1, tmp2, "uvec4 postinc_param");
        tmp1 = v14u32[0];
        tmp2 = v24u32[0];
        v14u32[4] = --tmp1;
        v24u32[4] = --tmp2;
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 predec_res");
        print_vec<4, uint32_t>(tmp1, tmp2, "uvec4 predec_param");
        tmp1 = v14u32[0];
        tmp2 = v24u32[0];
        v14u32[4] = tmp1--;
        v24u32[4] = tmp2--;
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 postdec_res");
        print_vec<4, uint32_t>(tmp1, tmp2, "uvec4 postdec_param");
        print_vec<4, uint32_t>((~v14u32[0]), (~v24u32[0]), "uvec4 invert");
        print_vec<4, uint32_t>((v14u32[0] & u321[1]), (v24u32[0] & u322[1]), "uvec4 ands");
        print_vec<4, uint32_t>((v14u32[0] | u321[1]), (v24u32[0] | u322[1]), "uvec4 ors");
        print_vec<4, uint32_t>((v14u32[0] ^ u321[1]), (v24u32[0] ^ u322[1]), "uvec4 xors");
        print_vec<4, uint32_t>((v14u32[0] << 12u), (v24u32[0] << 12u), "uvec4 lss");
        print_vec<4, uint32_t>((v14u32[0] >> 12u), (v24u32[0] >> 12u), "uvec4 rss");
        print_vec<4, uint32_t>((v14u32[0] & v14u32[2]), (v24u32[0] & v24u32[2]), "uvec4 andv");
        print_vec<4, uint32_t>((v14u32[0] | v14u32[2]), (v24u32[0] | v24u32[2]), "uvec4 orv");
        print_vec<4, uint32_t>((v14u32[0] ^ v14u32[2]), (v24u32[0] ^ v24u32[2]), "uvec4 xorv");
        print_vec<4, uint32_t>((v14u32[0] << glm::uvec4(2, 4, 8, 16)), (v24u32[0] << glm2::uvec4(2, 4, 8, 16)), "uvec4 lsv");
        print_vec<4, uint32_t>((v14u32[0] >> glm::uvec4(2, 4, 8, 16)), (v24u32[0] >> glm2::uvec4(2, 4, 8, 16)), "uvec4 rsv");
    }
#endif

#ifdef GLM2_TEST_VECTOR_CMP_OPERATORS
    // vec2
    {
        print_single<bool>((glm::vec2(0.0, 0.0) == glm::vec2(0.0, 0.0)), (vec2(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) == vec2(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec2 cmpeq");
        print_single<bool>((glm::vec2(0.0, 0.0) != glm::vec2(0.0, 0.0)), (vec2(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) != vec2(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec2 cmpneq");
        print_single<bool>((glm::vec2(1.0, 0.0) == glm::vec2(0.0, 0.0)), (vec2(_mm_set_ps(0.0, 0.0, 0.0, 1.0)) == vec2(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec2 cmpeq");
        print_single<bool>((glm::vec2(1.0, 0.0) != glm::vec2(0.0, 0.0)), (vec2(_mm_set_ps(0.0, 0.0, 0.0, 1.0)) != vec2(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec2 cmpneq");
        print_single<bool>((glm::vec2(0.0, 0.0) == glm::vec2(1.0, 0.0)), (vec2(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) == vec2(_mm_set_ps(0.0, 0.0, 0.0, 1.0))), "vec2 cmpeq");
        print_single<bool>((glm::vec2(0.0, 0.0) != glm::vec2(1.0, 0.0)), (vec2(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) != vec2(_mm_set_ps(0.0, 0.0, 0.0, 1.0))), "vec2 cmpneq");
        print_single<bool>((glm::vec2(0.0, 0.0) == glm::vec2(0.0, 0.0)), (vec2(_mm_set_ps(1.0, 0.0, 0.0, 0.0)) == vec2(_mm_set_ps(0.0, 1.0, 0.0, 0.0))), "vec2 cmpeq");
        print_single<bool>((glm::vec2(0.0, 0.0) != glm::vec2(0.0, 0.0)), (vec2(_mm_set_ps(1.0, 0.0, 0.0, 0.0)) != vec2(_mm_set_ps(0.0, 1.0, 0.0, 0.0))), "vec2 cmpneq");
    }

    // vec3
    {
        print_single<bool>((glm::vec3(0.0, 0.0, 0.0) == glm::vec3(0.0, 0.0, 0.0)), (vec3(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) == vec3(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec3 cmpeq");
        print_single<bool>((glm::vec3(0.0, 0.0, 0.0) != glm::vec3(0.0, 0.0, 0.0)), (vec3(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) != vec3(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec3 cmpneq");
        print_single<bool>((glm::vec3(1.0, 0.0, 0.0) == glm::vec3(0.0, 0.0, 0.0)), (vec3(_mm_set_ps(0.0, 0.0, 0.0, 1.0)) == vec3(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec3 cmpeq");
        print_single<bool>((glm::vec3(1.0, 0.0, 0.0) != glm::vec3(0.0, 0.0, 0.0)), (vec3(_mm_set_ps(0.0, 0.0, 0.0, 1.0)) != vec3(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec3 cmpneq");
        print_single<bool>((glm::vec3(0.0, 0.0, 0.0) == glm::vec3(0.0, 0.0, 1.0)), (vec3(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) == vec3(_mm_set_ps(0.0, 1.0, 0.0, 0.0))), "vec3 cmpeq");
        print_single<bool>((glm::vec3(0.0, 0.0, 0.0) != glm::vec3(0.0, 0.0, 1.0)), (vec3(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) != vec3(_mm_set_ps(0.0, 1.0, 0.0, 0.0))), "vec3 cmpneq");
        print_single<bool>((glm::vec3(0.0, 0.0, 0.0) == glm::vec3(0.0, 0.0, 0.0)), (vec3(_mm_set_ps(1.0, 0.0, 0.0, 0.0)) == vec3(_mm_set_ps(1.0, 0.0, 0.0, 0.0))), "vec3 cmpeq");
        print_single<bool>((glm::vec3(0.0, 0.0, 0.0) != glm::vec3(0.0, 0.0, 0.0)), (vec3(_mm_set_ps(1.0, 0.0, 0.0, 0.0)) != vec3(_mm_set_ps(1.0, 0.0, 0.0, 0.0))), "vec3 cmpneq");
    }

    // vec4
    {
        print_single<bool>((glm::vec4(0.0, 0.0, 0.0, 0.0) == glm::vec4(0.0, 0.0, 0.0, 0.0)), (vec4(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) == vec4(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec4 cmpeq");
        print_single<bool>((glm::vec4(0.0, 0.0, 0.0, 0.0) != glm::vec4(0.0, 0.0, 0.0, 0.0)), (vec4(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) != vec4(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec4 cmpneq");
        print_single<bool>((glm::vec4(1.0, 0.0, 0.0, 0.0) == glm::vec4(0.0, 0.0, 0.0, 0.0)), (vec4(_mm_set_ps(0.0, 0.0, 0.0, 1.0)) == vec4(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec4 cmpeq");
        print_single<bool>((glm::vec4(1.0, 0.0, 0.0, 0.0) != glm::vec4(0.0, 0.0, 0.0, 0.0)), (vec4(_mm_set_ps(0.0, 0.0, 0.0, 1.0)) != vec4(_mm_set_ps(0.0, 0.0, 0.0, 0.0))), "vec4 cmpneq");
        print_single<bool>((glm::vec4(0.0, 0.0, 0.0, 0.0) == glm::vec4(0.0, 0.0, 0.0, 1.0)), (vec4(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) == vec4(_mm_set_ps(1.0, 0.0, 0.0, 0.0))), "vec4 cmpeq");
        print_single<bool>((glm::vec4(0.0, 0.0, 0.0, 0.0) != glm::vec4(0.0, 0.0, 0.0, 1.0)), (vec4(_mm_set_ps(0.0, 0.0, 0.0, 0.0)) != vec4(_mm_set_ps(1.0, 0.0, 0.0, 0.0))), "vec4 cmpneq");
    }

    // dvec2
    {
        print_single<bool>((glm::dvec2(0.0, 0.0) == glm::dvec2(0.0, 0.0)), (dvec2(_mm_set_pd(0.0, 0.0)) == dvec2(_mm_set_pd(0.0, 0.0))), "dvec2 cmpeq");
        print_single<bool>((glm::dvec2(0.0, 0.0) != glm::dvec2(0.0, 0.0)), (dvec2(_mm_set_pd(0.0, 0.0)) != dvec2(_mm_set_pd(0.0, 0.0))), "dvec2 cmpneq");
        print_single<bool>((glm::dvec2(1.0, 0.0) == glm::dvec2(0.0, 0.0)), (dvec2(_mm_set_pd(0.0, 1.0)) == dvec2(_mm_set_pd(0.0, 0.0))), "dvec2 cmpeq");
        print_single<bool>((glm::dvec2(1.0, 0.0) != glm::dvec2(0.0, 0.0)), (dvec2(_mm_set_pd(0.0, 1.0)) != dvec2(_mm_set_pd(0.0, 0.0))), "dvec2 cmpneq");
        print_single<bool>((glm::dvec2(0.0, 0.0) == glm::dvec2(1.0, 0.0)), (dvec2(_mm_set_pd(0.0, 0.0)) == dvec2(_mm_set_pd(0.0, 1.0))), "dvec2 cmpeq");
        print_single<bool>((glm::dvec2(0.0, 0.0) != glm::dvec2(1.0, 0.0)), (dvec2(_mm_set_pd(0.0, 0.0)) != dvec2(_mm_set_pd(0.0, 1.0))), "dvec2 cmpneq");
    }

    // dvec3
    {
        print_single<bool>((glm::dvec3(0.0, 0.0, 0.0) == glm::dvec3(0.0, 0.0, 0.0)), (dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 0.0)) == dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 0.0))), "dvec3 cmpeq");
        print_single<bool>((glm::dvec3(0.0, 0.0, 0.0) != glm::dvec3(0.0, 0.0, 0.0)), (dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 0.0)) != dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 0.0))), "dvec3 cmpneq");
        print_single<bool>((glm::dvec3(1.0, 0.0, 0.0) == glm::dvec3(0.0, 0.0, 0.0)), (dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 1.0)) == dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 0.0))), "dvec3 cmpeq");
        print_single<bool>((glm::dvec3(1.0, 0.0, 0.0) != glm::dvec3(0.0, 0.0, 0.0)), (dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 1.0)) != dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 0.0))), "dvec3 cmpneq");
        print_single<bool>((glm::dvec3(0.0, 0.0, 0.0) == glm::dvec3(0.0, 0.0, 1.0)), (dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 0.0)) == dvec3(_mm256_set_pd(0.0, 1.0, 0.0, 0.0))), "dvec3 cmpeq");
        print_single<bool>((glm::dvec3(0.0, 0.0, 0.0) != glm::dvec3(0.0, 0.0, 1.0)), (dvec3(_mm256_set_pd(0.0, 0.0, 0.0, 0.0)) != dvec3(_mm256_set_pd(0.0, 1.0, 0.0, 0.0))), "dvec3 cmpneq");
        print_single<bool>((glm::dvec3(0.0, 0.0, 0.0) == glm::dvec3(0.0, 0.0, 0.0)), (dvec3(_mm256_set_pd(1.0, 0.0, 0.0, 0.0)) == dvec3(_mm256_set_pd(1.0, 0.0, 0.0, 0.0))), "dvec3 cmpeq");
        print_single<bool>((glm::dvec3(0.0, 0.0, 0.0) != glm::dvec3(0.0, 0.0, 0.0)), (dvec3(_mm256_set_pd(1.0, 0.0, 0.0, 0.0)) != dvec3(_mm256_set_pd(1.0, 0.0, 0.0, 0.0))), "dvec3 cmpneq");
    }

    // dvec4
    {
        print_single<bool>((glm::dvec4(0.0, 0.0, 0.0, 0.0) == glm::dvec4(0.0, 0.0, 0.0, 0.0)), (dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 0.0)) == dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 0.0))), "dvec4 cmpeq");
        print_single<bool>((glm::dvec4(0.0, 0.0, 0.0, 0.0) != glm::dvec4(0.0, 0.0, 0.0, 0.0)), (dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 0.0)) != dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 0.0))), "dvec4 cmpneq");
        print_single<bool>((glm::dvec4(1.0, 0.0, 0.0, 0.0) == glm::dvec4(0.0, 0.0, 0.0, 0.0)), (dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 1.0)) == dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 0.0))), "dvec4 cmpeq");
        print_single<bool>((glm::dvec4(1.0, 0.0, 0.0, 0.0) != glm::dvec4(0.0, 0.0, 0.0, 0.0)), (dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 1.0)) != dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 0.0))), "dvec4 cmpneq");
        print_single<bool>((glm::dvec4(0.0, 0.0, 0.0, 0.0) == glm::dvec4(0.0, 0.0, 0.0, 1.0)), (dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 0.0)) == dvec4(_mm256_set_pd(1.0, 0.0, 0.0, 0.0))), "dvec4 cmpeq");
        print_single<bool>((glm::dvec4(0.0, 0.0, 0.0, 0.0) != glm::dvec4(0.0, 0.0, 0.0, 1.0)), (dvec4(_mm256_set_pd(0.0, 0.0, 0.0, 0.0)) != dvec4(_mm256_set_pd(1.0, 0.0, 0.0, 0.0))), "dvec4 cmpneq");
    }

    // ivec2
    {
        print_single<bool>((glm::ivec2(0, 0) == glm::ivec2(0, 0)), (ivec2(_mm_set_pd(0, 0)) == ivec2(_mm_set_pd(0, 0))), "ivec2 cmpeq");
        print_single<bool>((glm::ivec2(0, 0) != glm::ivec2(0, 0)), (ivec2(_mm_set_pd(0, 0)) != ivec2(_mm_set_pd(0, 0))), "ivec2 cmpneq");
        print_single<bool>((glm::ivec2(1, 0) == glm::ivec2(0, 0)), (ivec2(_mm_set_pd(0, 1)) == ivec2(_mm_set_pd(0, 0))), "ivec2 cmpeq");
        print_single<bool>((glm::ivec2(1, 0) != glm::ivec2(0, 0)), (ivec2(_mm_set_pd(0, 1)) != ivec2(_mm_set_pd(0, 0))), "ivec2 cmpneq");
        print_single<bool>((glm::ivec2(0, 0) == glm::ivec2(1, 0)), (ivec2(_mm_set_pd(0, 0)) == ivec2(_mm_set_pd(0, 1))), "ivec2 cmpeq");
        print_single<bool>((glm::ivec2(0, 0) != glm::ivec2(1, 0)), (ivec2(_mm_set_pd(0, 0)) != ivec2(_mm_set_pd(0, 1))), "ivec2 cmpneq");
    }

    // ivec3
    {
        print_single<bool>((glm::ivec3(0, 0, 0) == glm::ivec3(0, 0, 0)), (ivec3(_mm_set_epi32(0, 0, 0, 0)) == ivec3(_mm_set_epi32(0, 0, 0, 0))), "ivec3 cmpeq");
        print_single<bool>((glm::ivec3(0, 0, 0) != glm::ivec3(0, 0, 0)), (ivec3(_mm_set_epi32(0, 0, 0, 0)) != ivec3(_mm_set_epi32(0, 0, 0, 0))), "ivec3 cmpneq");
        print_single<bool>((glm::ivec3(1, 0, 0) == glm::ivec3(0, 0, 0)), (ivec3(_mm_set_epi32(0, 0, 0, 1)) == ivec3(_mm_set_epi32(0, 0, 0, 0))), "ivec3 cmpeq");
        print_single<bool>((glm::ivec3(1, 0, 0) != glm::ivec3(0, 0, 0)), (ivec3(_mm_set_epi32(0, 0, 0, 1)) != ivec3(_mm_set_epi32(0, 0, 0, 0))), "ivec3 cmpneq");
        print_single<bool>((glm::ivec3(0, 0, 0) == glm::ivec3(0, 0, 1)), (ivec3(_mm_set_epi32(0, 0, 0, 0)) == ivec3(_mm_set_epi32(0, 1, 0, 0))), "ivec3 cmpeq");
        print_single<bool>((glm::ivec3(0, 0, 0) != glm::ivec3(0, 0, 1)), (ivec3(_mm_set_epi32(0, 0, 0, 0)) != ivec3(_mm_set_epi32(0, 1, 0, 0))), "ivec3 cmpneq");
        print_single<bool>((glm::ivec3(0, 0, 0) == glm::ivec3(0, 0, 0)), (ivec3(_mm_set_epi32(1, 0, 0, 0)) == ivec3(_mm_set_epi32(1, 0, 0, 0))), "ivec3 cmpeq");
        print_single<bool>((glm::ivec3(0, 0, 0) != glm::ivec3(0, 0, 0)), (ivec3(_mm_set_epi32(1, 0, 0, 0)) != ivec3(_mm_set_epi32(1, 0, 0, 0))), "ivec3 cmpneq");
    }

    // ivec4
    {
        print_single<bool>((glm::ivec4(0, 0, 0, 0) == glm::ivec4(0, 0, 0, 0)), (ivec4(_mm_set_epi32(0, 0, 0, 0)) == ivec4(_mm_set_epi32(0, 0, 0, 0))), "ivec4 cmpeq");
        print_single<bool>((glm::ivec4(0, 0, 0, 0) != glm::ivec4(0, 0, 0, 0)), (ivec4(_mm_set_epi32(0, 0, 0, 0)) != ivec4(_mm_set_epi32(0, 0, 0, 0))), "ivec4 cmpneq");
        print_single<bool>((glm::ivec4(1, 0, 0, 0) == glm::ivec4(0, 0, 0, 0)), (ivec4(_mm_set_epi32(0, 0, 0, 1)) == ivec4(_mm_set_epi32(0, 0, 0, 0))), "ivec4 cmpeq");
        print_single<bool>((glm::ivec4(1, 0, 0, 0) != glm::ivec4(0, 0, 0, 0)), (ivec4(_mm_set_epi32(0, 0, 0, 1)) != ivec4(_mm_set_epi32(0, 0, 0, 0))), "ivec4 cmpneq");
        print_single<bool>((glm::ivec4(0, 0, 0, 0) == glm::ivec4(0, 0, 0, 1)), (ivec4(_mm_set_epi32(0, 0, 0, 0)) == ivec4(_mm_set_epi32(1, 0, 0, 0))), "ivec4 cmpeq");
        print_single<bool>((glm::ivec4(0, 0, 0, 0) != glm::ivec4(0, 0, 0, 1)), (ivec4(_mm_set_epi32(0, 0, 0, 0)) != ivec4(_mm_set_epi32(1, 0, 0, 0))), "ivec4 cmpneq");
    }

    // uvec2
    {
        print_single<bool>((glm::uvec2(0, 0) == glm::uvec2(0, 0)), (uvec2(_mm_set_pd(0, 0)) == uvec2(_mm_set_pd(0, 0))), "uvec2 cmpeq");
        print_single<bool>((glm::uvec2(0, 0) != glm::uvec2(0, 0)), (uvec2(_mm_set_pd(0, 0)) != uvec2(_mm_set_pd(0, 0))), "uvec2 cmpneq");
        print_single<bool>((glm::uvec2(1, 0) == glm::uvec2(0, 0)), (uvec2(_mm_set_pd(0, 1)) == uvec2(_mm_set_pd(0, 0))), "uvec2 cmpeq");
        print_single<bool>((glm::uvec2(1, 0) != glm::uvec2(0, 0)), (uvec2(_mm_set_pd(0, 1)) != uvec2(_mm_set_pd(0, 0))), "uvec2 cmpneq");
        print_single<bool>((glm::uvec2(0, 0) == glm::uvec2(1, 0)), (uvec2(_mm_set_pd(0, 0)) == uvec2(_mm_set_pd(0, 1))), "uvec2 cmpeq");
        print_single<bool>((glm::uvec2(0, 0) != glm::uvec2(1, 0)), (uvec2(_mm_set_pd(0, 0)) != uvec2(_mm_set_pd(0, 1))), "uvec2 cmpneq");
    }

    // uvec3
    {
        print_single<bool>((glm::uvec3(0, 0, 0) == glm::uvec3(0, 0, 0)), (uvec3(_mm_set_epi32(0, 0, 0, 0)) == uvec3(_mm_set_epi32(0, 0, 0, 0))), "uvec3 cmpeq");
        print_single<bool>((glm::uvec3(0, 0, 0) != glm::uvec3(0, 0, 0)), (uvec3(_mm_set_epi32(0, 0, 0, 0)) != uvec3(_mm_set_epi32(0, 0, 0, 0))), "uvec3 cmpneq");
        print_single<bool>((glm::uvec3(1, 0, 0) == glm::uvec3(0, 0, 0)), (uvec3(_mm_set_epi32(0, 0, 0, 1)) == uvec3(_mm_set_epi32(0, 0, 0, 0))), "uvec3 cmpeq");
        print_single<bool>((glm::uvec3(1, 0, 0) != glm::uvec3(0, 0, 0)), (uvec3(_mm_set_epi32(0, 0, 0, 1)) != uvec3(_mm_set_epi32(0, 0, 0, 0))), "uvec3 cmpneq");
        print_single<bool>((glm::uvec3(0, 0, 0) == glm::uvec3(0, 0, 1)), (uvec3(_mm_set_epi32(0, 0, 0, 0)) == uvec3(_mm_set_epi32(0, 1, 0, 0))), "uvec3 cmpeq");
        print_single<bool>((glm::uvec3(0, 0, 0) != glm::uvec3(0, 0, 1)), (uvec3(_mm_set_epi32(0, 0, 0, 0)) != uvec3(_mm_set_epi32(0, 1, 0, 0))), "uvec3 cmpneq");
        print_single<bool>((glm::uvec3(0, 0, 0) == glm::uvec3(0, 0, 0)), (uvec3(_mm_set_epi32(1, 0, 0, 0)) == uvec3(_mm_set_epi32(1, 0, 0, 0))), "uvec3 cmpeq");
        print_single<bool>((glm::uvec3(0, 0, 0) != glm::uvec3(0, 0, 0)), (uvec3(_mm_set_epi32(1, 0, 0, 0)) != uvec3(_mm_set_epi32(1, 0, 0, 0))), "uvec3 cmpneq");
    }

    // uvec4
    {
        print_single<bool>((glm::uvec4(0, 0, 0, 0) == glm::uvec4(0, 0, 0, 0)), (uvec4(_mm_set_epi32(0, 0, 0, 0)) == uvec4(_mm_set_epi32(0, 0, 0, 0))), "uvec4 cmpeq");
        print_single<bool>((glm::uvec4(0, 0, 0, 0) != glm::uvec4(0, 0, 0, 0)), (uvec4(_mm_set_epi32(0, 0, 0, 0)) != uvec4(_mm_set_epi32(0, 0, 0, 0))), "uvec4 cmpneq");
        print_single<bool>((glm::uvec4(1, 0, 0, 0) == glm::uvec4(0, 0, 0, 0)), (uvec4(_mm_set_epi32(0, 0, 0, 1)) == uvec4(_mm_set_epi32(0, 0, 0, 0))), "uvec4 cmpeq");
        print_single<bool>((glm::uvec4(1, 0, 0, 0) != glm::uvec4(0, 0, 0, 0)), (uvec4(_mm_set_epi32(0, 0, 0, 1)) != uvec4(_mm_set_epi32(0, 0, 0, 0))), "uvec4 cmpneq");
        print_single<bool>((glm::uvec4(0, 0, 0, 0) == glm::uvec4(0, 0, 0, 1)), (uvec4(_mm_set_epi32(0, 0, 0, 0)) == uvec4(_mm_set_epi32(1, 0, 0, 0))), "uvec4 cmpeq");
        print_single<bool>((glm::uvec4(0, 0, 0, 0) != glm::uvec4(0, 0, 0, 1)), (uvec4(_mm_set_epi32(0, 0, 0, 0)) != uvec4(_mm_set_epi32(1, 0, 0, 0))), "uvec4 cmpneq");
    }
#endif

#ifdef GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_MAT2
    // mat2x2
    {
        glm::mat2x2 tmp1;   mat2x2 tmp2;
        print_mat<2, 2, float>((m122f[1] + f1[0]),                  (m222f[1] + f2[0]),                 "mat2x2 adds");
        print_mat<2, 2, float>(((m122f[3] = m122f[1]) += v12f[0]),  (m222f[1] + v22f[0]),               "mat2x2 addv");
        print_mat<2, 2, float>((m122f[1] + m122f[0]),               (m222f[1] + m222f[0]),              "mat2x2 addm");
        print_mat<2, 2, float>((m122f[1] - f1[0]),                  (m222f[1] - f2[0]),                 "mat2x2 subs");
        print_mat<2, 2, float>(((m122f[3] = m122f[1]) -= v12f[0]),  (m222f[1] - v22f[0]),               "mat2x2 subv");
        print_mat<2, 2, float>((m122f[1] - m122f[0]),               (m222f[1] - m222f[0]),              "mat2x2 subm");
        print_mat<2, 2, float>((m122f[1] * f1[0]),                  (m222f[1] * f2[0]),                 "mat2x2 muls");
        print_mat<2, 2, float>(((m122f[3] = m122f[1]) *= v12f[0]),  ((m222f[3] = m222f[1]) *= v22f[0]), "mat2x2 mulv");
        print_mat<2, 2, float>((m122f[1] / f1[0]),                  (m222f[1] / f2[0]),                 "mat2x2 divs");
        print_mat<2, 2, float>(((m122f[3] = m122f[1]) /= v12f[0]),  ((m222f[3] = m222f[1]) /= v22f[0]), "mat2x2 divv");
        print_mat<2, 2, float>((+m122f[1]), (+m222f[1]), "mat2x2 pos");
        print_mat<2, 2, float>((-m122f[1]), (-m222f[1]), "mat2x2 neg");
        tmp1 = m122f[0];
        tmp2 = m222f[0];
        m122f[3] = ++tmp1;
        m222f[3] = ++tmp2;
        print_mat<2, 2, float>(m122f[3], m222f[3], "mat2x2 preinc_res");
        print_mat<2, 2, float>(tmp1, tmp2, "mat2x2 preinc_param");
        tmp1 = m122f[0];
        tmp2 = m222f[0];
        m122f[3] = tmp1++;
        m222f[3] = tmp2++;
        print_mat<2, 2, float>(m122f[3], m222f[3], "mat2x2 postinc_res");
        print_mat<2, 2, float>(tmp1, tmp2, "mat2x2 postinc_param");
        tmp1 = m122f[0];
        tmp2 = m222f[0];
        m122f[3] = --tmp1;
        m222f[3] = --tmp2;
        print_mat<2, 2, float>(m122f[3], m222f[3], "mat2x2 predec_res");
        print_mat<2, 2, float>(tmp1, tmp2, "mat2x2 predec_param");
        tmp1 = m122f[0];
        tmp2 = m222f[0];
        m122f[3] = tmp1--;
        m222f[3] = tmp2--;
        print_mat<2, 2, float>(m122f[3], m222f[3], "mat2x2 postdec_res");
        print_mat<2, 2, float>(tmp1, tmp2, "mat2x2 postdec_param");
    }

    // mat2x3
    {
        glm::mat2x3 tmp1;   mat2x3 tmp2;
        print_mat<2, 3, float>((m123f[1] + f1[0]),                  (m223f[1] + f2[0]),                 "mat2x3 adds");
        print_mat<2, 3, float>(((m123f[3] = m123f[1]) += v13f[0]),  (m223f[1] + v23f[0]),               "mat2x3 addv");
        print_mat<2, 3, float>((m123f[1] + m123f[0]),               (m223f[1] + m223f[0]),              "mat2x3 addm");
        print_mat<2, 3, float>((m123f[1] - f1[0]),                  (m223f[1] - f2[0]),                 "mat2x3 subs");
        print_mat<2, 3, float>(((m123f[3] = m123f[1]) -= v13f[0]),  (m223f[1] - v23f[0]),               "mat2x3 subv");
        print_mat<2, 3, float>((m123f[1] - m123f[0]),               (m223f[1] - m223f[0]),              "mat2x3 subm");
        print_mat<2, 3, float>((m123f[1] * f1[0]),                  (m223f[1] * f2[0]),                 "mat2x3 muls");
        print_mat<2, 3, float>(((m123f[3] = m123f[1]) *= v13f[0]),  ((m223f[3] = m223f[1]) *= v23f[0]), "mat2x3 mulv");
        print_mat<2, 3, float>((m123f[1] / f1[0]),                  (m223f[1] / f2[0]),                 "mat2x3 divs");
        print_mat<2, 3, float>(((m123f[3] = m123f[1]) /= v13f[0]),  ((m223f[3] = m223f[1]) /= v23f[0]), "mat2x3 divv");
        print_mat<2, 3, float>((+m123f[1]), (+m223f[1]), "mat2x3 pos");
        print_mat<2, 3, float>((-m123f[1]), (-m223f[1]), "mat2x3 neg");
        tmp1 = m123f[0];
        tmp2 = m223f[0];
        m123f[3] = ++tmp1;
        m223f[3] = ++tmp2;
        print_mat<2, 3, float>(m123f[3], m223f[3], "mat2x3 preinc_res");
        print_mat<2, 3, float>(tmp1, tmp2, "mat2x3 preinc_param");
        tmp1 = m123f[0];
        tmp2 = m223f[0];
        m123f[3] = tmp1++;
        m223f[3] = tmp2++;
        print_mat<2, 3, float>(m123f[3], m223f[3], "mat2x3 postinc_res");
        print_mat<2, 3, float>(tmp1, tmp2, "mat2x3 postinc_param");
        tmp1 = m123f[0];
        tmp2 = m223f[0];
        m123f[3] = --tmp1;
        m223f[3] = --tmp2;
        print_mat<2, 3, float>(m123f[3], m223f[3], "mat2x3 predec_res");
        print_mat<2, 3, float>(tmp1, tmp2, "mat2x3 predec_param");
        tmp1 = m123f[0];
        tmp2 = m223f[0];
        m123f[3] = tmp1--;
        m223f[3] = tmp2--;
        print_mat<2, 3, float>(m123f[3], m223f[3], "mat2x3 postdec_res");
        print_mat<2, 3, float>(tmp1, tmp2, "mat2x3 postdec_param");
    }

    // mat2x4
    {
        glm::mat2x4 tmp1;   mat2x4 tmp2;
        print_mat<2, 4, float>((m124f[1] + f1[0]),                  (m224f[1] + f2[0]),                 "mat2x4 adds");
        print_mat<2, 4, float>(((m124f[3] = m124f[1]) += v14f[0]),  (m224f[1] + v24f[0]),               "mat2x4 addv");
        print_mat<2, 4, float>((m124f[1] + m124f[0]),               (m224f[1] + m224f[0]),              "mat2x4 addm");
        print_mat<2, 4, float>((m124f[1] - f1[0]),                  (m224f[1] - f2[0]),                 "mat2x4 subs");
        print_mat<2, 4, float>(((m124f[3] = m124f[1]) -= v14f[0]),  (m224f[1] - v24f[0]),               "mat2x4 subv");
        print_mat<2, 4, float>((m124f[1] - m124f[0]),               (m224f[1] - m224f[0]),              "mat2x4 subm");
        print_mat<2, 4, float>((m124f[1] * f1[0]),                  (m224f[1] * f2[0]),                 "mat2x4 muls");
        print_mat<2, 4, float>(((m124f[3] = m124f[1]) *= v14f[0]),  ((m224f[3] = m224f[1]) *= v24f[0]), "mat2x4 mulv");
        print_mat<2, 4, float>((m124f[1] / f1[0]),                  (m224f[1] / f2[0]),                 "mat2x4 divs");
        print_mat<2, 4, float>(((m124f[3] = m124f[1]) /= v14f[0]),  ((m224f[3] = m224f[1]) /= v24f[0]), "mat2x4 divv");
        print_mat<2, 4, float>((+m124f[1]), (+m224f[1]), "mat2x4 pos");
        print_mat<2, 4, float>((-m124f[1]), (-m224f[1]), "mat2x4 neg");
        tmp1 = m124f[0];
        tmp2 = m224f[0];
        m124f[3] = ++tmp1;
        m224f[3] = ++tmp2;
        print_mat<2, 4, float>(m124f[3], m224f[3], "mat2x4 preinc_res");
        print_mat<2, 4, float>(tmp1, tmp2, "mat2x4 preinc_param");
        tmp1 = m124f[0];
        tmp2 = m224f[0];
        m124f[3] = tmp1++;
        m224f[3] = tmp2++;
        print_mat<2, 4, float>(m124f[3], m224f[3], "mat2x4 postinc_res");
        print_mat<2, 4, float>(tmp1, tmp2, "mat2x4 postinc_param");
        tmp1 = m124f[0];
        tmp2 = m224f[0];
        m124f[3] = --tmp1;
        m224f[3] = --tmp2;
        print_mat<2, 4, float>(m124f[3], m224f[3], "mat2x4 predec_res");
        print_mat<2, 4, float>(tmp1, tmp2, "mat2x4 predec_param");
        tmp1 = m124f[0];
        tmp2 = m224f[0];
        m124f[3] = tmp1--;
        m224f[3] = tmp2--;
        print_mat<2, 4, float>(m124f[3], m224f[3], "mat2x4 postdec_res");
        print_mat<2, 4, float>(tmp1, tmp2, "mat2x4 postdec_param");
    }

#endif

#ifdef GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_MAT3
    // mat3x2
    {
        glm::mat3x2 tmp1;   mat3x2 tmp2;
        print_mat<3, 2, float>((m132f[1] + f1[0]),                  (m232f[1] + f2[0]),                 "mat3x2 adds");
        print_mat<3, 2, float>(((m132f[3] = m132f[1]) += v12f[0]),  (m232f[1] + v22f[0]),               "mat3x2 addv");
        print_mat<3, 2, float>((m132f[1] + m132f[0]),               (m232f[1] + m232f[0]),              "mat3x2 addm");
        print_mat<3, 2, float>((m132f[1] - f1[0]),                  (m232f[1] - f2[0]),                 "mat3x2 subs");
        print_mat<3, 2, float>(((m132f[3] = m132f[1]) -= v12f[0]),  (m232f[1] - v22f[0]),               "mat3x2 subv");
        print_mat<3, 2, float>((m132f[1] - m132f[0]),               (m232f[1] - m232f[0]),              "mat3x2 subm");
        print_mat<3, 2, float>((m132f[1] * f1[0]),                  (m232f[1] * f2[0]),                 "mat3x2 muls");
        print_mat<3, 2, float>(((m132f[3] = m132f[1]) *= v12f[0]),  ((m232f[3] = m232f[1]) *= v22f[0]), "mat3x2 mulv");
        print_mat<3, 2, float>((m132f[1] / f1[0]),                  (m232f[1] / f2[0]),                 "mat3x2 divs");
        print_mat<3, 2, float>(((m132f[3] = m132f[1]) /= v12f[0]),  ((m232f[3] = m232f[1]) /= v22f[0]), "mat3x2 divv");
        print_mat<3, 2, float>((+m132f[1]), (+m232f[1]), "mat3x2 pos");
        print_mat<3, 2, float>((-m132f[1]), (-m232f[1]), "mat3x2 neg");
        tmp1 = m132f[0];
        tmp2 = m232f[0];
        m132f[3] = ++tmp1;
        m232f[3] = ++tmp2;
        print_mat<3, 2, float>(m132f[3], m232f[3], "mat3x2 preinc_res");
        print_mat<3, 2, float>(tmp1, tmp2, "mat3x2 preinc_param");
        tmp1 = m132f[0];
        tmp2 = m232f[0];
        m132f[3] = tmp1++;
        m232f[3] = tmp2++;
        print_mat<3, 2, float>(m132f[3], m232f[3], "mat3x2 postinc_res");
        print_mat<3, 2, float>(tmp1, tmp2, "mat3x2 postinc_param");
        tmp1 = m132f[0];
        tmp2 = m232f[0];
        m132f[3] = --tmp1;
        m232f[3] = --tmp2;
        print_mat<3, 2, float>(m132f[3], m232f[3], "mat3x2 predec_res");
        print_mat<3, 2, float>(tmp1, tmp2, "mat3x2 predec_param");
        tmp1 = m132f[0];
        tmp2 = m232f[0];
        m132f[3] = tmp1--;
        m232f[3] = tmp2--;
        print_mat<3, 2, float>(m132f[3], m232f[3], "mat3x2 postdec_res");
        print_mat<3, 2, float>(tmp1, tmp2, "mat3x2 postdec_param");
    }

    // mat3x3
    {
        glm::mat3x3 tmp1;   mat3x3 tmp2;
        print_mat<3, 3, float>((m133f[1] + f1[0]),                  (m233f[1] + f2[0]),                 "mat3x3 adds");
        print_mat<3, 3, float>(((m133f[3] = m133f[1]) += v13f[0]),  (m233f[1] + v23f[0]),               "mat3x3 addv");
        print_mat<3, 3, float>((m133f[1] + m133f[0]),               (m233f[1] + m233f[0]),              "mat3x3 addm");
        print_mat<3, 3, float>((m133f[1] - f1[0]),                  (m233f[1] - f2[0]),                 "mat3x3 subs");
        print_mat<3, 3, float>(((m133f[3] = m133f[1]) -= v13f[0]),  (m233f[1] - v23f[0]),               "mat3x3 subv");
        print_mat<3, 3, float>((m133f[1] - m133f[0]),               (m233f[1] - m233f[0]),              "mat3x3 subm");
        print_mat<3, 3, float>((m133f[1] * f1[0]),                  (m233f[1] * f2[0]),                 "mat3x3 muls");
        print_mat<3, 3, float>(((m133f[3] = m133f[1]) *= v13f[0]),  ((m233f[3] = m233f[1]) *= v23f[0]), "mat3x3 mulv");
        print_mat<3, 3, float>((m133f[1] / f1[0]),                  (m233f[1] / f2[0]),                 "mat3x3 divs");
        print_mat<3, 3, float>(((m133f[3] = m133f[1]) /= v13f[0]),  ((m233f[3] = m233f[1]) /= v23f[0]), "mat3x3 divv");
        print_mat<3, 3, float>((+m133f[1]), (+m233f[1]), "mat3x3 pos");
        print_mat<3, 3, float>((-m133f[1]), (-m233f[1]), "mat3x3 neg");
        tmp1 = m133f[0];
        tmp2 = m233f[0];
        m133f[3] = ++tmp1;
        m233f[3] = ++tmp2;
        print_mat<3, 3, float>(m133f[3], m233f[3], "mat3x3 preinc_res");
        print_mat<3, 3, float>(tmp1, tmp2, "mat3x3 preinc_param");
        tmp1 = m133f[0];
        tmp2 = m233f[0];
        m133f[3] = tmp1++;
        m233f[3] = tmp2++;
        print_mat<3, 3, float>(m133f[3], m233f[3], "mat3x3 postinc_res");
        print_mat<3, 3, float>(tmp1, tmp2, "mat3x3 postinc_param");
        tmp1 = m133f[0];
        tmp2 = m233f[0];
        m133f[3] = --tmp1;
        m233f[3] = --tmp2;
        print_mat<3, 3, float>(m133f[3], m233f[3], "mat3x3 predec_res");
        print_mat<3, 3, float>(tmp1, tmp2, "mat3x3 predec_param");
        tmp1 = m133f[0];
        tmp2 = m233f[0];
        m133f[3] = tmp1--;
        m233f[3] = tmp2--;
        print_mat<3, 3, float>(m133f[3], m233f[3], "mat3x3 postdec_res");
        print_mat<3, 3, float>(tmp1, tmp2, "mat3x3 postdec_param");
    }

    // mat3x4
    {
        glm::mat3x4 tmp1;   mat3x4 tmp2;
        print_mat<3, 4, float>((m134f[1] + f1[0]),                  (m234f[1] + f2[0]),                 "mat3x4 adds");
        print_mat<3, 4, float>(((m134f[3] = m134f[1]) += v14f[0]),  (m234f[1] + v24f[0]),               "mat3x4 addv");
        print_mat<3, 4, float>((m134f[1] + m134f[0]),               (m234f[1] + m234f[0]),              "mat3x4 addm");
        print_mat<3, 4, float>((m134f[1] - f1[0]),                  (m234f[1] - f2[0]),                 "mat3x4 subs");
        print_mat<3, 4, float>(((m134f[3] = m134f[1]) -= v14f[0]),  (m234f[1] - v24f[0]),               "mat3x4 subv");
        print_mat<3, 4, float>((m134f[1] - m134f[0]),               (m234f[1] - m234f[0]),              "mat3x4 subm");
        print_mat<3, 4, float>((m134f[1] * f1[0]),                  (m234f[1] * f2[0]),                 "mat3x4 muls");
        print_mat<3, 4, float>(((m134f[3] = m134f[1]) *= v14f[0]),  ((m234f[3] = m234f[1]) *= v24f[0]), "mat3x4 mulv");
        print_mat<3, 4, float>((m134f[1] / f1[0]),                  (m234f[1] / f2[0]),                 "mat3x4 divs");
        print_mat<3, 4, float>(((m134f[3] = m134f[1]) /= v14f[0]),  ((m234f[3] = m234f[1]) /= v24f[0]), "mat3x4 divv");
        print_mat<3, 4, float>((+m134f[1]), (+m234f[1]), "mat3x4 pos");
        print_mat<3, 4, float>((-m134f[1]), (-m234f[1]), "mat3x4 neg");
        tmp1 = m134f[0];
        tmp2 = m234f[0];
        m134f[3] = ++tmp1;
        m234f[3] = ++tmp2;
        print_mat<3, 4, float>(m134f[3], m234f[3], "mat3x4 preinc_res");
        print_mat<3, 4, float>(tmp1, tmp2, "mat3x4 preinc_param");
        tmp1 = m134f[0];
        tmp2 = m234f[0];
        m134f[3] = tmp1++;
        m234f[3] = tmp2++;
        print_mat<3, 4, float>(m134f[3], m234f[3], "mat3x4 postinc_res");
        print_mat<3, 4, float>(tmp1, tmp2, "mat3x4 postinc_param");
        tmp1 = m134f[0];
        tmp2 = m234f[0];
        m134f[3] = --tmp1;
        m234f[3] = --tmp2;
        print_mat<3, 4, float>(m134f[3], m234f[3], "mat3x4 predec_res");
        print_mat<3, 4, float>(tmp1, tmp2, "mat3x4 predec_param");
        tmp1 = m134f[0];
        tmp2 = m234f[0];
        m134f[3] = tmp1--;
        m234f[3] = tmp2--;
        print_mat<3, 4, float>(m134f[3], m234f[3], "mat3x4 postdec_res");
        print_mat<3, 4, float>(tmp1, tmp2, "mat3x4 postdec_param");
    }

#endif

#ifdef GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_MAT4

    // mat4x2
    {
        glm::mat4x2 tmp1;   mat4x2 tmp2;
        print_mat<4, 2, float>((m142f[1] + f1[0]),                  (m242f[1] + f2[0]),                 "mat4x2 adds");
        print_mat<4, 2, float>(((m142f[3] = m142f[1]) += v12f[0]),  (m242f[1] + v22f[0]),               "mat4x2 addv");
        print_mat<4, 2, float>((m142f[1] + m142f[0]),               (m242f[1] + m242f[0]),              "mat4x2 addm");
        print_mat<4, 2, float>((m142f[1] - f1[0]),                  (m242f[1] - f2[0]),                 "mat4x2 subs");
        print_mat<4, 2, float>(((m142f[3] = m142f[1]) -= v12f[0]),  (m242f[1] - v22f[0]),               "mat4x2 subv");
        print_mat<4, 2, float>((m142f[1] - m142f[0]),               (m242f[1] - m242f[0]),              "mat4x2 subm");
        print_mat<4, 2, float>((m142f[1] * f1[0]),                  (m242f[1] * f2[0]),                 "mat4x2 muls");
        print_mat<4, 2, float>(((m142f[3] = m142f[1]) *= v12f[0]),  ((m242f[3] = m242f[1]) *= v22f[0]), "mat4x2 mulv");
        print_mat<4, 2, float>((m142f[1] / f1[0]),                  (m242f[1] / f2[0]),                 "mat4x2 divs");
        print_mat<4, 2, float>(((m142f[3] = m142f[1]) /= v12f[0]),  ((m242f[3] = m242f[1]) /= v22f[0]), "mat4x2 divv");
        print_mat<4, 2, float>((+m142f[1]), (+m242f[1]), "mat4x2 pos");
        print_mat<4, 2, float>((-m142f[1]), (-m242f[1]), "mat4x2 neg");
        tmp1 = m142f[0];
        tmp2 = m242f[0];
        m142f[3] = ++tmp1;
        m242f[3] = ++tmp2;
        print_mat<4, 2, float>(m142f[3], m242f[3], "mat4x2 preinc_res");
        print_mat<4, 2, float>(tmp1, tmp2, "mat4x2 preinc_param");
        tmp1 = m142f[0];
        tmp2 = m242f[0];
        m142f[3] = tmp1++;
        m242f[3] = tmp2++;
        print_mat<4, 2, float>(m142f[3], m242f[3], "mat4x2 postinc_res");
        print_mat<4, 2, float>(tmp1, tmp2, "mat4x2 postinc_param");
        tmp1 = m142f[0];
        tmp2 = m242f[0];
        m142f[3] = --tmp1;
        m242f[3] = --tmp2;
        print_mat<4, 2, float>(m142f[3], m242f[3], "mat4x2 predec_res");
        print_mat<4, 2, float>(tmp1, tmp2, "mat4x2 predec_param");
        tmp1 = m142f[0];
        tmp2 = m242f[0];
        m142f[3] = tmp1--;
        m242f[3] = tmp2--;
        print_mat<4, 2, float>(m142f[3], m242f[3], "mat4x2 postdec_res");
        print_mat<4, 2, float>(tmp1, tmp2, "mat4x2 postdec_param");
    }

    // mat4x3
    {
        glm::mat4x3 tmp1;   mat4x3 tmp2;
        print_mat<4, 3, float>((m143f[1] + f1[0]),                  (m243f[1] + f2[0]),                 "mat4x3 adds");
        print_mat<4, 3, float>(((m143f[3] = m143f[1]) += v13f[0]),  (m243f[1] + v23f[0]),               "mat4x3 addv");
        print_mat<4, 3, float>((m143f[1] + m143f[0]),               (m243f[1] + m243f[0]),              "mat4x3 addm");
        print_mat<4, 3, float>((m143f[1] - f1[0]),                  (m243f[1] - f2[0]),                 "mat4x3 subs");
        print_mat<4, 3, float>(((m143f[3] = m143f[1]) -= v13f[0]),  (m243f[1] - v23f[0]),               "mat4x3 subv");
        print_mat<4, 3, float>((m143f[1] - m143f[0]),               (m243f[1] - m243f[0]),              "mat4x3 subm");
        print_mat<4, 3, float>((m143f[1] * f1[0]),                  (m243f[1] * f2[0]),                 "mat4x3 muls");
        print_mat<4, 3, float>(((m143f[3] = m143f[1]) *= v13f[0]),  ((m243f[3] = m243f[1]) *= v23f[0]), "mat4x3 mulv");
        print_mat<4, 3, float>((m143f[1] / f1[0]),                  (m243f[1] / f2[0]),                 "mat4x3 divs");
        print_mat<4, 3, float>(((m143f[3] = m143f[1]) /= v13f[0]),  ((m243f[3] = m243f[1]) /= v23f[0]), "mat4x3 divv");
        print_mat<4, 3, float>((+m143f[1]), (+m243f[1]), "mat4x3 pos");
        print_mat<4, 3, float>((-m143f[1]), (-m243f[1]), "mat4x3 neg");
        tmp1 = m143f[0];
        tmp2 = m243f[0];
        m143f[3] = ++tmp1;
        m243f[3] = ++tmp2;
        print_mat<4, 3, float>(m143f[3], m243f[3], "mat4x3 preinc_res");
        print_mat<4, 3, float>(tmp1, tmp2, "mat4x3 preinc_param");
        tmp1 = m143f[0];
        tmp2 = m243f[0];
        m143f[3] = tmp1++;
        m243f[3] = tmp2++;
        print_mat<4, 3, float>(m143f[3], m243f[3], "mat4x3 postinc_res");
        print_mat<4, 3, float>(tmp1, tmp2, "mat4x3 postinc_param");
        tmp1 = m143f[0];
        tmp2 = m243f[0];
        m143f[3] = --tmp1;
        m243f[3] = --tmp2;
        print_mat<4, 3, float>(m143f[3], m243f[3], "mat4x3 predec_res");
        print_mat<4, 3, float>(tmp1, tmp2, "mat4x3 predec_param");
        tmp1 = m143f[0];
        tmp2 = m243f[0];
        m143f[3] = tmp1--;
        m243f[3] = tmp2--;
        print_mat<4, 3, float>(m143f[3], m243f[3], "mat4x3 postdec_res");
        print_mat<4, 3, float>(tmp1, tmp2, "mat4x3 postdec_param");
    }

    // mat4x4
    {
        glm::mat4x4 tmp1;   mat4x4 tmp2;
        print_mat<4, 4, float>((m144f[1] + f1[0]),                  (m244f[1] + f2[0]),                 "mat4x4 adds");
        print_mat<4, 4, float>(((m144f[3] = m144f[1]) += v14f[0]),  (m244f[1] + v24f[0]),               "mat4x4 addv");
        print_mat<4, 4, float>((m144f[1] + m144f[0]),               (m244f[1] + m244f[0]),              "mat4x4 addm");
        print_mat<4, 4, float>((m144f[1] - f1[0]),                  (m244f[1] - f2[0]),                 "mat4x4 subs");
        print_mat<4, 4, float>(((m144f[3] = m144f[1]) -= v14f[0]),  (m244f[1] - v24f[0]),               "mat4x4 subv");
        print_mat<4, 4, float>((m144f[1] - m144f[0]),               (m244f[1] - m244f[0]),              "mat4x4 subm");
        print_mat<4, 4, float>((m144f[1] * f1[0]),                  (m244f[1] * f2[0]),                 "mat4x4 muls");
        print_mat<4, 4, float>(((m144f[3] = m144f[1]) *= v14f[0]),  ((m244f[3] = m244f[1]) *= v24f[0]), "mat4x4 mulv");
        print_mat<4, 4, float>((m144f[1] / f1[0]),                  (m244f[1] / f2[0]),                 "mat4x4 divs");
        print_mat<4, 4, float>(((m144f[3] = m144f[1]) /= v14f[0]),  ((m244f[3] = m244f[1]) /= v24f[0]), "mat4x4 divv");
        print_mat<4, 4, float>((+m144f[1]), (+m244f[1]), "mat4x4 pos");
        print_mat<4, 4, float>((-m144f[1]), (-m244f[1]), "mat4x4 neg");
        tmp1 = m144f[0];
        tmp2 = m244f[0];
        m144f[3] = ++tmp1;
        m244f[3] = ++tmp2;
        print_mat<4, 4, float>(m144f[3], m244f[3], "mat4x4 preinc_res");
        print_mat<4, 4, float>(tmp1, tmp2, "mat4x4 preinc_param");
        tmp1 = m144f[0];
        tmp2 = m244f[0];
        m144f[3] = tmp1++;
        m244f[3] = tmp2++;
        print_mat<4, 4, float>(m144f[3], m244f[3], "mat4x4 postinc_res");
        print_mat<4, 4, float>(tmp1, tmp2, "mat4x4 postinc_param");
        tmp1 = m144f[0];
        tmp2 = m244f[0];
        m144f[3] = --tmp1;
        m244f[3] = --tmp2;
        print_mat<4, 4, float>(m144f[3], m244f[3], "mat4x4 predec_res");
        print_mat<4, 4, float>(tmp1, tmp2, "mat4x4 predec_param");
        tmp1 = m144f[0];
        tmp2 = m244f[0];
        m144f[3] = tmp1--;
        m244f[3] = tmp2--;
        print_mat<4, 4, float>(m144f[3], m244f[3], "mat4x4 postdec_res");
        print_mat<4, 4, float>(tmp1, tmp2, "mat4x4 postdec_param");
    }

#endif

#ifdef GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_DMAT2

    // dmat2x2
    {
        glm::dmat2x2 tmp1;   dmat2x2 tmp2;
        print_mat<2, 2, double>((m122d[1] + d1[0]),                  (m222d[1] + d2[0]),                 "dmat2x2 adds");
        print_mat<2, 2, double>(((m122d[3] = m122d[1]) += v12d[0]),  (m222d[1] + v22d[0]),               "dmat2x2 addv");
        print_mat<2, 2, double>((m122d[1] + m122d[0]),               (m222d[1] + m222d[0]),              "dmat2x2 addm");
        print_mat<2, 2, double>((m122d[1] - d1[0]),                  (m222d[1] - d2[0]),                 "dmat2x2 subs");
        print_mat<2, 2, double>(((m122d[3] = m122d[1]) -= v12d[0]),  (m222d[1] - v22d[0]),               "dmat2x2 subv");
        print_mat<2, 2, double>((m122d[1] - m122d[0]),               (m222d[1] - m222d[0]),              "dmat2x2 subm");
        print_mat<2, 2, double>((m122d[1] * d1[0]),                  (m222d[1] * d2[0]),                 "dmat2x2 muls");
        print_mat<2, 2, double>(((m122d[3] = m122d[1]) *= v12d[0]),  ((m222d[3] = m222d[1]) *= v22d[0]), "dmat2x2 mulv");
        print_mat<2, 2, double>((m122d[1] / d1[0]),                  (m222d[1] / d2[0]),                 "dmat2x2 divs");
        print_mat<2, 2, double>(((m122d[3] = m122d[1]) /= v12d[0]),  ((m222d[3] = m222d[1]) /= v22d[0]), "dmat2x2 divv");
        print_mat<2, 2, double>((+m122d[1]), (+m222d[1]), "dmat2x2 pos");
        print_mat<2, 2, double>((-m122d[1]), (-m222d[1]), "dmat2x2 neg");
        tmp1 = m122d[0];
        tmp2 = m222d[0];
        m122d[3] = ++tmp1;
        m222d[3] = ++tmp2;
        print_mat<2, 2, double>(m122d[3], m222d[3], "dmat2x2 preinc_res");
        print_mat<2, 2, double>(tmp1, tmp2, "dmat2x2 preinc_param");
        tmp1 = m122d[0];
        tmp2 = m222d[0];
        m122d[3] = tmp1++;
        m222d[3] = tmp2++;
        print_mat<2, 2, double>(m122d[3], m222d[3], "dmat2x2 postinc_res");
        print_mat<2, 2, double>(tmp1, tmp2, "dmat2x2 postinc_param");
        tmp1 = m122d[0];
        tmp2 = m222d[0];
        m122d[3] = --tmp1;
        m222d[3] = --tmp2;
        print_mat<2, 2, double>(m122d[3], m222d[3], "dmat2x2 predec_res");
        print_mat<2, 2, double>(tmp1, tmp2, "dmat2x2 predec_param");
        tmp1 = m122d[0];
        tmp2 = m222d[0];
        m122d[3] = tmp1--;
        m222d[3] = tmp2--;
        print_mat<2, 2, double>(m122d[3], m222d[3], "dmat2x2 postdec_res");
        print_mat<2, 2, double>(tmp1, tmp2, "dmat2x2 postdec_param");
    }

    // dmat2x3
    {
        glm::dmat2x3 tmp1;   dmat2x3 tmp2;
        print_mat<2, 3, double>((m123d[1] + d1[0]),                  (m223d[1] + d2[0]),                 "dmat2x3 adds");
        print_mat<2, 3, double>(((m123d[3] = m123d[1]) += v13d[0]),  (m223d[1] + v23d[0]),               "dmat2x3 addv");
        print_mat<2, 3, double>((m123d[1] + m123d[0]),               (m223d[1] + m223d[0]),              "dmat2x3 addm");
        print_mat<2, 3, double>((m123d[1] - d1[0]),                  (m223d[1] - d2[0]),                 "dmat2x3 subs");
        print_mat<2, 3, double>(((m123d[3] = m123d[1]) -= v13d[0]),  (m223d[1] - v23d[0]),               "dmat2x3 subv");
        print_mat<2, 3, double>((m123d[1] - m123d[0]),               (m223d[1] - m223d[0]),              "dmat2x3 subm");
        print_mat<2, 3, double>((m123d[1] * d1[0]),                  (m223d[1] * d2[0]),                 "dmat2x3 muls");
        print_mat<2, 3, double>(((m123d[3] = m123d[1]) *= v13d[0]),  ((m223d[3] = m223d[1]) *= v23d[0]), "dmat2x3 mulv");
        print_mat<2, 3, double>((m123d[1] / d1[0]),                  (m223d[1] / d2[0]),                 "dmat2x3 divs");
        print_mat<2, 3, double>(((m123d[3] = m123d[1]) /= v13d[0]),  ((m223d[3] = m223d[1]) /= v23d[0]), "dmat2x3 divv");
        print_mat<2, 3, double>((+m123d[1]), (+m223d[1]), "dmat2x3 pos");
        print_mat<2, 3, double>((-m123d[1]), (-m223d[1]), "dmat2x3 neg");
        tmp1 = m123d[0];
        tmp2 = m223d[0];
        m123d[3] = ++tmp1;
        m223d[3] = ++tmp2;
        print_mat<2, 3, double>(m123d[3], m223d[3], "dmat2x3 preinc_res");
        print_mat<2, 3, double>(tmp1, tmp2, "dmat2x3 preinc_param");
        tmp1 = m123d[0];
        tmp2 = m223d[0];
        m123d[3] = tmp1++;
        m223d[3] = tmp2++;
        print_mat<2, 3, double>(m123d[3], m223d[3], "dmat2x3 postinc_res");
        print_mat<2, 3, double>(tmp1, tmp2, "dmat2x3 postinc_param");
        tmp1 = m123d[0];
        tmp2 = m223d[0];
        m123d[3] = --tmp1;
        m223d[3] = --tmp2;
        print_mat<2, 3, double>(m123d[3], m223d[3], "dmat2x3 predec_res");
        print_mat<2, 3, double>(tmp1, tmp2, "dmat2x3 predec_param");
        tmp1 = m123d[0];
        tmp2 = m223d[0];
        m123d[3] = tmp1--;
        m223d[3] = tmp2--;
        print_mat<2, 3, double>(m123d[3], m223d[3], "dmat2x3 postdec_res");
        print_mat<2, 3, double>(tmp1, tmp2, "dmat2x3 postdec_param");
    }

    // dmat2x4
    {
        glm::dmat2x4 tmp1;   dmat2x4 tmp2;
        print_mat<2, 4, double>((m124d[1] + d1[0]),                  (m224d[1] + d2[0]),                 "dmat2x4 adds");
        print_mat<2, 4, double>(((m124d[3] = m124d[1]) += v14d[0]),  (m224d[1] + v24d[0]),               "dmat2x4 addv");
        print_mat<2, 4, double>((m124d[1] + m124d[0]),               (m224d[1] + m224d[0]),              "dmat2x4 addm");
        print_mat<2, 4, double>((m124d[1] - d1[0]),                  (m224d[1] - d2[0]),                 "dmat2x4 subs");
        print_mat<2, 4, double>(((m124d[3] = m124d[1]) -= v14d[0]),  (m224d[1] - v24d[0]),               "dmat2x4 subv");
        print_mat<2, 4, double>((m124d[1] - m124d[0]),               (m224d[1] - m224d[0]),              "dmat2x4 subm");
        print_mat<2, 4, double>((m124d[1] * d1[0]),                  (m224d[1] * d2[0]),                 "dmat2x4 muls");
        print_mat<2, 4, double>(((m124d[3] = m124d[1]) *= v14d[0]),  ((m224d[3] = m224d[1]) *= v24d[0]), "dmat2x4 mulv");
        print_mat<2, 4, double>((m124d[1] / d1[0]),                  (m224d[1] / d2[0]),                 "dmat2x4 divs");
        print_mat<2, 4, double>(((m124d[3] = m124d[1]) /= v14d[0]),  ((m224d[3] = m224d[1]) /= v24d[0]), "dmat2x4 divv");
        print_mat<2, 4, double>((+m124d[1]), (+m224d[1]), "dmat2x4 pos");
        print_mat<2, 4, double>((-m124d[1]), (-m224d[1]), "dmat2x4 neg");
        tmp1 = m124d[0];
        tmp2 = m224d[0];
        m124d[3] = ++tmp1;
        m224d[3] = ++tmp2;
        print_mat<2, 4, double>(m124d[3], m224d[3], "dmat2x4 preinc_res");
        print_mat<2, 4, double>(tmp1, tmp2, "dmat2x4 preinc_param");
        tmp1 = m124d[0];
        tmp2 = m224d[0];
        m124d[3] = tmp1++;
        m224d[3] = tmp2++;
        print_mat<2, 4, double>(m124d[3], m224d[3], "dmat2x4 postinc_res");
        print_mat<2, 4, double>(tmp1, tmp2, "dmat2x4 postinc_param");
        tmp1 = m124d[0];
        tmp2 = m224d[0];
        m124d[3] = --tmp1;
        m224d[3] = --tmp2;
        print_mat<2, 4, double>(m124d[3], m224d[3], "dmat2x4 predec_res");
        print_mat<2, 4, double>(tmp1, tmp2, "dmat2x4 predec_param");
        tmp1 = m124d[0];
        tmp2 = m224d[0];
        m124d[3] = tmp1--;
        m224d[3] = tmp2--;
        print_mat<2, 4, double>(m124d[3], m224d[3], "dmat2x4 postdec_res");
        print_mat<2, 4, double>(tmp1, tmp2, "dmat2x4 postdec_param");
    }

#endif

#ifdef GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_DMAT3

    // dmat3x2
    {
        glm::dmat3x2 tmp1;   dmat3x2 tmp2;
        print_mat<3, 2, double>((m132d[1] + d1[0]),                  (m232d[1] + d2[0]),                 "dmat3x2 adds");
        print_mat<3, 2, double>(((m132d[3] = m132d[1]) += v12d[0]),  (m232d[1] + v22d[0]),               "dmat3x2 addv");
        print_mat<3, 2, double>((m132d[1] + m132d[0]),               (m232d[1] + m232d[0]),              "dmat3x2 addm");
        print_mat<3, 2, double>((m132d[1] - d1[0]),                  (m232d[1] - d2[0]),                 "dmat3x2 subs");
        print_mat<3, 2, double>(((m132d[3] = m132d[1]) -= v12d[0]),  (m232d[1] - v22d[0]),               "dmat3x2 subv");
        print_mat<3, 2, double>((m132d[1] - m132d[0]),               (m232d[1] - m232d[0]),              "dmat3x2 subm");
        print_mat<3, 2, double>((m132d[1] * d1[0]),                  (m232d[1] * d2[0]),                 "dmat3x2 muls");
        print_mat<3, 2, double>(((m132d[3] = m132d[1]) *= v12d[0]),  ((m232d[3] = m232d[1]) *= v22d[0]), "dmat3x2 mulv");
        print_mat<3, 2, double>((m132d[1] / d1[0]),                  (m232d[1] / d2[0]),                 "dmat3x2 divs");
        print_mat<3, 2, double>(((m132d[3] = m132d[1]) /= v12d[0]),  ((m232d[3] = m232d[1]) /= v22d[0]), "dmat3x2 divv");
        print_mat<3, 2, double>((+m132d[1]), (+m232d[1]), "dmat3x2 pos");
        print_mat<3, 2, double>((-m132d[1]), (-m232d[1]), "dmat3x2 neg");
        tmp1 = m132d[0];
        tmp2 = m232d[0];
        m132d[3] = ++tmp1;
        m232d[3] = ++tmp2;
        print_mat<3, 2, double>(m132d[3], m232d[3], "dmat3x2 preinc_res");
        print_mat<3, 2, double>(tmp1, tmp2, "dmat3x2 preinc_param");
        tmp1 = m132d[0];
        tmp2 = m232d[0];
        m132d[3] = tmp1++;
        m232d[3] = tmp2++;
        print_mat<3, 2, double>(m132d[3], m232d[3], "dmat3x2 postinc_res");
        print_mat<3, 2, double>(tmp1, tmp2, "dmat3x2 postinc_param");
        tmp1 = m132d[0];
        tmp2 = m232d[0];
        m132d[3] = --tmp1;
        m232d[3] = --tmp2;
        print_mat<3, 2, double>(m132d[3], m232d[3], "dmat3x2 predec_res");
        print_mat<3, 2, double>(tmp1, tmp2, "dmat3x2 predec_param");
        tmp1 = m132d[0];
        tmp2 = m232d[0];
        m132d[3] = tmp1--;
        m232d[3] = tmp2--;
        print_mat<3, 2, double>(m132d[3], m232d[3], "dmat3x2 postdec_res");
        print_mat<3, 2, double>(tmp1, tmp2, "dmat3x2 postdec_param");
    }

    // dmat3x3
    {
        glm::dmat3x3 tmp1;   dmat3x3 tmp2;
        print_mat<3, 3, double>((m133d[1] + d1[0]),                  (m233d[1] + d2[0]),                 "dmat3x3 adds");
        print_mat<3, 3, double>(((m133d[3] = m133d[1]) += v13d[0]),  (m233d[1] + v23d[0]),               "dmat3x3 addv");
        print_mat<3, 3, double>((m133d[1] + m133d[0]),               (m233d[1] + m233d[0]),              "dmat3x3 addm");
        print_mat<3, 3, double>((m133d[1] - d1[0]),                  (m233d[1] - d2[0]),                 "dmat3x3 subs");
        print_mat<3, 3, double>(((m133d[3] = m133d[1]) -= v13d[0]),  (m233d[1] - v23d[0]),               "dmat3x3 subv");
        print_mat<3, 3, double>((m133d[1] - m133d[0]),               (m233d[1] - m233d[0]),              "dmat3x3 subm");
        print_mat<3, 3, double>((m133d[1] * d1[0]),                  (m233d[1] * d2[0]),                 "dmat3x3 muls");
        print_mat<3, 3, double>(((m133d[3] = m133d[1]) *= v13d[0]),  ((m233d[3] = m233d[1]) *= v23d[0]), "dmat3x3 mulv");
        print_mat<3, 3, double>((m133d[1] / d1[0]),                  (m233d[1] / d2[0]),                 "dmat3x3 divs");
        print_mat<3, 3, double>(((m133d[3] = m133d[1]) /= v13d[0]),  ((m233d[3] = m233d[1]) /= v23d[0]), "dmat3x3 divv");
        print_mat<3, 3, double>((+m133d[1]), (+m233d[1]), "dmat3x3 pos");
        print_mat<3, 3, double>((-m133d[1]), (-m233d[1]), "dmat3x3 neg");
        tmp1 = m133d[0];
        tmp2 = m233d[0];
        m133d[3] = ++tmp1;
        m233d[3] = ++tmp2;
        print_mat<3, 3, double>(m133d[3], m233d[3], "dmat3x3 preinc_res");
        print_mat<3, 3, double>(tmp1, tmp2, "dmat3x3 preinc_param");
        tmp1 = m133d[0];
        tmp2 = m233d[0];
        m133d[3] = tmp1++;
        m233d[3] = tmp2++;
        print_mat<3, 3, double>(m133d[3], m233d[3], "dmat3x3 postinc_res");
        print_mat<3, 3, double>(tmp1, tmp2, "dmat3x3 postinc_param");
        tmp1 = m133d[0];
        tmp2 = m233d[0];
        m133d[3] = --tmp1;
        m233d[3] = --tmp2;
        print_mat<3, 3, double>(m133d[3], m233d[3], "dmat3x3 predec_res");
        print_mat<3, 3, double>(tmp1, tmp2, "dmat3x3 predec_param");
        tmp1 = m133d[0];
        tmp2 = m233d[0];
        m133d[3] = tmp1--;
        m233d[3] = tmp2--;
        print_mat<3, 3, double>(m133d[3], m233d[3], "dmat3x3 postdec_res");
        print_mat<3, 3, double>(tmp1, tmp2, "dmat3x3 postdec_param");
    }

    // dmat3x4
    {
        glm::dmat3x4 tmp1;   dmat3x4 tmp2;
        print_mat<3, 4, double>((m134d[1] + d1[0]),                  (m234d[1] + d2[0]),                 "dmat3x4 adds");
        print_mat<3, 4, double>(((m134d[3] = m134d[1]) += v14d[0]),  (m234d[1] + v24d[0]),               "dmat3x4 addv");
        print_mat<3, 4, double>((m134d[1] + m134d[0]),               (m234d[1] + m234d[0]),              "dmat3x4 addm");
        print_mat<3, 4, double>((m134d[1] - d1[0]),                  (m234d[1] - d2[0]),                 "dmat3x4 subs");
        print_mat<3, 4, double>(((m134d[3] = m134d[1]) -= v14d[0]),  (m234d[1] - v24d[0]),               "dmat3x4 subv");
        print_mat<3, 4, double>((m134d[1] - m134d[0]),               (m234d[1] - m234d[0]),              "dmat3x4 subm");
        print_mat<3, 4, double>((m134d[1] * d1[0]),                  (m234d[1] * d2[0]),                 "dmat3x4 muls");
        print_mat<3, 4, double>(((m134d[3] = m134d[1]) *= v14d[0]),  ((m234d[3] = m234d[1]) *= v24d[0]), "dmat3x4 mulv");
        print_mat<3, 4, double>((m134d[1] / d1[0]),                  (m234d[1] / d2[0]),                 "dmat3x4 divs");
        print_mat<3, 4, double>(((m134d[3] = m134d[1]) /= v14d[0]),  ((m234d[3] = m234d[1]) /= v24d[0]), "dmat3x4 divv");
        print_mat<3, 4, double>((+m134d[1]), (+m234d[1]), "dmat3x4 pos");
        print_mat<3, 4, double>((-m134d[1]), (-m234d[1]), "dmat3x4 neg");
        tmp1 = m134d[0];
        tmp2 = m234d[0];
        m134d[3] = ++tmp1;
        m234d[3] = ++tmp2;
        print_mat<3, 4, double>(m134d[3], m234d[3], "dmat3x4 preinc_res");
        print_mat<3, 4, double>(tmp1, tmp2, "dmat3x4 preinc_param");
        tmp1 = m134d[0];
        tmp2 = m234d[0];
        m134d[3] = tmp1++;
        m234d[3] = tmp2++;
        print_mat<3, 4, double>(m134d[3], m234d[3], "dmat3x4 postinc_res");
        print_mat<3, 4, double>(tmp1, tmp2, "dmat3x4 postinc_param");
        tmp1 = m134d[0];
        tmp2 = m234d[0];
        m134d[3] = --tmp1;
        m234d[3] = --tmp2;
        print_mat<3, 4, double>(m134d[3], m234d[3], "dmat3x4 predec_res");
        print_mat<3, 4, double>(tmp1, tmp2, "dmat3x4 predec_param");
        tmp1 = m134d[0];
        tmp2 = m234d[0];
        m134d[3] = tmp1--;
        m234d[3] = tmp2--;
        print_mat<3, 4, double>(m134d[3], m234d[3], "dmat3x4 postdec_res");
        print_mat<3, 4, double>(tmp1, tmp2, "dmat3x4 postdec_param");
    }

#endif

#ifdef GLM2_TEST_MATRIX_ARITHMETIC_OPERATORS_DMAT4

    // dmat4x2
    {
        glm::dmat4x2 tmp1;   dmat4x2 tmp2;
        print_mat<4, 2, double>((m142d[1] + d1[0]),                  (m242d[1] + d2[0]),                 "dmat4x2 adds");
        print_mat<4, 2, double>(((m142d[3] = m142d[1]) += v12d[0]),  (m242d[1] + v22d[0]),               "dmat4x2 addv");
        print_mat<4, 2, double>((m142d[1] + m142d[0]),               (m242d[1] + m242d[0]),              "dmat4x2 addm");
        print_mat<4, 2, double>((m142d[1] - d1[0]),                  (m242d[1] - d2[0]),                 "dmat4x2 subs");
        print_mat<4, 2, double>(((m142d[3] = m142d[1]) -= v12d[0]),  (m242d[1] - v22d[0]),               "dmat4x2 subv");
        print_mat<4, 2, double>((m142d[1] - m142d[0]),               (m242d[1] - m242d[0]),              "dmat4x2 subm");
        print_mat<4, 2, double>((m142d[1] * d1[0]),                  (m242d[1] * d2[0]),                 "dmat4x2 muls");
        print_mat<4, 2, double>(((m142d[3] = m142d[1]) *= v12d[0]),  ((m242d[3] = m242d[1]) *= v22d[0]), "dmat4x2 mulv");
        print_mat<4, 2, double>((m142d[1] / d1[0]),                  (m242d[1] / d2[0]),                 "dmat4x2 divs");
        print_mat<4, 2, double>(((m142d[3] = m142d[1]) /= v12d[0]),  ((m242d[3] = m242d[1]) /= v22d[0]), "dmat4x2 divv");
        print_mat<4, 2, double>((+m142d[1]), (+m242d[1]), "dmat4x2 pos");
        print_mat<4, 2, double>((-m142d[1]), (-m242d[1]), "dmat4x2 neg");
        tmp1 = m142d[0];
        tmp2 = m242d[0];
        m142d[3] = ++tmp1;
        m242d[3] = ++tmp2;
        print_mat<4, 2, double>(m142d[3], m242d[3], "dmat4x2 preinc_res");
        print_mat<4, 2, double>(tmp1, tmp2, "dmat4x2 preinc_param");
        tmp1 = m142d[0];
        tmp2 = m242d[0];
        m142d[3] = tmp1++;
        m242d[3] = tmp2++;
        print_mat<4, 2, double>(m142d[3], m242d[3], "dmat4x2 postinc_res");
        print_mat<4, 2, double>(tmp1, tmp2, "dmat4x2 postinc_param");
        tmp1 = m142d[0];
        tmp2 = m242d[0];
        m142d[3] = --tmp1;
        m242d[3] = --tmp2;
        print_mat<4, 2, double>(m142d[3], m242d[3], "dmat4x2 predec_res");
        print_mat<4, 2, double>(tmp1, tmp2, "dmat4x2 predec_param");
        tmp1 = m142d[0];
        tmp2 = m242d[0];
        m142d[3] = tmp1--;
        m242d[3] = tmp2--;
        print_mat<4, 2, double>(m142d[3], m242d[3], "dmat4x2 postdec_res");
        print_mat<4, 2, double>(tmp1, tmp2, "dmat4x2 postdec_param");
    }

    // dmat4x3
    {
        glm::dmat4x3 tmp1;   dmat4x3 tmp2;
        print_mat<4, 3, double>((m143d[1] + d1[0]),                  (m243d[1] + d2[0]),                 "dmat4x3 adds");
        print_mat<4, 3, double>(((m143d[3] = m143d[1]) += v13d[0]),  (m243d[1] + v23d[0]),               "dmat4x3 addv");
        print_mat<4, 3, double>((m143d[1] + m143d[0]),               (m243d[1] + m243d[0]),              "dmat4x3 addm");
        print_mat<4, 3, double>((m143d[1] - d1[0]),                  (m243d[1] - d2[0]),                 "dmat4x3 subs");
        print_mat<4, 3, double>(((m143d[3] = m143d[1]) -= v13d[0]),  (m243d[1] - v23d[0]),               "dmat4x3 subv");
        print_mat<4, 3, double>((m143d[1] - m143d[0]),               (m243d[1] - m243d[0]),              "dmat4x3 subm");
        print_mat<4, 3, double>((m143d[1] * d1[0]),                  (m243d[1] * d2[0]),                 "dmat4x3 muls");
        print_mat<4, 3, double>(((m143d[3] = m143d[1]) *= v13d[0]),  ((m243d[3] = m243d[1]) *= v23d[0]), "dmat4x3 mulv");
        print_mat<4, 3, double>((m143d[1] / d1[0]),                  (m243d[1] / d2[0]),                 "dmat4x3 divs");
        print_mat<4, 3, double>(((m143d[3] = m143d[1]) /= v13d[0]),  ((m243d[3] = m243d[1]) /= v23d[0]), "dmat4x3 divv");
        print_mat<4, 3, double>((+m143d[1]), (+m243d[1]), "dmat4x3 pos");
        print_mat<4, 3, double>((-m143d[1]), (-m243d[1]), "dmat4x3 neg");
        tmp1 = m143d[0];
        tmp2 = m243d[0];
        m143d[3] = ++tmp1;
        m243d[3] = ++tmp2;
        print_mat<4, 3, double>(m143d[3], m243d[3], "dmat4x3 preinc_res");
        print_mat<4, 3, double>(tmp1, tmp2, "dmat4x3 preinc_param");
        tmp1 = m143d[0];
        tmp2 = m243d[0];
        m143d[3] = tmp1++;
        m243d[3] = tmp2++;
        print_mat<4, 3, double>(m143d[3], m243d[3], "dmat4x3 postinc_res");
        print_mat<4, 3, double>(tmp1, tmp2, "dmat4x3 postinc_param");
        tmp1 = m143d[0];
        tmp2 = m243d[0];
        m143d[3] = --tmp1;
        m243d[3] = --tmp2;
        print_mat<4, 3, double>(m143d[3], m243d[3], "dmat4x3 predec_res");
        print_mat<4, 3, double>(tmp1, tmp2, "dmat4x3 predec_param");
        tmp1 = m143d[0];
        tmp2 = m243d[0];
        m143d[3] = tmp1--;
        m243d[3] = tmp2--;
        print_mat<4, 3, double>(m143d[3], m243d[3], "dmat4x3 postdec_res");
        print_mat<4, 3, double>(tmp1, tmp2, "dmat4x3 postdec_param");
    }

    // dmat4x4
    {
        glm::dmat4x4 tmp1;   dmat4x4 tmp2;
        print_mat<4, 4, double>((m144d[1] + d1[0]),                  (m244d[1] + d2[0]),                 "dmat4x4 adds");
        print_mat<4, 4, double>(((m144d[3] = m144d[1]) += v14d[0]),  (m244d[1] + v24d[0]),               "dmat4x4 addv");
        print_mat<4, 4, double>((m144d[1] + m144d[0]),               (m244d[1] + m244d[0]),              "dmat4x4 addm");
        print_mat<4, 4, double>((m144d[1] - d1[0]),                  (m244d[1] - d2[0]),                 "dmat4x4 subs");
        print_mat<4, 4, double>(((m144d[3] = m144d[1]) -= v14d[0]),  (m244d[1] - v24d[0]),               "dmat4x4 subv");
        print_mat<4, 4, double>((m144d[1] - m144d[0]),               (m244d[1] - m244d[0]),              "dmat4x4 subm");
        print_mat<4, 4, double>((m144d[1] * d1[0]),                  (m244d[1] * d2[0]),                 "dmat4x4 muls");
        print_mat<4, 4, double>(((m144d[3] = m144d[1]) *= v14d[0]),  ((m244d[3] = m244d[1]) *= v24d[0]), "dmat4x4 mulv");
        print_mat<4, 4, double>((m144d[1] / d1[0]),                  (m244d[1] / d2[0]),                 "dmat4x4 divs");
        print_mat<4, 4, double>(((m144d[3] = m144d[1]) /= v14d[0]),  ((m244d[3] = m244d[1]) /= v24d[0]), "dmat4x4 divv");
        print_mat<4, 4, double>((+m144d[1]), (+m244d[1]), "dmat4x4 pos");
        print_mat<4, 4, double>((-m144d[1]), (-m244d[1]), "dmat4x4 neg");
        tmp1 = m144d[0];
        tmp2 = m244d[0];
        m144d[3] = ++tmp1;
        m244d[3] = ++tmp2;
        print_mat<4, 4, double>(m144d[3], m244d[3], "dmat4x4 preinc_res");
        print_mat<4, 4, double>(tmp1, tmp2, "dmat4x4 preinc_param");
        tmp1 = m144d[0];
        tmp2 = m244d[0];
        m144d[3] = tmp1++;
        m244d[3] = tmp2++;
        print_mat<4, 4, double>(m144d[3], m244d[3], "dmat4x4 postinc_res");
        print_mat<4, 4, double>(tmp1, tmp2, "dmat4x4 postinc_param");
        tmp1 = m144d[0];
        tmp2 = m244d[0];
        m144d[3] = --tmp1;
        m244d[3] = --tmp2;
        print_mat<4, 4, double>(m144d[3], m244d[3], "dmat4x4 predec_res");
        print_mat<4, 4, double>(tmp1, tmp2, "dmat4x4 predec_param");
        tmp1 = m144d[0];
        tmp2 = m244d[0];
        m144d[3] = tmp1--;
        m244d[3] = tmp2--;
        print_mat<4, 4, double>(m144d[3], m244d[3], "dmat4x4 postdec_res");
        print_mat<4, 4, double>(tmp1, tmp2, "dmat4x4 postdec_param");
    }
#endif

#ifdef GLM2_TEST_MATRIX_CMP_OPERATORS

    // mat2x2
    {
        const __m128 tmp1[1] = {_mm_set_ps(0,0, 0,0)};
        const __m128 tmp2[1] = {_mm_set_ps(0,0, 0,0)};
        print_single<bool>((glm::mat2x2(0,0, 0,0) == glm::mat2x2(0,0, 0,0)), mat2x2(tmp1) == mat2x2(tmp2), "mat2x2 cmpeq");
        print_single<bool>((glm::mat2x2(0,0, 0,0) != glm::mat2x2(0,0, 0,0)), mat2x2(tmp1) != mat2x2(tmp2), "mat2x2 cmpneq");
        const __m128 tmp3[1] = {_mm_set_ps(0,0, 0,1)};
        const __m128 tmp4[1] = {_mm_set_ps(0,0, 0,0)};
        print_single<bool>((glm::mat2x2(1,0, 0,0) == glm::mat2x2(0,0, 0,0)), mat2x2(tmp3) == mat2x2(tmp4), "mat2x2 cmpeq");
        print_single<bool>((glm::mat2x2(1,0, 0,0) != glm::mat2x2(0,0, 0,0)), mat2x2(tmp3) != mat2x2(tmp4), "mat2x2 cmpneq");
        const __m128 tmp5[1] = {_mm_set_ps(0,0, 0,0)};
        const __m128 tmp6[1] = {_mm_set_ps(0,1, 0,0)};
        print_single<bool>((glm::mat2x2(0,0, 0,0) == glm::mat2x2(0,0, 1,0)), mat2x2(tmp5) == mat2x2(tmp6), "mat2x2 cmpeq");
        print_single<bool>((glm::mat2x2(0,0, 0,0) != glm::mat2x2(0,0, 1,0)), mat2x2(tmp5) != mat2x2(tmp6), "mat2x2 cmpneq");
    }

    // mat2x3
    {
        const __m128 tmp1[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp2[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat2x3(0,0,0, 0,0,0) == glm::mat2x3(0,0,0, 0,0,0)), mat2x3(tmp1) == mat2x3(tmp2), "mat2x3 cmpeq");
        print_single<bool>((glm::mat2x3(0,0,0, 0,0,0) != glm::mat2x3(0,0,0, 0,0,0)), mat2x3(tmp1) != mat2x3(tmp2), "mat2x3 cmpneq");
        const __m128 tmp3[2] = {_mm_set_ps(0,0,0,1), _mm_set_ps(0,0,0,0)};
        const __m128 tmp4[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat2x3(1,0,0, 0,0,0) == glm::mat2x3(0,0,0, 0,0,0)), mat2x3(tmp3) == mat2x3(tmp4), "mat2x3 cmpeq");
        print_single<bool>((glm::mat2x3(1,0,0, 0,0,0) != glm::mat2x3(0,0,0, 0,0,0)), mat2x3(tmp3) != mat2x3(tmp4), "mat2x3 cmpneq");
        const __m128 tmp5[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp6[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,1,0)};
        print_single<bool>((glm::mat2x3(0,0,0, 0,0,0) == glm::mat2x3(0,0,0, 0,1,0)), mat2x3(tmp5) == mat2x3(tmp6), "mat2x3 cmpeq");
        print_single<bool>((glm::mat2x3(0,0,0, 0,0,0) != glm::mat2x3(0,0,0, 0,1,0)), mat2x3(tmp5) != mat2x3(tmp6), "mat2x3 cmpneq");
        const __m128 tmp7[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(1,0,0,0)};
        const __m128 tmp8[2] = {_mm_set_ps(1,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat2x3(0,0,0, 0,0,0) == glm::mat2x3(0,0,0, 0,0,0)), mat2x3(tmp7) == mat2x3(tmp8), "mat2x3 cmpeq");
        print_single<bool>((glm::mat2x3(0,0,0, 0,0,0) != glm::mat2x3(0,0,0, 0,0,0)), mat2x3(tmp7) != mat2x3(tmp8), "mat2x3 cmpneq");
    }

    // mat2x4
    {
        const __m128 tmp1[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp2[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat2x4(0,0,0,0, 0,0,0,0) == glm::mat2x4(0,0,0,0, 0,0,0,0)), mat2x4(tmp1) == mat2x4(tmp2), "mat2x4 cmpeq");
        print_single<bool>((glm::mat2x4(0,0,0,0, 0,0,0,0) != glm::mat2x4(0,0,0,0, 0,0,0,0)), mat2x4(tmp1) != mat2x4(tmp2), "mat2x4 cmpneq");
        const __m128 tmp3[2] = {_mm_set_ps(0,0,0,1), _mm_set_ps(0,0,0,0)};
        const __m128 tmp4[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat2x4(1,0,0,0, 0,0,0,0) == glm::mat2x4(0,0,0,0, 0,0,0,0)), mat2x4(tmp3) == mat2x4(tmp4), "mat2x4 cmpeq");
        print_single<bool>((glm::mat2x4(1,0,0,0, 0,0,0,0) != glm::mat2x4(0,0,0,0, 0,0,0,0)), mat2x4(tmp3) != mat2x4(tmp4), "mat2x4 cmpneq");
        const __m128 tmp5[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp6[2] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,1,0,0)};
        print_single<bool>((glm::mat2x4(0,0,0,0, 0,0,0,0) == glm::mat2x4(0,0,0,0, 0,1,0,0)), mat2x4(tmp5) == mat2x4(tmp6), "mat2x4 cmpeq");
        print_single<bool>((glm::mat2x4(0,0,0,0, 0,0,0,0) != glm::mat2x4(0,0,0,0, 0,1,0,0)), mat2x4(tmp5) != mat2x4(tmp6), "mat2x4 cmpneq");
    }

    // mat3x2
    {
        const __m128 tmp2[2] = {_mm_set_ps(0,0, 0,0), _mm_set_ps(0,0, 0,0)};
        const __m128 tmp1[2] = {_mm_set_ps(0,0, 0,0), _mm_set_ps(0,0, 0,0)};
        print_single<bool>((glm::mat3x2(0,0, 0,0, 0,0) == glm::mat3x2(0,0, 0,0, 0,0)), mat3x2(tmp1) == mat3x2(tmp2), "mat3x2 cmpeq");
        print_single<bool>((glm::mat3x2(0,0, 0,0, 0,0) != glm::mat3x2(0,0, 0,0, 0,0)), mat3x2(tmp1) != mat3x2(tmp2), "mat3x2 cmpneq");
        const __m128 tmp3[2] = {_mm_set_ps(0,0, 0,1), _mm_set_ps(0,0, 0,0)};
        const __m128 tmp4[2] = {_mm_set_ps(0,0, 0,0), _mm_set_ps(0,0, 0,0)};
        print_single<bool>((glm::mat3x2(1,0, 0,0, 0,0) == glm::mat3x2(0,0, 0,0, 0,0)), mat3x2(tmp3) == mat3x2(tmp4), "mat3x2 cmpeq");
        print_single<bool>((glm::mat3x2(1,0, 0,0, 0,0) != glm::mat3x2(0,0, 0,0, 0,0)), mat3x2(tmp3) != mat3x2(tmp4), "mat3x2 cmpneq");
        const __m128 tmp5[2] = {_mm_set_ps(0,0, 0,0), _mm_set_ps(0,0, 0,0)};
        const __m128 tmp6[2] = {_mm_set_ps(0,1, 0,0), _mm_set_ps(0,0, 0,0)};
        print_single<bool>((glm::mat3x2(0,0, 0,0, 0,0) == glm::mat3x2(0,0, 1,0, 0,0)), mat3x2(tmp5) == mat3x2(tmp6), "mat3x2 cmpeq");
        print_single<bool>((glm::mat3x2(0,0, 0,0, 0,0) != glm::mat3x2(0,0, 1,0, 0,0)), mat3x2(tmp5) != mat3x2(tmp6), "mat3x2 cmpneq");
    }

    // mat3x3
    {
        const __m128 tmp1[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp2[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat3x3(0,0,0, 0,0,0, 0,0,0) == glm::mat3x3(0,0,0, 0,0,0, 0,0,0)), mat3x3(tmp1) == mat3x3(tmp2), "mat3x3 cmpeq");
        print_single<bool>((glm::mat3x3(0,0,0, 0,0,0, 0,0,0) != glm::mat3x3(0,0,0, 0,0,0, 0,0,0)), mat3x3(tmp1) != mat3x3(tmp2), "mat3x3 cmpneq");
        const __m128 tmp3[3] = {_mm_set_ps(0,1,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp4[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat3x3(0,0,1, 0,0,0, 0,0,0) == glm::mat3x3(0,0,0, 0,0,0, 0,0,0)), mat3x3(tmp3) == mat3x3(tmp4), "mat3x3 cmpeq");
        print_single<bool>((glm::mat3x3(0,0,1, 0,0,0, 0,0,0) != glm::mat3x3(0,0,0, 0,0,0, 0,0,0)), mat3x3(tmp3) != mat3x3(tmp4), "mat3x3 cmpneq");
        const __m128 tmp5[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp6[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,1)};
        print_single<bool>((glm::mat3x3(0,0,0, 0,0,0, 0,0,0) == glm::mat3x3(0,0,0, 0,0,0, 1,0,0)), mat3x3(tmp5) == mat3x3(tmp6), "mat3x3 cmpeq");
        print_single<bool>((glm::mat3x3(0,0,0, 0,0,0, 0,0,0) != glm::mat3x3(0,0,0, 0,0,0, 1,0,0)), mat3x3(tmp5) != mat3x3(tmp6), "mat3x3 cmpneq");
        const __m128 tmp7[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(1,0,0,0), _mm_set_ps(1,0,0,0)};
        const __m128 tmp8[3] = {_mm_set_ps(1,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat3x3(0,0,0, 0,0,0, 0,0,0) == glm::mat3x3(0,0,0, 0,0,0, 0,0,0)), mat3x3(tmp7) == mat3x3(tmp8), "mat3x3 cmpeq");
        print_single<bool>((glm::mat3x3(0,0,0, 0,0,0, 0,0,0) != glm::mat3x3(0,0,0, 0,0,0, 0,0,0)), mat3x3(tmp7) != mat3x3(tmp8), "mat3x3 cmpneq");
    }

    // mat3x4
    {
        const __m128 tmp1[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp2[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0) == glm::mat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0)), mat3x4(tmp1) == mat3x4(tmp2), "mat3x4 cmpeq");
        print_single<bool>((glm::mat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0) != glm::mat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0)), mat3x4(tmp1) != mat3x4(tmp2), "mat3x4 cmpneq");
        const __m128 tmp3[3] = {_mm_set_ps(0,0,1,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp4[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat3x4(0,1,0,0, 0,0,0,0, 0,0,0,0) == glm::mat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0)), mat3x4(tmp3) == mat3x4(tmp4), "mat3x4 cmpeq");
        print_single<bool>((glm::mat3x4(0,1,0,0, 0,0,0,0, 0,0,0,0) != glm::mat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0)), mat3x4(tmp3) != mat3x4(tmp4), "mat3x4 cmpneq");
        const __m128 tmp5[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp6[3] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,1,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0) == glm::mat3x4(0,0,0,0, 0,0,1,0, 0,0,0,0)), mat3x4(tmp5) == mat3x4(tmp6), "mat3x4 cmpeq");
        print_single<bool>((glm::mat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0) != glm::mat3x4(0,0,0,0, 0,0,1,0, 0,0,0,0)), mat3x4(tmp5) != mat3x4(tmp6), "mat3x4 cmpneq");
    }

    // mat4x2
    {
        const __m128 tmp2[2] = {_mm_set_ps(0,0, 0,0), _mm_set_ps(0,0, 0,0)};
        const __m128 tmp1[2] = {_mm_set_ps(0,0, 0,0), _mm_set_ps(0,0, 0,0)};
        print_single<bool>((glm::mat4x2(0,0, 0,0, 0,0, 0,0) == glm::mat4x2(0,0, 0,0, 0,0, 0,0)), mat4x2(tmp1) == mat4x2(tmp2), "mat4x2 cmpeq");
        print_single<bool>((glm::mat4x2(0,0, 0,0, 0,0, 0,0) != glm::mat4x2(0,0, 0,0, 0,0, 0,0)), mat4x2(tmp1) != mat4x2(tmp2), "mat4x2 cmpneq");
        const __m128 tmp3[2] = {_mm_set_ps(0,1, 0,0), _mm_set_ps(0,0, 0,0)};
        const __m128 tmp4[2] = {_mm_set_ps(0,0, 0,0), _mm_set_ps(0,0, 0,0)};
        print_single<bool>((glm::mat4x2(0,0, 1,0, 0,0, 0,0) == glm::mat4x2(0,0, 0,0, 0,0, 0,0)), mat4x2(tmp3) == mat4x2(tmp4), "mat4x2 cmpeq");
        print_single<bool>((glm::mat4x2(0,0, 1,0, 0,0, 0,0) != glm::mat4x2(0,0, 0,0, 0,0, 0,0)), mat4x2(tmp3) != mat4x2(tmp4), "mat4x2 cmpneq");
        const __m128 tmp5[2] = {_mm_set_ps(0,0, 0,0), _mm_set_ps(0,0, 0,0)};
        const __m128 tmp6[2] = {_mm_set_ps(0,0, 0,0), _mm_set_ps(1,0, 0,0)};
        print_single<bool>((glm::mat4x2(0,0, 0,0, 0,0, 0,0) == glm::mat4x2(0,0, 0,0, 0,0, 0,1)), mat4x2(tmp5) == mat4x2(tmp6), "mat4x2 cmpeq");
        print_single<bool>((glm::mat4x2(0,0, 0,0, 0,0, 0,0) != glm::mat4x2(0,0, 0,0, 0,0, 0,1)), mat4x2(tmp5) != mat4x2(tmp6), "mat4x2 cmpneq");
    }

    // mat4x3
    {
        const __m128 tmp1[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp2[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) == glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), mat4x3(tmp1) == mat4x3(tmp2), "mat4x3 cmpeq");
        print_single<bool>((glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) != glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), mat4x3(tmp1) != mat4x3(tmp2), "mat4x3 cmpneq");
        const __m128 tmp3[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,1), _mm_set_ps(0,0,0,0)};
        const __m128 tmp4[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat4x3(0,0,0, 0,0,0, 1,0,0, 0,0,0) == glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), mat4x3(tmp3) == mat4x3(tmp4), "mat4x3 cmpeq");
        print_single<bool>((glm::mat4x3(0,0,0, 0,0,0, 1,0,0, 0,0,0) != glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), mat4x3(tmp3) != mat4x3(tmp4), "mat4x3 cmpneq");
        const __m128 tmp5[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp6[4] = {_mm_set_ps(0,0,1,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) == glm::mat4x3(0,1,0, 0,0,0, 0,0,0, 0,0,0)), mat4x3(tmp5) == mat4x3(tmp6), "mat4x3 cmpeq");
        print_single<bool>((glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) != glm::mat4x3(0,1,0, 0,0,0, 0,0,0, 0,0,0)), mat4x3(tmp5) != mat4x3(tmp6), "mat4x3 cmpneq");
        const __m128 tmp7[4] = {_mm_set_ps(1,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(1,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp8[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(1,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(1,0,0,0)};
        print_single<bool>((glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) == glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), mat4x3(tmp7) == mat4x3(tmp8), "mat4x3 cmpeq");
        print_single<bool>((glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) != glm::mat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), mat4x3(tmp7) != mat4x3(tmp8), "mat4x3 cmpneq");
    }

    // mat4x4
    {
        const __m128 tmp1[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp2[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0) == glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), mat4x4(tmp1) == mat4x4(tmp2), "mat4x4 cmpeq");
        print_single<bool>((glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0) != glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), mat4x4(tmp1) != mat4x4(tmp2), "mat4x4 cmpneq");
        const __m128 tmp3[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,1,0,0)};
        const __m128 tmp4[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,1,0) == glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), mat4x4(tmp3) == mat4x4(tmp4), "mat4x4 cmpeq");
        print_single<bool>((glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,1,0) != glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), mat4x4(tmp3) != mat4x4(tmp4), "mat4x4 cmpneq");
        const __m128 tmp5[4] = {_mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        const __m128 tmp6[4] = {_mm_set_ps(0,1,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0), _mm_set_ps(0,0,0,0)};
        print_single<bool>((glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0) == glm::mat4x4(0,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), mat4x4(tmp5) == mat4x4(tmp6), "mat4x4 cmpeq");
        print_single<bool>((glm::mat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0) != glm::mat4x4(0,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), mat4x4(tmp5) != mat4x4(tmp6), "mat4x4 cmpneq");
    }

    // dmat2x2
    {
        const __m256d tmp1[1] = {_mm256_set_pd(0,0, 0,0)};
        const __m256d tmp2[1] = {_mm256_set_pd(0,0, 0,0)};
        print_single<bool>((glm::dmat2x2(0,0, 0,0) == glm::dmat2x2(0,0, 0,0)), dmat2x2(tmp1) == dmat2x2(tmp2), "dmat2x2 cmpeq");
        print_single<bool>((glm::dmat2x2(0,0, 0,0) != glm::dmat2x2(0,0, 0,0)), dmat2x2(tmp1) != dmat2x2(tmp2), "dmat2x2 cmpneq");
        const __m256d tmp3[1] = {_mm256_set_pd(0,0, 0,1)};
        const __m256d tmp4[1] = {_mm256_set_pd(0,0, 0,0)};
        print_single<bool>((glm::dmat2x2(1,0, 0,0) == glm::dmat2x2(0,0, 0,0)), dmat2x2(tmp3) == dmat2x2(tmp4), "dmat2x2 cmpeq");
        print_single<bool>((glm::dmat2x2(1,0, 0,0) != glm::dmat2x2(0,0, 0,0)), dmat2x2(tmp3) != dmat2x2(tmp4), "dmat2x2 cmpneq");
        const __m256d tmp5[1] = {_mm256_set_pd(0,0, 0,0)};
        const __m256d tmp6[1] = {_mm256_set_pd(0,1, 0,0)};
        print_single<bool>((glm::dmat2x2(0,0, 0,0) == glm::dmat2x2(0,0, 1,0)), dmat2x2(tmp5) == dmat2x2(tmp6), "dmat2x2 cmpeq");
        print_single<bool>((glm::dmat2x2(0,0, 0,0) != glm::dmat2x2(0,0, 1,0)), dmat2x2(tmp5) != dmat2x2(tmp6), "dmat2x2 cmpneq");
    }

    // dmat2x3
    {
        const __m256d tmp1[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp2[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat2x3(0,0,0, 0,0,0) == glm::dmat2x3(0,0,0, 0,0,0)), dmat2x3(tmp1) == dmat2x3(tmp2), "dmat2x3 cmpeq");
        print_single<bool>((glm::dmat2x3(0,0,0, 0,0,0) != glm::dmat2x3(0,0,0, 0,0,0)), dmat2x3(tmp1) != dmat2x3(tmp2), "dmat2x3 cmpneq");
        const __m256d tmp3[2] = {_mm256_set_pd(0,0,0,1), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp4[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat2x3(1,0,0, 0,0,0) == glm::dmat2x3(0,0,0, 0,0,0)), dmat2x3(tmp3) == dmat2x3(tmp4), "dmat2x3 cmpeq");
        print_single<bool>((glm::dmat2x3(1,0,0, 0,0,0) != glm::dmat2x3(0,0,0, 0,0,0)), dmat2x3(tmp3) != dmat2x3(tmp4), "dmat2x3 cmpneq");
        const __m256d tmp5[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp6[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,1,0)};
        print_single<bool>((glm::dmat2x3(0,0,0, 0,0,0) == glm::dmat2x3(0,0,0, 0,1,0)), dmat2x3(tmp5) == dmat2x3(tmp6), "dmat2x3 cmpeq");
        print_single<bool>((glm::dmat2x3(0,0,0, 0,0,0) != glm::dmat2x3(0,0,0, 0,1,0)), dmat2x3(tmp5) != dmat2x3(tmp6), "dmat2x3 cmpneq");
        const __m256d tmp7[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(1,0,0,0)};
        const __m256d tmp8[2] = {_mm256_set_pd(1,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat2x3(0,0,0, 0,0,0) == glm::dmat2x3(0,0,0, 0,0,0)), dmat2x3(tmp7) == dmat2x3(tmp8), "dmat2x3 cmpeq");
        print_single<bool>((glm::dmat2x3(0,0,0, 0,0,0) != glm::dmat2x3(0,0,0, 0,0,0)), dmat2x3(tmp7) != dmat2x3(tmp8), "dmat2x3 cmpneq");
    }

    // dmat2x4
    {
        const __m256d tmp1[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp2[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat2x4(0,0,0,0, 0,0,0,0) == glm::dmat2x4(0,0,0,0, 0,0,0,0)), dmat2x4(tmp1) == dmat2x4(tmp2), "dmat2x4 cmpeq");
        print_single<bool>((glm::dmat2x4(0,0,0,0, 0,0,0,0) != glm::dmat2x4(0,0,0,0, 0,0,0,0)), dmat2x4(tmp1) != dmat2x4(tmp2), "dmat2x4 cmpneq");
        const __m256d tmp3[2] = {_mm256_set_pd(0,0,0,1), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp4[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat2x4(1,0,0,0, 0,0,0,0) == glm::dmat2x4(0,0,0,0, 0,0,0,0)), dmat2x4(tmp3) == dmat2x4(tmp4), "dmat2x4 cmpeq");
        print_single<bool>((glm::dmat2x4(1,0,0,0, 0,0,0,0) != glm::dmat2x4(0,0,0,0, 0,0,0,0)), dmat2x4(tmp3) != dmat2x4(tmp4), "dmat2x4 cmpneq");
        const __m256d tmp5[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp6[2] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,1,0,0)};
        print_single<bool>((glm::dmat2x4(0,0,0,0, 0,0,0,0) == glm::dmat2x4(0,0,0,0, 0,1,0,0)), dmat2x4(tmp5) == dmat2x4(tmp6), "dmat2x4 cmpeq");
        print_single<bool>((glm::dmat2x4(0,0,0,0, 0,0,0,0) != glm::dmat2x4(0,0,0,0, 0,1,0,0)), dmat2x4(tmp5) != dmat2x4(tmp6), "dmat2x4 cmpneq");
    }

    // dmat3x2
    {
        const __m256d tmp2[2] = {_mm256_set_pd(0,0, 0,0), _mm256_set_pd(0,0, 0,0)};
        const __m256d tmp1[2] = {_mm256_set_pd(0,0, 0,0), _mm256_set_pd(0,0, 0,0)};
        print_single<bool>((glm::dmat3x2(0,0, 0,0, 0,0) == glm::dmat3x2(0,0, 0,0, 0,0)), dmat3x2(tmp1) == dmat3x2(tmp2), "dmat3x2 cmpeq");
        print_single<bool>((glm::dmat3x2(0,0, 0,0, 0,0) != glm::dmat3x2(0,0, 0,0, 0,0)), dmat3x2(tmp1) != dmat3x2(tmp2), "dmat3x2 cmpneq");
        const __m256d tmp3[2] = {_mm256_set_pd(0,0, 0,1), _mm256_set_pd(0,0, 0,0)};
        const __m256d tmp4[2] = {_mm256_set_pd(0,0, 0,0), _mm256_set_pd(0,0, 0,0)};
        print_single<bool>((glm::dmat3x2(1,0, 0,0, 0,0) == glm::dmat3x2(0,0, 0,0, 0,0)), dmat3x2(tmp3) == dmat3x2(tmp4), "dmat3x2 cmpeq");
        print_single<bool>((glm::dmat3x2(1,0, 0,0, 0,0) != glm::dmat3x2(0,0, 0,0, 0,0)), dmat3x2(tmp3) != dmat3x2(tmp4), "dmat3x2 cmpneq");
        const __m256d tmp5[2] = {_mm256_set_pd(0,0, 0,0), _mm256_set_pd(0,0, 0,0)};
        const __m256d tmp6[2] = {_mm256_set_pd(0,1, 0,0), _mm256_set_pd(0,0, 0,0)};
        print_single<bool>((glm::dmat3x2(0,0, 0,0, 0,0) == glm::dmat3x2(0,0, 1,0, 0,0)), dmat3x2(tmp5) == dmat3x2(tmp6), "dmat3x2 cmpeq");
        print_single<bool>((glm::dmat3x2(0,0, 0,0, 0,0) != glm::dmat3x2(0,0, 1,0, 0,0)), dmat3x2(tmp5) != dmat3x2(tmp6), "dmat3x2 cmpneq");
    }

    // dmat3x3
    {
        const __m256d tmp1[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp2[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat3x3(0,0,0, 0,0,0, 0,0,0) == glm::dmat3x3(0,0,0, 0,0,0, 0,0,0)), dmat3x3(tmp1) == dmat3x3(tmp2), "dmat3x3 cmpeq");
        print_single<bool>((glm::dmat3x3(0,0,0, 0,0,0, 0,0,0) != glm::dmat3x3(0,0,0, 0,0,0, 0,0,0)), dmat3x3(tmp1) != dmat3x3(tmp2), "dmat3x3 cmpneq");
        const __m256d tmp3[3] = {_mm256_set_pd(0,1,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp4[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat3x3(0,0,1, 0,0,0, 0,0,0) == glm::dmat3x3(0,0,0, 0,0,0, 0,0,0)), dmat3x3(tmp3) == dmat3x3(tmp4), "dmat3x3 cmpeq");
        print_single<bool>((glm::dmat3x3(0,0,1, 0,0,0, 0,0,0) != glm::dmat3x3(0,0,0, 0,0,0, 0,0,0)), dmat3x3(tmp3) != dmat3x3(tmp4), "dmat3x3 cmpneq");
        const __m256d tmp5[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp6[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,1)};
        print_single<bool>((glm::dmat3x3(0,0,0, 0,0,0, 0,0,0) == glm::dmat3x3(0,0,0, 0,0,0, 1,0,0)), dmat3x3(tmp5) == dmat3x3(tmp6), "dmat3x3 cmpeq");
        print_single<bool>((glm::dmat3x3(0,0,0, 0,0,0, 0,0,0) != glm::dmat3x3(0,0,0, 0,0,0, 1,0,0)), dmat3x3(tmp5) != dmat3x3(tmp6), "dmat3x3 cmpneq");
        const __m256d tmp7[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(1,0,0,0), _mm256_set_pd(1,0,0,0)};
        const __m256d tmp8[3] = {_mm256_set_pd(1,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat3x3(0,0,0, 0,0,0, 0,0,0) == glm::dmat3x3(0,0,0, 0,0,0, 0,0,0)), dmat3x3(tmp7) == dmat3x3(tmp8), "dmat3x3 cmpeq");
        print_single<bool>((glm::dmat3x3(0,0,0, 0,0,0, 0,0,0) != glm::dmat3x3(0,0,0, 0,0,0, 0,0,0)), dmat3x3(tmp7) != dmat3x3(tmp8), "dmat3x3 cmpneq");
    }

    // dmat3x4
    {
        const __m256d tmp1[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp2[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0) == glm::dmat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat3x4(tmp1) == dmat3x4(tmp2), "dmat3x4 cmpeq");
        print_single<bool>((glm::dmat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0) != glm::dmat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat3x4(tmp1) != dmat3x4(tmp2), "dmat3x4 cmpneq");
        const __m256d tmp3[3] = {_mm256_set_pd(0,0,1,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp4[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat3x4(0,1,0,0, 0,0,0,0, 0,0,0,0) == glm::dmat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat3x4(tmp3) == dmat3x4(tmp4), "dmat3x4 cmpeq");
        print_single<bool>((glm::dmat3x4(0,1,0,0, 0,0,0,0, 0,0,0,0) != glm::dmat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat3x4(tmp3) != dmat3x4(tmp4), "dmat3x4 cmpneq");
        const __m256d tmp5[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp6[3] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,1,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0) == glm::dmat3x4(0,0,0,0, 0,0,1,0, 0,0,0,0)), dmat3x4(tmp5) == dmat3x4(tmp6), "dmat3x4 cmpeq");
        print_single<bool>((glm::dmat3x4(0,0,0,0, 0,0,0,0, 0,0,0,0) != glm::dmat3x4(0,0,0,0, 0,0,1,0, 0,0,0,0)), dmat3x4(tmp5) != dmat3x4(tmp6), "dmat3x4 cmpneq");
    }

    // dmat4x2
    {
        const __m256d tmp2[2] = {_mm256_set_pd(0,0, 0,0), _mm256_set_pd(0,0, 0,0)};
        const __m256d tmp1[2] = {_mm256_set_pd(0,0, 0,0), _mm256_set_pd(0,0, 0,0)};
        print_single<bool>((glm::dmat4x2(0,0, 0,0, 0,0, 0,0) == glm::dmat4x2(0,0, 0,0, 0,0, 0,0)), dmat4x2(tmp1) == dmat4x2(tmp2), "dmat4x2 cmpeq");
        print_single<bool>((glm::dmat4x2(0,0, 0,0, 0,0, 0,0) != glm::dmat4x2(0,0, 0,0, 0,0, 0,0)), dmat4x2(tmp1) != dmat4x2(tmp2), "dmat4x2 cmpneq");
        const __m256d tmp3[2] = {_mm256_set_pd(0,1, 0,0), _mm256_set_pd(0,0, 0,0)};
        const __m256d tmp4[2] = {_mm256_set_pd(0,0, 0,0), _mm256_set_pd(0,0, 0,0)};
        print_single<bool>((glm::dmat4x2(0,0, 1,0, 0,0, 0,0) == glm::dmat4x2(0,0, 0,0, 0,0, 0,0)), dmat4x2(tmp3) == dmat4x2(tmp4), "dmat4x2 cmpeq");
        print_single<bool>((glm::dmat4x2(0,0, 1,0, 0,0, 0,0) != glm::dmat4x2(0,0, 0,0, 0,0, 0,0)), dmat4x2(tmp3) != dmat4x2(tmp4), "dmat4x2 cmpneq");
        const __m256d tmp5[2] = {_mm256_set_pd(0,0, 0,0), _mm256_set_pd(0,0, 0,0)};
        const __m256d tmp6[2] = {_mm256_set_pd(0,0, 0,0), _mm256_set_pd(1,0, 0,0)};
        print_single<bool>((glm::dmat4x2(0,0, 0,0, 0,0, 0,0) == glm::dmat4x2(0,0, 0,0, 0,0, 0,1)), dmat4x2(tmp5) == dmat4x2(tmp6), "dmat4x2 cmpeq");
        print_single<bool>((glm::dmat4x2(0,0, 0,0, 0,0, 0,0) != glm::dmat4x2(0,0, 0,0, 0,0, 0,1)), dmat4x2(tmp5) != dmat4x2(tmp6), "dmat4x2 cmpneq");
    }

    // dmat4x3
    {
        const __m256d tmp1[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp2[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) == glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), dmat4x3(tmp1) == dmat4x3(tmp2), "dmat4x3 cmpeq");
        print_single<bool>((glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) != glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), dmat4x3(tmp1) != dmat4x3(tmp2), "dmat4x3 cmpneq");
        const __m256d tmp3[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,1), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp4[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat4x3(0,0,0, 0,0,0, 1,0,0, 0,0,0) == glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), dmat4x3(tmp3) == dmat4x3(tmp4), "dmat4x3 cmpeq");
        print_single<bool>((glm::dmat4x3(0,0,0, 0,0,0, 1,0,0, 0,0,0) != glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), dmat4x3(tmp3) != dmat4x3(tmp4), "dmat4x3 cmpneq");
        const __m256d tmp5[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp6[4] = {_mm256_set_pd(0,0,1,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) == glm::dmat4x3(0,1,0, 0,0,0, 0,0,0, 0,0,0)), dmat4x3(tmp5) == dmat4x3(tmp6), "dmat4x3 cmpeq");
        print_single<bool>((glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) != glm::dmat4x3(0,1,0, 0,0,0, 0,0,0, 0,0,0)), dmat4x3(tmp5) != dmat4x3(tmp6), "dmat4x3 cmpneq");
        const __m256d tmp7[4] = {_mm256_set_pd(1,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(1,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp8[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(1,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(1,0,0,0)};
        print_single<bool>((glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) == glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), dmat4x3(tmp7) == dmat4x3(tmp8), "dmat4x3 cmpeq");
        print_single<bool>((glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0) != glm::dmat4x3(0,0,0, 0,0,0, 0,0,0, 0,0,0)), dmat4x3(tmp7) != dmat4x3(tmp8), "dmat4x3 cmpneq");
    }

    // dmat4x4
    {
        const __m256d tmp1[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp2[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0) == glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat4x4(tmp1) == dmat4x4(tmp2), "dmat4x4 cmpeq");
        print_single<bool>((glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0) != glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat4x4(tmp1) != dmat4x4(tmp2), "dmat4x4 cmpneq");
        const __m256d tmp3[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,1,0,0)};
        const __m256d tmp4[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,1,0) == glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat4x4(tmp3) == dmat4x4(tmp4), "dmat4x4 cmpeq");
        print_single<bool>((glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,1,0) != glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat4x4(tmp3) != dmat4x4(tmp4), "dmat4x4 cmpneq");
        const __m256d tmp5[4] = {_mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        const __m256d tmp6[4] = {_mm256_set_pd(0,1,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0), _mm256_set_pd(0,0,0,0)};
        print_single<bool>((glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0) == glm::dmat4x4(0,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat4x4(tmp5) == dmat4x4(tmp6), "dmat4x4 cmpeq");
        print_single<bool>((glm::dmat4x4(0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0) != glm::dmat4x4(0,0,1,0, 0,0,0,0, 0,0,0,0, 0,0,0,0)), dmat4x4(tmp5) != dmat4x4(tmp6), "dmat4x4 cmpneq");
    }

#endif

#ifdef GLM2_TEST_MATRIX_EXT_ARITHMETIC
    
    // mat2x2
    {
        print_vec<2, float>((m122f[1] * v12f[0]), (m222f[1] * v22f[0]), "mat2x2 mul vec2");
        print_vec<2, float>((m122f[2] / v12f[0]), (m222f[2] / v22f[0]), "mat2x2 div vec2");
        print_mat<2, 2, float>((m122f[1] * m122f[0]), (m222f[1] * m222f[0]), "mat2x2 mul mat2x2");
        print_mat<3, 2, float>((m122f[1] * m132f[0]), (m222f[1] * m232f[0]), "mat2x2 mul mat3x2");
        print_mat<4, 2, float>((m122f[1] * m142f[0]), (m222f[1] * m242f[0]), "mat2x2 mul mat4x2");
        print_mat<2, 2, float>((m122f[1] / m122f[2]), (m222f[1] / m222f[2]), "mat2x2 div mat2x2");
    }

    // mat2x3
    {
        print_vec<3, float>((m123f[1] * v12f[0]), (m223f[1] * v22f[0]), "mat2x3 mul vec2");
        print_mat<2, 3, float>((m123f[1] * m122f[0]), (m223f[1] * m222f[0]), "mat2x3 mul mat2x2");
        print_mat<3, 3, float>((m123f[1] * m132f[0]), (m223f[1] * m232f[0]), "mat2x3 mul mat3x2");
        print_mat<4, 3, float>((m123f[1] * m142f[0]), (m223f[1] * m242f[0]), "mat2x3 mul mat4x2");
    }

    // mat2x4
    {
        print_vec<4, float>((m124f[1] * v12f[0]), (m224f[1] * v22f[0]), "mat2x4 mul vec2");
        print_mat<2, 4, float>((m124f[1] * m122f[0]), (m224f[1] * m222f[0]), "mat2x4 mul mat2x2");
        print_mat<3, 4, float>((m124f[1] * m132f[0]), (m224f[1] * m232f[0]), "mat2x4 mul mat3x2");
        print_mat<4, 4, float>((m124f[1] * m142f[0]), (m224f[1] * m242f[0]), "mat2x4 mul mat4x2");
    }

    // mat3x2
    {
        print_vec<2, float>((m132f[1] * v13f[0]), (m232f[1] * v23f[0]), "mat3x2 mul vec3");
        print_mat<2, 2, float>((m132f[1] * m123f[0]), (m232f[1] * m223f[0]), "mat3x2 mul mat2x3");
        print_mat<3, 2, float>((m132f[1] * m133f[0]), (m232f[1] * m233f[0]), "mat3x2 mul mat3x3");
        print_mat<4, 2, float>((m132f[1] * m143f[0]), (m232f[1] * m243f[0]), "mat3x2 mul mat4x3");
    }

    // mat3x3
    {
        print_vec<3, float>((m133f[1] * v13f[0]), (m233f[1] * v23f[0]), "mat3x3 mul vec3");
        print_vec<3, float>((m133f[2] / v13f[0]), (m233f[2] / v23f[0]), "mat3x3 div vec3");
        print_mat<2, 3, float>((m133f[1] * m123f[0]), (m233f[1] * m223f[0]), "mat3x3 mul mat2x3");
        print_mat<3, 3, float>((m133f[1] * m133f[0]), (m233f[1] * m233f[0]), "mat3x3 mul mat3x3");
        print_mat<4, 3, float>((m133f[1] * m143f[0]), (m233f[1] * m243f[0]), "mat3x3 mul mat4x3");
        print_mat<3, 3, float>((m133f[1] / m133f[2]), (m233f[1] / m233f[2]), "mat3x3 div mat3x3");
    }

    // mat3x4
    {
        print_vec<4, float>((m134f[1] * v13f[0]), (m234f[1] * v23f[0]), "mat2x4 mul vec3");
        print_mat<2, 4, float>((m134f[1] * m123f[0]), (m234f[1] * m223f[0]), "mat3x4 mul mat2x3");
        print_mat<3, 4, float>((m134f[1] * m133f[0]), (m234f[1] * m233f[0]), "mat3x4 mul mat3x3");
        print_mat<4, 4, float>((m134f[1] * m143f[0]), (m234f[1] * m243f[0]), "mat3x4 mul mat4x3");
    }

    // mat4x2
    {
        print_vec<2, float>((m142f[1] * v14f[0]), (m242f[1] * v24f[0]), "mat4x2 mul vec4");
        print_mat<2, 2, float>((m142f[1] * m124f[0]), (m242f[1] * m224f[0]), "mat4x2 mul mat2x4");
        print_mat<3, 2, float>((m142f[1] * m134f[0]), (m242f[1] * m234f[0]), "mat4x2 mul mat3x4");
        print_mat<4, 2, float>((m142f[1] * m144f[0]), (m242f[1] * m244f[0]), "mat4x2 mul mat4x4");
    }

    // mat4x3
    {
        print_vec<3, float>((m143f[1] * v14f[0]), (m243f[1] * v24f[0]), "mat4x3 mul vec4");
        print_mat<2, 3, float>((m143f[1] * m124f[0]), (m243f[1] * m224f[0]), "mat4x3 mul mat2x4");
        print_mat<3, 3, float>((m143f[1] * m134f[0]), (m243f[1] * m234f[0]), "mat4x3 mul mat3x4");
        print_mat<4, 3, float>((m143f[1] * m144f[0]), (m243f[1] * m244f[0]), "mat4x3 mul mat4x4");
    }

    // mat4x4
    {
        print_vec<4, float>((m144f[1] * v14f[0]), (m244f[1] * v24f[0]), "mat4x4 mul vec4");
        print_vec<4, float>((m144f[2] / v14f[0]), (m244f[2] / v24f[0]), "mat4x4 div vec4");
        print_mat<2, 4, float>((m144f[1] * m124f[0]), (m244f[1] * m224f[0]), "mat4x4 mul mat2x4");
        print_mat<3, 4, float>((m144f[1] * m134f[0]), (m244f[1] * m234f[0]), "mat4x4 mul mat3x4");
        print_mat<4, 4, float>((m144f[1] * m144f[0]), (m244f[1] * m244f[0]), "mat4x4 mul mat4x4");
        print_mat<4, 4, float>((m144f[1] / m144f[2]), (m244f[1] / m244f[2]), "mat4x4 div mat4x4");
    }

    // dmat2x2
    {
        print_vec<2, double>((m122d[1] * v12d[0]), (m222d[1] * v22d[0]), "dmat2x2 mul dvec2");
        print_vec<2, double>((m122d[2] / v12d[0]), (m222d[2] / v22d[0]), "dmat2x2 div dvec2");
        print_mat<2, 2, double>((m122d[1] * m122d[0]), (m222d[1] * m222d[0]), "dmat2x2 mul dmat2x2");
        print_mat<3, 2, double>((m122d[1] * m132d[0]), (m222d[1] * m232d[0]), "dmat2x2 mul dmat3x2");
        print_mat<4, 2, double>((m122d[1] * m142d[0]), (m222d[1] * m242d[0]), "dmat2x2 mul dmat4x2");
        print_mat<2, 2, double>((m122d[1] / m122d[2]), (m222d[1] / m222d[2]), "dmat2x2 div dmat2x2");
    }

    // dmat2x3
    {
        print_vec<3, double>((m123d[1] * v12d[0]), (m223d[1] * v22d[0]), "dmat2x3 mul dvec2");
        print_mat<2, 3, double>((m123d[1] * m122d[0]), (m223d[1] * m222d[0]), "dmat2x3 mul dmat2x2");
        print_mat<3, 3, double>((m123d[1] * m132d[0]), (m223d[1] * m232d[0]), "dmat2x3 mul dmat3x2");
        print_mat<4, 3, double>((m123d[1] * m142d[0]), (m223d[1] * m242d[0]), "dmat2x3 mul dmat4x2");
    }

    // dmat2x4
    {
        print_vec<4, double>((m124d[1] * v12d[0]), (m224d[1] * v22d[0]), "dmat2x4 mul dvec2");
        print_mat<2, 4, double>((m124d[1] * m122d[0]), (m224d[1] * m222d[0]), "dmat2x4 mul dmat2x2");
        print_mat<3, 4, double>((m124d[1] * m132d[0]), (m224d[1] * m232d[0]), "dmat2x4 mul dmat3x2");
        print_mat<4, 4, double>((m124d[1] * m142d[0]), (m224d[1] * m242d[0]), "dmat2x4 mul dmat4x2");
    }

    // dmat3x2
    {
        print_vec<2, double>((m132d[1] * v13d[0]), (m232d[1] * v23d[0]), "dmat3x2 mul dvec3");
        print_mat<2, 2, double>((m132d[1] * m123d[0]), (m232d[1] * m223d[0]), "dmat3x2 mul dmat2x3");
        print_mat<3, 2, double>((m132d[1] * m133d[0]), (m232d[1] * m233d[0]), "dmat3x2 mul dmat3x3");
        print_mat<4, 2, double>((m132d[1] * m143d[0]), (m232d[1] * m243d[0]), "dmat3x2 mul dmat4x3");
    }

    // dmat3x3
    {
        print_vec<3, double>((m133d[1] * v13d[0]), (m233d[1] * v23d[0]), "dmat3x3 mul dvec3");
        print_vec<3, double>((m133d[2] / v13d[0]), (m233d[2] / v23d[0]), "dmat3x3 div dvec3");
        print_mat<2, 3, double>((m133d[1] * m123d[0]), (m233d[1] * m223d[0]), "dmat3x3 mul dmat2x3");
        print_mat<3, 3, double>((m133d[1] * m133d[0]), (m233d[1] * m233d[0]), "dmat3x3 mul dmat3x3");
        print_mat<4, 3, double>((m133d[1] * m143d[0]), (m233d[1] * m243d[0]), "dmat3x3 mul dmat4x3");
        print_mat<3, 3, double>((m133d[1] / m133d[2]), (m233d[1] / m233d[2]), "dmat3x3 div dmat3x3");
    }

    // dmat3x4
    {
        print_vec<4, double>((m134d[1] * v13d[0]), (m234d[1] * v23d[0]), "dmat2x4 mul dvec3");
        print_mat<2, 4, double>((m134d[1] * m123d[0]), (m234d[1] * m223d[0]), "dmat3x4 mul dmat2x3");
        print_mat<3, 4, double>((m134d[1] * m133d[0]), (m234d[1] * m233d[0]), "dmat3x4 mul dmat3x3");
        print_mat<4, 4, double>((m134d[1] * m143d[0]), (m234d[1] * m243d[0]), "dmat3x4 mul dmat4x3");
    }

    // dmat4x2
    {
        print_vec<2, double>((m142d[1] * v14d[0]), (m242d[1] * v24d[0]), "dmat4x2 mul dvec4");
        print_mat<2, 2, double>((m142d[1] * m124d[0]), (m242d[1] * m224d[0]), "dmat4x2 mul dmat2x4");
        print_mat<3, 2, double>((m142d[1] * m134d[0]), (m242d[1] * m234d[0]), "dmat4x2 mul dmat3x4");
        print_mat<4, 2, double>((m142d[1] * m144d[0]), (m242d[1] * m244d[0]), "dmat4x2 mul dmat4x4");
    }

    // dmat4x3
    {
        print_vec<3, double>((m143d[1] * v14d[0]), (m243d[1] * v24d[0]), "dmat4x3 mul dvec4");
        print_mat<2, 3, double>((m143d[1] * m124d[0]), (m243d[1] * m224d[0]), "dmat4x3 mul dmat2x4");
        print_mat<3, 3, double>((m143d[1] * m134d[0]), (m243d[1] * m234d[0]), "dmat4x3 mul dmat3x4");
        print_mat<4, 3, double>((m143d[1] * m144d[0]), (m243d[1] * m244d[0]), "dmat4x3 mul dmat4x4");
    }

    // dmat4x4
    {
        print_vec<4, double>((m144d[1] * v14d[0]), (m244d[1] * v24d[0]), "dmat4x4 mul dvec4");
        print_vec<4, double>((m144d[2] / v14d[0]), (m244d[2] / v24d[0]), "dmat4x4 div dvec4");
        print_mat<2, 4, double>((m144d[1] * m124d[0]), (m244d[1] * m224d[0]), "dmat4x4 mul dmat2x4");
        print_mat<3, 4, double>((m144d[1] * m134d[0]), (m244d[1] * m234d[0]), "dmat4x4 mul dmat3x4");
        print_mat<4, 4, double>((m144d[1] * m144d[0]), (m244d[1] * m244d[0]), "dmat4x4 mul dmat4x4");
        print_mat<4, 4, double>((m144d[1] / m144d[2]), (m244d[1] / m244d[2]), "dmat4x4 div dmat4x4");
    }

#endif

#ifdef GLM2_TEST_COMMON
    // function abs
    {
        f1[4] = glm::abs(f1[0]);
        f2[4] = glm2::abs(f1[0]);
        print_single<float>(f1[4], f2[4], "abs +f");
        f1[4] = glm::abs(f1[1]);
        f2[4] = glm2::abs(f1[1]);
        print_single<float>(f1[4], f2[4], "abs -f");
        d1[4] = glm::abs(d1[0]);
        d2[4] = glm2::abs(d1[0]);
        print_single<double>(d1[4], d2[4], "abs +d");
        d1[4] = glm::abs(d1[1]);
        d2[4] = glm2::abs(d1[1]);
        print_single<double>(d1[4], d2[4], "abs -d");
        i321[4] = glm::abs(i321[0]);
        i322[4] = glm2::abs(i321[0]);
        print_single<int32_t>(i321[4], i322[4], "abs +i");
        i321[4] = glm::abs(i321[1]);
        i322[4] = glm2::abs(i321[1]);
        print_single<int32_t>(i321[4], i322[4], "abs -i");
        v12f[4] = glm::abs(v12f[0]);
        v22f[4] = glm2::abs(v22f[0]);
        print_vec<2, float>(v12f[4], v22f[4], "abs v2f");
        v13f[4] = glm::abs(v13f[0]);
        v23f[4] = glm2::abs(v23f[0]);
        print_vec<3, float>(v13f[4], v23f[4], "abs v3f");
        v14f[4] = glm::abs(v14f[0]);
        v24f[4] = glm2::abs(v24f[0]);
        print_vec<4, float>(v14f[4], v24f[4], "abs v4f");
        v12d[4] = glm::abs(v12d[0]);
        v22d[4] = glm2::abs(v22d[0]);
        print_vec<2, double>(v12d[4], v22d[4], "abs v2d");
        v13d[4] = glm::abs(v13d[0]);
        v23d[4] = glm2::abs(v23d[0]);
        print_vec<3, double>(v13d[4], v23d[4], "abs v3d");
        v14d[4] = glm::abs(v14d[0]);
        v24d[4] = glm2::abs(v24d[0]);
        print_vec<4, double>(v14d[4], v24d[4], "abs v4d");
        v12i32[4] = glm::abs(v12i32[0]);
        v22i32[4] = glm2::abs(v22i32[0]);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "abs v2d");
        v13i32[4] = glm::abs(v13i32[0]);
        v23i32[4] = glm2::abs(v23i32[0]);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "abs v3d");
        v14i32[4] = glm::abs(v14i32[0]);
        v24i32[4] = glm2::abs(v24i32[0]);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "abs v4d");
    }

    // function ceil
    {
        f1[4] = glm::ceil(f1[0]);
        f2[4] = glm2::ceil(f1[0]);
        print_single<float>(f1[4], f2[4], "ceil +f");
        f1[4] = glm::ceil(f1[1]);
        f2[4] = glm2::ceil(f1[1]);
        print_single<float>(f1[4], f2[4], "ceil -f");
        d1[4] = glm::ceil(d1[0]);
        d2[4] = glm2::ceil(d1[0]);
        print_single<double>(d1[4], d2[4], "ceil +d");
        d1[4] = glm::ceil(d1[1]);
        d2[4] = glm2::ceil(d1[1]);
        print_single<double>(d1[4], d2[4], "ceil -d");
        v12f[4] = glm::ceil(v12f[0]);
        v22f[4] = glm2::ceil(v22f[0]);
        print_vec<2, float>(v12f[4], v22f[4], "ceil v2f");
        v13f[4] = glm::ceil(v13f[0]);
        v23f[4] = glm2::ceil(v23f[0]);
        print_vec<3, float>(v13f[4], v23f[4], "ceil v3f");
        v14f[4] = glm::ceil(v14f[0]);
        v24f[4] = glm2::ceil(v24f[0]);
        print_vec<4, float>(v14f[4], v24f[4], "ceil v4f");
        v12d[4] = glm::ceil(v12d[0]);
        v22d[4] = glm2::ceil(v22d[0]);
        print_vec<2, double>(v12d[4], v22d[4], "ceil v2d");
        v13d[4] = glm::ceil(v13d[0]);
        v23d[4] = glm2::ceil(v23d[0]);
        print_vec<3, double>(v13d[4], v23d[4], "ceil v3d");
        v14d[4] = glm::ceil(v14d[0]);
        v24d[4] = glm2::ceil(v24d[0]);
        print_vec<4, double>(v14d[4], v24d[4], "ceil v4d");
    }

    // function floor
    {
        f1[4] = glm::floor(f1[0]);
        f2[4] = glm2::floor(f1[0]);
        print_single<float>(f1[4], f2[4], "floor +f");
        f1[4] = glm::floor(f1[1]);
        f2[4] = glm2::floor(f1[1]);
        print_single<float>(f1[4], f2[4], "floor -f");
        d1[4] = glm::floor(d1[0]);
        d2[4] = glm2::floor(d1[0]);
        print_single<double>(d1[4], d2[4], "floor +d");
        d1[4] = glm::floor(d1[1]);
        d2[4] = glm2::floor(d1[1]);
        print_single<double>(d1[4], d2[4], "floor -d");
        v12f[4] = glm::floor(v12f[1]);
        v22f[4] = glm2::floor(v22f[1]);
        print_vec<2, float>(v12f[4], v22f[4], "floor v2f");
        v13f[4] = glm::floor(v13f[1]);
        v23f[4] = glm2::floor(v23f[1]);
        print_vec<3, float>(v13f[4], v23f[4], "floor v3f");
        v14f[4] = glm::floor(v14f[1]);
        v24f[4] = glm2::floor(v24f[1]);
        print_vec<4, float>(v14f[4], v24f[4], "floor v4f");
        v12d[4] = glm::floor(v12d[1]);
        v22d[4] = glm2::floor(v22d[1]);
        print_vec<2, double>(v12d[4], v22d[4], "floor v2d");
        v13d[4] = glm::floor(v13d[1]);
        v23d[4] = glm2::floor(v23d[1]);
        print_vec<3, double>(v13d[4], v23d[4], "floor v3d");
        v14d[4] = glm::floor(v14d[1]);
        v24d[4] = glm2::floor(v24d[1]);
        print_vec<4, double>(v14d[4], v24d[4], "floor v4d");
    }

    // function fract
    {
        f1[4] = glm::fract(f1[0]);
        f2[4] = glm2::fract(f1[0]);
        print_single<float>(f1[4], f2[4], "fract +f");
        f1[4] = glm::fract(f1[1]);
        f2[4] = glm2::fract(f1[1]);
        print_single<float>(f1[4], f2[4], "fract -f");
        d1[4] = glm::fract(d1[0]);
        d2[4] = glm2::fract(d1[0]);
        print_single<double>(d1[4], d2[4], "fract +d");
        d1[4] = glm::fract(d1[1]);
        d2[4] = glm2::fract(d1[1]);
        print_single<double>(d1[4], d2[4], "fract -d");
        v12f[4] = glm::fract(v12f[1]);
        v22f[4] = glm2::fract(v22f[1]);
        print_vec<2, float>(v12f[4], v22f[4], "fract v2f");
        v13f[4] = glm::fract(v13f[1]);
        v23f[4] = glm2::fract(v23f[1]);
        print_vec<3, float>(v13f[4], v23f[4], "fract v3f");
        v14f[4] = glm::fract(v14f[1]);
        v24f[4] = glm2::fract(v24f[1]);
        print_vec<4, float>(v14f[4], v24f[4], "fract v4f");
        v12d[4] = glm::fract(v12d[1]);
        v22d[4] = glm2::fract(v22d[1]);
        print_vec<2, double>(v12d[4], v22d[4], "fract v2d");
        v13d[4] = glm::fract(v13d[1]);
        v23d[4] = glm2::fract(v23d[1]);
        print_vec<3, double>(v13d[4], v23d[4], "fract v3d");
        v14d[4] = glm::fract(v14d[1]);
        v24d[4] = glm2::fract(v24d[1]);
        print_vec<4, double>(v14d[4], v24d[4], "fract v4d");
    }

    // function round
    {
        f1[4] = glm::round(f1[0]);
        f2[4] = glm2::round(f1[0]);
        print_single<float>(f1[4], f2[4], "round +f");
        f1[4] = glm::round(f1[1]);
        f2[4] = glm2::round(f1[1]);
        print_single<float>(f1[4], f2[4], "round -f");
        d1[4] = glm::round(d1[0]);
        d2[4] = glm2::round(d1[0]);
        print_single<double>(d1[4], d2[4], "round +d");
        d1[4] = glm::round(d1[1]);
        d2[4] = glm2::round(d1[1]);
        print_single<double>(d1[4], d2[4], "round -d");
        v12f[4] = glm::round(v12f[1]);
        v22f[4] = glm2::round(v22f[1]);
        print_vec<2, float>(v12f[4], v22f[4], "round v2f");
        v13f[4] = glm::round(v13f[1]);
        v23f[4] = glm2::round(v23f[1]);
        print_vec<3, float>(v13f[4], v23f[4], "round v3f");
        v14f[4] = glm::round(v14f[1]);
        v24f[4] = glm2::round(v24f[1]);
        print_vec<4, float>(v14f[4], v24f[4], "round v4f");
        v12d[4] = glm::round(v12d[1]);
        v22d[4] = glm2::round(v22d[1]);
        print_vec<2, double>(v12d[4], v22d[4], "round v2d");
        v13d[4] = glm::round(v13d[1]);
        v23d[4] = glm2::round(v23d[1]);
        print_vec<3, double>(v13d[4], v23d[4], "round v3d");
        v14d[4] = glm::round(v14d[1]);
        v24d[4] = glm2::round(v24d[1]);
        print_vec<4, double>(v14d[4], v24d[4], "round v4d");
    }

    // function roundEven
    {
        f1[4] = glm::roundEven(f1[0]);
        f2[4] = glm2::roundEven(f1[0]);
        print_single<float>(f1[4], f2[4], "roundEven +f");
        f1[4] = glm::roundEven(f1[1]);
        f2[4] = glm2::roundEven(f1[1]);
        print_single<float>(f1[4], f2[4], "roundEven -f");
        d1[4] = glm::roundEven(d1[0]);
        d2[4] = glm2::roundEven(d1[0]);
        print_single<double>(d1[4], d2[4], "roundEven +d");
        d1[4] = glm::roundEven(d1[1]);
        d2[4] = glm2::roundEven(d1[1]);
        print_single<double>(d1[4], d2[4], "roundEven -d");
        v12f[4] = glm::roundEven(v12f[1]);
        v22f[4] = glm2::roundEven(v22f[1]);
        print_vec<2, float>(v12f[4], v22f[4], "roundEven v2f");
        v13f[4] = glm::roundEven(v13f[1]);
        v23f[4] = glm2::roundEven(v23f[1]);
        print_vec<3, float>(v13f[4], v23f[4], "roundEven v3f");
        v14f[4] = glm::roundEven(v14f[1]);
        v24f[4] = glm2::roundEven(v24f[1]);
        print_vec<4, float>(v14f[4], v24f[4], "roundEven v4f");
        v12d[4] = glm::roundEven(v12d[1]);
        v22d[4] = glm2::roundEven(v22d[1]);
        print_vec<2, double>(v12d[4], v22d[4], "roundEven v2d");
        v13d[4] = glm::roundEven(v13d[1]);
        v23d[4] = glm2::roundEven(v23d[1]);
        print_vec<3, double>(v13d[4], v23d[4], "roundEven v3d");
        v14d[4] = glm::roundEven(v14d[1]);
        v24d[4] = glm2::roundEven(v24d[1]);
        print_vec<4, double>(v14d[4], v24d[4], "roundEven v4d");
    }

    // function sign
    {
        f1[4] = glm::sign(f1[0]);
        f2[4] = glm2::sign(f1[0]);
        print_single<float>(f1[4], f2[4], "sign +f");
        f1[4] = glm::sign(f1[1]);
        f2[4] = glm2::sign(f1[1]);
        print_single<float>(f1[4], f2[4], "sign -f");
        d1[4] = glm::sign(d1[0]);
        d2[4] = glm2::sign(d1[0]);
        print_single<double>(d1[4], d2[4], "sign +d");
        d1[4] = glm::sign(d1[1]);
        d2[4] = glm2::sign(d1[1]);
        print_single<double>(d1[4], d2[4], "sign -d");
        i321[4] = glm::sign(i321[0]);
        i322[4] = glm2::sign(i321[0]);
        print_single<int32_t>(i321[4], i322[4], "sign +i32");
        i321[4] = glm::sign(i321[1]);
        i322[4] = glm2::sign(i321[1]);
        print_single<int32_t>(i321[4], i322[4], "sign -i32");
        v12f[4] = glm::sign(v12f[0]);
        v22f[4] = glm2::sign(v22f[0]);
        print_vec<2, float>(v12f[4], v22f[4], "sign v2f");
        v13f[4] = glm::sign(v13f[0]);
        v23f[4] = glm2::sign(v23f[0]);
        print_vec<3, float>(v13f[4], v23f[4], "sign v3f");
        v14f[4] = glm::sign(v14f[0]);
        v24f[4] = glm2::sign(v24f[0]);
        print_vec<4, float>(v14f[4], v24f[4], "sign v4f");
        v12d[4] = glm::sign(v12d[0]);
        v22d[4] = glm2::sign(v22d[0]);
        print_vec<2, double>(v12d[4], v22d[4], "sign v2d");
        v13d[4] = glm::sign(v13d[0]);
        v23d[4] = glm2::sign(v23d[0]);
        print_vec<3, double>(v13d[4], v23d[4], "sign v3d");
        v14d[4] = glm::sign(v14d[0]);
        v24d[4] = glm2::sign(v24d[0]);
        print_vec<4, double>(v14d[4], v24d[4], "sign v4d");
        v12i32[4] = glm::sign(v12i32[0]);
        v22i32[4] = glm2::sign(v22i32[0]);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "sign v2i32");
        v13i32[4] = glm::sign(v13i32[0]);
        v23i32[4] = glm2::sign(v23i32[0]);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "sign v3i32");
        v14i32[4] = glm::sign(v14i32[0]);
        v24i32[4] = glm2::sign(v24i32[0]);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "sign v4i32");
    }

    // function trunc
    {
        f1[4] = glm::trunc(f1[0]);
        f2[4] = glm2::trunc(f1[0]);
        print_single<float>(f1[4], f2[4], "trunc +f");
        f1[4] = glm::trunc(f1[1]);
        f2[4] = glm2::trunc(f1[1]);
        print_single<float>(f1[4], f2[4], "trunc -f");
        d1[4] = glm::trunc(d1[0]);
        d2[4] = glm2::trunc(d1[0]);
        print_single<double>(d1[4], d2[4], "trunc +d");
        d1[4] = glm::trunc(d1[1]);
        d2[4] = glm2::trunc(d1[1]);
        print_single<double>(d1[4], d2[4], "trunc -d");
        v12f[4] = glm::trunc(v12f[1]);
        v22f[4] = glm2::trunc(v22f[1]);
        print_vec<2, float>(v12f[4], v22f[4], "trunc v2f");
        v13f[4] = glm::trunc(v13f[1]);
        v23f[4] = glm2::trunc(v23f[1]);
        print_vec<3, float>(v13f[4], v23f[4], "trunc v3f");
        v14f[4] = glm::trunc(v14f[1]);
        v24f[4] = glm2::trunc(v24f[1]);
        print_vec<4, float>(v14f[4], v24f[4], "trunc v4f");
        v12d[4] = glm::trunc(v12d[1]);
        v22d[4] = glm2::trunc(v22d[1]);
        print_vec<2, double>(v12d[4], v22d[4], "trunc v2d");
        v13d[4] = glm::trunc(v13d[1]);
        v23d[4] = glm2::trunc(v23d[1]);
        print_vec<3, double>(v13d[4], v23d[4], "trunc v3d");
        v14d[4] = glm::trunc(v14d[1]);
        v24d[4] = glm2::trunc(v24d[1]);
        print_vec<4, double>(v14d[4], v24d[4], "trunc v4d");
    }

    // function fma
    {
        f1[4] = glm::fma(f1[0], f1[1], f1[1]);
        f2[4] = glm2::fma(f2[0], f2[1], f2[1]);
        print_single<float>(f1[4], f2[4], "fma f");
        d1[4] = glm::fma(d1[0], d1[1], d1[1]);
        d2[4] = glm2::fma(d2[0], d2[1], d2[1]);
        print_single<double>(d1[4], d2[4], "fma d");
        v12f[4] = glm::fma(v12f[0], v12f[1], v12f[1]);
        v22f[4] = glm2::fma(v22f[0], v22f[1], v22f[1]);
        print_vec<2, float>(v12f[4], v22f[4], "fma v2f");
        v13f[4] = glm::fma(v13f[0], v13f[1], v13f[1]);
        v23f[4] = glm2::fma(v23f[0], v23f[1], v23f[1]);
        print_vec<3, float>(v13f[4], v23f[4], "fma v3f");
        v14f[4] = glm::fma(v14f[0], v14f[1], v14f[1]);
        v24f[4] = glm2::fma(v24f[0], v24f[1], v24f[1]);
        print_vec<4, float>(v14f[4], v24f[4], "fma v4f");
        v12d[4] = glm::fma(v12d[0], v12d[1], v12d[1]);
        v22d[4] = glm2::fma(v22d[0], v22d[1], v22d[1]);
        print_vec<2, double>(v12d[4], v22d[4], "fma v2d");
        v13d[4] = glm::fma(v13d[0], v13d[1], v13d[1]);
        v23d[4] = glm2::fma(v23d[0], v23d[1], v23d[1]);
        print_vec<3, double>(v13d[4], v23d[4], "fma v3d");
        v14d[4] = glm::fma(v14d[0], v14d[1], v14d[1]);
        v24d[4] = glm2::fma(v24d[0], v24d[1], v24d[1]);
        print_vec<4, double>(v14d[4], v24d[4], "fma v4d");
    }

    // function min
    {
        f1[4] = glm::min(f1[0], 1.0f);
        f2[4] = glm2::min(f2[0], 1.0f);
        print_single<float>(f1[4], f2[4], "min f");
        d1[4] = glm::min(d1[0], 1.0);
        d2[4] = glm2::min(d2[0], 1.0);
        print_single<double>(d1[4], d2[4], "min d");
        i321[4] = glm::min(i321[0], 5);
        i322[4] = glm2::min(i322[0], 5);
        print_single<int32_t>(i321[4], i322[4], "min i32");
        u321[4] = glm::min(u321[0], 5u);
        u322[4] = glm2::min(u322[0], 5u);
        print_single<uint32_t>(u321[4], u322[4], "min u32");
        v12f[4] = glm::min(v12f[3], 0.5f);
        v22f[4] = glm2::min(v22f[3], 0.5f);
        print_vec<2, float>(v12f[4], v22f[4], "min vs2f");
        v13f[4] = glm::min(v13f[3], 0.5f);
        v23f[4] = glm2::min(v23f[3], 0.5f);
        print_vec<3, float>(v13f[4], v23f[4], "min vs3f");
        v14f[4] = glm::min(v14f[3], 0.5f);
        v24f[4] = glm2::min(v24f[3], 0.5f);
        print_vec<4, float>(v14f[4], v24f[4], "min vs4f");
        v12d[4] = glm::min(v12d[3], 0.5);
        v22d[4] = glm2::min(v22d[3], 0.5);
        print_vec<2, double>(v12d[4], v22d[4], "min vs2d");
        v13d[4] = glm::min(v13d[3], 0.5);
        v23d[4] = glm2::min(v23d[3], 0.5);
        print_vec<3, double>(v13d[4], v23d[4], "min vs3d");
        v14d[4] = glm::min(v14d[3], 0.5);
        v24d[4] = glm2::min(v24d[3], 0.5);
        print_vec<4, double>(v14d[4], v24d[4], "min vs4d");
        v12i32[4] = glm::min(v12i32[3], 5);
        v22i32[4] = glm2::min(v22i32[3], 5);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "min vs2i32");
        v13i32[4] = glm::min(v13i32[3], 5);
        v23i32[4] = glm2::min(v23i32[3], 5);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "min vs3i32");
        v14i32[4] = glm::min(v14i32[3], 5);
        v24i32[4] = glm2::min(v24i32[3], 5);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "min vs4i32");
        v12u32[4] = glm::min(v12u32[3], 20u);
        v22u32[4] = glm2::min(v22u32[3], 20u);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "min vs2u32");
        v13u32[4] = glm::min(v13u32[3], 20u);
        v23u32[4] = glm2::min(v23u32[3], 20u);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "min vs3u32");
        v14u32[4] = glm::min(v14u32[3], 20u);
        v24u32[4] = glm2::min(v24u32[3], 20u);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "min vs4u32");
        v12f[4] = glm::min(v12f[3], glm::vec2(0.5f));
        v22f[4] = glm2::min(v22f[3], glm2::vec2(0.5f));
        print_vec<2, float>(v12f[4], v22f[4], "min vv2f");
        v13f[4] = glm::min(v13f[3], glm::vec3(0.5f));
        v23f[4] = glm2::min(v23f[3], glm2::vec3(0.5f));
        print_vec<3, float>(v13f[4], v23f[4], "min vv3f");
        v14f[4] = glm::min(v14f[3], glm::vec4(0.5f));
        v24f[4] = glm2::min(v24f[3], glm2::vec4(0.5f));
        print_vec<4, float>(v14f[4], v24f[4], "min vv4f");
        v12d[4] = glm::min(v12d[3], glm::dvec2(0.5));
        v22d[4] = glm2::min(v22d[3], glm2::dvec2(0.5));
        print_vec<2, double>(v12d[4], v22d[4], "min vv2d");
        v13d[4] = glm::min(v13d[3], glm::dvec3(0.5));
        v23d[4] = glm2::min(v23d[3], glm2::dvec3(0.5));
        print_vec<3, double>(v13d[4], v23d[4], "min vv3d");
        v14d[4] = glm::min(v14d[3], glm::dvec4(0.5));
        v24d[4] = glm2::min(v24d[3], glm2::dvec4(0.5));
        print_vec<4, double>(v14d[4], v24d[4], "min vv4d");
        v12i32[4] = glm::min(v12i32[3], glm::ivec2(5));
        v22i32[4] = glm2::min(v22i32[3], glm2::ivec2(5));
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "min vv2i32");
        v13i32[4] = glm::min(v13i32[3], glm::ivec3(5));
        v23i32[4] = glm2::min(v23i32[3], glm2::ivec3(5));
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "min vv3i32");
        v14i32[4] = glm::min(v14i32[3], glm::ivec4(5));
        v24i32[4] = glm2::min(v24i32[3], glm2::ivec4(5));
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "min vv4i32");
        v12u32[4] = glm::min(v12u32[3], glm::uvec2(20));
        v22u32[4] = glm2::min(v22u32[3], glm2::uvec2(20));
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "min vv2u32");
        v13u32[4] = glm::min(v13u32[3], glm::uvec3(20));
        v23u32[4] = glm2::min(v23u32[3], glm2::uvec3(20));
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "min vv3u32");
        v14u32[4] = glm::min(v14u32[3], glm::uvec4(20));
        v24u32[4] = glm2::min(v24u32[3], glm2::uvec4(20));
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "min vv4u32");
    }

    // function max
    {
        f1[4] = glm::max(f1[0], 1.0f);
        f2[4] = glm2::max(f2[0], 1.0f);
        print_single<float>(f1[4], f2[4], "max f");
        d1[4] = glm::max(d1[0], 1.0);
        d2[4] = glm2::max(d2[0], 1.0);
        print_single<double>(d1[4], d2[4], "max d");
        i321[4] = glm::max(i321[0], 5);
        i322[4] = glm2::max(i322[0], 5);
        print_single<int32_t>(i321[4], i322[4], "max i32");
        u321[4] = glm::max(u321[0], 5u);
        u322[4] = glm2::max(u322[0], 5u);
        print_single<uint32_t>(u321[4], u322[4], "max u32");
        v12f[4] = glm::max(v12f[3], 0.5f);
        v22f[4] = glm2::max(v22f[3], 0.5f);
        print_vec<2, float>(v12f[4], v22f[4], "max vs2f");
        v13f[4] = glm::max(v13f[3], 0.5f);
        v23f[4] = glm2::max(v23f[3], 0.5f);
        print_vec<3, float>(v13f[4], v23f[4], "max vs3f");
        v14f[4] = glm::max(v14f[3], 0.5f);
        v24f[4] = glm2::max(v24f[3], 0.5f);
        print_vec<4, float>(v14f[4], v24f[4], "max vs4f");
        v12d[4] = glm::max(v12d[3], 0.5);
        v22d[4] = glm2::max(v22d[3], 0.5);
        print_vec<2, double>(v12d[4], v22d[4], "max vs2d");
        v13d[4] = glm::max(v13d[3], 0.5);
        v23d[4] = glm2::max(v23d[3], 0.5);
        print_vec<3, double>(v13d[4], v23d[4], "max vs3d");
        v14d[4] = glm::max(v14d[3], 0.5);
        v24d[4] = glm2::max(v24d[3], 0.5);
        print_vec<4, double>(v14d[4], v24d[4], "max vs4d");
        v12i32[4] = glm::max(v12i32[3], 5);
        v22i32[4] = glm2::max(v22i32[3], 5);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "max vs2i32");
        v13i32[4] = glm::max(v13i32[3], 5);
        v23i32[4] = glm2::max(v23i32[3], 5);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "max vs3i32");
        v14i32[4] = glm::max(v14i32[3], 5);
        v24i32[4] = glm2::max(v24i32[3], 5);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "max vs4i32");
        v12u32[4] = glm::max(v12u32[3], 20u);
        v22u32[4] = glm2::max(v22u32[3], 20u);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "max vs2u32");
        v13u32[4] = glm::max(v13u32[3], 20u);
        v23u32[4] = glm2::max(v23u32[3], 20u);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "max vs3u32");
        v14u32[4] = glm::max(v14u32[3], 20u);
        v24u32[4] = glm2::max(v24u32[3], 20u);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "max vs4u32");
        v12f[4] = glm::max(v12f[3], glm::vec2(0.5f));
        v22f[4] = glm2::max(v22f[3], glm2::vec2(0.5f));
        print_vec<2, float>(v12f[4], v22f[4], "max vv2f");
        v13f[4] = glm::max(v13f[3], glm::vec3(0.5f));
        v23f[4] = glm2::max(v23f[3], glm2::vec3(0.5f));
        print_vec<3, float>(v13f[4], v23f[4], "max vv3f");
        v14f[4] = glm::max(v14f[3], glm::vec4(0.5f));
        v24f[4] = glm2::max(v24f[3], glm2::vec4(0.5f));
        print_vec<4, float>(v14f[4], v24f[4], "max vv4f");
        v12d[4] = glm::max(v12d[3], glm::dvec2(0.5));
        v22d[4] = glm2::max(v22d[3], glm2::dvec2(0.5));
        print_vec<2, double>(v12d[4], v22d[4], "max vv2d");
        v13d[4] = glm::max(v13d[3], glm::dvec3(0.5));
        v23d[4] = glm2::max(v23d[3], glm2::dvec3(0.5));
        print_vec<3, double>(v13d[4], v23d[4], "max vv3d");
        v14d[4] = glm::max(v14d[3], glm::dvec4(0.5));
        v24d[4] = glm2::max(v24d[3], glm2::dvec4(0.5));
        print_vec<4, double>(v14d[4], v24d[4], "max vv4d");
        v12i32[4] = glm::max(v12i32[3], glm::ivec2(5));
        v22i32[4] = glm2::max(v22i32[3], glm2::ivec2(5));
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "max vv2i32");
        v13i32[4] = glm::max(v13i32[3], glm::ivec3(5));
        v23i32[4] = glm2::max(v23i32[3], glm2::ivec3(5));
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "max vv3i32");
        v14i32[4] = glm::max(v14i32[3], glm::ivec4(5));
        v24i32[4] = glm2::max(v24i32[3], glm2::ivec4(5));
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "max vv4i32");
        v12u32[4] = glm::max(v12u32[3], glm::uvec2(20));
        v22u32[4] = glm2::max(v22u32[3], glm2::uvec2(20));
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "max vv2u32");
        v13u32[4] = glm::max(v13u32[3], glm::uvec3(20));
        v23u32[4] = glm2::max(v23u32[3], glm2::uvec3(20));
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "max vv3u32");
        v14u32[4] = glm::max(v14u32[3], glm::uvec4(20));
        v24u32[4] = glm2::max(v24u32[3], glm2::uvec4(20));
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "max vv4u32");
    }

    // function mod
    {
        f1[4] = glm::mod(f1[0], 1.0f);
        f2[4] = glm2::mod(f2[0], 1.0f);
        print_single<float>(f1[4], f2[4], "mod f");
        d1[4] = glm::mod(d1[0], 1.0);
        d2[4] = glm2::mod(d2[0], 1.0);
        print_single<double>(d1[4], d2[4], "mod d");
        v12f[4] = glm::mod(v12f[3], 0.5f);
        v22f[4] = glm2::mod(v22f[3], 0.5f);
        print_vec<2, float>(v12f[4], v22f[4], "mod vs2f");
        v13f[4] = glm::mod(v13f[3], 0.5f);
        v23f[4] = glm2::mod(v23f[3], 0.5f);
        print_vec<3, float>(v13f[4], v23f[4], "mod vs3f");
        v14f[4] = glm::mod(v14f[3], 0.5f);
        v24f[4] = glm2::mod(v24f[3], 0.5f);
        print_vec<4, float>(v14f[4], v24f[4], "mod vs4f");
        v12d[4] = glm::mod(v12d[3], 0.5);
        v22d[4] = glm2::mod(v22d[3], 0.5);
        print_vec<2, double>(v12d[4], v22d[4], "mod vs2d");
        v13d[4] = glm::mod(v13d[3], 0.5);
        v23d[4] = glm2::mod(v23d[3], 0.5);
        print_vec<3, double>(v13d[4], v23d[4], "mod vs3d");
        v14d[4] = glm::mod(v14d[3], 0.5);
        v24d[4] = glm2::mod(v24d[3], 0.5);
        print_vec<4, double>(v14d[4], v24d[4], "mod vs4d");
        v12f[4] = glm::mod(v12f[3], glm::vec2(0.5f));
        v22f[4] = glm2::mod(v22f[3], glm2::vec2(0.5f));
        print_vec<2, float>(v12f[4], v22f[4], "mod vv2f");
        v13f[4] = glm::mod(v13f[3], glm::vec3(0.5f));
        v23f[4] = glm2::mod(v23f[3], glm2::vec3(0.5f));
        print_vec<3, float>(v13f[4], v23f[4], "mod vv3f");
        v14f[4] = glm::mod(v14f[3], glm::vec4(0.5f));
        v24f[4] = glm2::mod(v24f[3], glm2::vec4(0.5f));
        print_vec<4, float>(v14f[4], v24f[4], "mod vv4f");
        v12d[4] = glm::mod(v12d[3], glm::dvec2(0.5));
        v22d[4] = glm2::mod(v22d[3], glm2::dvec2(0.5));
        print_vec<2, double>(v12d[4], v22d[4], "mod vv2d");
        v13d[4] = glm::mod(v13d[3], glm::dvec3(0.5));
        v23d[4] = glm2::mod(v23d[3], glm2::dvec3(0.5));
        print_vec<3, double>(v13d[4], v23d[4], "mod vv3d");
        v14d[4] = glm::mod(v14d[3], glm::dvec4(0.5));
        v24d[4] = glm2::mod(v24d[3], glm2::dvec4(0.5));
        print_vec<4, double>(v14d[4], v24d[4], "mod vv4d");
    }

    // function clamp
    {
        f1[4] = glm::clamp(f1[0], 0.0f, 1.0f);
        f2[4] = glm2::clamp(f2[0], 0.0f, 1.0f);
        print_single<float>(f1[4], f2[4], "clamp f");
        d1[4] = glm::clamp(d1[0], 0.0, 1.0);
        d2[4] = glm2::clamp(d2[0], 0.0, 1.0);
        print_single<double>(d1[4], d2[4], "clamp d");
        i321[4] = glm::clamp(i321[0], 0, 5);
        i322[4] = glm2::clamp(i322[0], 0, 5);
        print_single<int32_t>(i321[4], i322[4], "clamp i32");
        u321[4] = glm::clamp(u321[0], 0u, 5u);
        u322[4] = glm2::clamp(u322[0], 0u, 5u);
        print_single<uint32_t>(u321[4], u322[4], "clamp u32");
        v12f[4] = glm::clamp(v12f[3], 0.5f, 0.7f);
        v22f[4] = glm2::clamp(v22f[3], 0.5f, 0.7f);
        print_vec<2, float>(v12f[4], v22f[4], "clamp vs2f");
        v13f[4] = glm::clamp(v13f[3], 0.5f, 0.7f);
        v23f[4] = glm2::clamp(v23f[3], 0.5f, 0.7f);
        print_vec<3, float>(v13f[4], v23f[4], "clamp vs3f");
        v14f[4] = glm::clamp(v14f[3], 0.5f, 0.7f);
        v24f[4] = glm2::clamp(v24f[3], 0.5f, 0.7f);
        print_vec<4, float>(v14f[4], v24f[4], "clamp vs4f");
        v12d[4] = glm::clamp(v12d[3], 0.5, 0.7);
        v22d[4] = glm2::clamp(v22d[3], 0.5, 0.7);
        print_vec<2, double>(v12d[4], v22d[4], "clamp vs2d");
        v13d[4] = glm::clamp(v13d[3], 0.5, 0.7);
        v23d[4] = glm2::clamp(v23d[3], 0.5, 0.7);
        print_vec<3, double>(v13d[4], v23d[4], "clamp vs3d");
        v14d[4] = glm::clamp(v14d[3], 0.5, 0.7);
        v24d[4] = glm2::clamp(v24d[3], 0.5, 0.7);
        print_vec<4, double>(v14d[4], v24d[4], "clamp vs4d");
        v12i32[4] = glm::clamp(v12i32[0], -5, 5);
        v22i32[4] = glm2::clamp(v22i32[0], -5, 5);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "clamp vs2i32");
        v13i32[4] = glm::clamp(v13i32[0], -5, 5);
        v23i32[4] = glm2::clamp(v23i32[0], -5, 5);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "clamp vs3i32");
        v14i32[4] = glm::clamp(v14i32[0], -5, 5);
        v24i32[4] = glm2::clamp(v24i32[0], -5, 5);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "clamp vs4i32");
        v12u32[4] = glm::clamp(v12u32[0], 20u, 50u);
        v22u32[4] = glm2::clamp(v22u32[0], 20u, 50u);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "clamp vs2u32");
        v13u32[4] = glm::clamp(v13u32[0], 20u, 50u);
        v23u32[4] = glm2::clamp(v23u32[0], 20u, 50u);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "clamp vs3u32");
        v14u32[4] = glm::clamp(v14u32[0], 20u, 50u);
        v24u32[4] = glm2::clamp(v24u32[0], 20u, 50u);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "clamp vs4u32");
        v12f[4] = glm::clamp(v12f[3], glm::vec2(0.5f), glm::vec2(0.7f));
        v22f[4] = glm2::clamp(v22f[3], glm2::vec2(0.5f), glm2::vec2(0.7f));
        print_vec<2, float>(v12f[4], v22f[4], "clamp vv2f");
        v13f[4] = glm::clamp(v13f[3], glm::vec3(0.5f), glm::vec3(0.7f));
        v23f[4] = glm2::clamp(v23f[3], glm2::vec3(0.5f), glm2::vec3(0.7f));
        print_vec<3, float>(v13f[4], v23f[4], "clamp vv3f");
        v14f[4] = glm::clamp(v14f[3], glm::vec4(0.5f), glm::vec4(0.7f));
        v24f[4] = glm2::clamp(v24f[3], glm2::vec4(0.5f), glm2::vec4(0.7f));
        print_vec<4, float>(v14f[4], v24f[4], "clamp vv4f");
        v12d[4] = glm::clamp(v12d[3], glm::dvec2(0.5), glm::dvec2(0.7));
        v22d[4] = glm2::clamp(v22d[3], glm2::dvec2(0.5), glm2::dvec2(0.7));
        print_vec<2, double>(v12d[4], v22d[4], "clamp vv2d");
        v13d[4] = glm::clamp(v13d[3], glm::dvec3(0.5), glm::dvec3(0.7));
        v23d[4] = glm2::clamp(v23d[3], glm2::dvec3(0.5), glm2::dvec3(0.7));
        print_vec<3, double>(v13d[4], v23d[4], "clamp vv3d");
        v14d[4] = glm::clamp(v14d[3], glm::dvec4(0.5), glm::dvec4(0.7));
        v24d[4] = glm2::clamp(v24d[3], glm2::dvec4(0.5), glm2::dvec4(0.7));
        print_vec<4, double>(v14d[4], v24d[4], "clamp vv4d");
        v12i32[4] = glm::clamp(v12i32[0], glm::ivec2(-5), glm::ivec2(5));
        v22i32[4] = glm2::clamp(v22i32[0], glm2::ivec2(-5), glm2::ivec2(5));
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "clamp vs2i32");
        v13i32[4] = glm::clamp(v13i32[0], glm::ivec3(-5), glm::ivec3(5));
        v23i32[4] = glm2::clamp(v23i32[0], glm2::ivec3(-5), glm2::ivec3(5));
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "clamp vs3i32");
        v14i32[4] = glm::clamp(v14i32[0], glm::ivec4(-5), glm::ivec4(5));
        v24i32[4] = glm2::clamp(v24i32[0], glm2::ivec4(-5), glm2::ivec4(5));
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "clamp vs4i32");
        v12u32[4] = glm::clamp(v12u32[0], glm::uvec2(20), glm::uvec2(50));
        v22u32[4] = glm2::clamp(v22u32[0], glm2::uvec2(20), glm2::uvec2(50));
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "clamp vs2u32");
        v13u32[4] = glm::clamp(v13u32[0], glm::uvec3(20), glm::uvec3(50));
        v23u32[4] = glm2::clamp(v23u32[0], glm2::uvec3(20),  glm2::uvec3(50));
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "clamp vs3u32");
        v14u32[4] = glm::clamp(v14u32[0], glm::uvec4(20), glm::uvec4(50));
        v24u32[4] = glm2::clamp(v24u32[0], glm2::uvec4(20),  glm2::uvec4(50));
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "clamp vs4u32");
    }

    // function step
    {
        f1[4] = glm::step(1.0f, f1[0]);
        f2[4] = glm2::step(1.0f, f2[0]);
        print_single<float>(f1[4], f2[4], "step f");
        d1[4] = glm::step(1.0, d1[0]);
        d2[4] = glm2::step(1.0, d2[0]);
        print_single<double>(d1[4], d2[4], "step d");
        v12f[4] = glm::step(0.5f, v12f[3]);
        v22f[4] = glm2::step(0.5f, v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "step vs2f");
        v13f[4] = glm::step(0.5f, v13f[3]);
        v23f[4] = glm2::step(0.5f, v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "step vs3f");
        v14f[4] = glm::step(0.5f, v14f[3]);
        v24f[4] = glm2::step(0.5f, v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "step vs4f");
        v12d[4] = glm::step(0.5, v12d[3]);
        v22d[4] = glm2::step(0.5, v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "step vs2d");
        v13d[4] = glm::step(0.5, v13d[3]);
        v23d[4] = glm2::step(0.5, v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "step vs3d");
        v14d[4] = glm::step(0.5, v14d[3]);
        v24d[4] = glm2::step(0.5, v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "step vs4d");
        v12f[4] = glm::step(glm::vec2(0.5f), v12f[3]);
        v22f[4] = glm2::step(glm2::vec2(0.5f), v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "step vv2f");
        v13f[4] = glm::step(glm::vec3(0.5f), v13f[3]);
        v23f[4] = glm2::step(glm2::vec3(0.5f), v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "step vv3f");
        v14f[4] = glm::step(glm::vec4(0.5f), v14f[3]);
        v24f[4] = glm2::step(glm2::vec4(0.5f), v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "step vv4f");
        v12d[4] = glm::step(glm::dvec2(0.5), v12d[3]);
        v22d[4] = glm2::step(glm2::dvec2(0.5), v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "step vv2d");
        v13d[4] = glm::step(glm::dvec3(0.5), v13d[3]);
        v23d[4] = glm2::step(glm2::dvec3(0.5), v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "step vv3d");
        v14d[4] = glm::step(glm::dvec4(0.5), v14d[3]);
        v24d[4] = glm2::step(glm2::dvec4(0.5), v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "step vv4d");
    }

    // function smoothstep
    {
        f1[4] = glm::smoothstep(0.0f, 1.5f, f1[3]);
        f2[4] = glm2::smoothstep(0.0f, 1.5f, f2[3]);
        print_single<float>(f1[4], f2[4], "smoothstep f");
        d1[4] = glm::smoothstep(0.0, 1.5, d1[3]);
        d2[4] = glm2::smoothstep(0.0, 1.5, d2[3]);
        print_single<double>(d1[4], d2[4], "smoothstep d");
        v12f[4] = glm::smoothstep(0.0f, 1.0f, v12f[3]);
        v22f[4] = glm2::smoothstep(0.0f, 1.0f, v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "smoothstep vs2f");
        v13f[4] = glm::smoothstep(0.0f, 1.0f, v13f[3]);
        v23f[4] = glm2::smoothstep(0.0f, 1.0f, v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "smoothstep vs3f");
        v14f[4] = glm::smoothstep(0.0f, 1.0f, v14f[3]);
        v24f[4] = glm2::smoothstep(0.0f, 1.0f, v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "smoothstep vs4f");
        v12d[4] = glm::smoothstep(0.0, 1.0, v12d[3]);
        v22d[4] = glm2::smoothstep(0.0, 1.0, v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "smoothstep vs2d");
        v13d[4] = glm::smoothstep(0.0, 1.0, v13d[3]);
        v23d[4] = glm2::smoothstep(0.0, 1.0, v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "smoothstep vs3d");
        v14d[4] = glm::smoothstep(0.0, 1.0, v14d[3]);
        v24d[4] = glm2::smoothstep(0.0, 1.0, v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "smoothstep vs4d");
        v12f[4] = glm::smoothstep(glm::vec2(0.0f), glm::vec2(1.0f), v12f[3]);
        v22f[4] = glm2::smoothstep(glm2::vec2(0.0f), glm2::vec2(1.0f), v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "smoothstep vv2f");
        v13f[4] = glm::smoothstep(glm::vec3(0.0f), glm::vec3(1.0f), v13f[3]);
        v23f[4] = glm2::smoothstep(glm2::vec3(0.0f), glm2::vec3(1.0f), v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "smoothstep vv3f");
        v14f[4] = glm::smoothstep(glm::vec4(0.0f), glm::vec4(1.0f), v14f[3]);
        v24f[4] = glm2::smoothstep(glm2::vec4(0.0f), glm2::vec4(1.0f), v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "smoothstep vv4f");
        v12d[4] = glm::smoothstep(glm::dvec2(0.0), glm::dvec2(1.0), v12d[3]);
        v22d[4] = glm2::smoothstep(glm2::dvec2(0.0), glm2::dvec2(1.0), v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "smoothstep vv2d");
        v13d[4] = glm::smoothstep(glm::dvec3(0.0), glm::dvec3(1.0), v13d[3]);
        v23d[4] = glm2::smoothstep(glm2::dvec3(0.0), glm2::dvec3(1.0), v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "smoothstep vv3d");
        v14d[4] = glm::smoothstep(glm::dvec4(0.0), glm::dvec4(1.0), v14d[3]);
        v24d[4] = glm2::smoothstep(glm2::dvec4(0.0), glm2::dvec4(1.0), v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "smoothstep vv4d");
    }

    // function mix
    {
        f1[4] = glm::mix(f1[0], f1[1], 0.7f);
        f2[4] = glm2::mix(f2[0], f2[1], 0.7f);
        print_single<float>(f1[4], f2[4], "mix f");
        d1[4] = glm::mix(d1[0], d1[1], 0.7);
        d2[4] = glm2::mix(d2[0], d2[1], 0.7);
        print_single<double>(d1[4], d2[4], "mix d");
        v12f[4] = glm::mix(v12f[0], v12f[1], 0.7f);
        v22f[4] = glm2::mix(v22f[0], v22f[1], 0.7f);
        print_vec<2, float>(v12f[4], v22f[4], "mix vs2f");
        v13f[4] = glm::mix(v13f[0], v13f[1], 0.7f);
        v23f[4] = glm2::mix(v23f[0], v23f[1], 0.7f);
        print_vec<3, float>(v13f[4], v23f[4], "mix vs3f");
        v14f[4] = glm::mix(v14f[0], v14f[1], 0.7f);
        v24f[4] = glm2::mix(v24f[0], v24f[1], 0.7f);
        print_vec<4, float>(v14f[4], v24f[4], "mix vs4f");
        v12d[4] = glm::mix(v12d[0], v12d[1], 0.7);
        v22d[4] = glm2::mix(v22d[0], v22d[1], 0.7);
        print_vec<2, double>(v12d[4], v22d[4], "mix vs2d");
        v13d[4] = glm::mix(v13d[0], v13d[1], 0.7);
        v23d[4] = glm2::mix(v23d[0], v23d[1], 0.7);
        print_vec<3, double>(v13d[4], v23d[4], "mix vs3d");
        v14d[4] = glm::mix(v14d[0], v14d[1], 0.7);
        v24d[4] = glm2::mix(v24d[0], v24d[1], 0.7);
        print_vec<4, double>(v14d[4], v24d[4], "mix vs4d");
        v12f[4] = glm::mix(v12f[0], v12f[1], v12f[3]);
        v22f[4] = glm2::mix(v22f[0], v22f[1], v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "mix vv2f");
        v13f[4] = glm::mix(v13f[0], v13f[1], v13f[3]);
        v23f[4] = glm2::mix(v23f[0], v23f[1], v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "mix vv3f");
        v14f[4] = glm::mix(v14f[0], v14f[1], v14f[3]);
        v24f[4] = glm2::mix(v24f[0], v24f[1], v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "mix vv4f");
        v12d[4] = glm::mix(v12d[0], v12d[1], v12d[3]);
        v22d[4] = glm2::mix(v22d[0], v22d[1], v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "mix vv2d");
        v13d[4] = glm::mix(v13d[0], v13d[1], v13d[3]);
        v23d[4] = glm2::mix(v23d[0], v23d[1], v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "mix vv3d");
        v14d[4] = glm::mix(v14d[0], v14d[1], v14d[3]);
        v24d[4] = glm2::mix(v24d[0], v24d[1], v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "mix vv4d");
    }

    // frexp
    {
        glm::ivec4 tmp1; glm2::ivec4 tmp2;
        v14f[4] = glm::frexp(v14f[2], tmp1);
        v24f[4] = glm2::frexp(v24f[2], tmp2);
        print_vec<4, float>(v14f[4], v24f[4], "frexp fractional");
        print_vec<4, float>(tmp1, tmp2, "frexp exponent");
    }

    // ldexp
    {
        glm::ivec4 tmp1; glm2::ivec4 tmp2;
        v14f[4] = glm::ldexp(v14f[2], tmp1);
        v24f[4] = glm2::ldexp(v24f[2], tmp2);
        print_vec<4, float>(v14f[4], v24f[4], "ldexp fractional");
        print_vec<4, float>(tmp1, tmp2, "ldexp exponent");
    }

    // modf
    {
        float tmpf1, tmpf2;
        double tmpd1, tmpd2;
        glm::vec2 tmpvf21; glm2::vec2 tmpvf22;
        glm::vec3 tmpvf31; glm2::vec3 tmpvf32;
        glm::vec4 tmpvf41; glm2::vec4 tmpvf42;
        glm::dvec2 tmpvd21; glm2::dvec2 tmpvd22;
        glm::dvec3 tmpvd31; glm2::dvec3 tmpvd32;
        glm::dvec4 tmpvd41; glm2::dvec4 tmpvd42;
        f1[4] = glm::modf(f1[2], tmpf1);
        f2[4] = glm2::modf(f2[2], tmpf2);
        print_single<float>(f1[4], f2[4], "modf fractional f");
        print_single<float>(tmpf1, tmpf2, "modf integer f");
        d1[4] = glm::modf(d1[2], tmpd1);
        d2[4] = glm2::modf(d2[2], tmpd2);
        print_single<double>(d1[4], d2[4], "modf fractional d");
        print_single<double>(tmpf1, tmpf2, "modf integer d");
        v12f[4] = glm::modf(v12f[2], tmpvf21);
        v22f[4] = glm2::modf(v22f[2], tmpvf22);
        print_vec<2, float>(v12f[4], v22f[4], "modf fractional v2f");
        print_vec<2, float>(tmpvf21, tmpvf22, "modf integer v2f");
        v13f[4] = glm::modf(v13f[2], tmpvf31);
        v23f[4] = glm2::modf(v23f[2], tmpvf32);
        print_vec<3, float>(v13f[4], v23f[4], "modf fractional v3f");
        print_vec<3, float>(tmpvf31, tmpvf32, "modf integer v3f");
        v14f[4] = glm::modf(v14f[2], tmpvf41);
        v24f[4] = glm2::modf(v24f[2], tmpvf42);
        print_vec<4, float>(v14f[4], v24f[4], "modf fractional v4f");
        print_vec<4, float>(tmpvf41, tmpvf42, "modf integer v4f");
        v12d[4] = glm::modf(v12d[2], tmpvd21);
        v22d[4] = glm2::modf(v22d[2], tmpvd22);
        print_vec<2, double>(v12d[4], v22d[4], "modf fractional v2d");
        print_vec<2, double>(tmpvd21, tmpvd22, "modf integer v2d");
        v13d[4] = glm::modf(v13d[2], tmpvd31);
        v23d[4] = glm2::modf(v23d[2], tmpvd32);
        print_vec<3, double>(v13d[4], v23d[4], "modf fractional v3d");
        print_vec<3, double>(tmpvd31, tmpvd32, "modf integer v3d");
        v14d[4] = glm::modf(v14d[2], tmpvd41);
        v24d[4] = glm2::modf(v24d[2], tmpvd42);
        print_vec<4, double>(v14d[4], v24d[4], "modf fractional v4d");
        print_vec<4, double>(tmpvd41, tmpvd42, "modf integer v4d");
    }

    // isinf
    {
        b1[2] = glm::isinf(5.0f);
        b2[2] = glm2::isinf(5.0f);
        print_single<bool>(b1[2], b2[2], "isinf f 1");
        b1[2] = glm::isinf(INFINITY);
        b2[2] = glm2::isinf(INFINITY);
        print_single<bool>(b1[2], b2[2], "isinf f 2");
        b1[2] = glm::isinf(-INFINITY);
        b2[2] = glm2::isinf(-INFINITY);
        print_single<bool>(b1[2], b2[2], "isinf f 3");
        v12b[2] = glm::isinf(glm::vec2(5.0f, -INFINITY));
        v22b[2] = glm2::isinf(glm2::vec2(5.0f, -INFINITY));
        print_vec<2, uint32_t>((glm::uvec2(v12b[2]) * GLM2_TRUE), v22b[2], "isinf v2f 1");
        v12b[2] = glm::isinf(glm::vec2(INFINITY, -INFINITY));
        v22b[2] = glm2::isinf(glm2::vec2(INFINITY, -INFINITY));
        print_vec<2, uint32_t>((glm::uvec2(v12b[2]) * GLM2_TRUE), v22b[2], "isinf v2f 2");
        v13b[2] = glm::isinf(glm::vec3(5.0f, INFINITY, -INFINITY));
        v23b[2] = glm2::isinf(glm2::vec3(5.0f, INFINITY, -INFINITY));
        print_vec<3, uint32_t>((glm::uvec3(v13b[2]) * GLM2_TRUE), v23b[2], "isinf v3f");
        v14b[2] = glm::isinf(glm::vec4(5.0f, INFINITY, NAN, -INFINITY));
        v24b[2] = glm2::isinf(glm2::vec4(5.0f, INFINITY, NAN, -INFINITY));
        print_vec<4, uint32_t>((glm::uvec4(v14b[2]) * GLM2_TRUE), v24b[2], "isinf v4f");

        b1[2] = glm::isinf(5.0);
        b2[2] = glm2::isinf(5.0);
        print_single<bool>(b1[2], b2[2], "isinf d 1");
        b1[2] = glm::isinf(DOUBLE_INFINITY);
        b2[2] = glm2::isinf(DOUBLE_INFINITY);
        print_single<bool>(b1[2], b2[2], "isinf d 2");
        b1[2] = glm::isinf(-DOUBLE_INFINITY);
        b2[2] = glm2::isinf(-DOUBLE_INFINITY);
        print_single<bool>(b1[2], b2[2], "isinf d 3");
        v12b[2] = glm::isinf(glm::dvec2(5.0, -DOUBLE_INFINITY));
        v22b[2] = glm2::isinf(glm2::dvec2(5.0, -DOUBLE_INFINITY));
        print_vec<2, uint32_t>((glm::uvec2(v12b[2]) * GLM2_TRUE), v22b[2], "isinf v2d 1");
        v12b[2] = glm::isinf(glm::dvec2(DOUBLE_INFINITY, -DOUBLE_INFINITY));
        v22b[2] = glm2::isinf(glm2::dvec2(DOUBLE_INFINITY, -DOUBLE_INFINITY));
        print_vec<2, uint32_t>((glm::uvec2(v12b[2]) * GLM2_TRUE), v22b[2], "isinf v2d 2");
        v13b[2] = glm::isinf(glm::dvec3(5.0, DOUBLE_INFINITY, -DOUBLE_INFINITY));
        v23b[2] = glm2::isinf(glm2::dvec3(5.0, DOUBLE_INFINITY, -DOUBLE_INFINITY));
        print_vec<3, uint32_t>((glm::uvec3(v13b[2]) * GLM2_TRUE), v23b[2], "isinf v3d");
        v14b[2] = glm::isinf(glm::dvec4(5.0, DOUBLE_INFINITY, NAN, -DOUBLE_INFINITY));
        v24b[2] = glm2::isinf(glm2::dvec4(5.0, DOUBLE_INFINITY, NAN, -DOUBLE_INFINITY));
        print_vec<4, uint32_t>((glm::uvec4(v14b[2]) * GLM2_TRUE), v24b[2], "isinf v4d");
    }

    // isnan
    {
        b1[2] = glm::isnan(5.0f);
        b2[2] = glm2::isnan(5.0f);
        print_single<bool>(b1[2], b2[2], "isnan f 1");
        b1[2] = glm::isnan(NAN);
        b2[2] = glm2::isnan(NAN);
        print_single<bool>(b1[2], b2[2], "isnan f 2");
        b1[2] = glm::isnan(-NAN);
        b2[2] = glm2::isnan(-NAN);
        print_single<bool>(b1[2], b2[2], "isnan f 3");
        v12b[2] = glm::isnan(glm::vec2(5.0f, -NAN));
        v22b[2] = glm2::isnan(glm2::vec2(5.0f, -NAN));
        print_vec<2, uint32_t>((glm::uvec2(v12b[2]) * GLM2_TRUE), v22b[2], "isnan v2f 1");
        v12b[2] = glm::isnan(glm::vec2(NAN, -NAN));
        v22b[2] = glm2::isnan(glm2::vec2(NAN, -NAN));
        print_vec<2, uint32_t>((glm::uvec2(v12b[2]) * GLM2_TRUE), v22b[2], "isnan v2f 2");
        v13b[2] = glm::isnan(glm::vec3(5.0f, NAN, -NAN));
        v23b[2] = glm2::isnan(glm2::vec3(5.0f, NAN, -NAN));
        print_vec<3, uint32_t>((glm::uvec3(v13b[2]) * GLM2_TRUE), v23b[2], "isnan v3f");
        v14b[2] = glm::isnan(glm::vec4(5.0f, NAN, INFINITY, -NAN));
        v24b[2] = glm2::isnan(glm2::vec4(5.0f, NAN, INFINITY, -NAN));
        print_vec<4, uint32_t>((glm::uvec4(v14b[2]) * GLM2_TRUE), v24b[2], "isnan v4f");

        b1[2] = glm::isnan(5.0);
        b2[2] = glm2::isnan(5.0);
        print_single<bool>(b1[2], b2[2], "isnan d 1");
        b1[2] = glm::isnan(DOUBLE_NAN);
        b2[2] = glm2::isnan(DOUBLE_NAN);
        print_single<bool>(b1[2], b2[2], "isnan d 2");
        b1[2] = glm::isnan(-DOUBLE_NAN);
        b2[2] = glm2::isnan(-DOUBLE_NAN);
        print_single<bool>(b1[2], b2[2], "isnan d 3");
        v12b[2] = glm::isnan(glm::dvec2(5.0, -DOUBLE_NAN));
        v22b[2] = glm2::isnan(glm2::dvec2(5.0, -DOUBLE_NAN));
        print_vec<2, uint32_t>((glm::uvec2(v12b[2]) * GLM2_TRUE), v22b[2], "isnan v2d 1");
        v12b[2] = glm::isnan(glm::dvec2(DOUBLE_NAN, -DOUBLE_NAN));
        v22b[2] = glm2::isnan(glm2::dvec2(DOUBLE_NAN, -DOUBLE_NAN));
        print_vec<2, uint32_t>((glm::uvec2(v12b[2]) * GLM2_TRUE), v22b[2], "isnan v2d 2");
        v13b[2] = glm::isnan(glm::dvec3(5.0, DOUBLE_NAN, -DOUBLE_NAN));
        v23b[2] = glm2::isnan(glm2::dvec3(5.0, DOUBLE_NAN, -DOUBLE_NAN));
        print_vec<3, uint32_t>((glm::uvec3(v13b[2]) * GLM2_TRUE), v23b[2], "isnan v3d");
        v14b[2] = glm::isnan(glm::dvec4(5.0, DOUBLE_NAN, INFINITY, -DOUBLE_NAN));
        v24b[2] = glm2::isnan(glm2::dvec4(5.0, DOUBLE_NAN, INFINITY, -DOUBLE_NAN));
        print_vec<4, uint32_t>((glm::uvec4(v14b[2]) * GLM2_TRUE), v24b[2], "isnan v4d");
    }

    // floatBitsToInt
    {
        i321[4] = glm::floatBitsToInt(f1[0]);
        i322[4] = glm2::floatBitsToInt(f2[0]);
        print_single<int32_t>(i321[4], i322[4], "floatBitsToInt f");
        v12i32[4] = glm::floatBitsToInt(v12f[0]);
        v22i32[4] = glm2::floatBitsToInt(v22f[0]);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "floatBitsToInt v2f");
        v13i32[4] = glm::floatBitsToInt(v13f[0]);
        v23i32[4] = glm2::floatBitsToInt(v23f[0]);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "floatBitsToInt v3f");
        v14i32[4] = glm::floatBitsToInt(v14f[0]);
        v24i32[4] = glm2::floatBitsToInt(v24f[0]);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "floatBitsToInt v4f");
    }

    // floatBitsToUint
    {
        u321[4] = glm::floatBitsToInt(f1[0]);
        u322[4] = glm2::floatBitsToInt(f2[0]);
        print_single<uint32_t>(u321[4], u322[4], "floatBitsToUint f");
        v12u32[4] = glm::floatBitsToInt(v12f[0]);
        v22u32[4] = glm2::floatBitsToInt(v22f[0]);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "floatBitsToUint v2f");
        v13u32[4] = glm::floatBitsToInt(v13f[0]);
        v23u32[4] = glm2::floatBitsToInt(v23f[0]);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "floatBitsToUint v3f");
        v14u32[4] = glm::floatBitsToInt(v14f[0]);
        v24u32[4] = glm2::floatBitsToInt(v24f[0]);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "floatBitsToUint v4f");
    }

    // intBitsToFloat
    {
        f1[4] = glm::intBitsToFloat(i321[2]);
        f2[4] = glm2::intBitsToFloat(i322[2]);
        print_single<float>(f1[4], f2[4], "intBitsToFloat i32");
        v12f[4] = glm::intBitsToFloat(v12i32[2]);
        v22f[4] = glm2::intBitsToFloat(v22i32[2]);
        print_vec<2, float>(v12f[4], v22f[4], "intBitsToFloat v2i32");
        v13f[4] = glm::intBitsToFloat(v13i32[2]);
        v23f[4] = glm2::intBitsToFloat(v23i32[2]);
        print_vec<3, float>(v13f[4], v23f[4], "intBitsToFloat v3i32");
        v14f[4] = glm::intBitsToFloat(v14i32[2]);
        v24f[4] = glm2::intBitsToFloat(v24i32[2]);
        print_vec<4, float>(v14f[4], v24f[4], "intBitsToFloat v4i32");
    }

    // uintBitsToFloat
    {
        f1[4] = glm::uintBitsToFloat(u321[2]);
        f2[4] = glm2::uintBitsToFloat(u322[2]);
        print_single<float>(f1[4], f2[4], "uintBitsToFloat u32");
        v12f[4] = glm::uintBitsToFloat(v12u32[2]);
        v22f[4] = glm2::uintBitsToFloat(v22u32[2]);
        print_vec<2, float>(v12f[4], v22f[4], "uintBitsToFloat v2u32");
        v13f[4] = glm::uintBitsToFloat(v13u32[2]);
        v23f[4] = glm2::uintBitsToFloat(v23u32[2]);
        print_vec<3, float>(v13f[4], v23f[4], "uintBitsToFloat v3u32");
        v14f[4] = glm::uintBitsToFloat(v14u32[2]);
        v24f[4] = glm2::uintBitsToFloat(v24u32[2]);
        print_vec<4, float>(v14f[4], v24f[4], "uintBitsToFloat v4u32");
    }

#endif

#ifdef GLM2_TEST_EXPONENTIAL
    // function exp
    {
        f1[4] = glm::exp(f1[0]);
        f2[4] = glm2::exp(f1[0]);
        print_single<float>(f1[4], f2[4], "exp f");
        d1[4] = glm::exp(d1[0]);
        d2[4] = glm2::exp(d1[0]);
        print_single<double>(d1[4], d2[4], "exp d");
        v12f[4] = glm::exp(v12f[3]);
        v22f[4] = glm2::exp(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "exp v2f");
        v13f[4] = glm::exp(v13f[3]);
        v23f[4] = glm2::exp(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "exp v3f");
        v14f[4] = glm::exp(v14f[3]);
        v24f[4] = glm2::exp(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "exp v4f");
        v12d[4] = glm::exp(v12d[3]);
        v22d[4] = glm2::exp(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "exp v2d");
        v13d[4] = glm::exp(v13d[3]);
        v23d[4] = glm2::exp(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "exp v3d");
        v14d[4] = glm::exp(v14d[3]);
        v24d[4] = glm2::exp(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "exp v4d");
    }

    // function exp2
    {
        f1[4] = glm::exp2(f1[0]);
        f2[4] = glm2::exp2(f1[0]);
        print_single<float>(f1[4], f2[4], "exp2 f");
        d1[4] = glm::exp2(d1[0]);
        d2[4] = glm2::exp2(d1[0]);
        print_single<double>(d1[4], d2[4], "exp2 d");
        v12f[4] = glm::exp2(v12f[3]);
        v22f[4] = glm2::exp2(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "exp2 v2f");
        v13f[4] = glm::exp2(v13f[3]);
        v23f[4] = glm2::exp2(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "exp2 v3f");
        v14f[4] = glm::exp2(v14f[3]);
        v24f[4] = glm2::exp2(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "exp2 v4f");
        v12d[4] = glm::exp2(v12d[3]);
        v22d[4] = glm2::exp2(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "exp2 v2d");
        v13d[4] = glm::exp2(v13d[3]);
        v23d[4] = glm2::exp2(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "exp2 v3d");
        v14d[4] = glm::exp2(v14d[3]);
        v24d[4] = glm2::exp2(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "exp2 v4d");
    }

    // function log
    {
        f1[4] = glm::log(f1[0]);
        f2[4] = glm2::log(f1[0]);
        print_single<float>(f1[4], f2[4], "log f");
        d1[4] = glm::log(d1[0]);
        d2[4] = glm2::log(d1[0]);
        print_single<double>(d1[4], d2[4], "log d");
        v12f[4] = glm::log(v12f[3]);
        v22f[4] = glm2::log(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "log v2f");
        v13f[4] = glm::log(v13f[3]);
        v23f[4] = glm2::log(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "log v3f");
        v14f[4] = glm::log(v14f[3]);
        v24f[4] = glm2::log(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "log v4f");
        v12d[4] = glm::log(v12d[3]);
        v22d[4] = glm2::log(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "log v2d");
        v13d[4] = glm::log(v13d[3]);
        v23d[4] = glm2::log(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "log v3d");
        v14d[4] = glm::log(v14d[3]);
        v24d[4] = glm2::log(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "log v4d");
    }

    // function log2
    {
        f1[4] = glm::log2(f1[0]);
        f2[4] = glm2::log2(f1[0]);
        print_single<float>(f1[4], f2[4], "log2 f");
        d1[4] = glm::log2(d1[0]);
        d2[4] = glm2::log2(d1[0]);
        print_single<double>(d1[4], d2[4], "log2 d");
        v12f[4] = glm::log2(v12f[3]);
        v22f[4] = glm2::log2(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "log2 v2f");
        v13f[4] = glm::log2(v13f[3]);
        v23f[4] = glm2::log2(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "log2 v3f");
        v14f[4] = glm::log2(v14f[3]);
        v24f[4] = glm2::log2(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "log2 v4f");
        v12d[4] = glm::log2(v12d[3]);
        v22d[4] = glm2::log2(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "log2 v2d");
        v13d[4] = glm::log2(v13d[3]);
        v23d[4] = glm2::log2(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "log2 v3d");
        v14d[4] = glm::log2(v14d[3]);
        v24d[4] = glm2::log2(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "log2 v4d");
    }

    // function sqrt
    {
        f1[4] = glm::sqrt(f1[0]);
        f2[4] = glm2::sqrt(f1[0]);
        print_single<float>(f1[4], f2[4], "sqrt f");
        d1[4] = glm::sqrt(d1[0]);
        d2[4] = glm2::sqrt(d1[0]);
        print_single<double>(d1[4], d2[4], "sqrt d");
        v12f[4] = glm::sqrt(v12f[3]);
        v22f[4] = glm2::sqrt(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "sqrt v2f");
        v13f[4] = glm::sqrt(v13f[3]);
        v23f[4] = glm2::sqrt(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "sqrt v3f");
        v14f[4] = glm::sqrt(v14f[3]);
        v24f[4] = glm2::sqrt(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "sqrt v4f");
        v12d[4] = glm::sqrt(v12d[3]);
        v22d[4] = glm2::sqrt(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "sqrt v2d");
        v13d[4] = glm::sqrt(v13d[3]);
        v23d[4] = glm2::sqrt(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "sqrt v3d");
        v14d[4] = glm::sqrt(v14d[3]);
        v24d[4] = glm2::sqrt(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "sqrt v4d");
    }

    // function inversesqrt
    {
            f1[4] = glm::inversesqrt(f1[0]);
            f2[4] = glm2::inversesqrt(f1[0]);
            print_single<float>(f1[4], f2[4], "inversesqrt f");
            d1[4] = glm::inversesqrt(d1[0]);
            d2[4] = glm2::inversesqrt(d1[0]);
            print_single<double>(d1[4], d2[4], "inversesqrt d");
            v12f[4] = glm::inversesqrt(v12f[3]);
            v22f[4] = glm2::inversesqrt(v22f[3]);
            print_vec<2, float>(v12f[4], v22f[4], "inversesqrt v2f");
            v13f[4] = glm::inversesqrt(v13f[3]);
            v23f[4] = glm2::inversesqrt(v23f[3]);
            print_vec<3, float>(v13f[4], v23f[4], "inversesqrt v3f");
            v14f[4] = glm::inversesqrt(v14f[3]);
            v24f[4] = glm2::inversesqrt(v24f[3]);
            print_vec<4, float>(v14f[4], v24f[4], "inversesqrt v4f");
            v12d[4] = glm::inversesqrt(v12d[3]);
            v22d[4] = glm2::inversesqrt(v22d[3]);
            print_vec<2, double>(v12d[4], v22d[4], "inversesqrt v2d");
            v13d[4] = glm::inversesqrt(v13d[3]);
            v23d[4] = glm2::inversesqrt(v23d[3]);
            print_vec<3, double>(v13d[4], v23d[4], "inversesqrt v3d");
            v14d[4] = glm::inversesqrt(v14d[3]);
            v24d[4] = glm2::inversesqrt(v24d[3]);
            print_vec<4, double>(v14d[4], v24d[4], "inversesqrt v4d");
        }
#endif

#ifdef GLM2_TEST_TRIGONOMETRIC
    // function acos
    {
        f1[4] = glm::acos(f1[0]);
        f2[4] = glm2::acos(f1[0]);
        print_single<float>(f1[4], f2[4], "acos +f");
        d1[4] = glm::acos(d1[0]);
        d2[4] = glm2::acos(d1[0]);
        print_single<double>(d1[4], d2[4], "acos +d");
        v12f[4] = glm::acos(v12f[3]);
        v22f[4] = glm2::acos(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "acos v2f");
        v13f[4] = glm::acos(v13f[3]);
        v23f[4] = glm2::acos(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "acos v3f");
        v14f[4] = glm::acos(v14f[3]);
        v24f[4] = glm2::acos(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "acos v4f");
        v12d[4] = glm::acos(v12d[3]);
        v22d[4] = glm2::acos(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "acos v2d");
        v13d[4] = glm::acos(v13d[3]);
        v23d[4] = glm2::acos(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "acos v3d");
        v14d[4] = glm::acos(v14d[3]);
        v24d[4] = glm2::acos(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "acos v4d");
    }

    // function acosh
    {
        f1[4] = glm::acosh(f1[0]);
        f2[4] = glm2::acosh(f1[0]);
        print_single<float>(f1[4], f2[4], "acosh +f");
        d1[4] = glm::acosh(d1[0]);
        d2[4] = glm2::acosh(d1[0]);
        print_single<double>(d1[4], d2[4], "acosh +d");
        v12f[4] = glm::acosh(v12f[3]);
        v22f[4] = glm2::acosh(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "acosh v2f");
        v13f[4] = glm::acosh(v13f[3]);
        v23f[4] = glm2::acosh(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "acosh v3f");
        v14f[4] = glm::acosh(v14f[3]);
        v24f[4] = glm2::acosh(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "acosh v4f");
        v12d[4] = glm::acosh(v12d[3]);
        v22d[4] = glm2::acosh(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "acosh v2d");
        v13d[4] = glm::acosh(v13d[3]);
        v23d[4] = glm2::acosh(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "acosh v3d");
        v14d[4] = glm::acosh(v14d[3]);
        v24d[4] = glm2::acosh(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "acosh v4d");
    }

    // function asin
    {
        f1[4] = glm::asin(f1[0]);
        f2[4] = glm2::asin(f1[0]);
        print_single<float>(f1[4], f2[4], "asin +f");
        d1[4] = glm::asin(d1[0]);
        d2[4] = glm2::asin(d1[0]);
        print_single<double>(d1[4], d2[4], "asin +d");
        v12f[4] = glm::asin(v12f[3]);
        v22f[4] = glm2::asin(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "asin v2f");
        v13f[4] = glm::asin(v13f[3]);
        v23f[4] = glm2::asin(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "asin v3f");
        v14f[4] = glm::asin(v14f[3]);
        v24f[4] = glm2::asin(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "asin v4f");
        v12d[4] = glm::asin(v12d[3]);
        v22d[4] = glm2::asin(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "asin v2d");
        v13d[4] = glm::asin(v13d[3]);
        v23d[4] = glm2::asin(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "asin v3d");
        v14d[4] = glm::asin(v14d[3]);
        v24d[4] = glm2::asin(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "asin v4d");
    }

    // function asinh
    {
        f1[4] = glm::asinh(f1[0]);
        f2[4] = glm2::asinh(f1[0]);
        print_single<float>(f1[4], f2[4], "asinh +f");
        d1[4] = glm::asinh(d1[0]);
        d2[4] = glm2::asinh(d1[0]);
        print_single<double>(d1[4], d2[4], "asinh +d");
        v12f[4] = glm::asinh(v12f[3]);
        v22f[4] = glm2::asinh(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "asinh v2f");
        v13f[4] = glm::asinh(v13f[3]);
        v23f[4] = glm2::asinh(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "asinh v3f");
        v14f[4] = glm::asinh(v14f[3]);
        v24f[4] = glm2::asinh(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "asinh v4f");
        v12d[4] = glm::asinh(v12d[3]);
        v22d[4] = glm2::asinh(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "asinh v2d");
        v13d[4] = glm::asinh(v13d[3]);
        v23d[4] = glm2::asinh(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "asinh v3d");
        v14d[4] = glm::asinh(v14d[3]);
        v24d[4] = glm2::asinh(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "asinh v4d");
    }

    // function atan
    {
        f1[4] = glm::atan(f1[0]);
        f2[4] = glm2::atan(f1[0]);
        print_single<float>(f1[4], f2[4], "atan +f");
        d1[4] = glm::atan(d1[0]);
        d2[4] = glm2::atan(d1[0]);
        print_single<double>(d1[4], d2[4], "atan +d");
        v12f[4] = glm::atan(v12f[3]);
        v22f[4] = glm2::atan(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "atan v2f");
        v13f[4] = glm::atan(v13f[3]);
        v23f[4] = glm2::atan(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "atan v3f");
        v14f[4] = glm::atan(v14f[3]);
        v24f[4] = glm2::atan(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "atan v4f");
        v12d[4] = glm::atan(v12d[3]);
        v22d[4] = glm2::atan(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "atan v2d");
        v13d[4] = glm::atan(v13d[3]);
        v23d[4] = glm2::atan(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "atan v3d");
        v14d[4] = glm::atan(v14d[3]);
        v24d[4] = glm2::atan(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "atan v4d");
    }

    // function atanh
    {
        f1[4] = glm::atanh(f1[0]);
        f2[4] = glm2::atanh(f1[0]);
        print_single<float>(f1[4], f2[4], "atanh +f");
        d1[4] = glm::atanh(d1[0]);
        d2[4] = glm2::atanh(d1[0]);
        print_single<double>(d1[4], d2[4], "atanh +d");
        v12f[4] = glm::atanh(v12f[3]);
        v22f[4] = glm2::atanh(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "atanh v2f");
        v13f[4] = glm::atanh(v13f[3]);
        v23f[4] = glm2::atanh(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "atanh v3f");
        v14f[4] = glm::atanh(v14f[3]);
        v24f[4] = glm2::atanh(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "atanh v4f");
        v12d[4] = glm::atanh(v12d[3]);
        v22d[4] = glm2::atanh(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "atanh v2d");
        v13d[4] = glm::atanh(v13d[3]);
        v23d[4] = glm2::atanh(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "atanh v3d");
        v14d[4] = glm::atanh(v14d[3]);
        v24d[4] = glm2::atanh(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "atanh v4d");
    }

    // function cos
    {
        f1[4] = glm::cos(f1[0]);
        f2[4] = glm2::cos(f1[0]);
        print_single<float>(f1[4], f2[4], "cos +f");
        d1[4] = glm::cos(d1[0]);
        d2[4] = glm2::cos(d1[0]);
        print_single<double>(d1[4], d2[4], "cos +d");
        v12f[4] = glm::cos(v12f[3]);
        v22f[4] = glm2::cos(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "cos v2f");
        v13f[4] = glm::cos(v13f[3]);
        v23f[4] = glm2::cos(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "cos v3f");
        v14f[4] = glm::cos(v14f[3]);
        v24f[4] = glm2::cos(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "cos v4f");
        v12d[4] = glm::cos(v12d[3]);
        v22d[4] = glm2::cos(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "cos v2d");
        v13d[4] = glm::cos(v13d[3]);
        v23d[4] = glm2::cos(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "cos v3d");
        v14d[4] = glm::cos(v14d[3]);
        v24d[4] = glm2::cos(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "cos v4d");
    }

    // function cosh
    {
        f1[4] = glm::cosh(f1[0]);
        f2[4] = glm2::cosh(f1[0]);
        print_single<float>(f1[4], f2[4], "cosh +f");
        d1[4] = glm::cosh(d1[0]);
        d2[4] = glm2::cosh(d1[0]);
        print_single<double>(d1[4], d2[4], "cosh +d");
        v12f[4] = glm::cosh(v12f[3]);
        v22f[4] = glm2::cosh(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "cosh v2f");
        v13f[4] = glm::cosh(v13f[3]);
        v23f[4] = glm2::cosh(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "cosh v3f");
        v14f[4] = glm::cosh(v14f[3]);
        v24f[4] = glm2::cosh(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "cosh v4f");
        v12d[4] = glm::cosh(v12d[3]);
        v22d[4] = glm2::cosh(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "cosh v2d");
        v13d[4] = glm::cosh(v13d[3]);
        v23d[4] = glm2::cosh(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "cosh v3d");
        v14d[4] = glm::cosh(v14d[3]);
        v24d[4] = glm2::cosh(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "cosh v4d");
    }

    // function sin
    {
        f1[4] = glm::sin(f1[0]);
        f2[4] = glm2::sin(f1[0]);
        print_single<float>(f1[4], f2[4], "sin +f");
        d1[4] = glm::sin(d1[0]);
        d2[4] = glm2::sin(d1[0]);
        print_single<double>(d1[4], d2[4], "sin +d");
        v12f[4] = glm::sin(v12f[3]);
        v22f[4] = glm2::sin(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "sin v2f");
        v13f[4] = glm::sin(v13f[3]);
        v23f[4] = glm2::sin(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "sin v3f");
        v14f[4] = glm::sin(v14f[3]);
        v24f[4] = glm2::sin(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "sin v4f");
        v12d[4] = glm::sin(v12d[3]);
        v22d[4] = glm2::sin(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "sin v2d");
        v13d[4] = glm::sin(v13d[3]);
        v23d[4] = glm2::sin(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "sin v3d");
        v14d[4] = glm::sin(v14d[3]);
        v24d[4] = glm2::sin(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "sin v4d");
    }

    // function sinh
    {
        f1[4] = glm::sinh(f1[0]);
        f2[4] = glm2::sinh(f1[0]);
        print_single<float>(f1[4], f2[4], "sinh +f");
        d1[4] = glm::sinh(d1[0]);
        d2[4] = glm2::sinh(d1[0]);
        print_single<double>(d1[4], d2[4], "sinh +d");
        v12f[4] = glm::sinh(v12f[3]);
        v22f[4] = glm2::sinh(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "sinh v2f");
        v13f[4] = glm::sinh(v13f[3]);
        v23f[4] = glm2::sinh(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "sinh v3f");
        v14f[4] = glm::sinh(v14f[3]);
        v24f[4] = glm2::sinh(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "sinh v4f");
        v12d[4] = glm::sinh(v12d[3]);
        v22d[4] = glm2::sinh(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "sinh v2d");
        v13d[4] = glm::sinh(v13d[3]);
        v23d[4] = glm2::sinh(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "sinh v3d");
        v14d[4] = glm::sinh(v14d[3]);
        v24d[4] = glm2::sinh(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "sinh v4d");
    }

    // function tan
    {
        f1[4] = glm::tan(f1[0]);
        f2[4] = glm2::tan(f1[0]);
        print_single<float>(f1[4], f2[4], "tan +f");
        d1[4] = glm::tan(d1[0]);
        d2[4] = glm2::tan(d1[0]);
        print_single<double>(d1[4], d2[4], "tan +d");
        v12f[4] = glm::tan(v12f[3]);
        v22f[4] = glm2::tan(v22f[3]);
        print_vec<2, float>(v12f[4], v22f[4], "tan v2f");
        v13f[4] = glm::tan(v13f[3]);
        v23f[4] = glm2::tan(v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "tan v3f");
        v14f[4] = glm::tan(v14f[3]);
        v24f[4] = glm2::tan(v24f[3]);
        print_vec<4, float>(v14f[4], v24f[4], "tan v4f");
        v12d[4] = glm::tan(v12d[3]);
        v22d[4] = glm2::tan(v22d[3]);
        print_vec<2, double>(v12d[4], v22d[4], "tan v2d");
        v13d[4] = glm::tan(v13d[3]);
        v23d[4] = glm2::tan(v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "tan v3d");
        v14d[4] = glm::tan(v14d[3]);
        v24d[4] = glm2::tan(v24d[3]);
        print_vec<4, double>(v14d[4], v24d[4], "tan v4d");
    }

    // function tanh
    {
            f1[4] = glm::tanh(f1[0]);
            f2[4] = glm2::tanh(f1[0]);
            print_single<float>(f1[4], f2[4], "tanh +f");
            d1[4] = glm::tanh(d1[0]);
            d2[4] = glm2::tanh(d1[0]);
            print_single<double>(d1[4], d2[4], "tanh +d");
            v12f[4] = glm::tanh(v12f[3]);
            v22f[4] = glm2::tanh(v22f[3]);
            print_vec<2, float>(v12f[4], v22f[4], "tanh v2f");
            v13f[4] = glm::tanh(v13f[3]);
            v23f[4] = glm2::tanh(v23f[3]);
            print_vec<3, float>(v13f[4], v23f[4], "tanh v3f");
            v14f[4] = glm::tanh(v14f[3]);
            v24f[4] = glm2::tanh(v24f[3]);
            print_vec<4, float>(v14f[4], v24f[4], "tanh v4f");
            v12d[4] = glm::tanh(v12d[3]);
            v22d[4] = glm2::tanh(v22d[3]);
            print_vec<2, double>(v12d[4], v22d[4], "tanh v2d");
            v13d[4] = glm::tanh(v13d[3]);
            v23d[4] = glm2::tanh(v23d[3]);
            print_vec<3, double>(v13d[4], v23d[4], "tanh v3d");
            v14d[4] = glm::tanh(v14d[3]);
            v24d[4] = glm2::tanh(v24d[3]);
            print_vec<4, double>(v14d[4], v24d[4], "tanh v4d");
        }
#endif

#ifdef GLM2_TEST_GEOMETRIC
    // function cross
    {
        v13f[4] = glm::cross(v13f[0], v13f[3]);
        v23f[4] = glm2::cross(v23f[0], v23f[3]);
        print_vec<3, float>(v13f[4], v23f[4], "cross v3f");
        v13d[4] = glm::cross(v13d[0], v13d[3]);
        v23d[4] = glm2::cross(v23d[0], v23d[3]);
        print_vec<3, double>(v13d[4], v23d[4], "cross v3d");
    }

    // function dot
    {   
        f1[4] = glm::dot(v12f[0], v12f[1]);
        v22f[4] = glm2::dot(v22f[0], v22f[1]);
        print_single<float>(f1[4], v22f[4][0], "dot v2f");
        f1[4] = glm::dot(v13f[0], v13f[1]);
        v23f[4] = glm2::dot(v23f[0], v23f[1]);
        print_single<float>(f1[4], v23f[4][0], "dot v3f");
        f1[4] = glm::dot(v14f[0], v14f[1]);
        v24f[4] = glm2::dot(v24f[0], v24f[1]);
        print_single<float>(f1[4], v24f[4][0], "dot v4f");
        d1[4] = glm::dot(v12d[0], v12d[1]);
        v22d[4] = glm2::dot(v22d[0], v22d[1]);
        print_single<double>(d1[4], v22d[4][0], "dot v2d");
        d1[4] = glm::dot(v13d[0], v13d[1]);
        v23d[4] = glm2::dot(v23d[0], v23d[1]);
        print_single<double>(d1[4], v23d[4][0], "dot v3d");
        d1[4] = glm::dot(v14d[0], v14d[1]);
        v24d[4] = glm2::dot(v24d[0], v24d[1]);
        print_single<double>(d1[4], v24d[4][0], "dot v4d");
    }

    // function distance
    {   
        f1[4] = glm::distance(v12f[0], v12f[1]);
        v22f[4] = glm2::distance(v22f[0], v22f[1]);
        print_single<float>(f1[4], v22f[4][0], "distance v2f");
        f1[4] = glm::distance(v13f[0], v13f[1]);
        v23f[4] = glm2::distance(v23f[0], v23f[1]);
        print_single<float>(f1[4], v23f[4][0], "distance v3f");
        f1[4] = glm::distance(v14f[0], v14f[1]);
        v24f[4] = glm2::distance(v24f[0], v24f[1]);
        print_single<float>(f1[4], v24f[4][0], "distance v4f");
        d1[4] = glm::distance(v12d[0], v12d[1]);
        v22d[4] = glm2::distance(v22d[0], v22d[1]);
        print_single<double>(d1[4], v22d[4][0], "distance v2d");
        d1[4] = glm::distance(v13d[0], v13d[1]);
        v23d[4] = glm2::distance(v23d[0], v23d[1]);
        print_single<double>(d1[4], v23d[4][0], "distance v3d");
        d1[4] = glm::distance(v14d[0], v14d[1]);
        v24d[4] = glm2::distance(v24d[0], v24d[1]);
        print_single<double>(d1[4], v24d[4][0], "distance v4d");
    }

    // function length
    {   
        f1[4] = glm::length(v12f[1]);
        v22f[4] = glm2::length(v22f[1]);
        print_single<float>(f1[4], v22f[4][0], "length v2f");
        f1[4] = glm::length(v13f[1]);
        v23f[4] = glm2::length(v23f[1]);
        print_single<float>(f1[4], v23f[4][0], "length v3f");
        f1[4] = glm::length(v14f[1]);
        v24f[4] = glm2::length(v24f[1]);
        print_single<float>(f1[4], v24f[4][0], "length v4f");
        d1[4] = glm::length(v12d[1]);
        v22d[4] = glm2::length(v22d[1]);
        print_single<double>(d1[4], v22d[4][0], "length v2d");
        d1[4] = glm::length(v13d[1]);
        v23d[4] = glm2::length(v23d[1]);
        print_single<double>(d1[4], v23d[4][0], "length v3d");
        d1[4] = glm::length(v14d[1]);
        v24d[4] = glm2::length(v24d[1]);
        print_single<double>(d1[4], v24d[4][0], "length v4d");
    }

    // function faceforward
    {   
        v12f[4] = glm::faceforward(v12f[0], v12f[3], v12f[1]);
        v22f[4] = glm2::faceforward(v22f[0], v22f[3], v22f[1]);
        print_vec<2, float>(v12f[4], v22f[4], "faceforward v2f");
        v13f[4] = glm::faceforward(v13f[0], v13f[3], v13f[1]);
        v23f[4] = glm2::faceforward(v23f[0], v23f[3], v23f[1]);
        print_vec<3, float>(v13f[4], v23f[4], "faceforward v3f");
        v14f[4] = glm::faceforward(v14f[0], v14f[3], v14f[1]);
        v24f[4] = glm2::faceforward(v24f[0], v24f[3], v24f[1]);
        print_vec<4, float>(v14f[4], v24f[4], "faceforward v4f");
        v12d[4] = glm::faceforward(v12d[0], v12d[3], v12d[1]);
        v22d[4] = glm2::faceforward(v22d[0], v22d[3], v22d[1]);
        print_vec<2, double>(v12d[4], v22d[4], "faceforward v2d");
        v13d[4] = glm::faceforward(v13d[0], v13d[3], v13d[1]);
        v23d[4] = glm2::faceforward(v23d[0], v23d[3], v23d[1]);
        print_vec<3, double>(v13d[4], v23d[4], "faceforward v3d");
        v14d[4] = glm::faceforward(v14d[0], v14d[3], v14d[1]);
        v24d[4] = glm2::faceforward(v24d[0], v24d[3], v24d[1]);
        print_vec<4, double>(v14d[4], v24d[4], "faceforward v4d");
    }

    // function normalize
    {   
        v12f[4] = glm::normalize(v12f[1]);
        v22f[4] = glm2::normalize(v22f[1]);
        print_vec<2, float>(v12f[4], v22f[4], "normalize v2f");
        v13f[4] = glm::normalize(v13f[1]);
        v23f[4] = glm2::normalize(v23f[1]);
        print_vec<3, float>(v13f[4], v23f[4], "normalize v3f");
        v14f[4] = glm::normalize(v14f[1]);
        v24f[4] = glm2::normalize(v24f[1]);
        print_vec<4, float>(v14f[4], v24f[4], "normalize v4f");
        v12d[4] = glm::normalize(v12d[1]);
        v22d[4] = glm2::normalize(v22d[1]);
        print_vec<2, double>(v12d[4], v22d[4], "normalize v2d");
        v13d[4] = glm::normalize(v13d[1]);
        v23d[4] = glm2::normalize(v23d[1]);
        print_vec<3, double>(v13d[4], v23d[4], "normalize v3d");
        v14d[4] = glm::normalize(v14d[1]);
        v24d[4] = glm2::normalize(v24d[1]);
        print_vec<4, double>(v14d[4], v24d[4], "normalize v4d");
    }

    // function reflect
    {   
        v12f[4] = glm::reflect(v12f[0], v12f[1]);
        v22f[4] = glm2::reflect(v22f[0], v22f[1]);
        print_vec<2, float>(v12f[4], v22f[4], "reflect v2f");
        v13f[4] = glm::reflect(v13f[0], v13f[1]);
        v23f[4] = glm2::reflect(v23f[0], v23f[1]);
        print_vec<3, float>(v13f[4], v23f[4], "reflect v3f");
        v14f[4] = glm::reflect(v14f[0], v14f[1]);
        v24f[4] = glm2::reflect(v24f[0], v24f[1]);
        print_vec<4, float>(v14f[4], v24f[4], "reflect v4f");
        v12d[4] = glm::reflect(v12d[0], v12d[1]);
        v22d[4] = glm2::reflect(v22d[0], v22d[1]);
        print_vec<2, double>(v12d[4], v22d[4], "reflect v2d");
        v13d[4] = glm::reflect(v13d[0], v13d[1]);
        v23d[4] = glm2::reflect(v23d[0], v23d[1]);
        print_vec<3, double>(v13d[4], v23d[4], "reflect v3d");
        v14d[4] = glm::reflect(v14d[0], v14d[1]);
        v24d[4] = glm2::reflect(v24d[0], v24d[1]);
        print_vec<4, double>(v14d[4], v24d[4], "reflect v4d");
    }

    // function refract
    {   
            v12f[4] = glm::refract(v12f[0], v12f[1], 0.658f);
            v22f[4] = glm2::refract(v22f[0], v22f[1], 0.658f);
            print_vec<2, float>(v12f[4], v22f[4], "refract v2f");
            v13f[4] = glm::refract(v13f[0], v13f[1], 0.658f);
            v23f[4] = glm2::refract(v23f[0], v23f[1], 0.658f);
            print_vec<3, float>(v13f[4], v23f[4], "refract v3f");
            v14f[4] = glm::refract(v14f[0], v14f[1], 0.658f);
            v24f[4] = glm2::refract(v24f[0], v24f[1], 0.658f);
            print_vec<4, float>(v14f[4], v24f[4], "refract v4f");
            v12d[4] = glm::refract(v12d[0], v12d[1], 0.658);
            v22d[4] = glm2::refract(v22d[0], v22d[1], 0.658);
            print_vec<2, double>(v12d[4], v22d[4], "refract v2d");
            v13d[4] = glm::refract(v13d[0], v13d[1], 0.658);
            v23d[4] = glm2::refract(v23d[0], v23d[1], 0.658);
            print_vec<3, double>(v13d[4], v23d[4], "refract v3d");
            v14d[4] = glm::refract(v14d[0], v14d[1], 0.658);
            v24d[4] = glm2::refract(v24d[0], v24d[1], 0.658);
            print_vec<4, double>(v14d[4], v24d[4], "refract v4d");
        }
#endif

#ifdef GLM2_TEST_MATRIX
    // transpose
    {
        m122f[3] = glm::transpose(m122f[0]);
        m222f[3] = transpose(m222f[0]);
        print_mat<2, 2, float>(m122f[3], m222f[3], "mat2x2 transpose");
        m132f[3] = glm::transpose(m123f[0]);
        m232f[3] = transpose(m223f[0]);
        print_mat<3, 2, float>(m132f[3], m232f[3], "mat2x3 transpose");
        m142f[3] = glm::transpose(m124f[0]);
        m242f[3] = transpose(m224f[0]);
        print_mat<4, 2, float>(m142f[3], m242f[3], "mat2x4 transpose");
        m123f[3] = glm::transpose(m132f[0]);
        m223f[3] = transpose(m232f[0]);
        print_mat<2, 3, float>(m123f[3], m223f[3], "mat3x2 transpose");
        m133f[3] = glm::transpose(m133f[0]);
        m233f[3] = transpose(m233f[0]);
        print_mat<3, 3, float>(m133f[3], m233f[3], "mat3x3 transpose");
        m143f[3] = glm::transpose(m134f[0]);
        m243f[3] = transpose(m234f[0]);
        print_mat<4, 3, float>(m143f[3], m243f[3], "mat3x4 transpose");
        m124f[3] = glm::transpose(m142f[0]);
        m224f[3] = transpose(m242f[0]);
        print_mat<2, 4, float>(m124f[3], m224f[3], "mat4x2 transpose");
        m134f[3] = glm::transpose(m143f[0]);
        m234f[3] = transpose(m243f[0]);
        print_mat<3, 4, float>(m134f[3], m234f[3], "mat4x3 transpose");
        m144f[3] = glm::transpose(m144f[0]);
        m244f[3] = transpose(m244f[0]);
        print_mat<4, 4, float>(m144f[3], m244f[3], "mat4x4 transpose");
        m122d[3] = glm::transpose(m122d[0]);
        m222d[3] = transpose(m222d[0]);
        print_mat<2, 2, double>(m122d[3], m222d[3], "dmat2x2 transpose");
        m132d[3] = glm::transpose(m123d[0]);
        m232d[3] = transpose(m223d[0]);
        print_mat<3, 2, double>(m132d[3], m232d[3], "dmat2x3 transpose");
        m142d[3] = glm::transpose(m124d[0]);
        m242d[3] = transpose(m224d[0]);
        print_mat<4, 2, double>(m142d[3], m242d[3], "dmat2x4 transpose");
        m123d[3] = glm::transpose(m132d[0]);
        m223d[3] = transpose(m232d[0]);
        print_mat<2, 3, double>(m123d[3], m223d[3], "dmat3x2 transpose");
        m133d[3] = glm::transpose(m133d[0]);
        m233d[3] = transpose(m233d[0]);
        print_mat<3, 3, double>(m133d[3], m233d[3], "dmat3x3 transpose");
        m143d[3] = glm::transpose(m134d[0]);
        m243d[3] = transpose(m234d[0]);
        print_mat<4, 3, double>(m143d[3], m243d[3], "dmat3x4 transpose");
        m124d[3] = glm::transpose(m142d[0]);
        m224d[3] = transpose(m242d[0]);
        print_mat<2, 4, double>(m124d[3], m224d[3], "dmat4x2 transpose");
        m134d[3] = glm::transpose(m143d[0]);
        m234d[3] = transpose(m243d[0]);
        print_mat<3, 4, double>(m134d[3], m234d[3], "dmat4x3 transpose");
        m144d[3] = glm::transpose(m144d[0]);
        m244d[3] = transpose(m244d[0]);
        print_mat<4, 4, double>(m144d[3], m244d[3], "dmat4x4 transpose");
    }

    // determinant
    {
        f1[4] = glm::determinant(m122f[2]);
        f2[4] = determinant(m222f[2]);
        print_single<float>(f1[4], f2[4], "mat2x2 determinant");
        f1[4] = glm::determinant(m133f[2]);
        f2[4] = determinant(m233f[2]);
        print_single<float>(f1[4], f2[4], "mat3x3 determinant");
        f1[4] = glm::determinant(m144f[2]);
        f2[4] = determinant(m244f[2]);
        print_single<float>(f1[4], f2[4], "mat4x4 determinant");
        d1[4] = glm::determinant(m122d[2]);
        d2[4] = determinant(m222d[2]);
        print_single<double>(d1[4], d2[4], "dmat2x2 determinant");
        d1[4] = glm::determinant(m133d[2]);
        d2[4] = determinant(m233d[2]);
        print_single<double>(d1[4], d2[4], "dmat3x3 determinant");
        d1[4] = glm::determinant(m144d[2]);
        d2[4] = determinant(m244d[2]);
        print_single<double>(d1[4], d2[4], "dmat4x4 determinant");
    }

    // inverse
    {
        m122f[3] = glm::inverse(m122f[2]);
        m222f[3] = inverse(m222f[2]);
        print_mat<2, 2, float>(m122f[3], m222f[3], "mat2x2 inverse");
        m133f[3] = glm::inverse(m133f[2]);
        m233f[3] = inverse(m233f[2]);
        print_mat<3, 3, float>(m133f[3], m233f[3], "mat3x3 inverse");
        m144f[3] = glm::inverse(m144f[2]);
        m244f[3] = inverse(m244f[2]);
        print_mat<4, 4, float>(m144f[3], m244f[3], "mat4x4 inverse");
        m122d[3] = glm::inverse(m122d[2]);
        m222d[3] = inverse(m222d[2]);
        print_mat<2, 2, double>(m122d[3], m222d[3], "dmat2x2 inverse");
        m133d[3] = glm::inverse(m133d[2]);
        m233d[3] = inverse(m233d[2]);
        print_mat<3, 3, double>(m133d[3], m233d[3], "dmat3x3 inverse");
        m144d[3] = glm::inverse(m144d[2]);
        m244d[3] = inverse(m244d[2]);
        print_mat<4, 4, double>(m144d[3], m244d[3], "dmat4x4 inverse");
    }
#endif

#ifdef GLM2_TEST_INTEGER

    // bitCount
    {
        i321[4] = glm::bitCount(i321[3]);
        i322[4] = glm2::bitCount(i322[3]);
        print_single<int32_t>(i321[4], i322[4], "int32_t bitCount");
        v12i32[4] = glm::bitCount(v12i32[3]);
        v22i32[4] = glm2::bitCount(v22i32[3]);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 bitCount");
        v13i32[4] = glm::bitCount(v13i32[3]);
        v23i32[4] = glm2::bitCount(v23i32[3]);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 bitCount");
        v14i32[4] = glm::bitCount(v14i32[3]);
        v24i32[4] = glm2::bitCount(v24i32[3]);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 bitCount");

        u321[4] = glm::bitCount(u321[3]);
        u322[4] = glm2::bitCount(u322[3]);
        print_single<uint32_t>(u321[4], u322[4], "uint32_t bitCount");
        v12u32[4] = glm::bitCount(v12u32[3]);
        v22u32[4] = glm2::bitCount(v22u32[3]);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 bitCount");
        v13u32[4] = glm::bitCount(v13u32[3]);
        v23u32[4] = glm2::bitCount(v23u32[3]);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 bitCount");
        v14u32[4] = glm::bitCount(v14u32[3]);
        v24u32[4] = glm2::bitCount(v24u32[3]);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 bitCount");
    }

    // bitfieldExtract
    {
        i321[4] = glm::bitfieldExtract(i321[3], 5, 20);
        i322[4] = glm2::bitfieldExtract(i322[3], 5, 20);
        print_single<int32_t>(i321[4], i322[4], "int32_t bitfieldExtract 1");
        i321[4] = glm::bitfieldExtract(i321[3], 5, 27);
        i322[4] = glm2::bitfieldExtract(i322[3], 5, 27);
        print_single<int32_t>(i321[4], i322[4], "int32_t bitfieldExtract 2");
        i321[4] = glm::bitfieldExtract(i321[3], 0, 32);
        i322[4] = glm2::bitfieldExtract(i322[3], 0, 32);
        print_single<int32_t>(i321[4], i322[4], "int32_t bitfieldExtract 3");
        v12i32[4] = glm::bitfieldExtract(v12i32[3], 5, 20);
        v22i32[4] = glm2::bitfieldExtract(v22i32[3], 5, 20);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 bitfieldExtract 1");
        v12i32[4] = glm::bitfieldExtract(v12i32[3], 5, 27);
        v22i32[4] = glm2::bitfieldExtract(v22i32[3], 5, 27);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 bitfieldExtract 2");
        v12i32[4] = glm::bitfieldExtract(v12i32[3], 0, 32);
        v22i32[4] = glm2::bitfieldExtract(v22i32[3], 0, 32);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 bitfieldExtract 3");
        v13i32[4] = glm::bitfieldExtract(v13i32[3], 5, 20);
        v23i32[4] = glm2::bitfieldExtract(v23i32[3], 5, 20);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 bitfieldExtract 1");
        v13i32[4] = glm::bitfieldExtract(v13i32[3], 5, 27);
        v23i32[4] = glm2::bitfieldExtract(v23i32[3], 5, 27);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 bitfieldExtract 2");
        v13i32[4] = glm::bitfieldExtract(v13i32[3], 0, 32);
        v23i32[4] = glm2::bitfieldExtract(v23i32[3], 0, 32);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 bitfieldExtract 3");
        v14i32[4] = glm::bitfieldExtract(v14i32[3], 5, 20);
        v24i32[4] = glm2::bitfieldExtract(v24i32[3], 5, 20);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 bitfieldExtract 1");
        v14i32[4] = glm::bitfieldExtract(v14i32[3], 5, 27);
        v24i32[4] = glm2::bitfieldExtract(v24i32[3], 5, 27);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 bitfieldExtract 2");
        v14i32[4] = glm::bitfieldExtract(v14i32[3], 0, 32);
        v24i32[4] = glm2::bitfieldExtract(v24i32[3], 0, 32);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 bitfieldExtract 3");

        u321[4] = glm::bitfieldExtract(u321[3], 5, 20);
        u322[4] = glm2::bitfieldExtract(u322[3], 5, 20);
        print_single<uint32_t>(u321[4], u322[4], "uint32_t bitfieldExtract 1");
        u321[4] = glm::bitfieldExtract(u321[3], 5, 27);
        u322[4] = glm2::bitfieldExtract(u322[3], 5, 27);
        print_single<uint32_t>(u321[4], u322[4], "uint32_t bitfieldExtract 2");
        u321[4] = glm::bitfieldExtract(u321[3], 0, 32);
        u322[4] = glm2::bitfieldExtract(u322[3], 0, 32);
        print_single<uint32_t>(u321[4], u322[4], "uint32_t bitfieldExtract 3");
        v12u32[4] = glm::bitfieldExtract(v12u32[3], 5, 20);
        v22u32[4] = glm2::bitfieldExtract(v22u32[3], 5, 20);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 bitfieldExtract 1");
        v12u32[4] = glm::bitfieldExtract(v12u32[3], 5, 27);
        v22u32[4] = glm2::bitfieldExtract(v22u32[3], 5, 27);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 bitfieldExtract 2");
        v12u32[4] = glm::bitfieldExtract(v12u32[3], 0, 32);
        v22u32[4] = glm2::bitfieldExtract(v22u32[3], 0, 32);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 bitfieldExtract 3");
        v13u32[4] = glm::bitfieldExtract(v13u32[3], 5, 20);
        v23u32[4] = glm2::bitfieldExtract(v23u32[3], 5, 20);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 bitfieldExtract 1");
        v13u32[4] = glm::bitfieldExtract(v13u32[3], 5, 27);
        v23u32[4] = glm2::bitfieldExtract(v23u32[3], 5, 27);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 bitfieldExtract 2");
        v13u32[4] = glm::bitfieldExtract(v13u32[3], 0, 32);
        v23u32[4] = glm2::bitfieldExtract(v23u32[3], 0, 32);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 bitfieldExtract 3");
        v14u32[4] = glm::bitfieldExtract(v14u32[3], 5, 20);
        v24u32[4] = glm2::bitfieldExtract(v24u32[3], 5, 20);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 bitfieldExtract 1");
        v14u32[4] = glm::bitfieldExtract(v14u32[3], 5, 27);
        v24u32[4] = glm2::bitfieldExtract(v24u32[3], 5, 27);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 bitfieldExtract 2");
        v14u32[4] = glm::bitfieldExtract(v14u32[3], 0, 32);
        v24u32[4] = glm2::bitfieldExtract(v24u32[3], 0, 32);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 bitfieldExtract 3");
    }

    // bitfieldInsert
    {
        i321[4] = glm::bitfieldInsert(i321[3], i321[2], 5, 20);
        i322[4] = glm2::bitfieldInsert(i322[3], i322[2], 5, 20);
        print_single<int32_t>(i321[4], i322[4], "int32_t bitfieldInsert 1");
        i321[4] = glm::bitfieldInsert(i321[3], i321[2], 5, 27);
        i322[4] = glm2::bitfieldInsert(i322[3], i322[2], 5, 27);
        print_single<int32_t>(i321[4], i322[4], "int32_t bitfieldInsert 2");
        i321[4] = glm::bitfieldInsert(i321[3], i321[2], 0, 32);
        i322[4] = glm2::bitfieldInsert(i322[3], i322[2], 0, 32);
        print_single<int32_t>(i321[4], i322[4], "int32_t bitfieldInsert 3");
        v12i32[4] = glm::bitfieldInsert(v12i32[3], v12i32[2], 5, 20);
        v22i32[4] = glm2::bitfieldInsert(v22i32[3], v22i32[2], 5, 20);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 bitfieldInsert 1");
        v12i32[4] = glm::bitfieldInsert(v12i32[3], v12i32[2], 5, 27);
        v22i32[4] = glm2::bitfieldInsert(v22i32[3], v22i32[2], 5, 27);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 bitfieldInsert 2");
        v12i32[4] = glm::bitfieldInsert(v12i32[3], v12i32[2], 0, 32);
        v22i32[4] = glm2::bitfieldInsert(v22i32[3], v22i32[2], 0, 32);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 bitfieldInsert 3");
        v13i32[4] = glm::bitfieldInsert(v13i32[3], v13i32[2], 5, 20);
        v23i32[4] = glm2::bitfieldInsert(v23i32[3], v23i32[2], 5, 20);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 bitfieldInsert 1");
        v13i32[4] = glm::bitfieldInsert(v13i32[3], v13i32[2], 5, 27);
        v23i32[4] = glm2::bitfieldInsert(v23i32[3], v23i32[2], 5, 27);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 bitfieldInsert 2");
        v13i32[4] = glm::bitfieldInsert(v13i32[3], v13i32[2], 0, 32);
        v23i32[4] = glm2::bitfieldInsert(v23i32[3], v23i32[2], 0, 32);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 bitfieldInsert 3");
        v14i32[4] = glm::bitfieldInsert(v14i32[3], v14i32[2], 5, 20);
        v24i32[4] = glm2::bitfieldInsert(v24i32[3], v24i32[2], 5, 20);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 bitfieldInsert 1");
        v14i32[4] = glm::bitfieldInsert(v14i32[3], v14i32[2], 5, 27);
        v24i32[4] = glm2::bitfieldInsert(v24i32[3], v24i32[2], 5, 27);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 bitfieldInsert 2");
        v14i32[4] = glm::bitfieldInsert(v14i32[3], v14i32[2], 0, 32);
        v24i32[4] = glm2::bitfieldInsert(v24i32[3], v24i32[2], 0, 32);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 bitfieldInsert 3");

        u321[4] = glm::bitfieldInsert(u321[3], u321[2], 5, 20);
        u322[4] = glm2::bitfieldInsert(u322[3], u322[2], 5, 20);
        print_single<uint32_t>(u321[4], u322[4], "uint32_t bitfieldInsert 1");
        u321[4] = glm::bitfieldInsert(u321[3], u321[2], 5, 27);
        u322[4] = glm2::bitfieldInsert(u322[3], u322[2], 5, 27);
        print_single<uint32_t>(u321[4], u322[4], "uint32_t bitfieldInsert 2");
        u321[4] = glm::bitfieldInsert(u321[3], u321[2], 0, 32);
        u322[4] = glm2::bitfieldInsert(u322[3], u322[2], 0, 32);
        print_single<uint32_t>(u321[4], u322[4], "uint32_t bitfieldInsert 3");
        v12u32[4] = glm::bitfieldInsert(v12u32[3], v12u32[2], 5, 20);
        v22u32[4] = glm2::bitfieldInsert(v22u32[3], v22u32[2], 5, 20);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 bitfieldInsert 1");
        v12u32[4] = glm::bitfieldInsert(v12u32[3], v12u32[2], 5, 27);
        v22u32[4] = glm2::bitfieldInsert(v22u32[3], v22u32[2], 5, 27);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 bitfieldInsert 2");
        v12u32[4] = glm::bitfieldInsert(v12u32[3], v12u32[2], 0, 32);
        v22u32[4] = glm2::bitfieldInsert(v22u32[3], v22u32[2], 0, 32);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 bitfieldInsert 3");
        v13u32[4] = glm::bitfieldInsert(v13u32[3], v13u32[2], 5, 20);
        v23u32[4] = glm2::bitfieldInsert(v23u32[3], v23u32[2], 5, 20);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 bitfieldInsert 1");
        v13u32[4] = glm::bitfieldInsert(v13u32[3], v13u32[2], 5, 27);
        v23u32[4] = glm2::bitfieldInsert(v23u32[3], v23u32[2], 5, 27);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 bitfieldInsert 2");
        v13u32[4] = glm::bitfieldInsert(v13u32[3], v13u32[2], 0, 32);
        v23u32[4] = glm2::bitfieldInsert(v23u32[3], v23u32[2], 0, 32);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 bitfieldInsert 3");
        v14u32[4] = glm::bitfieldInsert(v14u32[3], v14u32[2], 5, 20);
        v24u32[4] = glm2::bitfieldInsert(v24u32[3], v24u32[2], 5, 20);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 bitfieldInsert 1");
        v14u32[4] = glm::bitfieldInsert(v14u32[3], v14u32[2], 5, 27);
        v24u32[4] = glm2::bitfieldInsert(v24u32[3], v24u32[2], 5, 27);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 bitfieldInsert 2");
        v14u32[4] = glm::bitfieldInsert(v14u32[3], v14u32[2], 0, 32);
        v24u32[4] = glm2::bitfieldInsert(v24u32[3], v24u32[2], 0, 32);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 bitfieldInsert 3");
    }

    // bitfieldReverse
    {
#if 0
        i321[4] = glm::bitfieldReverse(i321[3]);
        i322[4] = glm2::bitfieldReverse(i322[3]);
        print_single<int32_t>(i321[4], i322[4], "int32_t bitfieldReverse");
        v12i32[4] = glm::bitfieldReverse(v12i32[3]);
        v22i32[4] = glm2::bitfieldReverse(v22i32[3]);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 bitfieldReverse");
        v13i32[4] = glm::bitfieldReverse(v13i32[3]);
        v23i32[4] = glm2::bitfieldReverse(v23i32[3]);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 bitfieldReverse");
        v14i32[4] = glm::bitfieldReverse(v14i32[3]);
        v24i32[4] = glm2::bitfieldReverse(v24i32[3]);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 bitfieldReverse");
#endif
        u321[4] = glm::bitfieldReverse(u321[3]);
        u322[4] = glm2::bitfieldReverse(u322[3]);
        print_single<uint32_t>(u321[4], u322[4], "uint32_t bitfieldReverse");
        v12u32[4] = glm::bitfieldReverse(v12u32[3]);
        v22u32[4] = glm2::bitfieldReverse(v22u32[3]);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "uvec2 bitfieldReverse");
        v13u32[4] = glm::bitfieldReverse(v13u32[3]);
        v23u32[4] = glm2::bitfieldReverse(v23u32[3]);
        print_vec<3, uint32_t>(v13u32[4], v23u32[4], "uvec3 bitfieldReverse");
        v14u32[4] = glm::bitfieldReverse(v14u32[3]);
        v24u32[4] = glm2::bitfieldReverse(v24u32[3]);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 bitfieldReverse");
    }

    // findLSB
    {
        i321[4] = glm::findLSB(i321[3]);
        i322[4] = glm2::findLSB(i322[3]);
        print_single<int32_t>(i321[4], i322[4], "int32_t findLSB");
        v12i32[4] = glm::findLSB(v12i32[3]);
        v22i32[4] = glm2::findLSB(v22i32[3]);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 findLSB");
        v13i32[4] = glm::findLSB(v13i32[3]);
        v23i32[4] = glm2::findLSB(v23i32[3]);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 findLSB");
        v14i32[4] = glm::findLSB(v14i32[3]);
        v24i32[4] = glm2::findLSB(v24i32[3]);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 findLSB");

        i321[4] = glm::findLSB(i321[3]);
        i322[4] = glm2::findLSB(i322[3]);
        print_single<uint32_t>(i321[4], i322[4], "uint32_t findLSB");
        v12i32[4] = glm::findLSB(v12i32[3]);
        v22i32[4] = glm2::findLSB(v22i32[3]);
        print_vec<2, uint32_t>(v12i32[4], v22i32[4], "uvec2 findLSB");
        v13i32[4] = glm::findLSB(v13i32[3]);
        v23i32[4] = glm2::findLSB(v23i32[3]);
        print_vec<3, uint32_t>(v13i32[4], v23i32[4], "uvec3 findLSB");
        v14i32[4] = glm::findLSB(v14i32[3]);
        v24i32[4] = glm2::findLSB(v24i32[3]);
        print_vec<4, uint32_t>(v14i32[4], v24i32[4], "uvec4 findLSB");

        i321[4] = glm::findLSB(i321[2]);
        i322[4] = glm2::findLSB(i322[2]);
        print_single<int32_t>(i321[4], i322[4], "int32_t findLSB 0");
        v12i32[4] = glm::findLSB(v12i32[1]);
        v22i32[4] = glm2::findLSB(v22i32[1]);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 findLSB 0");
        v13i32[4] = glm::findLSB(v13i32[1]);
        v23i32[4] = glm2::findLSB(v23i32[1]);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 findLSB 0");
        v14i32[4] = glm::findLSB(v14i32[1]);
        v24i32[4] = glm2::findLSB(v24i32[1]);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 findLSB 0");

        i321[4] = glm::findLSB(i321[2]);
        i322[4] = glm2::findLSB(i322[2]);
        print_single<uint32_t>(i321[4], i322[4], "uint32_t findLSB 0");
        v12i32[4] = glm::findLSB(v12i32[1]);
        v22i32[4] = glm2::findLSB(v22i32[1]);
        print_vec<2, uint32_t>(v12i32[4], v22i32[4], "uvec2 findLSB 0");
        v13i32[4] = glm::findLSB(v13i32[1]);
        v23i32[4] = glm2::findLSB(v23i32[1]);
        print_vec<3, uint32_t>(v13i32[4], v23i32[4], "uvec3 findLSB 0");
        v14i32[4] = glm::findLSB(v14i32[1]);
        v24i32[4] = glm2::findLSB(v24i32[1]);
        print_vec<4, uint32_t>(v14i32[4], v24i32[4], "uvec4 findLSB 0");
    }

    // findMSB
    {
        i321[4] = glm::findMSB(i321[3]);
        i322[4] = glm2::findMSB(i322[3]);
        print_single<int32_t>(i321[4], i322[4], "int32_t findMSB");
        v12i32[4] = glm::findMSB(v12i32[3]);
        v22i32[4] = glm2::findMSB(v22i32[3]);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 findMSB");
        v13i32[4] = glm::findMSB(v13i32[3]);
        v23i32[4] = glm2::findMSB(v23i32[3]);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 findMSB");
        v14i32[4] = glm::findMSB(v14i32[3]);
        v24i32[4] = glm2::findMSB(v24i32[3]);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 findMSB");

        i321[4] = glm::findMSB(i321[3]);
        i322[4] = glm2::findMSB(i322[3]);
        print_single<uint32_t>(i321[4], i322[4], "uint32_t findMSB");
        v12i32[4] = glm::findMSB(v12i32[3]);
        v22i32[4] = glm2::findMSB(v22i32[3]);
        print_vec<2, uint32_t>(v12i32[4], v22i32[4], "uvec2 findMSB");
        v13i32[4] = glm::findMSB(v13i32[3]);
        v23i32[4] = glm2::findMSB(v23i32[3]);
        print_vec<3, uint32_t>(v13i32[4], v23i32[4], "uvec3 findMSB");
        v14i32[4] = glm::findMSB(v14i32[3]);
        v24i32[4] = glm2::findMSB(v24i32[3]);
        print_vec<4, uint32_t>(v14i32[4], v24i32[4], "uvec4 findMSB");

        i321[4] = glm::findMSB(i321[2]);
        i322[4] = glm2::findMSB(i322[2]);
        print_single<int32_t>(i321[4], i322[4], "int32_t findMSB 0");
        v12i32[4] = glm::findMSB(v12i32[1]);
        v22i32[4] = glm2::findMSB(v22i32[1]);
        print_vec<2, int32_t>(v12i32[4], v22i32[4], "ivec2 findMSB 0");
        v13i32[4] = glm::findMSB(v13i32[1]);
        v23i32[4] = glm2::findMSB(v23i32[1]);
        print_vec<3, int32_t>(v13i32[4], v23i32[4], "ivec3 findMSB 0");
        v14i32[4] = glm::findMSB(v14i32[1]);
        v24i32[4] = glm2::findMSB(v24i32[1]);
        print_vec<4, int32_t>(v14i32[4], v24i32[4], "ivec4 findMSB 0");

        i321[4] = glm::findMSB(i321[2]);
        i322[4] = glm2::findMSB(i322[2]);
        print_single<uint32_t>(i321[4], i322[4], "uint32_t findMSB 0");
        v12i32[4] = glm::findMSB(v12i32[1]);
        v22i32[4] = glm2::findMSB(v22i32[1]);
        print_vec<2, uint32_t>(v12i32[4], v22i32[4], "uvec2 findMSB 0");
        v13i32[4] = glm::findMSB(v13i32[1]);
        v23i32[4] = glm2::findMSB(v23i32[1]);
        print_vec<3, uint32_t>(v13i32[4], v23i32[4], "uvec3 findMSB 0");
        v14i32[4] = glm::findMSB(v14i32[1]);
        v24i32[4] = glm2::findMSB(v24i32[1]);
        print_vec<4, uint32_t>(v14i32[4], v24i32[4], "uvec4 findMSB 0");
    }

    // imulExtended
    {
        glm::ivec4 tmp1, tmp2;
        ivec4 tmp3, tmp4;
        glm::imulExtended(v14i32[3], v14i32[2], tmp1, tmp2);
        glm2::imulExtended(v24i32[3], v24i32[2], tmp3, tmp4);
        print_vec<4, int32_t>(tmp2, tmp4, "ivec4 imulExtended lsb");
        print_vec<4, int32_t>(tmp1, tmp3, "ivec4 imulExtended msb");
    }

    // umulExtended
    {
        glm::uvec4 tmp1, tmp2;
        uvec4 tmp3, tmp4;
        glm::umulExtended(v14u32[3], v14u32[2], tmp1, tmp2);
        glm2::umulExtended(v24u32[3], v24u32[2], tmp3, tmp4);
        print_vec<4, uint32_t>(tmp2, tmp4, "uvec4 umulExtended lsb");
        print_vec<4, uint32_t>(tmp1, tmp3, "uvec4 umulExtended msb");
    }

    // uaddCarry
    {
        glm::uvec4 carry1;
        uvec4 carry2;
        v14u32[4] = glm::uaddCarry(v14u32[0], v14u32[2], carry1);
        v24u32[4] = glm2::uaddCarry(v24u32[0], v24u32[2], carry2);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 uaddCarry result");
        print_vec<4, uint32_t>(carry1, carry2, "uvec4 uaddCarry carry");
    }

    // uaddCarry
    {
        glm::uvec4 borrow1;
        uvec4 borrow2;
        v14u32[4] = glm::usubBorrow(v14u32[0], v14u32[3], borrow1);
        v24u32[4] = glm2::usubBorrow(v24u32[0], v24u32[3], borrow2);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 usubBorrow result");
        print_vec<4, uint32_t>(borrow1, borrow2, "uvec4 usubBorrow borrow");
        v14u32[4] = glm::usubBorrow(v14u32[3], v14u32[0], borrow1);
        v24u32[4] = glm2::usubBorrow(v24u32[3], v24u32[0], borrow2);
        print_vec<4, uint32_t>(v14u32[4], v24u32[4], "uvec4 usubBorrow result reverse");
        print_vec<4, uint32_t>(borrow1, borrow2, "uvec4 usubBorrow carry borrow");
    }

#endif

#ifdef GLM2_TEST_PACKING

    // packDouble2x32
    {
        d1[4] = glm::packDouble2x32(v12u32[0]);
        d2[4] = glm2::packDouble2x32(v22u32[0]);
        print_single<double>(d1[4], d2[4], "packDouble2x32");   
    }

    // packHalf2x16
    {
        u321[4] = glm::packDouble2x32(v12f[0]);
        u322[4] = glm2::packDouble2x32(v22f[0]);
        print_single<uint32_t>(u321[4], u322[4], "packHalf2x16");   
    }

    // packSnorm2x16
    {
        u321[4] = glm::packSnorm2x16(v12f[0]);
        u322[4] = glm2::packSnorm2x16(v22f[0]);
        print_single<uint32_t>(u321[4], u322[4], "packSnorm2x16");   
    }

    // packSnorm4x8
    {
        u321[4] = glm::packSnorm4x8(v14f[0]);
        u322[4] = glm2::packSnorm4x8(v24f[0]);
        print_single<uint32_t>(u321[4], u322[4], "packSnorm4x8");   
    }

    // packUnorm2x16
    {
        u321[4] = glm::packUnorm2x16(v12f[0]);
        u322[4] = glm2::packUnorm2x16(v22f[0]);
        print_single<uint32_t>(u321[4], u322[4], "packUnorm2x16");   
    }

    // packUnorm4x8
    {
        u321[4] = glm::packUnorm4x8(v14f[0]);
        u322[4] = glm2::packUnorm4x8(v24f[0]);
        print_single<uint32_t>(u321[4], u322[4], "packUnorm4x8");   
    }

    // unpackDouble2x32
    {
        v12u32[4] = glm::unpackDouble2x32(d1[0]);
        v22u32[4] = glm2::unpackDouble2x32(d2[0]);
        print_vec<2, uint32_t>(v12u32[4], v22u32[4], "unpackDouble2x32");
    }

    // unpackHalf2x16
    {
        v12f[4] = glm::unpackHalf2x16(u321[3]);
        v22f[4] = glm2::unpackHalf2x16(u322[3]);
        print_vec<2, float>(v12f[4], v22f[4], "unpackHalf2x16");
    }

    // unpackSnorm2x16
    {
        v12f[4] = glm::unpackSnorm2x16(u321[3]);
        v22f[4] = glm2::unpackSnorm2x16(u322[3]);
        print_vec<2, float>(v12f[4], v22f[4], "unpackSnorm2x16");
    }

    // unpackSnorm4x8
    {
        v14f[4] = glm::unpackSnorm4x8(u321[3]);
        v24f[4] = glm2::unpackSnorm4x8(u322[3]);
        print_vec<4, float>(v14f[4], v24f[4], "unpackSnorm4x8");
    }

    // unpackUnorm2x16
    {
        v12f[4] = glm::unpackUnorm2x16(u321[3]);
        v22f[4] = glm2::unpackUnorm2x16(u322[3]);
        print_vec<2, float>(v12f[4], v22f[4], "unpackUnorm2x16");
    }

    // unpackUnorm4x8
    {
        v14f[4] = glm::unpackUnorm4x8(u321[3]);
        v24f[4] = glm2::unpackUnorm4x8(u322[3]);
        print_vec<4, float>(v14f[4], v24f[4], "unpackUnorm4x8");
    }

#endif

#ifdef GLM2_TEST_VECTOR_RELATIONAL

    // all
    {
        b1[2] = glm::all(v14b[0]);
        b2[2] = glm2::all(v24b[0]);
        print_single<bool>(b1[2], b2[2], "bvec4 all, different");
        b1[2] = glm::all(v14b[1]);
        b2[2] = glm2::all(v24b[1]);
        print_single<bool>(b1[2], b2[2], "bvec4 all, only true");
        b1[2] = glm::all(v14b[2]);
        b2[2] = glm2::all(v24b[2]);
        print_single<bool>(b1[2], b2[2], "bvec4 all, only false");
    }

    // all
    {
        b1[2] = glm::any(v14b[0]);
        b2[2] = glm2::any(v24b[0]);
        print_single<bool>(b1[2], b2[2], "bvec4 any, different");
        b1[2] = glm::any(v14b[1]);
        b2[2] = glm2::any(v24b[1]);
        print_single<bool>(b1[2], b2[2], "bvec4 any, only true");
        b1[2] = glm::any(v14b[2]);
        b2[2] = glm2::any(v24b[2]);
        print_single<bool>(b1[2], b2[2], "bvec4 any, only false");
    }

    // equal
    {
        v12b[4] = glm::equal(v12f[0], v12f[1]);
        v22b[4] = glm2::equal(v22f[0], v22f[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 equal, different");
        v12b[4] = glm::equal(v12f[0], v12f[0]);
        v22b[4] = glm2::equal(v22f[0], v22f[0]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 equal, equal");
        v13b[4] = glm::equal(v13f[0], v13f[1]);
        v23b[4] = glm2::equal(v23f[0], v23f[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 equal, different");
        v13b[4] = glm::equal(v13f[0], v13f[0]);
        v23b[4] = glm2::equal(v23f[0], v23f[0]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 equal, equal");
        v14b[4] = glm::equal(v14f[0], v14f[1]);
        v24b[4] = glm2::equal(v24f[0], v24f[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec4 equal, different");
        v14b[4] = glm::equal(v14f[0], v14f[0]);
        v24b[4] = glm2::equal(v24f[0], v24f[0]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec4 equal, equal");

        v12b[4] = glm::equal(v12d[0], v12d[1]);
        v22b[4] = glm2::equal(v22d[0], v22d[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 equal, different");
        v12b[4] = glm::equal(v12d[0], v12d[0]);
        v22b[4] = glm2::equal(v22d[0], v22d[0]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 equal, equal");
        v13b[4] = glm::equal(v13d[0], v13d[1]);
        v23b[4] = glm2::equal(v23d[0], v23d[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 equal, different");
        v13b[4] = glm::equal(v13d[0], v13d[0]);
        v23b[4] = glm2::equal(v23d[0], v23d[0]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 equal, equal");
        v14b[4] = glm::equal(v14d[0], v14d[1]);
        v24b[4] = glm2::equal(v24d[0], v24d[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec4 equal, different");
        v14b[4] = glm::equal(v14d[0], v14d[0]);
        v24b[4] = glm2::equal(v24d[0], v24d[0]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec4 equal, equal");

        v12b[4] = glm::equal(v12i32[0], v12i32[1]);
        v22b[4] = glm2::equal(v22i32[0], v22i32[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 equal, different");
        v12b[4] = glm::equal(v12i32[0], v12i32[0]);
        v22b[4] = glm2::equal(v22i32[0], v22i32[0]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 equal, equal");
        v13b[4] = glm::equal(v13i32[0], v13i32[1]);
        v23b[4] = glm2::equal(v23i32[0], v23i32[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 equal, different");
        v13b[4] = glm::equal(v13i32[0], v13i32[0]);
        v23b[4] = glm2::equal(v23i32[0], v23i32[0]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 equal, equal");
        v14b[4] = glm::equal(v14i32[0], v14i32[1]);
        v24b[4] = glm2::equal(v24i32[0], v24i32[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec4 equal, different");
        v14b[4] = glm::equal(v14i32[0], v14i32[0]);
        v24b[4] = glm2::equal(v24i32[0], v24i32[0]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec4 equal, equal");

        v12b[4] = glm::equal(v12u32[0], v12u32[1]);
        v22b[4] = glm2::equal(v22u32[0], v22u32[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 equal, different");
        v12b[4] = glm::equal(v12u32[0], v12u32[0]);
        v22b[4] = glm2::equal(v22u32[0], v22u32[0]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 equal, equal");
        v13b[4] = glm::equal(v13u32[0], v13u32[1]);
        v23b[4] = glm2::equal(v23u32[0], v23u32[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 equal, different");
        v13b[4] = glm::equal(v13u32[0], v13u32[0]);
        v23b[4] = glm2::equal(v23u32[0], v23u32[0]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 equal, equal");
        v14b[4] = glm::equal(v14u32[0], v14u32[1]);
        v24b[4] = glm2::equal(v24u32[0], v24u32[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec4 equal, different");
        v14b[4] = glm::equal(v14u32[0], v14u32[0]);
        v24b[4] = glm2::equal(v24u32[0], v24u32[0]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec4 equal, equal");
    }

    // notEqual
    {
        v12b[4] = glm::notEqual(v12f[0], v12f[1]);
        v22b[4] = glm2::notEqual(v22f[0], v22f[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 notEqual, different");
        v12b[4] = glm::notEqual(v12f[0], v12f[0]);
        v22b[4] = glm2::notEqual(v22f[0], v22f[0]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 notEqual, equal");
        v13b[4] = glm::notEqual(v13f[0], v13f[1]);
        v23b[4] = glm2::notEqual(v23f[0], v23f[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 notEqual, different");
        v13b[4] = glm::notEqual(v13f[0], v13f[0]);
        v23b[4] = glm2::notEqual(v23f[0], v23f[0]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 notEqual, equal");
        v14b[4] = glm::notEqual(v14f[0], v14f[1]);
        v24b[4] = glm2::notEqual(v24f[0], v24f[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec4 notEqual, different");
        v14b[4] = glm::notEqual(v14f[0], v14f[0]);
        v24b[4] = glm2::notEqual(v24f[0], v24f[0]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec4 notEqual, equal");

        v12b[4] = glm::notEqual(v12d[0], v12d[1]);
        v22b[4] = glm2::notEqual(v22d[0], v22d[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 notEqual, different");
        v12b[4] = glm::notEqual(v12d[0], v12d[0]);
        v22b[4] = glm2::notEqual(v22d[0], v22d[0]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 notEqual, equal");
        v13b[4] = glm::notEqual(v13d[0], v13d[1]);
        v23b[4] = glm2::notEqual(v23d[0], v23d[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 notEqual, different");
        v13b[4] = glm::notEqual(v13d[0], v13d[0]);
        v23b[4] = glm2::notEqual(v23d[0], v23d[0]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 notEqual, equal");
        v14b[4] = glm::notEqual(v14d[0], v14d[1]);
        v24b[4] = glm2::notEqual(v24d[0], v24d[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec4 notEqual, different");
        v14b[4] = glm::notEqual(v14d[0], v14d[0]);
        v24b[4] = glm2::notEqual(v24d[0], v24d[0]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec4 notEqual, equal");

        v12b[4] = glm::notEqual(v12i32[0], v12i32[1]);
        v22b[4] = glm2::notEqual(v22i32[0], v22i32[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 notEqual, different");
        v12b[4] = glm::notEqual(v12i32[0], v12i32[0]);
        v22b[4] = glm2::notEqual(v22i32[0], v22i32[0]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 notEqual, equal");
        v13b[4] = glm::notEqual(v13i32[0], v13i32[1]);
        v23b[4] = glm2::notEqual(v23i32[0], v23i32[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 notEqual, different");
        v13b[4] = glm::notEqual(v13i32[0], v13i32[0]);
        v23b[4] = glm2::notEqual(v23i32[0], v23i32[0]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 notEqual, equal");
        v14b[4] = glm::notEqual(v14i32[0], v14i32[1]);
        v24b[4] = glm2::notEqual(v24i32[0], v24i32[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec4 notEqual, different");
        v14b[4] = glm::notEqual(v14i32[0], v14i32[0]);
        v24b[4] = glm2::notEqual(v24i32[0], v24i32[0]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec4 notEqual, equal");

        v12b[4] = glm::notEqual(v12u32[0], v12u32[1]);
        v22b[4] = glm2::notEqual(v22u32[0], v22u32[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 notEqual, different");
        v12b[4] = glm::notEqual(v12u32[0], v12u32[0]);
        v22b[4] = glm2::notEqual(v22u32[0], v22u32[0]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 notEqual, equal");
        v13b[4] = glm::notEqual(v13u32[0], v13u32[1]);
        v23b[4] = glm2::notEqual(v23u32[0], v23u32[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 notEqual, different");
        v13b[4] = glm::notEqual(v13u32[0], v13u32[0]);
        v23b[4] = glm2::notEqual(v23u32[0], v23u32[0]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 notEqual, equal");
        v14b[4] = glm::notEqual(v14u32[0], v14u32[1]);
        v24b[4] = glm2::notEqual(v24u32[0], v24u32[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec4 notEqual, different");
        v14b[4] = glm::notEqual(v14u32[0], v14u32[0]);
        v24b[4] = glm2::notEqual(v24u32[0], v24u32[0]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec4 notEqual, equal");
    }
    
    // greaterThan
    {
        v12b[4] = glm::greaterThan(v12f[1], v12f[3]);
        v22b[4] = glm2::greaterThan(v22f[1], v22f[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 greaterThan");
        v13b[4] = glm::greaterThan(v13f[1], v13f[3]);
        v23b[4] = glm2::greaterThan(v23f[1], v23f[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 greaterThan");
        v14b[4] = glm::greaterThan(v14f[1], v14f[3]);
        v24b[4] = glm2::greaterThan(v24f[1], v24f[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec2 greaterThan");

        v12b[4] = glm::greaterThan(v12d[1], v12d[3]);
        v22b[4] = glm2::greaterThan(v22d[1], v22d[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 greaterThan");
        v13b[4] = glm::greaterThan(v13d[1], v13d[3]);
        v23b[4] = glm2::greaterThan(v23d[1], v23d[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 greaterThan");
        v14b[4] = glm::greaterThan(v14d[1], v14d[3]);
        v24b[4] = glm2::greaterThan(v24d[1], v24d[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec2 greaterThan");

        v12b[4] = glm::greaterThan(v12i32[2], v12i32[3]);
        v22b[4] = glm2::greaterThan(v22i32[2], v22i32[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 greaterThan");
        v13b[4] = glm::greaterThan(v13i32[2], v13i32[3]);
        v23b[4] = glm2::greaterThan(v23i32[2], v23i32[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 greaterThan");
        v14b[4] = glm::greaterThan(v14i32[2], v14i32[3]);
        v24b[4] = glm2::greaterThan(v24i32[2], v24i32[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec2 greaterThan");

        v12b[4] = glm::greaterThan(v12u32[0], v12u32[2]);
        v22b[4] = glm2::greaterThan(v22u32[0], v22u32[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 greaterThan");
        v13b[4] = glm::greaterThan(v13u32[0], v13u32[2]);
        v23b[4] = glm2::greaterThan(v23u32[0], v23u32[2]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 greaterThan");
        v14b[4] = glm::greaterThan(v14u32[0], v14u32[2]);
        v24b[4] = glm2::greaterThan(v24u32[0], v24u32[2]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec2 greaterThan");
    }

    // lessThan
    {
        v12b[4] = glm::lessThan(v12f[1], v12f[3]);
        v22b[4] = glm2::lessThan(v22f[1], v22f[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 lessThan");
        v13b[4] = glm::lessThan(v13f[1], v13f[3]);
        v23b[4] = glm2::lessThan(v23f[1], v23f[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 lessThan");
        v14b[4] = glm::lessThan(v14f[1], v14f[3]);
        v24b[4] = glm2::lessThan(v24f[1], v24f[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec2 lessThan");

        v12b[4] = glm::lessThan(v12d[1], v12d[3]);
        v22b[4] = glm2::lessThan(v22d[1], v22d[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 lessThan");
        v13b[4] = glm::lessThan(v13d[1], v13d[3]);
        v23b[4] = glm2::lessThan(v23d[1], v23d[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 lessThan");
        v14b[4] = glm::lessThan(v14d[1], v14d[3]);
        v24b[4] = glm2::lessThan(v24d[1], v24d[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec2 lessThan");

        v12b[4] = glm::lessThan(v12i32[2], v12i32[3]);
        v22b[4] = glm2::lessThan(v22i32[2], v22i32[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 lessThan");
        v13b[4] = glm::lessThan(v13i32[2], v13i32[3]);
        v23b[4] = glm2::lessThan(v23i32[2], v23i32[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 lessThan");
        v14b[4] = glm::lessThan(v14i32[2], v14i32[3]);
        v24b[4] = glm2::lessThan(v24i32[2], v24i32[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec2 lessThan");

        v12b[4] = glm::lessThan(v12u32[2], v12u32[3]);
        v22b[4] = glm2::lessThan(v22u32[2], v22u32[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 lessThan");
        v13b[4] = glm::lessThan(v13u32[2], v13u32[3]);
        v23b[4] = glm2::lessThan(v23u32[2], v23u32[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 lessThan");
        v14b[4] = glm::lessThan(v14u32[2], v14u32[3]);
        v24b[4] = glm2::lessThan(v24u32[2], v24u32[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec2 lessThan");
    }

    // greaterThanEqual
    {
        v12b[4] = glm::greaterThanEqual(v12f[1], v12f[3]);
        v22b[4] = glm2::greaterThanEqual(v22f[1], v22f[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 greaterThanEqual, different");
        v12b[4] = glm::greaterThanEqual(v12f[1], v12f[1]);
        v22b[4] = glm2::greaterThanEqual(v22f[1], v22f[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 greaterThanEqual, equal");
        v13b[4] = glm::greaterThanEqual(v13f[1], v13f[3]);
        v23b[4] = glm2::greaterThanEqual(v23f[1], v23f[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 greaterThanEqual, different");
        v13b[4] = glm::greaterThanEqual(v13f[1], v13f[1]);
        v23b[4] = glm2::greaterThanEqual(v23f[1], v23f[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 greaterThanEqual, equal");
        v14b[4] = glm::greaterThanEqual(v14f[1], v14f[3]);
        v24b[4] = glm2::greaterThanEqual(v24f[1], v24f[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec4 greaterThanEqual, different");
        v14b[4] = glm::greaterThanEqual(v14f[1], v14f[1]);
        v24b[4] = glm2::greaterThanEqual(v24f[1], v24f[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec4 greaterThanEqual, equal");

        v12b[4] = glm::greaterThanEqual(v12d[1], v12d[3]);
        v22b[4] = glm2::greaterThanEqual(v22d[1], v22d[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 greaterThanEqual, different");
        v12b[4] = glm::greaterThanEqual(v12d[1], v12d[1]);
        v22b[4] = glm2::greaterThanEqual(v22d[1], v22d[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 greaterThanEqual, equal");
        v13b[4] = glm::greaterThanEqual(v13d[1], v13d[3]);
        v23b[4] = glm2::greaterThanEqual(v23d[1], v23d[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 greaterThanEqual, different");
        v13b[4] = glm::greaterThanEqual(v13d[1], v13d[1]);
        v23b[4] = glm2::greaterThanEqual(v23d[1], v23d[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 greaterThanEqual, equal");
        v14b[4] = glm::greaterThanEqual(v14d[1], v14d[3]);
        v24b[4] = glm2::greaterThanEqual(v24d[1], v24d[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec4 greaterThanEqual, different");
        v14b[4] = glm::greaterThanEqual(v14d[1], v14d[1]);
        v24b[4] = glm2::greaterThanEqual(v24d[1], v24d[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec4 greaterThanEqual, equal");

        v12b[4] = glm::greaterThanEqual(v12i32[2], v12i32[3]);
        v22b[4] = glm2::greaterThanEqual(v22i32[2], v22i32[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 greaterThanEqual, different");
        v12b[4] = glm::greaterThanEqual(v12i32[2], v12i32[2]);
        v22b[4] = glm2::greaterThanEqual(v22i32[2], v22i32[2]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 greaterThanEqual, equal");
        v13b[4] = glm::greaterThanEqual(v13i32[2], v13i32[3]);
        v23b[4] = glm2::greaterThanEqual(v23i32[2], v23i32[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 greaterThanEqual, different");
        v13b[4] = glm::greaterThanEqual(v13i32[2], v13i32[2]);
        v23b[4] = glm2::greaterThanEqual(v23i32[2], v23i32[2]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 greaterThanEqual, equal");
        v14b[4] = glm::greaterThanEqual(v14i32[2], v14i32[3]);
        v24b[4] = glm2::greaterThanEqual(v24i32[2], v24i32[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec4 greaterThanEqual, different");
        v14b[4] = glm::greaterThanEqual(v14i32[2], v14i32[2]);
        v24b[4] = glm2::greaterThanEqual(v24i32[2], v24i32[2]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec4 greaterThanEqual, equal");

        v12b[4] = glm::greaterThanEqual(v12u32[2], v12u32[3]);
        v22b[4] = glm2::greaterThanEqual(v22u32[2], v22u32[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 greaterThanEqual, different");
        v12b[4] = glm::greaterThanEqual(v12u32[2], v12u32[2]);
        v22b[4] = glm2::greaterThanEqual(v22u32[2], v22u32[2]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 greaterThanEqual, equal");
        v13b[4] = glm::greaterThanEqual(v13u32[2], v13u32[3]);
        v23b[4] = glm2::greaterThanEqual(v23u32[2], v23u32[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 greaterThanEqual, different");
        v13b[4] = glm::greaterThanEqual(v13u32[2], v13u32[2]);
        v23b[4] = glm2::greaterThanEqual(v23u32[2], v23u32[2]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 greaterThanEqual, equal");
        v14b[4] = glm::greaterThanEqual(v14u32[2], v14u32[3]);
        v24b[4] = glm2::greaterThanEqual(v24u32[2], v24u32[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec4 greaterThanEqual, different");
        v14b[4] = glm::greaterThanEqual(v14u32[2], v14u32[2]);
        v24b[4] = glm2::greaterThanEqual(v24u32[2], v24u32[2]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec4 greaterThanEqual, equal");
    }

    // lessThanEqual
    {
        v12b[4] = glm::lessThanEqual(v12f[1], v12f[3]);
        v22b[4] = glm2::lessThanEqual(v22f[1], v22f[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 lessThanEqual, different");
        v12b[4] = glm::lessThanEqual(v12f[1], v12f[1]);
        v22b[4] = glm2::lessThanEqual(v22f[1], v22f[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "vec2 lessThanEqual, equal");
        v13b[4] = glm::lessThanEqual(v13f[1], v13f[3]);
        v23b[4] = glm2::lessThanEqual(v23f[1], v23f[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 lessThanEqual, different");
        v13b[4] = glm::lessThanEqual(v13f[1], v13f[1]);
        v23b[4] = glm2::lessThanEqual(v23f[1], v23f[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "vec3 lessThanEqual, equal");
        v14b[4] = glm::lessThanEqual(v14f[1], v14f[3]);
        v24b[4] = glm2::lessThanEqual(v24f[1], v24f[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec4 lessThanEqual, different");
        v14b[4] = glm::lessThanEqual(v14f[1], v14f[1]);
        v24b[4] = glm2::lessThanEqual(v24f[1], v24f[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "vec4 lessThanEqual, equal");

        v12b[4] = glm::lessThanEqual(v12d[1], v12d[3]);
        v22b[4] = glm2::lessThanEqual(v22d[1], v22d[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 lessThanEqual, different");
        v12b[4] = glm::lessThanEqual(v12d[1], v12d[1]);
        v22b[4] = glm2::lessThanEqual(v22d[1], v22d[1]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "dvec2 lessThanEqual, equal");
        v13b[4] = glm::lessThanEqual(v13d[1], v13d[3]);
        v23b[4] = glm2::lessThanEqual(v23d[1], v23d[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 lessThanEqual, different");
        v13b[4] = glm::lessThanEqual(v13d[1], v13d[1]);
        v23b[4] = glm2::lessThanEqual(v23d[1], v23d[1]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "dvec3 lessThanEqual, equal");
        v14b[4] = glm::lessThanEqual(v14d[1], v14d[3]);
        v24b[4] = glm2::lessThanEqual(v24d[1], v24d[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec4 lessThanEqual, different");
        v14b[4] = glm::lessThanEqual(v14d[1], v14d[1]);
        v24b[4] = glm2::lessThanEqual(v24d[1], v24d[1]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "dvec4 lessThanEqual, equal");

        v12b[4] = glm::lessThanEqual(v12i32[2], v12i32[3]);
        v22b[4] = glm2::lessThanEqual(v22i32[2], v22i32[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 lessThanEqual, different");
        v12b[4] = glm::lessThanEqual(v12i32[2], v12i32[2]);
        v22b[4] = glm2::lessThanEqual(v22i32[2], v22i32[2]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "ivec2 lessThanEqual, equal");
        v13b[4] = glm::lessThanEqual(v13i32[2], v13i32[3]);
        v23b[4] = glm2::lessThanEqual(v23i32[2], v23i32[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 lessThanEqual, different");
        v13b[4] = glm::lessThanEqual(v13i32[2], v13i32[2]);
        v23b[4] = glm2::lessThanEqual(v23i32[2], v23i32[2]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "ivec3 lessThanEqual, equal");
        v14b[4] = glm::lessThanEqual(v14i32[2], v14i32[3]);
        v24b[4] = glm2::lessThanEqual(v24i32[2], v24i32[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec4 lessThanEqual, different");
        v14b[4] = glm::lessThanEqual(v14i32[2], v14i32[2]);
        v24b[4] = glm2::lessThanEqual(v24i32[2], v24i32[2]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "ivec4 lessThanEqual, equal");

        v12b[4] = glm::lessThanEqual(v12u32[2], v12u32[3]);
        v22b[4] = glm2::lessThanEqual(v22u32[2], v22u32[3]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 lessThanEqual, different");
        v12b[4] = glm::lessThanEqual(v12u32[2], v12u32[2]);
        v22b[4] = glm2::lessThanEqual(v22u32[2], v22u32[2]);
        print_vec<2, uint32_t>((glm::uvec2(v12b[4]) * GLM2_TRUE), v22b[4], "uvec2 lessThanEqual, equal");
        v13b[4] = glm::lessThanEqual(v13u32[2], v13u32[3]);
        v23b[4] = glm2::lessThanEqual(v23u32[2], v23u32[3]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 lessThanEqual, different");
        v13b[4] = glm::lessThanEqual(v13u32[2], v13u32[2]);
        v23b[4] = glm2::lessThanEqual(v23u32[2], v23u32[2]);
        print_vec<3, uint32_t>((glm::uvec3(v13b[4]) * GLM2_TRUE), v23b[4], "uvec3 lessThanEqual, equal");
        v14b[4] = glm::lessThanEqual(v14u32[2], v14u32[3]);
        v24b[4] = glm2::lessThanEqual(v24u32[2], v24u32[3]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec4 lessThanEqual, different");
        v14b[4] = glm::lessThanEqual(v14u32[2], v14u32[2]);
        v24b[4] = glm2::lessThanEqual(v24u32[2], v24u32[2]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[4]) * GLM2_TRUE), v24b[4], "uvec4 lessThanEqual, equal");
    }

    // not
    {
        v14b[2] = glm::not_(v14b[0]);
        v24b[2] = glm2::not_(v24b[0]);
        print_vec<4, uint32_t>((glm::uvec4(v14b[2]) * GLM2_TRUE), v24b[2], "bvec4 not_");
    }

#endif

#ifdef GLM2_TEST_MATRIX_TRANSFORMATION
#endif

    std::cout << ATTRIBUTE_UNDERLINE COLOR_GREEN << "TRUE: " << count_true << COLOR_RESET "   " << ATTRIBUTE_UNDERLINE COLOR_RED << "FALSE: " << count_false << COLOR_RESET << std::endl;
}
