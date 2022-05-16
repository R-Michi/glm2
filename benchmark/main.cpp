/**
* @file     benchmark/main.cpp
* @brief    All library functions are benchmarked here against the glm functions.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <benchmark/benchmark.h>
#include <sstream>
#include <fstream>
#include <unordered_map>
#include <glm/glm.hpp>
#define GLM2_FORCE_EXPLICIT_CAST
#include "../glm2/glm2.h"

//#define GLM2_BENCHMARK_CUSTOM
//#define GLM2_BENCHMARK_DOUBLE

//#define GLM2_BENCHMARK_VECTOR_ARITHMETIC_OPERATORS
//#define GLM2_BENCHMARK_VECTOR_ARITHMETIC_OPERATORS_INTEGER
//#define GLM2_BENCHMARK_VECTOR_CMP_OPERATORS
//#define GLM2_BENCHMARK_VECTOR_CMP_OPERATORS_INTEGER
//#define GLM2_BENCHMARK_MATRIX_ARITHMETIC_OPERATORS
//#define GLM2_BENCHMARK_MATRIX_CMP_OPERATORS
//#define GLM2_BENCHMARK_MATRIX_EXT_ARITHMETIC
//#define GLM2_BENCHMARK_COMMON
#define GLM2_BENCHMARK_COMMON_INTEGER               
//#define GLM2_BENCHMARK_EXPONENTIAL
//#define GLM2_BENCHMARK_GEOMETRIC
//#define GLM2_BENCHMARK_MATRIX
#define GLM2_BENCHMARK_INTEGER
#define GLM2_BENCHMARK_PACKING
#define GLM2_BENCHMARK_VECTOR_RELATIONAL
#define GLM2_BENCHMARK_VECTOR_RELATIONAL_INTEGER

#ifdef GLM2_BENCHMARK_DOUBLE
    #define GLM2_VALUE_ZERO 0.0
    #define GLM2_VALUE_ONE  1.0
#else
    #define GLM2_VALUE_ZERO 0.0f
    #define GLM2_VALUE_ONE  1.0f
#endif

bool b;
#ifndef GLM2_BENCHMARK_DOUBLE
float f1, f2, f3, f4, f5;
glm::vec2 v121, v122, v123, v124, v125;
glm::vec3 v131, v132, v133, v134, v135;
glm::vec4 v141, v142, v143, v144, v145;
glm2::vec2 v221, v222, v223, v224, v225;
glm2::vec3 v231, v232, v233, v234, v235;
glm2::vec4 v241, v242, v243, v244, v245;

glm::mat2x2 m1221, m1222, m1223, m1224, m1225;
glm::mat2x3 m1231, m1232, m1233, m1234, m1235;
glm::mat2x4 m1241, m1242, m1243, m1244, m1245;
glm::mat3x2 m1321, m1322, m1323, m1324, m1325;
glm::mat3x3 m1331, m1332, m1333, m1334, m1335;
glm::mat3x4 m1341, m1342, m1343, m1344, m1345;
glm::mat4x2 m1421, m1422, m1423, m1424, m1425;
glm::mat4x3 m1431, m1432, m1433, m1434, m1435;
glm::mat4x4 m1441, m1442, m1443, m1444, m1445;
glm2::mat2x2 m2221, m2222, m2223, m2224, m2225;
glm2::mat2x3 m2231, m2232, m2233, m2234, m2235;
glm2::mat2x4 m2241, m2242, m2243, m2244, m2245;
glm2::mat3x2 m2321, m2322, m2323, m2324, m2325;
glm2::mat3x3 m2331, m2332, m2333, m2334, m2335;
glm2::mat3x4 m2341, m2342, m2343, m2344, m2345;
glm2::mat4x2 m2421, m2422, m2423, m2424, m2425;
glm2::mat4x3 m2431, m2432, m2433, m2434, m2435;
glm2::mat4x4 m2441, m2442, m2443, m2444, m2445;
#else
double f1, f2, f3, f4, f5;
glm::dvec2 v121, v122, v123, v124, v125;
glm::dvec3 v131, v132, v133, v134, v135;
glm::dvec4 v141, v142, v143, v144, v145;
glm2::dvec2 v221, v222, v223, v224, v225;
glm2::dvec3 v231, v232, v233, v234, v235;
glm2::dvec4 v241, v242, v243, v244, v245;

glm::dmat2x2 m1221, m1222, m1223, m1224, m1225;
glm::dmat2x3 m1231, m1232, m1233, m1234, m1235;
glm::dmat2x4 m1241, m1242, m1243, m1244, m1245;
glm::dmat3x2 m1321, m1322, m1323, m1324, m1325;
glm::dmat3x3 m1331, m1332, m1333, m1334, m1335;
glm::dmat3x4 m1341, m1342, m1343, m1344, m1345;
glm::dmat4x2 m1421, m1422, m1423, m1424, m1425;
glm::dmat4x3 m1431, m1432, m1433, m1434, m1435;
glm::dmat4x4 m1441, m1442, m1443, m1444, m1445;
glm2::dmat2x2 m2221, m2222, m2223, m2224, m2225;
glm2::dmat2x3 m2231, m2232, m2233, m2234, m2235;
glm2::dmat2x4 m2241, m2242, m2243, m2244, m2245;
glm2::dmat3x2 m2321, m2322, m2323, m2324, m2325;
glm2::dmat3x3 m2331, m2332, m2333, m2334, m2335;
glm2::dmat3x4 m2341, m2342, m2343, m2344, m2345;
glm2::dmat4x2 m2421, m2422, m2423, m2424, m2425;
glm2::dmat4x3 m2431, m2432, m2433, m2434, m2435;
glm2::dmat4x4 m2441, m2442, m2443, m2444, m2445;
#endif

int32_t i1, i2, i3, i4, i5;
uint32_t u1, u2, u3, u4, u5;

glm::ivec2 v121i, v122i, v123i, v124i, v125i;
glm::ivec3 v131i, v132i, v133i, v134i, v135i;
glm::ivec4 v141i, v142i, v143i, v144i, v145i;
glm2::ivec2 v221i, v222i, v223i, v224i, v225i;
glm2::ivec3 v231i, v232i, v233i, v234i, v235i;
glm2::ivec4 v241i, v242i, v243i, v244i, v245i;

glm::uvec2 v121u, v122u, v123u, v124u, v125u;
glm::uvec3 v131u, v132u, v133u, v134u, v135u;
glm::uvec4 v141u, v142u, v143u, v144u, v145u;
glm2::uvec2 v221u, v222u, v223u, v224u, v225u;
glm2::uvec3 v231u, v232u, v233u, v234u, v235u;
glm2::uvec4 v241u, v242u, v243u, v244u, v245u;

#ifndef GLM2_BENCHMARK_CUSTOM

#ifdef GLM2_BENCHMARK_VECTOR_ARITHMETIC_OPERATORS
// vector add benchmark
static void glm__vec2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = v122 + v123;
}
static void glm__vec3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = v132 + v133;
}
static void glm__vec4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = v142 + v143;
}
static void glm2_vec2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = v222 + v223;
}
static void glm2_vec3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = v232 + v233;
}
static void glm2_vec4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = v242 + v243;
}
BENCHMARK(glm__vec2_add);
BENCHMARK(glm2_vec2_add);
BENCHMARK(glm__vec3_add);
BENCHMARK(glm2_vec3_add);
BENCHMARK(glm__vec4_add);
BENCHMARK(glm2_vec4_add);

// vector multiply benchmark
static void glm__vec2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = v122 - v123;
}
static void glm__vec3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = v132 - v133;
}
static void glm__vec4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = v142 - v143;
}
static void glm2_vec2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = v222 - v223;
}
static void glm2_vec3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = v232 - v233;
}
static void glm2_vec4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = v242 - v243;
}
BENCHMARK(glm__vec2_sub);
BENCHMARK(glm2_vec2_sub);
BENCHMARK(glm__vec3_sub);
BENCHMARK(glm2_vec3_sub);
BENCHMARK(glm__vec4_sub);
BENCHMARK(glm2_vec4_sub);

// vector multiply benchmark
static void glm__vec2_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = v122 * v123;
}
static void glm__vec3_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = v132 * v133;
}
static void glm__vec4_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = v142 * v143;
}
static void glm2_vec2_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = v222 * v223;
}
static void glm2_vec3_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = v232 * v233;
}
static void glm2_vec4_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = v242 * v243;
}
BENCHMARK(glm__vec2_mul);
BENCHMARK(glm2_vec2_mul);
BENCHMARK(glm__vec3_mul);
BENCHMARK(glm2_vec3_mul);
BENCHMARK(glm__vec4_mul);
BENCHMARK(glm2_vec4_mul);

// vector divide benchmark
static void glm__vec2_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = v122 / v123;
}
static void glm__vec3_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = v132 / v133;
}
static void glm__vec4_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = v142 / v143;
}
static void glm2_vec2_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = v222 / v223;
}
static void glm2_vec3_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = v232 / v233;
}
static void glm2_vec4_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = v242 / v243;
}
BENCHMARK(glm__vec2_div);
BENCHMARK(glm2_vec2_div);
BENCHMARK(glm__vec3_div);
BENCHMARK(glm2_vec3_div);
BENCHMARK(glm__vec4_div);
BENCHMARK(glm2_vec4_div);
#endif

#ifdef GLM2_BENCHMARK_VECTOR_CMP_OPERATORS
static void glm__vec2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v121 == v122;
}
static void glm__vec3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v131 == v132;
}
static void glm__vec4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v141 == v142;
}
static void glm2_vec2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v221 == v222;
}
static void glm2_vec3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v231 == v232;
}
static void glm2_vec4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v241 == v242;
}
BENCHMARK(glm__vec2_cmpeq);
BENCHMARK(glm2_vec2_cmpeq);
BENCHMARK(glm__vec3_cmpeq);
BENCHMARK(glm2_vec3_cmpeq);
BENCHMARK(glm__vec4_cmpeq);
BENCHMARK(glm2_vec4_cmpeq);

static void glm__vec2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v121 != v122;
}
static void glm__vec3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v131 != v132;
}
static void glm__vec4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v141 != v142;
}
static void glm2_vec2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v221 != v222;
}
static void glm2_vec3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v231 != v232;
}
static void glm2_vec4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v241 != v242;
}
BENCHMARK(glm__vec2_cmpneq);
BENCHMARK(glm2_vec2_cmpneq);
BENCHMARK(glm__vec3_cmpneq);
BENCHMARK(glm2_vec3_cmpneq);
BENCHMARK(glm__vec4_cmpneq);
BENCHMARK(glm2_vec4_cmpneq);
#endif

#ifdef GLM2_BENCHMARK_VECTOR_ARITHMETIC_OPERATORS_INTEGER
// vector add benchmark
static void glm__ivec2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i + v123i;
}
static void glm__ivec3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i + v133i;
}
static void glm__ivec4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i + v143i;
}
static void glm2_ivec2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i + v223i;
}
static void glm2_ivec3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i + v233i;
}
static void glm2_ivec4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i + v243i;
}
BENCHMARK(glm__ivec2_add);
BENCHMARK(glm2_ivec2_add);
BENCHMARK(glm__ivec3_add);
BENCHMARK(glm2_ivec3_add);
BENCHMARK(glm__ivec4_add);
BENCHMARK(glm2_ivec4_add);

// vector multiply benchmark
static void glm__ivec2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i - v123i;
}
static void glm__ivec3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i - v133i;
}
static void glm__ivec4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i - v143i;
}
static void glm2_ivec2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i - v223i;
}
static void glm2_ivec3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i - v233i;
}
static void glm2_ivec4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i - v243i;
}
BENCHMARK(glm__ivec2_sub);
BENCHMARK(glm2_ivec2_sub);
BENCHMARK(glm__ivec3_sub);
BENCHMARK(glm2_ivec3_sub);
BENCHMARK(glm__ivec4_sub);
BENCHMARK(glm2_ivec4_sub);

// vector multiply benchmark
static void glm__ivec2_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i * v123i;
}
static void glm__ivec3_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i * v133i;
}
static void glm__ivec4_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i * v143i;
}
static void glm2_ivec2_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i * v223i;
}
static void glm2_ivec3_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i * v233i;
}
static void glm2_ivec4_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i * v243i;
}
BENCHMARK(glm__ivec2_mul);
BENCHMARK(glm2_ivec2_mul);
BENCHMARK(glm__ivec3_mul);
BENCHMARK(glm2_ivec3_mul);
BENCHMARK(glm__ivec4_mul);
BENCHMARK(glm2_ivec4_mul);

// vector divide benchmark
static void glm__ivec2_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i / v123i;
}
static void glm__ivec3_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i / v133i;
}
static void glm__ivec4_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i / v143i;
}
static void glm2_ivec2_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i / v223i;
}
static void glm2_ivec3_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i / v233i;
}
static void glm2_ivec4_div(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i / v243i;
}
BENCHMARK(glm__ivec2_div);
BENCHMARK(glm2_ivec2_div);
BENCHMARK(glm__ivec3_div);
BENCHMARK(glm2_ivec3_div);
BENCHMARK(glm__ivec4_div);
BENCHMARK(glm2_ivec4_div);

// vector divide benchmark
static void glm__ivec2_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i % v123i;
}
static void glm__ivec3_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i % v133i;
}
static void glm__ivec4_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i % v143i;
}
static void glm2_ivec2_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i % v223i;
}
static void glm2_ivec3_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i % v233i;
}
static void glm2_ivec4_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i % v243i;
}
BENCHMARK(glm__ivec2_mod);
BENCHMARK(glm2_ivec2_mod);
BENCHMARK(glm__ivec3_mod);
BENCHMARK(glm2_ivec3_mod);
BENCHMARK(glm__ivec4_mod);
BENCHMARK(glm2_ivec4_mod);

// vector divide benchmark
static void glm__ivec2_and(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i & v123i;
}
static void glm__ivec3_and(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i & v133i;
}
static void glm__ivec4_and(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i & v143i;
}
static void glm2_ivec2_and(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i & v223i;
}
static void glm2_ivec3_and(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i & v233i;
}
static void glm2_ivec4_and(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i & v243i;
}
BENCHMARK(glm__ivec2_and);
BENCHMARK(glm2_ivec2_and);
BENCHMARK(glm__ivec3_and);
BENCHMARK(glm2_ivec3_and);
BENCHMARK(glm__ivec4_and);
BENCHMARK(glm2_ivec4_and);

// vector divide benchmark
static void glm__ivec2_or(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i | v123i;
}
static void glm__ivec3_or(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i | v133i;
}
static void glm__ivec4_or(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i | v143i;
}
static void glm2_ivec2_or(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i | v223i;
}
static void glm2_ivec3_or(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i | v233i;
}
static void glm2_ivec4_or(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i | v243i;
}
BENCHMARK(glm__ivec2_or);
BENCHMARK(glm2_ivec2_or);
BENCHMARK(glm__ivec3_or);
BENCHMARK(glm2_ivec3_or);
BENCHMARK(glm__ivec4_or);
BENCHMARK(glm2_ivec4_or);

// vector divide benchmark
static void glm__ivec2_xor(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i ^ v123i;
}
static void glm__ivec3_xor(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i ^ v133i;
}
static void glm__ivec4_xor(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i ^ v143i;
}
static void glm2_ivec2_xor(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i ^ v223i;
}
static void glm2_ivec3_xor(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i ^ v233i;
}
static void glm2_ivec4_xor(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i ^ v243i;
}
BENCHMARK(glm__ivec2_xor);
BENCHMARK(glm2_ivec2_xor);
BENCHMARK(glm__ivec3_xor);
BENCHMARK(glm2_ivec3_xor);
BENCHMARK(glm__ivec4_xor);
BENCHMARK(glm2_ivec4_xor);

static void glm__ivec2_sr(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i << v123i;
}
static void glm__ivec3_sr(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i << v133i;
}
static void glm__ivec4_sr(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i << v143i;
}
static void glm2_ivec2_sr(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i << v223i;
}
static void glm2_ivec3_sr(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i << v233i;
}
static void glm2_ivec4_sr(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i << v243i;
}
BENCHMARK(glm__ivec2_sr);
BENCHMARK(glm2_ivec2_sr);
BENCHMARK(glm__ivec3_sr);
BENCHMARK(glm2_ivec3_sr);
BENCHMARK(glm__ivec4_sr);
BENCHMARK(glm2_ivec4_sr);

static void glm__ivec2_sl(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i >> v123i;
}
static void glm__ivec3_sl(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i >> v133i;
}
static void glm__ivec4_sl(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i >> v143i;
}
static void glm2_ivec2_sl(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i >> v223i;
}
static void glm2_ivec3_sl(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i >> v233i;
}
static void glm2_ivec4_sl(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i >> v243i;
}
BENCHMARK(glm__ivec2_sl);
BENCHMARK(glm2_ivec2_sl);
BENCHMARK(glm__ivec3_sl);
BENCHMARK(glm2_ivec3_sl);
BENCHMARK(glm__ivec4_sl);
BENCHMARK(glm2_ivec4_sl);

static void glm__ivec2_srs(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i << i1;
}
static void glm__ivec3_srs(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i << i1;
}
static void glm__ivec4_srs(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i << i1;
}
static void glm2_ivec2_srs(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i << i1;
}
static void glm2_ivec3_srs(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i << i1;
}
static void glm2_ivec4_srs(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i << i1;
}
BENCHMARK(glm__ivec2_srs);
BENCHMARK(glm2_ivec2_srs);
BENCHMARK(glm__ivec3_srs);
BENCHMARK(glm2_ivec3_srs);
BENCHMARK(glm__ivec4_srs);
BENCHMARK(glm2_ivec4_srs);

static void glm__ivec2_sls(benchmark::State& state)
{
    while(state.KeepRunning())
        v121i = v122i >> i1;
}
static void glm__ivec3_sls(benchmark::State& state)
{
    while(state.KeepRunning())
        v131i = v132i >> i1;
}
static void glm__ivec4_sls(benchmark::State& state)
{
    while(state.KeepRunning())
        v141i = v142i >> i1;
}
static void glm2_ivec2_sls(benchmark::State& state)
{
    while(state.KeepRunning())
        v221i = v222i >> i1;
}
static void glm2_ivec3_sls(benchmark::State& state)
{
    while(state.KeepRunning())
        v231i = v232i >> i1;
}
static void glm2_ivec4_sls(benchmark::State& state)
{
    while(state.KeepRunning())
        v241i = v242i >> i1;
}
BENCHMARK(glm__ivec2_sls);
BENCHMARK(glm2_ivec2_sls);
BENCHMARK(glm__ivec3_sls);
BENCHMARK(glm2_ivec3_sls);
BENCHMARK(glm__ivec4_sls);
BENCHMARK(glm2_ivec4_sls);

#endif

#ifdef GLM2_BENCHMARK_VECTOR_CMP_OPERATORS_INTEGER

static void glm__ivec2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v121i == v122i;
}
static void glm__ivec3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v131i == v132i;
}
static void glm__ivec4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v141i == v142i;
}
static void glm2_ivec2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v221i == v222i;
}
static void glm2_ivec3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v231i == v232i;
}
static void glm2_ivec4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v241i == v242i;
}
BENCHMARK(glm__ivec2_cmpeq);
BENCHMARK(glm2_ivec2_cmpeq);
BENCHMARK(glm__ivec3_cmpeq);
BENCHMARK(glm2_ivec3_cmpeq);
BENCHMARK(glm__ivec4_cmpeq);
BENCHMARK(glm2_ivec4_cmpeq);

static void glm__ivec2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v121i != v122i;
}
static void glm__ivec3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v131i != v132i;
}
static void glm__ivec4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v141i != v142i;
}
static void glm2_ivec2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v221i != v222i;
}
static void glm2_ivec3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v231i != v232i;
}
static void glm2_ivec4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = v241i != v242i;
}
BENCHMARK(glm__ivec2_cmpneq);
BENCHMARK(glm2_ivec2_cmpneq);
BENCHMARK(glm__ivec3_cmpneq);
BENCHMARK(glm2_ivec3_cmpneq);
BENCHMARK(glm__ivec4_cmpneq);
BENCHMARK(glm2_ivec4_cmpneq);

#endif

#ifdef GLM2_BENCHMARK_MATRIX_ARITHMETIC_OPERATORS

static void glm__mat2x2_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222 + f1;
}
static void glm__mat2x3_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1232 + f1;
}
static void glm__mat2x4_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1242 + f1;
}
static void glm__mat3x2_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1322 + f1;
}
static void glm__mat3x3_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332 + f1;
}
static void glm__mat3x4_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1342 + f1;
}
static void glm__mat4x2_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1422 + f1;
}
static void glm__mat4x3_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1432 + f1;
}
static void glm__mat4x4_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442 + f1;
}
static void glm2_mat2x2_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222 + f1;
}
static void glm2_mat2x3_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2232 + f1;
}
static void glm2_mat2x4_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2242 + f1;
}
static void glm2_mat3x2_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2322 + f1;
}
static void glm2_mat3x3_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332 + f1;
}
static void glm2_mat3x4_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2342 + f1;
}
static void glm2_mat4x2_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2422 + f1;
}
static void glm2_mat4x3_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2432 + f1;
}
static void glm2_mat4x4_addf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442 + f1;
}
BENCHMARK(glm__mat2x2_addf);
BENCHMARK(glm2_mat2x2_addf);
BENCHMARK(glm__mat2x3_addf);
BENCHMARK(glm2_mat2x3_addf);
BENCHMARK(glm__mat2x4_addf);
BENCHMARK(glm2_mat2x4_addf);
BENCHMARK(glm__mat3x2_addf);
BENCHMARK(glm2_mat3x2_addf);
BENCHMARK(glm__mat3x3_addf);
BENCHMARK(glm2_mat3x3_addf);
BENCHMARK(glm__mat3x4_addf);
BENCHMARK(glm2_mat3x4_addf);
BENCHMARK(glm__mat4x2_addf);
BENCHMARK(glm2_mat4x2_addf);
BENCHMARK(glm__mat4x3_addf);
BENCHMARK(glm2_mat4x3_addf);
BENCHMARK(glm__mat4x4_addf);
BENCHMARK(glm2_mat4x4_addf);

static void glm__mat2x2_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 += v121;
}
static void glm__mat2x3_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 += v131;
}
static void glm__mat2x4_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 += v141;
}
static void glm__mat3x2_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 += v121;
}
static void glm__mat3x3_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 += v131;
}
static void glm__mat3x4_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 += v141;
}
static void glm__mat4x2_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 += v121;
}
static void glm__mat4x3_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 += v131;
}
static void glm__mat4x4_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 += v141;
}
static void glm2_mat2x2_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 += v221;
}
static void glm2_mat2x3_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 += v231;
}
static void glm2_mat2x4_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 += v241;
}
static void glm2_mat3x2_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 += v221;
}
static void glm2_mat3x3_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 += v231;
}
static void glm2_mat3x4_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 += v241;
}
static void glm2_mat4x2_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 += v221;
}
static void glm2_mat4x3_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 += v231;
}
static void glm2_mat4x4_addv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 += v241;
}
BENCHMARK(glm__mat2x2_addv);
BENCHMARK(glm2_mat2x2_addv);
BENCHMARK(glm__mat2x3_addv);
BENCHMARK(glm2_mat2x3_addv);
BENCHMARK(glm__mat2x4_addv);
BENCHMARK(glm2_mat2x4_addv);
BENCHMARK(glm__mat3x2_addv);
BENCHMARK(glm2_mat3x2_addv);
BENCHMARK(glm__mat3x3_addv);
BENCHMARK(glm2_mat3x3_addv);
BENCHMARK(glm__mat3x4_addv);
BENCHMARK(glm2_mat3x4_addv);
BENCHMARK(glm__mat4x2_addv);
BENCHMARK(glm2_mat4x2_addv);
BENCHMARK(glm__mat4x3_addv);
BENCHMARK(glm2_mat4x3_addv);
BENCHMARK(glm__mat4x4_addv);
BENCHMARK(glm2_mat4x4_addv);

static void glm__mat2x2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222 + m1223;
}
static void glm__mat2x3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1232 + m1233;
}
static void glm__mat2x4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1242 + m1243;
}
static void glm__mat3x2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1322 + m1323;
}
static void glm__mat3x3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332 + m1333;
}
static void glm__mat3x4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1342 + m1343;
}
static void glm__mat4x2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1422 + m1423;
}
static void glm__mat4x3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1432 + m1433;
}
static void glm__mat4x4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442 + m1443;
}
static void glm2_mat2x2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222 + m2223;
}
static void glm2_mat2x3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2232 + m2233;
}
static void glm2_mat2x4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2242 + m2243;
}
static void glm2_mat3x2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2322 + m2323;
}
static void glm2_mat3x3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332 + m2333;
}
static void glm2_mat3x4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2342 + m2343;
}
static void glm2_mat4x2_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2422 + m2423;
}
static void glm2_mat4x3_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2432 + m2433;
}
static void glm2_mat4x4_add(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442 + m2443;
}
BENCHMARK(glm__mat2x2_add);
BENCHMARK(glm2_mat2x2_add);
BENCHMARK(glm__mat2x3_add);
BENCHMARK(glm2_mat2x3_add);
BENCHMARK(glm__mat2x4_add);
BENCHMARK(glm2_mat2x4_add);
BENCHMARK(glm__mat3x2_add);
BENCHMARK(glm2_mat3x2_add);
BENCHMARK(glm__mat3x3_add);
BENCHMARK(glm2_mat3x3_add);
BENCHMARK(glm__mat3x4_add);
BENCHMARK(glm2_mat3x4_add);
BENCHMARK(glm__mat4x2_add);
BENCHMARK(glm2_mat4x2_add);
BENCHMARK(glm__mat4x3_add);
BENCHMARK(glm2_mat4x3_add);
BENCHMARK(glm__mat4x4_add);
BENCHMARK(glm2_mat4x4_add);

static void glm__mat2x2_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222 - f1;
}
static void glm__mat2x3_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1232 - f1;
}
static void glm__mat2x4_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1242 - f1;
}
static void glm__mat3x2_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1322 - f1;
}
static void glm__mat3x3_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332 - f1;
}
static void glm__mat3x4_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1342 - f1;
}
static void glm__mat4x2_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1422 - f1;
}
static void glm__mat4x3_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1432 - f1;
}
static void glm__mat4x4_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442 - f1;
}
static void glm2_mat2x2_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222 - f1;
}
static void glm2_mat2x3_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2232 - f1;
}
static void glm2_mat2x4_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2242 - f1;
}
static void glm2_mat3x2_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2322 - f1;
}
static void glm2_mat3x3_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332 - f1;
}
static void glm2_mat3x4_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2342 - f1;
}
static void glm2_mat4x2_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2422 - f1;
}
static void glm2_mat4x3_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2432 - f1;
}
static void glm2_mat4x4_subf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442 - f1;
}
BENCHMARK(glm__mat2x2_subf);
BENCHMARK(glm2_mat2x2_subf);
BENCHMARK(glm__mat2x3_subf);
BENCHMARK(glm2_mat2x3_subf);
BENCHMARK(glm__mat2x4_subf);
BENCHMARK(glm2_mat2x4_subf);
BENCHMARK(glm__mat3x2_subf);
BENCHMARK(glm2_mat3x2_subf);
BENCHMARK(glm__mat3x3_subf);
BENCHMARK(glm2_mat3x3_subf);
BENCHMARK(glm__mat3x4_subf);
BENCHMARK(glm2_mat3x4_subf);
BENCHMARK(glm__mat4x2_subf);
BENCHMARK(glm2_mat4x2_subf);
BENCHMARK(glm__mat4x3_subf);
BENCHMARK(glm2_mat4x3_subf);
BENCHMARK(glm__mat4x4_subf);
BENCHMARK(glm2_mat4x4_subf);

static void glm__mat2x2_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 -= v121;
}
static void glm__mat2x3_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 -= v131;
}
static void glm__mat2x4_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 -= v141;
}
static void glm__mat3x2_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 -= v121;
}
static void glm__mat3x3_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 -= v131;
}
static void glm__mat3x4_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 -= v141;
}
static void glm__mat4x2_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 -= v121;
}
static void glm__mat4x3_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 -= v131;
}
static void glm__mat4x4_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 -= v141;
}
static void glm2_mat2x2_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 -= v221;
}
static void glm2_mat2x3_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 -= v231;
}
static void glm2_mat2x4_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 -= v241;
}
static void glm2_mat3x2_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 -= v221;
}
static void glm2_mat3x3_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 -= v231;
}
static void glm2_mat3x4_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 -= v241;
}
static void glm2_mat4x2_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 -= v221;
}
static void glm2_mat4x3_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 -= v231;
}
static void glm2_mat4x4_subv(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 -= v241;
}
BENCHMARK(glm__mat2x2_subv);
BENCHMARK(glm2_mat2x2_subv);
BENCHMARK(glm__mat2x3_subv);
BENCHMARK(glm2_mat2x3_subv);
BENCHMARK(glm__mat2x4_subv);
BENCHMARK(glm2_mat2x4_subv);
BENCHMARK(glm__mat3x2_subv);
BENCHMARK(glm2_mat3x2_subv);
BENCHMARK(glm__mat3x3_subv);
BENCHMARK(glm2_mat3x3_subv);
BENCHMARK(glm__mat3x4_subv);
BENCHMARK(glm2_mat3x4_subv);
BENCHMARK(glm__mat4x2_subv);
BENCHMARK(glm2_mat4x2_subv);
BENCHMARK(glm__mat4x3_subv);
BENCHMARK(glm2_mat4x3_subv);
BENCHMARK(glm__mat4x4_subv);
BENCHMARK(glm2_mat4x4_subv);

static void glm__mat2x2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222 - m1223;
}
static void glm__mat2x3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1232 - m1233;
}
static void glm__mat2x4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1242 - m1243;
}
static void glm__mat3x2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1322 - m1323;
}
static void glm__mat3x3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332 - m1333;
}
static void glm__mat3x4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1342 - m1343;
}
static void glm__mat4x2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1422 - m1423;
}
static void glm__mat4x3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1432 - m1433;
}
static void glm__mat4x4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442 - m1443;
}
static void glm2_mat2x2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222 - m2223;
}
static void glm2_mat2x3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2232 - m2233;
}
static void glm2_mat2x4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2242 - m2243;
}
static void glm2_mat3x2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2322 - m2323;
}
static void glm2_mat3x3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332 - m2333;
}
static void glm2_mat3x4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2342 - m2343;
}
static void glm2_mat4x2_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2422 - m2423;
}
static void glm2_mat4x3_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2432 - m2433;
}
static void glm2_mat4x4_sub(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442 - m2443;
}
BENCHMARK(glm__mat2x2_sub);
BENCHMARK(glm2_mat2x2_sub);
BENCHMARK(glm__mat2x3_sub);
BENCHMARK(glm2_mat2x3_sub);
BENCHMARK(glm__mat2x4_sub);
BENCHMARK(glm2_mat2x4_sub);
BENCHMARK(glm__mat3x2_sub);
BENCHMARK(glm2_mat3x2_sub);
BENCHMARK(glm__mat3x3_sub);
BENCHMARK(glm2_mat3x3_sub);
BENCHMARK(glm__mat3x4_sub);
BENCHMARK(glm2_mat3x4_sub);
BENCHMARK(glm__mat4x2_sub);
BENCHMARK(glm2_mat4x2_sub);
BENCHMARK(glm__mat4x3_sub);
BENCHMARK(glm2_mat4x3_sub);
BENCHMARK(glm__mat4x4_sub);
BENCHMARK(glm2_mat4x4_sub);

static void glm__mat2x2_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222 * f1;
}
static void glm__mat2x3_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1232 * f1;
}
static void glm__mat2x4_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1242 * f1;
}
static void glm__mat3x2_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1322 * f1;
}
static void glm__mat3x3_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332 * f1;
}
static void glm__mat3x4_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1342 * f1;
}
static void glm__mat4x2_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1422 * f1;
}
static void glm__mat4x3_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1432 * f1;
}
static void glm__mat4x4_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442 * f1;
}
static void glm2_mat2x2_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222 * f1;
}
static void glm2_mat2x3_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2232 * f1;
}
static void glm2_mat2x4_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2242 * f1;
}
static void glm2_mat3x2_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2322 * f1;
}
static void glm2_mat3x3_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332 * f1;
}
static void glm2_mat3x4_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2342 * f1;
}
static void glm2_mat4x2_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2422 * f1;
}
static void glm2_mat4x3_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2432 * f1;
}
static void glm2_mat4x4_mulf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442 * f1;
}
BENCHMARK(glm__mat2x2_mulf);
BENCHMARK(glm2_mat2x2_mulf);
BENCHMARK(glm__mat2x3_mulf);
BENCHMARK(glm2_mat2x3_mulf);
BENCHMARK(glm__mat2x4_mulf);
BENCHMARK(glm2_mat2x4_mulf);
BENCHMARK(glm__mat3x2_mulf);
BENCHMARK(glm2_mat3x2_mulf);
BENCHMARK(glm__mat3x3_mulf);
BENCHMARK(glm2_mat3x3_mulf);
BENCHMARK(glm__mat3x4_mulf);
BENCHMARK(glm2_mat3x4_mulf);
BENCHMARK(glm__mat4x2_mulf);
BENCHMARK(glm2_mat4x2_mulf);
BENCHMARK(glm__mat4x3_mulf);
BENCHMARK(glm2_mat4x3_mulf);
BENCHMARK(glm__mat4x4_mulf);
BENCHMARK(glm2_mat4x4_mulf);

static void glm__mat2x2_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222 / f1;
}
static void glm__mat2x3_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1232 / f1;
}
static void glm__mat2x4_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1242 / f1;
}
static void glm__mat3x2_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1322 / f1;
}
static void glm__mat3x3_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332 / f1;
}
static void glm__mat3x4_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1342 / f1;
}
static void glm__mat4x2_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1422 / f1;
}
static void glm__mat4x3_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1432 / f1;
}
static void glm__mat4x4_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442 / f1;
}
static void glm2_mat2x2_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222 / f1;
}
static void glm2_mat2x3_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2232 / f1;
}
static void glm2_mat2x4_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2242 / f1;
}
static void glm2_mat3x2_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2322 / f1;
}
static void glm2_mat3x3_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332 / f1;
}
static void glm2_mat3x4_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2342 / f1;
}
static void glm2_mat4x2_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2422 / f1;
}
static void glm2_mat4x3_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2432 / f1;
}
static void glm2_mat4x4_divf(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442 / f1;
}
BENCHMARK(glm__mat2x2_divf);
BENCHMARK(glm2_mat2x2_divf);
BENCHMARK(glm__mat2x3_divf);
BENCHMARK(glm2_mat2x3_divf);
BENCHMARK(glm__mat2x4_divf);
BENCHMARK(glm2_mat2x4_divf);
BENCHMARK(glm__mat3x2_divf);
BENCHMARK(glm2_mat3x2_divf);
BENCHMARK(glm__mat3x3_divf);
BENCHMARK(glm2_mat3x3_divf);
BENCHMARK(glm__mat3x4_divf);
BENCHMARK(glm2_mat3x4_divf);
BENCHMARK(glm__mat4x2_divf);
BENCHMARK(glm2_mat4x2_divf);
BENCHMARK(glm__mat4x3_divf);
BENCHMARK(glm2_mat4x3_divf);
BENCHMARK(glm__mat4x4_divf);
BENCHMARK(glm2_mat4x4_divf);

static void glm__mat2x2_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = +m1222;
}
static void glm__mat2x3_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = +m1232;
}
static void glm__mat2x4_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = +m1242;
}
static void glm__mat3x2_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = +m1322;
}
static void glm__mat3x3_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = +m1332;
}
static void glm__mat3x4_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = +m1342;
}
static void glm__mat4x2_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = +m1422;
}
static void glm__mat4x3_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = +m1432;
}
static void glm__mat4x4_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = +m1442;
}
static void glm2_mat2x2_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = +m2222;
}
static void glm2_mat2x3_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = +m2232;
}
static void glm2_mat2x4_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = +m2242;
}
static void glm2_mat3x2_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = +m2322;
}
static void glm2_mat3x3_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = +m2332;
}
static void glm2_mat3x4_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = +m2342;
}
static void glm2_mat4x2_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = +m2422;
}
static void glm2_mat4x3_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = +m2432;
}
static void glm2_mat4x4_pos(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = +m2442;
}
BENCHMARK(glm__mat2x2_pos);
BENCHMARK(glm2_mat2x2_pos);
BENCHMARK(glm__mat2x3_pos);
BENCHMARK(glm2_mat2x3_pos);
BENCHMARK(glm__mat2x4_pos);
BENCHMARK(glm2_mat2x4_pos);
BENCHMARK(glm__mat3x2_pos);
BENCHMARK(glm2_mat3x2_pos);
BENCHMARK(glm__mat3x3_pos);
BENCHMARK(glm2_mat3x3_pos);
BENCHMARK(glm__mat3x4_pos);
BENCHMARK(glm2_mat3x4_pos);
BENCHMARK(glm__mat4x2_pos);
BENCHMARK(glm2_mat4x2_pos);
BENCHMARK(glm__mat4x3_pos);
BENCHMARK(glm2_mat4x3_pos);
BENCHMARK(glm__mat4x4_pos);
BENCHMARK(glm2_mat4x4_pos);

static void glm__mat2x2_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = -m1222;
}
static void glm__mat2x3_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = -m1232;
}
static void glm__mat2x4_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = -m1242;
}
static void glm__mat3x2_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = -m1322;
}
static void glm__mat3x3_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = -m1332;
}
static void glm__mat3x4_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = -m1342;
}
static void glm__mat4x2_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = -m1422;
}
static void glm__mat4x3_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = -m1432;
}
static void glm__mat4x4_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = -m1442;
}
static void glm2_mat2x2_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = -m2222;
}
static void glm2_mat2x3_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = -m2232;
}
static void glm2_mat2x4_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = -m2242;
}
static void glm2_mat3x2_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = -m2322;
}
static void glm2_mat3x3_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = -m2332;
}
static void glm2_mat3x4_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = -m2342;
}
static void glm2_mat4x2_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = -m2422;
}
static void glm2_mat4x3_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = -m2432;
}
static void glm2_mat4x4_neg(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = -m2442;
}
BENCHMARK(glm__mat2x2_neg);
BENCHMARK(glm2_mat2x2_neg);
BENCHMARK(glm__mat2x3_neg);
BENCHMARK(glm2_mat2x3_neg);
BENCHMARK(glm__mat2x4_neg);
BENCHMARK(glm2_mat2x4_neg);
BENCHMARK(glm__mat3x2_neg);
BENCHMARK(glm2_mat3x2_neg);
BENCHMARK(glm__mat3x3_neg);
BENCHMARK(glm2_mat3x3_neg);
BENCHMARK(glm__mat3x4_neg);
BENCHMARK(glm2_mat3x4_neg);
BENCHMARK(glm__mat4x2_neg);
BENCHMARK(glm2_mat4x2_neg);
BENCHMARK(glm__mat4x3_neg);
BENCHMARK(glm2_mat4x3_neg);
BENCHMARK(glm__mat4x4_neg);
BENCHMARK(glm2_mat4x4_neg);

static void glm__mat2x2_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = ++m1222;
}
static void glm__mat2x3_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = ++m1232;
}
static void glm__mat2x4_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = ++m1242;
}
static void glm__mat3x2_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = ++m1322;
}
static void glm__mat3x3_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = ++m1332;
}
static void glm__mat3x4_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = ++m1342;
}
static void glm__mat4x2_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = ++m1422;
}
static void glm__mat4x3_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = ++m1432;
}
static void glm__mat4x4_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = ++m1442;
}
static void glm2_mat2x2_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = ++m2222;
}
static void glm2_mat2x3_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = ++m2232;
}
static void glm2_mat2x4_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = ++m2242;
}
static void glm2_mat3x2_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = ++m2322;
}
static void glm2_mat3x3_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = ++m2332;
}
static void glm2_mat3x4_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = ++m2342;
}
static void glm2_mat4x2_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = ++m2422;
}
static void glm2_mat4x3_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = ++m2432;
}
static void glm2_mat4x4_preinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = ++m2442;
}
BENCHMARK(glm__mat2x2_preinc);
BENCHMARK(glm2_mat2x2_preinc);
BENCHMARK(glm__mat2x3_preinc);
BENCHMARK(glm2_mat2x3_preinc);
BENCHMARK(glm__mat2x4_preinc);
BENCHMARK(glm2_mat2x4_preinc);
BENCHMARK(glm__mat3x2_preinc);
BENCHMARK(glm2_mat3x2_preinc);
BENCHMARK(glm__mat3x3_preinc);
BENCHMARK(glm2_mat3x3_preinc);
BENCHMARK(glm__mat3x4_preinc);
BENCHMARK(glm2_mat3x4_preinc);
BENCHMARK(glm__mat4x2_preinc);
BENCHMARK(glm2_mat4x2_preinc);
BENCHMARK(glm__mat4x3_preinc);
BENCHMARK(glm2_mat4x3_preinc);
BENCHMARK(glm__mat4x4_preinc);
BENCHMARK(glm2_mat4x4_preinc);

static void glm__mat2x2_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222++;
}
static void glm__mat2x3_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1232++;
}
static void glm__mat2x4_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1242++;
}
static void glm__mat3x2_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1322++;
}
static void glm__mat3x3_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332++;
}
static void glm__mat3x4_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1342++;
}
static void glm__mat4x2_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1422++;
}
static void glm__mat4x3_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1432++;
}
static void glm__mat4x4_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442++;
}
static void glm2_mat2x2_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222++;
}
static void glm2_mat2x3_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2232++;
}
static void glm2_mat2x4_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2242++;
}
static void glm2_mat3x2_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2322++;
}
static void glm2_mat3x3_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332++;
}
static void glm2_mat3x4_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2342++;
}
static void glm2_mat4x2_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2422++;
}
static void glm2_mat4x3_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2432++;
}
static void glm2_mat4x4_postinc(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442++;
}
BENCHMARK(glm__mat2x2_postinc);
BENCHMARK(glm2_mat2x2_postinc);
BENCHMARK(glm__mat2x3_postinc);
BENCHMARK(glm2_mat2x3_postinc);
BENCHMARK(glm__mat2x4_postinc);
BENCHMARK(glm2_mat2x4_postinc);
BENCHMARK(glm__mat3x2_postinc);
BENCHMARK(glm2_mat3x2_postinc);
BENCHMARK(glm__mat3x3_postinc);
BENCHMARK(glm2_mat3x3_postinc);
BENCHMARK(glm__mat3x4_postinc);
BENCHMARK(glm2_mat3x4_postinc);
BENCHMARK(glm__mat4x2_postinc);
BENCHMARK(glm2_mat4x2_postinc);
BENCHMARK(glm__mat4x3_postinc);
BENCHMARK(glm2_mat4x3_postinc);
BENCHMARK(glm__mat4x4_postinc);
BENCHMARK(glm2_mat4x4_postinc);

static void glm__mat2x2_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = --m1222;
}
static void glm__mat2x3_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = --m1232;
}
static void glm__mat2x4_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = --m1242;
}
static void glm__mat3x2_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = --m1322;
}
static void glm__mat3x3_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = --m1332;
}
static void glm__mat3x4_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = --m1342;
}
static void glm__mat4x2_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = --m1422;
}
static void glm__mat4x3_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = --m1432;
}
static void glm__mat4x4_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = --m1442;
}
static void glm2_mat2x2_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = --m2222;
}
static void glm2_mat2x3_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = --m2232;
}
static void glm2_mat2x4_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = --m2242;
}
static void glm2_mat3x2_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = --m2322;
}
static void glm2_mat3x3_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = --m2332;
}
static void glm2_mat3x4_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = --m2342;
}
static void glm2_mat4x2_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = --m2422;
}
static void glm2_mat4x3_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = --m2432;
}
static void glm2_mat4x4_predec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = --m2442;
}
BENCHMARK(glm__mat2x2_predec);
BENCHMARK(glm2_mat2x2_predec);
BENCHMARK(glm__mat2x3_predec);
BENCHMARK(glm2_mat2x3_predec);
BENCHMARK(glm__mat2x4_predec);
BENCHMARK(glm2_mat2x4_predec);
BENCHMARK(glm__mat3x2_predec);
BENCHMARK(glm2_mat3x2_predec);
BENCHMARK(glm__mat3x3_predec);
BENCHMARK(glm2_mat3x3_predec);
BENCHMARK(glm__mat3x4_predec);
BENCHMARK(glm2_mat3x4_predec);
BENCHMARK(glm__mat4x2_predec);
BENCHMARK(glm2_mat4x2_predec);
BENCHMARK(glm__mat4x3_predec);
BENCHMARK(glm2_mat4x3_predec);
BENCHMARK(glm__mat4x4_predec);
BENCHMARK(glm2_mat4x4_predec);

static void glm__mat2x2_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222--;
}
static void glm__mat2x3_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1232--;
}
static void glm__mat2x4_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1242--;
}
static void glm__mat3x2_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1322--;
}
static void glm__mat3x3_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332--;
}
static void glm__mat3x4_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1342--;
}
static void glm__mat4x2_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1422--;
}
static void glm__mat4x3_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1432--;
}
static void glm__mat4x4_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442--;
}
static void glm2_mat2x2_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222--;
}
static void glm2_mat2x3_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2232--;
}
static void glm2_mat2x4_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2242--;
}
static void glm2_mat3x2_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2322--;
}
static void glm2_mat3x3_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332--;
}
static void glm2_mat3x4_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2342--;
}
static void glm2_mat4x2_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2422--;
}
static void glm2_mat4x3_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2432--;
}
static void glm2_mat4x4_postdec(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442--;
}
BENCHMARK(glm__mat2x2_postdec);
BENCHMARK(glm2_mat2x2_postdec);
BENCHMARK(glm__mat2x3_postdec);
BENCHMARK(glm2_mat2x3_postdec);
BENCHMARK(glm__mat2x4_postdec);
BENCHMARK(glm2_mat2x4_postdec);
BENCHMARK(glm__mat3x2_postdec);
BENCHMARK(glm2_mat3x2_postdec);
BENCHMARK(glm__mat3x3_postdec);
BENCHMARK(glm2_mat3x3_postdec);
BENCHMARK(glm__mat3x4_postdec);
BENCHMARK(glm2_mat3x4_postdec);
BENCHMARK(glm__mat4x2_postdec);
BENCHMARK(glm2_mat4x2_postdec);
BENCHMARK(glm__mat4x3_postdec);
BENCHMARK(glm2_mat4x3_postdec);
BENCHMARK(glm__mat4x4_postdec);
BENCHMARK(glm2_mat4x4_postdec);

#endif

#ifdef GLM2_BENCHMARK_MATRIX_CMP_OPERATORS
static void glm__mat2x2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1221 == m1222;
}
static void glm__mat2x3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1231 == m1232;
}
static void glm__mat2x4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1241 == m1242;
}
static void glm__mat3x2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1321 == m1322;
}
static void glm__mat3x3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1331 == m1332;
}
static void glm__mat3x4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1341 == m1342;
}
static void glm__mat4x2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1421 == m1422;
}
static void glm__mat4x3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1431 == m1432;
}
static void glm__mat4x4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1441 == m1442;
}
static void glm2_mat2x2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2221 == m2222;
}
static void glm2_mat2x3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2231 == m2232;
}
static void glm2_mat2x4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2241 == m2242;
}
static void glm2_mat3x2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2321 == m2322;
}
static void glm2_mat3x3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2331 == m2332;
}
static void glm2_mat3x4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2341 == m2342;
}
static void glm2_mat4x2_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2421 == m2422;
}
static void glm2_mat4x3_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2431 == m2432;
}
static void glm2_mat4x4_cmpeq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2441 == m2442;
}
BENCHMARK(glm__mat2x2_cmpeq);
BENCHMARK(glm2_mat2x2_cmpeq);
BENCHMARK(glm__mat2x3_cmpeq);
BENCHMARK(glm2_mat2x3_cmpeq);
BENCHMARK(glm__mat2x4_cmpeq);
BENCHMARK(glm2_mat2x4_cmpeq);
BENCHMARK(glm__mat3x2_cmpeq);
BENCHMARK(glm2_mat3x2_cmpeq);
BENCHMARK(glm__mat3x3_cmpeq);
BENCHMARK(glm2_mat3x3_cmpeq);
BENCHMARK(glm__mat3x4_cmpeq);
BENCHMARK(glm2_mat3x4_cmpeq);
BENCHMARK(glm__mat4x2_cmpeq);
BENCHMARK(glm2_mat4x2_cmpeq);
BENCHMARK(glm__mat4x3_cmpeq);
BENCHMARK(glm2_mat4x3_cmpeq);
BENCHMARK(glm__mat4x4_cmpeq);
BENCHMARK(glm2_mat4x4_cmpeq);

static void glm__mat2x2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1221 != m1222;
}
static void glm__mat2x3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1231 != m1232;
}
static void glm__mat2x4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1241 != m1242;
}
static void glm__mat3x2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1321 != m1322;
}
static void glm__mat3x3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1331 != m1332;
}
static void glm__mat3x4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1341 != m1342;
}
static void glm__mat4x2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1421 != m1422;
}
static void glm__mat4x3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1431 != m1432;
}
static void glm__mat4x4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m1441 != m1442;
}
static void glm2_mat2x2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2221 != m2222;
}
static void glm2_mat2x3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2231 != m2232;
}
static void glm2_mat2x4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2241 != m2242;
}
static void glm2_mat3x2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2321 != m2322;
}
static void glm2_mat3x3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2331 != m2332;
}
static void glm2_mat3x4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2341 != m2342;
}
static void glm2_mat4x2_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2421 != m2422;
}
static void glm2_mat4x3_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2431 != m2432;
}
static void glm2_mat4x4_cmpneq(benchmark::State& state)
{
    while(state.KeepRunning())
        b = m2441 != m2442;
}
BENCHMARK(glm__mat2x2_cmpneq);
BENCHMARK(glm2_mat2x2_cmpneq);
BENCHMARK(glm__mat2x3_cmpneq);
BENCHMARK(glm2_mat2x3_cmpneq);
BENCHMARK(glm__mat2x4_cmpneq);
BENCHMARK(glm2_mat2x4_cmpneq);
BENCHMARK(glm__mat3x2_cmpneq);
BENCHMARK(glm2_mat3x2_cmpneq);
BENCHMARK(glm__mat3x3_cmpneq);
BENCHMARK(glm2_mat3x3_cmpneq);
BENCHMARK(glm__mat3x4_cmpneq);
BENCHMARK(glm2_mat3x4_cmpneq);
BENCHMARK(glm__mat4x2_cmpneq);
BENCHMARK(glm2_mat4x2_cmpneq);
BENCHMARK(glm__mat4x3_cmpneq);
BENCHMARK(glm2_mat4x3_cmpneq);
BENCHMARK(glm__mat4x4_cmpneq);
BENCHMARK(glm2_mat4x4_cmpneq);
#endif

#ifdef GLM2_BENCHMARK_MATRIX_EXT_ARITHMETIC

static void glm__mat2x2_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = m1221 * v122;
}
static void glm2_mat2x2_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = m2221 * v222;
}
static void glm__mat2x2_divv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = m1221 / v122;
}
static void glm2_mat2x2_divv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = m2221 / v222;
}
static void glm__mat2x2_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222 * m1223;
}
static void glm2_mat2x2_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222 * m2223;
}
static void glm__mat2x2_div(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1222 / m1223;
}
static void glm2_mat2x2_div(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2222 / m2223;
}
static void glm__mat2x2_mul_mat3x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1222 * m1323;
}
static void glm2_mat2x2_mul_mat3x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2222 * m2323;
}
static void glm__mat2x2_mul_mat4x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1222 * m1423;
}
static void glm2_mat2x2_mul_mat4x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2222 * m2423;
}
BENCHMARK(glm__mat2x2_mulv);
BENCHMARK(glm2_mat2x2_mulv);
BENCHMARK(glm__mat2x2_divv);
BENCHMARK(glm2_mat2x2_divv);
BENCHMARK(glm__mat2x2_mul);
BENCHMARK(glm2_mat2x2_mul);
BENCHMARK(glm__mat2x2_div);
BENCHMARK(glm2_mat2x2_div);
BENCHMARK(glm__mat2x2_mul_mat3x2);
BENCHMARK(glm2_mat2x2_mul_mat3x2);
BENCHMARK(glm__mat2x2_mul_mat4x2);
BENCHMARK(glm2_mat2x2_mul_mat4x2);

static void glm__mat2x3_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = m1231 * v122;
}
static void glm2_mat2x3_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = m2231 * v222;
}
static void glm__mat2x3_mul_mat2x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1232 * m1223;
}
static void glm2_mat2x3_mul_mat2x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2232 * m2223;
}
static void glm__mat2x3_mul_mat3x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1232 * m1323;
}
static void glm2_mat2x3_mul_mat3x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2232 * m2323;
}
static void glm__mat2x3_mul_mat4x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1232 * m1423;
}
static void glm2_mat2x3_mul_mat4x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2232 * m2423;
}
BENCHMARK(glm__mat2x3_mulv);
BENCHMARK(glm2_mat2x3_mulv);
BENCHMARK(glm__mat2x3_mul_mat2x2);
BENCHMARK(glm2_mat2x3_mul_mat2x2);
BENCHMARK(glm__mat2x3_mul_mat3x2);
BENCHMARK(glm2_mat2x3_mul_mat3x2);
BENCHMARK(glm__mat2x3_mul_mat4x2);
BENCHMARK(glm2_mat2x3_mul_mat4x2);

static void glm__mat2x4_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = m1241 * v122;
}
static void glm2_mat2x4_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = m2241 * v222;
}
static void glm__mat2x4_mul_mat2x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1242 * m1223;
}
static void glm2_mat2x4_mul_mat2x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2242 * m2223;
}
static void glm__mat2x4_mul_mat3x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1242 * m1323;
}
static void glm2_mat2x4_mul_mat3x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2242 * m2323;
}
static void glm__mat2x4_mul_mat4x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1242 * m1423;
}
static void glm2_mat2x4_mul_mat4x2(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2242 * m2423;
}
BENCHMARK(glm__mat2x4_mulv);
BENCHMARK(glm2_mat2x4_mulv);
BENCHMARK(glm__mat2x4_mul_mat2x2);
BENCHMARK(glm2_mat2x4_mul_mat2x2);
BENCHMARK(glm__mat2x4_mul_mat3x2);
BENCHMARK(glm2_mat2x4_mul_mat3x2);
BENCHMARK(glm__mat2x4_mul_mat4x2);
BENCHMARK(glm2_mat2x4_mul_mat4x2);

static void glm__mat3x2_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = m1321 * v132;
}
static void glm2_mat3x2_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = m2321 * v232;
}
static void glm__mat3x2_mul_mat2x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1322 * m1233;
}
static void glm2_mat3x2_mul_mat2x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2322 * m2233;
}
static void glm__mat3x2_mul_mat3x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1322 * m1333;
}
static void glm2_mat3x2_mul_mat3x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2322 * m2333;
}
static void glm__mat3x2_mul_mat4x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1322 * m1433;
}
static void glm2_mat3x2_mul_mat4x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2322 * m2433;
}
BENCHMARK(glm__mat3x2_mulv);
BENCHMARK(glm2_mat3x2_mulv);
BENCHMARK(glm__mat3x2_mul_mat2x3);
BENCHMARK(glm2_mat3x2_mul_mat2x3);
BENCHMARK(glm__mat3x2_mul_mat3x3);
BENCHMARK(glm2_mat3x2_mul_mat3x3);
BENCHMARK(glm__mat3x2_mul_mat4x3);
BENCHMARK(glm2_mat3x2_mul_mat4x3);

static void glm__mat3x3_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = m1331 * v132;
}
static void glm2_mat3x3_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = m2331 * v232;
}
static void glm__mat3x3_divv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = m1331 / v132;
}
static void glm2_mat3x3_divv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = m2331 / v232;
}
static void glm__mat3x3_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332 * m1333;
}
static void glm2_mat3x3_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332 * m2333;
}
static void glm__mat3x3_div(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1332 / m1333;
}
static void glm2_mat3x3_div(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2332 / m2333;
}
static void glm__mat3x3_mul_mat2x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1332 * m1233;
}
static void glm2_mat3x3_mul_mat2x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2332 * m2233;
}
static void glm__mat3x3_mul_mat4x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1332 * m1433;
}
static void glm2_mat3x3_mul_mat4x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2332 * m2433;
}
BENCHMARK(glm__mat3x3_mulv);
BENCHMARK(glm2_mat3x3_mulv);
BENCHMARK(glm__mat3x3_divv);
BENCHMARK(glm2_mat3x3_divv);
BENCHMARK(glm__mat3x3_mul);
BENCHMARK(glm2_mat3x3_mul);
BENCHMARK(glm__mat3x3_div);
BENCHMARK(glm2_mat3x3_div);
BENCHMARK(glm__mat3x3_mul_mat2x3);
BENCHMARK(glm2_mat3x3_mul_mat2x3);
BENCHMARK(glm__mat3x3_mul_mat4x3);
BENCHMARK(glm2_mat3x3_mul_mat4x3);

static void glm__mat3x4_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = m1341 * v132;
}
static void glm2_mat3x4_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = m2341 * v232;
}
static void glm__mat3x4_mul_mat2x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1342 * m1233;
}
static void glm2_mat3x4_mul_mat2x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2342 * m2233;
}
static void glm__mat3x4_mul_mat3x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1342 * m1333;
}
static void glm2_mat3x4_mul_mat3x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2342 * m2333;
}
static void glm__mat3x4_mul_mat4x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1342 * m1433;
}
static void glm2_mat3x4_mul_mat4x3(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2342 * m2433;
}
BENCHMARK(glm__mat3x4_mulv);
BENCHMARK(glm2_mat3x4_mulv);
BENCHMARK(glm__mat3x4_mul_mat2x3);
BENCHMARK(glm2_mat3x4_mul_mat2x3);
BENCHMARK(glm__mat3x4_mul_mat3x3);
BENCHMARK(glm2_mat3x4_mul_mat3x3);
BENCHMARK(glm__mat3x4_mul_mat4x3);
BENCHMARK(glm2_mat3x4_mul_mat4x3);

static void glm__mat4x2_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = m1421 * v142;
}
static void glm2_mat4x2_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = m2421 * v242;
}
static void glm__mat4x2_mul_mat2x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = m1422 * m1243;
}
static void glm2_mat4x2_mul_mat2x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = m2422 * m2243;
}
static void glm__mat4x2_mul_mat3x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = m1422 * m1343;
}
static void glm2_mat4x2_mul_mat3x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = m2422 * m2343;
}
static void glm__mat4x2_mul_mat4x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = m1422 * m1443;
}
static void glm2_mat4x2_mul_mat4x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = m2422 * m2443;
}
BENCHMARK(glm__mat4x2_mulv);
BENCHMARK(glm2_mat4x2_mulv);
BENCHMARK(glm__mat4x2_mul_mat2x4);
BENCHMARK(glm2_mat4x2_mul_mat2x4);
BENCHMARK(glm__mat4x2_mul_mat3x4);
BENCHMARK(glm2_mat4x2_mul_mat3x4);
BENCHMARK(glm__mat4x2_mul_mat4x4);
BENCHMARK(glm2_mat4x2_mul_mat4x4);

static void glm__mat4x3_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = m1431 * v142;
}
static void glm2_mat4x3_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = m2431 * v242;
}
static void glm__mat4x3_mul_mat2x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = m1432 * m1243;
}
static void glm2_mat4x3_mul_mat2x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = m2432 * m2243;
}
static void glm__mat4x3_mul_mat3x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = m1432 * m1343;
}
static void glm2_mat4x3_mul_mat3x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = m2432 * m2343;
}
static void glm__mat4x3_mul_mat4x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = m1432 * m1443;
}
static void glm2_mat4x3_mul_mat4x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = m2432 * m2443;
}
BENCHMARK(glm__mat4x3_mulv);
BENCHMARK(glm2_mat4x3_mulv);
BENCHMARK(glm__mat4x3_mul_mat2x4);
BENCHMARK(glm2_mat4x3_mul_mat2x4);
BENCHMARK(glm__mat4x3_mul_mat3x4);
BENCHMARK(glm2_mat4x3_mul_mat3x4);
BENCHMARK(glm__mat4x3_mul_mat4x4);
BENCHMARK(glm2_mat4x3_mul_mat4x4);

static void glm__mat4x4_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = m1441 * v142;
}
static void glm2_mat4x4_mulv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = m2441 * v242;
}
static void glm__mat4x4_divv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = m1441 / v142;
}
static void glm2_mat4x4_divv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = m2441 / v242;
}
static void glm__mat4x4_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442 * m1443;
}
static void glm2_mat4x4_mul(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442 * m2443;
}
static void glm__mat4x4_div(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = m1442 / m1443;
}
static void glm2_mat4x4_div(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = m2442 / m2443;
}
static void glm__mat4x4_mul_mat2x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = m1442 * m1243;
}
static void glm2_mat4x4_mul_mat2x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = m2442 * m2243;
}
static void glm__mat4x4_mul_mat3x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = m1442 * m1343;
}
static void glm2_mat4x4_mul_mat3x4(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = m2442 * m2343;
}
BENCHMARK(glm__mat4x4_mulv);
BENCHMARK(glm2_mat4x4_mulv);
BENCHMARK(glm__mat4x4_divv);
BENCHMARK(glm2_mat4x4_divv);
BENCHMARK(glm__mat4x4_mul);
BENCHMARK(glm2_mat4x4_mul);
BENCHMARK(glm__mat4x4_div);
BENCHMARK(glm2_mat4x4_div);
BENCHMARK(glm__mat4x4_mul_mat2x4);
BENCHMARK(glm2_mat4x4_mul_mat2x4);
BENCHMARK(glm__mat4x4_mul_mat3x4);
BENCHMARK(glm2_mat4x4_mul_mat3x4);

#endif

#ifdef GLM2_BENCHMARK_COMMON
static void glm__vec2_abs(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::abs(v122);
}
static void glm__vec3_abs(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::abs(v132);
}
static void glm__vec4_abs(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::abs(v142);
}
static void glm2_vec2_abs(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::abs(v222);
}
static void glm2_vec3_abs(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::abs(v232);
}
static void glm2_vec4_abs(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::abs(v242);
}
BENCHMARK(glm__vec2_abs);
BENCHMARK(glm2_vec2_abs);
BENCHMARK(glm__vec3_abs);
BENCHMARK(glm2_vec3_abs);
BENCHMARK(glm__vec4_abs);
BENCHMARK(glm2_vec4_abs);

static void glm__vec2_ceil(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::ceil(v122);
}
static void glm__vec3_ceil(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::ceil(v132);
}
static void glm__vec4_ceil(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::ceil(v142);
}
static void glm2_vec2_ceil(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::ceil(v222);
}
static void glm2_vec3_ceil(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::ceil(v232);
}
static void glm2_vec4_ceil(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::ceil(v242);
}
BENCHMARK(glm__vec2_ceil);
BENCHMARK(glm2_vec2_ceil);
BENCHMARK(glm__vec3_ceil);
BENCHMARK(glm2_vec3_ceil);
BENCHMARK(glm__vec4_ceil);
BENCHMARK(glm2_vec4_ceil);

static void glm__vec2_clamp(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::clamp(v122, GLM2_VALUE_ZERO, GLM2_VALUE_ONE);
}
static void glm__vec3_clamp(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::clamp(v132, GLM2_VALUE_ZERO, GLM2_VALUE_ONE);
}
static void glm__vec4_clamp(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::clamp(v142, GLM2_VALUE_ZERO, GLM2_VALUE_ONE);
}
static void glm2_vec2_clamp(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::clamp(v222, GLM2_VALUE_ZERO, GLM2_VALUE_ONE);
}
static void glm2_vec3_clamp(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::clamp(v232, GLM2_VALUE_ZERO, GLM2_VALUE_ONE);
}
static void glm2_vec4_clamp(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::clamp(v242, GLM2_VALUE_ZERO, GLM2_VALUE_ONE);
}
BENCHMARK(glm__vec2_clamp);
BENCHMARK(glm2_vec2_clamp);
BENCHMARK(glm__vec3_clamp);
BENCHMARK(glm2_vec3_clamp);
BENCHMARK(glm__vec4_clamp);
BENCHMARK(glm2_vec4_clamp);

static void glm__vec2_clampv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::clamp(v122, v123, v124);
}
static void glm__vec3_clampv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::clamp(v132, v133, v134);
}
static void glm__vec4_clampv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::clamp(v142, v143, v144);
}
static void glm2_vec2_clampv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::clamp(v222, v223, v224);
}
static void glm2_vec3_clampv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::clamp(v232, v233, v234);
}
static void glm2_vec4_clampv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::clamp(v242, v243, v244);
}
BENCHMARK(glm__vec2_clampv);
BENCHMARK(glm2_vec2_clampv);
BENCHMARK(glm__vec3_clampv);
BENCHMARK(glm2_vec3_clampv);
BENCHMARK(glm__vec4_clampv);
BENCHMARK(glm2_vec4_clampv);

static void glm__vec2_floor(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::floor(v122);
}
static void glm__vec3_floor(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::floor(v132);
}
static void glm__vec4_floor(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::floor(v142);
}
static void glm2_vec2_floor(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::floor(v222);
}
static void glm2_vec3_floor(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::floor(v232);
}
static void glm2_vec4_floor(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::floor(v242);
}
BENCHMARK(glm__vec2_floor);
BENCHMARK(glm2_vec2_floor);
BENCHMARK(glm__vec3_floor);
BENCHMARK(glm2_vec3_floor);
BENCHMARK(glm__vec4_floor);
BENCHMARK(glm2_vec4_floor);

static void glm__vec2_fract(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::fract(v122);
}
static void glm__vec3_fract(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::fract(v132);
}
static void glm__vec4_fract(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::fract(v142);
}
static void glm2_vec2_fract(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::fract(v222);
}
static void glm2_vec3_fract(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::fract(v232);
}
static void glm2_vec4_fract(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::fract(v242);
}
BENCHMARK(glm__vec2_fract);
BENCHMARK(glm2_vec2_fract);
BENCHMARK(glm__vec3_fract);
BENCHMARK(glm2_vec3_fract);
BENCHMARK(glm__vec4_fract);
BENCHMARK(glm2_vec4_fract);

static void glm__vec2_fma(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::fma(v122, v123, v124);
}
static void glm__vec3_fma(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::fma(v132, v133, v134);
}
static void glm__vec4_fma(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::fma(v142, v143, v144);
}
static void glm2_vec2_fma(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::fma(v222, v223, v224);
}
static void glm2_vec3_fma(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::fma(v232, v233, v234);
}
static void glm2_vec4_fma(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::fma(v242, v243, v244);
}
BENCHMARK(glm__vec2_fma);
BENCHMARK(glm2_vec2_fma);
BENCHMARK(glm__vec3_fma);
BENCHMARK(glm2_vec3_fma);
BENCHMARK(glm__vec4_fma);
BENCHMARK(glm2_vec4_fma);

static void glm2_vec2_fms(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::fms(v222, v223, v224);
}
static void glm2_vec3_fms(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::fms(v232, v233, v234);
}
static void glm2_vec4_fms(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::fms(v242, v243, v244);
}
BENCHMARK(glm2_vec2_fms);
BENCHMARK(glm2_vec3_fms);
BENCHMARK(glm2_vec4_fms);

static void glm__vec2_max(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::max(v122, GLM2_VALUE_ONE);
}
static void glm__vec3_max(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::max(v132, GLM2_VALUE_ONE);
}
static void glm__vec4_max(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::max(v142, GLM2_VALUE_ONE);
}
static void glm2_vec2_max(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::max(v222, GLM2_VALUE_ONE);
}
static void glm2_vec3_max(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::max(v232, GLM2_VALUE_ONE);
}
static void glm2_vec4_max(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::max(v242, GLM2_VALUE_ONE);
}
BENCHMARK(glm__vec2_max);
BENCHMARK(glm2_vec2_max);
BENCHMARK(glm__vec3_max);
BENCHMARK(glm2_vec3_max);
BENCHMARK(glm__vec4_max);
BENCHMARK(glm2_vec4_max);

static void glm__vec2_maxv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::max(v122, v123);
}
static void glm__vec3_maxv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::max(v132, v133);
}
static void glm__vec4_maxv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::max(v142, v143);
}
static void glm2_vec2_maxv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::max(v222, v223);
}
static void glm2_vec3_maxv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::max(v232, v233);
}
static void glm2_vec4_maxv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::max(v242, v243);
}
BENCHMARK(glm__vec2_maxv);
BENCHMARK(glm2_vec2_maxv);
BENCHMARK(glm__vec3_maxv);
BENCHMARK(glm2_vec3_maxv);
BENCHMARK(glm__vec4_maxv);
BENCHMARK(glm2_vec4_maxv);

static void glm__vec2_min(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::min(v122, GLM2_VALUE_ONE);
}
static void glm__vec3_min(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::min(v132, GLM2_VALUE_ONE);
}
static void glm__vec4_min(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::min(v142, GLM2_VALUE_ONE);
}
static void glm2_vec2_min(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::min(v222, GLM2_VALUE_ONE);
}
static void glm2_vec3_min(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::min(v232, GLM2_VALUE_ONE);
}
static void glm2_vec4_min(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::min(v242, GLM2_VALUE_ONE);
}
BENCHMARK(glm__vec2_min);
BENCHMARK(glm2_vec2_min);
BENCHMARK(glm__vec3_min);
BENCHMARK(glm2_vec3_min);
BENCHMARK(glm__vec4_min);
BENCHMARK(glm2_vec4_min);

static void glm__vec2_minv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::min(v122, v123);
}
static void glm__vec3_minv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::min(v132, v133);
}
static void glm__vec4_minv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::min(v142, v143);
}
static void glm2_vec2_minv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::min(v222, v223);
}
static void glm2_vec3_minv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::min(v232, v233);
}
static void glm2_vec4_minv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::min(v242, v243);
}
BENCHMARK(glm__vec2_minv);
BENCHMARK(glm2_vec2_minv);
BENCHMARK(glm__vec3_minv);
BENCHMARK(glm2_vec3_minv);
BENCHMARK(glm__vec4_minv);
BENCHMARK(glm2_vec4_minv);

static void glm__vec2_mix(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::mix(v122, v123, GLM2_VALUE_ONE);
}
static void glm__vec3_mix(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::mix(v132, v133, GLM2_VALUE_ONE);
}
static void glm__vec4_mix(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::mix(v142, v143, GLM2_VALUE_ONE);
}
static void glm2_vec2_mix(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::mix(v222, v223, GLM2_VALUE_ONE);
}
static void glm2_vec3_mix(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::mix(v232, v233, GLM2_VALUE_ONE);
}
static void glm2_vec4_mix(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::mix(v242, v243, GLM2_VALUE_ONE);
}
BENCHMARK(glm__vec2_mix);
BENCHMARK(glm2_vec2_mix);
BENCHMARK(glm__vec3_mix);
BENCHMARK(glm2_vec3_mix);
BENCHMARK(glm__vec4_mix);
BENCHMARK(glm2_vec4_mix);

static void glm__vec2_mixv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::mix(v122, v123, v124);
}
static void glm__vec3_mixv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::mix(v132, v133, v134);
}
static void glm__vec4_mixv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::mix(v142, v143, v144);
}
static void glm2_vec2_mixv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::mix(v222, v223, v224);
}
static void glm2_vec3_mixv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::mix(v232, v233, v234);
}
static void glm2_vec4_mixv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::mix(v242, v243, v244);
}
BENCHMARK(glm__vec2_mixv);
BENCHMARK(glm2_vec2_mixv);
BENCHMARK(glm__vec3_mixv);
BENCHMARK(glm2_vec3_mixv);
BENCHMARK(glm__vec4_mixv);
BENCHMARK(glm2_vec4_mixv);

static void glm__vec2_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::mod(v122, GLM2_VALUE_ONE);
}
static void glm__vec3_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::mod(v132, GLM2_VALUE_ONE);
}
static void glm__vec4_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::mod(v142, GLM2_VALUE_ONE);
}
static void glm2_vec2_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::mod(v222, GLM2_VALUE_ONE);
}
static void glm2_vec3_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::mod(v232, GLM2_VALUE_ONE);
}
static void glm2_vec4_mod(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::mod(v242, GLM2_VALUE_ONE);
}
BENCHMARK(glm__vec2_mod);
BENCHMARK(glm2_vec2_mod);
BENCHMARK(glm__vec3_mod);
BENCHMARK(glm2_vec3_mod);
BENCHMARK(glm__vec4_mod);
BENCHMARK(glm2_vec4_mod);

static void glm__vec2_modv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::mod(v122, v123);
}
static void glm__vec3_modv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::mod(v132, v133);
}
static void glm__vec4_modv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::mod(v142, v143);
}
static void glm2_vec2_modv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::mod(v222, v223);
}
static void glm2_vec3_modv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::mod(v232, v233);
}
static void glm2_vec4_modv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::mod(v242, v243);
}
BENCHMARK(glm__vec2_modv);
BENCHMARK(glm2_vec2_modv);
BENCHMARK(glm__vec3_modv);
BENCHMARK(glm2_vec3_modv);
BENCHMARK(glm__vec4_modv);
BENCHMARK(glm2_vec4_modv);

static void glm__vec2_round(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::round(v122);
}
static void glm__vec3_round(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::round(v132);
}
static void glm__vec4_round(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::round(v142);
}
static void glm2_vec2_round(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::round(v222);
}
static void glm2_vec3_round(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::round(v232);
}
static void glm2_vec4_round(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::round(v242);
}
BENCHMARK(glm__vec2_round);
BENCHMARK(glm2_vec2_round);
BENCHMARK(glm__vec3_round);
BENCHMARK(glm2_vec3_round);
BENCHMARK(glm__vec4_round);
BENCHMARK(glm2_vec4_round);

static void glm__vec2_roundEven(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::roundEven(v122);
}
static void glm__vec3_roundEven(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::roundEven(v132);
}
static void glm__vec4_roundEven(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::roundEven(v142);
}
static void glm2_vec2_roundEven(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::roundEven(v222);
}
static void glm2_vec3_roundEven(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::roundEven(v232);
}
static void glm2_vec4_roundEven(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::roundEven(v242);
}
BENCHMARK(glm__vec2_roundEven);
BENCHMARK(glm2_vec2_roundEven);
BENCHMARK(glm__vec3_roundEven);
BENCHMARK(glm2_vec3_roundEven);
BENCHMARK(glm__vec4_roundEven);
BENCHMARK(glm2_vec4_roundEven);

static void glm__vec2_sign(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::sign(v122);
}
static void glm__vec3_sign(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::sign(v132);
}
static void glm__vec4_sign(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::sign(v142);
}
static void glm2_vec2_sign(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::sign(v222);
}
static void glm2_vec3_sign(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::sign(v232);
}
static void glm2_vec4_sign(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::sign(v242);
}
BENCHMARK(glm__vec2_sign);
BENCHMARK(glm2_vec2_sign);
BENCHMARK(glm__vec3_sign);
BENCHMARK(glm2_vec3_sign);
BENCHMARK(glm__vec4_sign);
BENCHMARK(glm2_vec4_sign);

static void glm__vec2_trunc(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::trunc(v122);
}
static void glm__vec3_trunc(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::trunc(v132);
}
static void glm__vec4_trunc(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::trunc(v142);
}
static void glm2_vec2_trunc(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::trunc(v222);
}
static void glm2_vec3_trunc(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::trunc(v232);
}
static void glm2_vec4_trunc(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::trunc(v242);
}
BENCHMARK(glm__vec2_trunc);
BENCHMARK(glm2_vec2_trunc);
BENCHMARK(glm__vec3_trunc);
BENCHMARK(glm2_vec3_trunc);
BENCHMARK(glm__vec4_trunc);
BENCHMARK(glm2_vec4_trunc);

static void glm__vec2_smoothstep(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::smoothstep(GLM2_VALUE_ZERO, GLM2_VALUE_ONE, v122);
}
static void glm__vec3_smoothstep(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::smoothstep(GLM2_VALUE_ZERO, GLM2_VALUE_ONE, v132);
}
static void glm__vec4_smoothstep(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::smoothstep(GLM2_VALUE_ZERO, GLM2_VALUE_ONE, v142);
}
static void glm2_vec2_smoothstep(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::smoothstep(GLM2_VALUE_ZERO, GLM2_VALUE_ONE, v222);
}
static void glm2_vec3_smoothstep(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::smoothstep(GLM2_VALUE_ZERO, GLM2_VALUE_ONE, v232);
}
static void glm2_vec4_smoothstep(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::smoothstep(GLM2_VALUE_ZERO, GLM2_VALUE_ONE, v242);
}
BENCHMARK(glm__vec2_smoothstep);
BENCHMARK(glm2_vec2_smoothstep);
BENCHMARK(glm__vec3_smoothstep);
BENCHMARK(glm2_vec3_smoothstep);
BENCHMARK(glm__vec4_smoothstep);
BENCHMARK(glm2_vec4_smoothstep);

static void glm__vec2_smoothstepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::smoothstep(v122, v123, v124);
}
static void glm__vec3_smoothstepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::smoothstep(v132, v133, v134);
}
static void glm__vec4_smoothstepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::smoothstep(v142, v143, v144);
}
static void glm2_vec2_smoothstepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::smoothstep(v222, v223, v224);
}
static void glm2_vec3_smoothstepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::smoothstep(v232, v233, v234);
}
static void glm2_vec4_smoothstepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::smoothstep(v242, v243, v244);
}
BENCHMARK(glm__vec2_smoothstepv);
BENCHMARK(glm2_vec2_smoothstepv);
BENCHMARK(glm__vec3_smoothstepv);
BENCHMARK(glm2_vec3_smoothstepv);
BENCHMARK(glm__vec4_smoothstepv);
BENCHMARK(glm2_vec4_smoothstepv);

static void glm__vec2_step(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::step(GLM2_VALUE_ONE, v122);
}
static void glm__vec3_step(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::step(GLM2_VALUE_ONE, v132);
}
static void glm__vec4_step(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::step(GLM2_VALUE_ONE, v142);
}
static void glm2_vec2_step(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::step(GLM2_VALUE_ONE, v222);
}
static void glm2_vec3_step(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::step(GLM2_VALUE_ONE, v232);
}
static void glm2_vec4_step(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::step(GLM2_VALUE_ONE, v242);
}
BENCHMARK(glm__vec2_step);
BENCHMARK(glm2_vec2_step);
BENCHMARK(glm__vec3_step);
BENCHMARK(glm2_vec3_step);
BENCHMARK(glm__vec4_step);
BENCHMARK(glm2_vec4_step);

static void glm__vec2_stepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::step(v122, v123);
}
static void glm__vec3_stepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::step(v132, v133);
}
static void glm__vec4_stepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::step(v142, v143);
}
static void glm2_vec2_stepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::step(v222, v223);
}
static void glm2_vec3_stepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::step(v232, v233);
}
static void glm2_vec4_stepv(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::step(v242, v243);
}
BENCHMARK(glm__vec2_stepv);
BENCHMARK(glm2_vec2_stepv);
BENCHMARK(glm__vec3_stepv);
BENCHMARK(glm2_vec3_stepv);
BENCHMARK(glm__vec4_stepv);
BENCHMARK(glm2_vec4_stepv);
#endif

#ifdef GLM2_BENCHMARK_EXPONENTIAL
static void glm__vec2_sqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::sqrt(v122);
}
static void glm__vec3_sqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::sqrt(v132);
}
static void glm__vec4_sqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::sqrt(v142);
}
static void glm2_vec2_sqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::sqrt(v222);
}
static void glm2_vec3_sqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::sqrt(v232);
}
static void glm2_vec4_sqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::sqrt(v242);
}
BENCHMARK(glm__vec2_sqrt);
BENCHMARK(glm2_vec2_sqrt);
BENCHMARK(glm__vec3_sqrt);
BENCHMARK(glm2_vec3_sqrt);
BENCHMARK(glm__vec4_sqrt);
BENCHMARK(glm2_vec4_sqrt);

static void glm__vec2_inversesqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::inversesqrt(v122);
}
static void glm__vec3_inversesqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::inversesqrt(v132);
}
static void glm__vec4_inversesqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::inversesqrt(v142);
}
static void glm2_vec2_inversesqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::inversesqrt(v222);
}
static void glm2_vec3_inversesqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::inversesqrt(v232);
}
static void glm2_vec4_inversesqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::inversesqrt(v242);
}
BENCHMARK(glm__vec2_inversesqrt);
BENCHMARK(glm2_vec2_inversesqrt);
BENCHMARK(glm__vec3_inversesqrt);
BENCHMARK(glm2_vec3_inversesqrt);
BENCHMARK(glm__vec4_inversesqrt);
BENCHMARK(glm2_vec4_inversesqrt);

#ifndef GLM2_BENCHMARK_DOUBLE
static void glm2_vec2_fastInversesqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::fastInversesqrt(v222);
}
static void glm2_vec3_fastInversesqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::fastInversesqrt(v232);
}
static void glm2_vec4_fastInversesqrt(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::fastInversesqrt(v242);
}
BENCHMARK(glm2_vec2_fastInversesqrt);
BENCHMARK(glm2_vec3_fastInversesqrt);
BENCHMARK(glm2_vec4_fastInversesqrt);
#endif
#endif

#ifdef GLM2_BENCHMARK_GEOMETRIC
static void glm__vec3_cross(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::cross(v132, v133);
}
static void glm2_vec3_cross(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::cross(v232, v233);
}
BENCHMARK(glm__vec3_cross);
BENCHMARK(glm2_vec3_cross);

static void glm__vec2_length(benchmark::State& state)
{
    while(state.KeepRunning())
        f1 = glm::length(v122);
}
static void glm__vec3_length(benchmark::State& state)
{
    while(state.KeepRunning())
        f2 = glm::length(v132);
}
static void glm__vec4_length(benchmark::State& state)
{
    while(state.KeepRunning())
        f3 = glm::length(v142);
}
static void glm2_vec2_length(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::length(v222);
}
static void glm2_vec3_length(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::length(v232);
}
static void glm2_vec4_length(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::length(v242);
}
BENCHMARK(glm__vec2_length);
BENCHMARK(glm2_vec2_length);
BENCHMARK(glm__vec3_length);
BENCHMARK(glm2_vec3_length);
BENCHMARK(glm__vec4_length);
BENCHMARK(glm2_vec4_length);

static void glm__vec2_distance(benchmark::State& state)
{
    while(state.KeepRunning())
        f1 = glm::distance(v122, v123);
}
static void glm__vec3_distance(benchmark::State& state)
{
    while(state.KeepRunning())
        f2 = glm::distance(v132, v133);
}
static void glm__vec4_distance(benchmark::State& state)
{
    while(state.KeepRunning())
        f3 = glm::distance(v142, v143);
}
static void glm2_vec2_distance(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::distance(v222, v223);
}
static void glm2_vec3_distance(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::distance(v232, v233);
}
static void glm2_vec4_distance(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::distance(v242, v243);
}
BENCHMARK(glm__vec2_distance);
BENCHMARK(glm2_vec2_distance);
BENCHMARK(glm__vec3_distance);
BENCHMARK(glm2_vec3_distance);
BENCHMARK(glm__vec4_distance);
BENCHMARK(glm2_vec4_distance);

static void glm__vec2_dot(benchmark::State& state)
{
    while(state.KeepRunning())
        f1 = glm::dot(v122, v123);
}
static void glm__vec3_dot(benchmark::State& state)
{
    while(state.KeepRunning())
        f2 = glm::dot(v132, v133);
}
static void glm__vec4_dot(benchmark::State& state)
{
    while(state.KeepRunning())
        f3 = glm::dot(v142, v143);
}
static void glm2_vec2_dot(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::dot(v222, v223);
}
static void glm2_vec3_dot(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::dot(v232, v233);
}
static void glm2_vec4_dot(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::dot(v242, v243);
}
BENCHMARK(glm__vec2_dot);
BENCHMARK(glm2_vec2_dot);
BENCHMARK(glm__vec3_dot);
BENCHMARK(glm2_vec3_dot);
BENCHMARK(glm__vec4_dot);
BENCHMARK(glm2_vec4_dot);

static void glm__vec2_faceForward(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::faceforward(v122, v123, v124);
}
static void glm__vec3_faceForward(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::faceforward(v132, v133, v134);
}
static void glm__vec4_faceForward(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::faceforward(v142, v143, v144);
}
static void glm2_vec2_faceForward(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::faceforward(v222, v223, v224);
}
static void glm2_vec3_faceForward(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::faceforward(v232, v233, v234);
}
static void glm2_vec4_faceForward(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::faceforward(v242, v243, v244);
}
BENCHMARK(glm__vec2_faceForward);
BENCHMARK(glm2_vec2_faceForward);
BENCHMARK(glm__vec3_faceForward);
BENCHMARK(glm2_vec3_faceForward);
BENCHMARK(glm__vec4_faceForward);
BENCHMARK(glm2_vec4_faceForward);

static void glm__vec2_normalize(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::normalize(v122);
}
static void glm__vec3_normalize(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::normalize(v132);
}
static void glm__vec4_normalize(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::normalize(v142);
}
static void glm2_vec2_normalize(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::normalize(v222);
}
static void glm2_vec3_normalize(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::normalize(v232);
}
static void glm2_vec4_normalize(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::normalize(v242);
}
BENCHMARK(glm__vec2_normalize);
BENCHMARK(glm2_vec2_normalize);
BENCHMARK(glm__vec3_normalize);
BENCHMARK(glm2_vec3_normalize);
BENCHMARK(glm__vec4_normalize);
BENCHMARK(glm2_vec4_normalize);

#ifndef GLM2_BENCHMARK_DOUBLE
static void glm2_vec2_fastNormalize(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::fastNormalize(v222);
}
static void glm2_vec3_fastNormalize(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::fastNormalize(v232);
}
static void glm2_vec4_fastNormalize(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::fastNormalize(v242);
}
BENCHMARK(glm2_vec2_fastNormalize);
BENCHMARK(glm2_vec3_fastNormalize);
BENCHMARK(glm2_vec4_fastNormalize);
#endif

static void glm__vec2_reflect(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::reflect(v122, v123);
}
static void glm__vec3_reflect(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::reflect(v132, v133);
}
static void glm__vec4_reflect(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::reflect(v142, v143);
}
static void glm2_vec2_reflect(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::reflect(v222, v223);
}
static void glm2_vec3_reflect(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::reflect(v232, v233);
}
static void glm2_vec4_reflect(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::reflect(v242, v243);
}
BENCHMARK(glm__vec2_reflect);
BENCHMARK(glm2_vec2_reflect);
BENCHMARK(glm__vec3_reflect);
BENCHMARK(glm2_vec3_reflect);
BENCHMARK(glm__vec4_reflect);
BENCHMARK(glm2_vec4_reflect);

static void glm__vec2_refract(benchmark::State& state)
{
    while(state.KeepRunning())
        v121 = glm::refract(v122, v123, GLM2_VALUE_ONE);
}
static void glm__vec3_refract(benchmark::State& state)
{
    while(state.KeepRunning())
        v131 = glm::refract(v132, v133, GLM2_VALUE_ONE);
}
static void glm__vec4_refract(benchmark::State& state)
{
    while(state.KeepRunning())
        v141 = glm::refract(v142, v143, GLM2_VALUE_ONE);
}
static void glm2_vec2_refract(benchmark::State& state)
{
    while(state.KeepRunning())
        v221 = glm2::refract(v222, v223, GLM2_VALUE_ONE);
}
static void glm2_vec3_refract(benchmark::State& state)
{
    while(state.KeepRunning())
        v231 = glm2::refract(v232, v233, GLM2_VALUE_ONE);
}
static void glm2_vec4_refract(benchmark::State& state)
{
    while(state.KeepRunning())
        v241 = glm2::refract(v242, v243, GLM2_VALUE_ONE);
}
BENCHMARK(glm__vec2_refract);
BENCHMARK(glm2_vec2_refract);
BENCHMARK(glm__vec3_refract);
BENCHMARK(glm2_vec3_refract);
BENCHMARK(glm__vec4_refract);
BENCHMARK(glm2_vec4_refract);

#endif

#ifdef GLM2_BENCHMARK_MATRIX
static void glm__mat2x2_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = glm::transpose(m1222);
}
static void glm__mat2x3_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m1321 = glm::transpose(m1232);
}
static void glm__mat2x4_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m1421 = glm::transpose(m1242);
}
static void glm__mat3x2_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m1231 = glm::transpose(m1322);
}
static void glm__mat3x3_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = glm::transpose(m1332);
}
static void glm__mat3x4_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m1431 = glm::transpose(m1432);
}
static void glm__mat4x2_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m1241 = glm::transpose(m1422);
}
static void glm__mat4x3_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m1341 = glm::transpose(m1432);
}
static void glm__mat4x4_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = glm::transpose(m1442);
}
static void glm2_mat2x2_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = glm2::transpose(m2222);
}
static void glm2_mat2x3_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m2321 = glm2::transpose(m2232);
}
static void glm2_mat2x4_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m2421 = glm2::transpose(m2242);
}
static void glm2_mat3x2_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m2231 = glm2::transpose(m2322);
}
static void glm2_mat3x3_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = glm2::transpose(m2332);
}
static void glm2_mat3x4_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m2431 = glm2::transpose(m2342);
}
static void glm2_mat4x2_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m2241 = glm2::transpose(m2422);
}
static void glm2_mat4x3_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m2341 = glm2::transpose(m2432);
}
static void glm2_mat4x4_transpose(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = glm2::transpose(m2442);
}
BENCHMARK(glm__mat2x2_transpose);
BENCHMARK(glm2_mat2x2_transpose);
BENCHMARK(glm__mat2x3_transpose);
BENCHMARK(glm2_mat2x3_transpose);
BENCHMARK(glm__mat2x4_transpose);
BENCHMARK(glm2_mat2x4_transpose);
BENCHMARK(glm__mat3x2_transpose);
BENCHMARK(glm2_mat3x2_transpose);
BENCHMARK(glm__mat3x3_transpose);
BENCHMARK(glm2_mat3x3_transpose);
BENCHMARK(glm__mat3x4_transpose);
BENCHMARK(glm2_mat3x4_transpose);
BENCHMARK(glm__mat4x2_transpose);
BENCHMARK(glm2_mat4x2_transpose);
BENCHMARK(glm__mat4x3_transpose);
BENCHMARK(glm2_mat4x3_transpose);
BENCHMARK(glm__mat4x4_transpose);
BENCHMARK(glm2_mat4x4_transpose);

static void glm__mat2x2_determinant(benchmark::State& state)
{
    while(state.KeepRunning())
        f1 = glm::determinant(m1222);
}
static void glm__mat3x3_determinant(benchmark::State& state)
{
    while(state.KeepRunning())
        f1 = glm::determinant(m1332);
}
static void glm__mat4x4_determinant(benchmark::State& state)
{
    while(state.KeepRunning())
        f1 = glm::determinant(m1442);
}
static void glm2_mat2x2_determinant(benchmark::State& state)
{
    while(state.KeepRunning())
        f1 = glm2::determinant(m2222);
}
static void glm2_mat3x3_determinant(benchmark::State& state)
{
    while(state.KeepRunning())
        f1 = glm2::determinant(m2332);
}
static void glm2_mat4x4_determinant(benchmark::State& state)
{
    while(state.KeepRunning())
        f1 = glm2::determinant(m2442);
}
BENCHMARK(glm__mat2x2_determinant);
BENCHMARK(glm2_mat2x2_determinant);
BENCHMARK(glm__mat3x3_determinant);
BENCHMARK(glm2_mat3x3_determinant);
BENCHMARK(glm__mat4x4_determinant);
BENCHMARK(glm2_mat4x4_determinant);

static void glm__mat2x2_inverse(benchmark::State& state)
{
    while(state.KeepRunning())
        m1221 = glm::inverse(m1222);
}
static void glm__mat3x3_inverse(benchmark::State& state)
{
    while(state.KeepRunning())
        m1331 = glm::inverse(m1332);
}
static void glm__mat4x4_inverse(benchmark::State& state)
{
    while(state.KeepRunning())
        m1441 = glm::inverse(m1442);
}
static void glm2_mat2x2_inverse(benchmark::State& state)
{
    while(state.KeepRunning())
        m2221 = glm2::inverse(m2222);
}
static void glm2_mat3x3_inverse(benchmark::State& state)
{
    while(state.KeepRunning())
        m2331 = glm2::inverse(m2332);
}
static void glm2_mat4x4_inverse(benchmark::State& state)
{
    while(state.KeepRunning())
        m2441 = glm2::inverse(m2442);
}
BENCHMARK(glm__mat2x2_inverse);
BENCHMARK(glm2_mat2x2_inverse);
BENCHMARK(glm__mat3x3_inverse);
BENCHMARK(glm2_mat3x3_inverse);
BENCHMARK(glm__mat4x4_inverse);
BENCHMARK(glm2_mat4x4_inverse);
#endif

#else

glm2::vec4 v1, v2, v3, v4, v5;

static void glm__func(benchmark::State& state)
{
    while(state.KeepRunning())
    {
        v141 = m1441 * v142;
    }
}
static void glm2_func(benchmark::State& state)
{
    while(state.KeepRunning())
    {
        v241 = m2441 * v242;
    }
}
BENCHMARK(glm__func);
BENCHMARK(glm2_func);

#endif

int main(int argc, char** argv)
{
    benchmark::Initialize(&argc, argv);
    if(benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
    benchmark::RunSpecifiedBenchmarks();
    benchmark::Shutdown();
    return 0;
}
