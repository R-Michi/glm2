/**
* @file     constants.h
* @brief    Useful mathematical and other constants.
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#pragma once

/// Useful mathematical constants
#define GLM2_1_3            0.333333333333333333333     // 1/3
#define GLM2_2_3            0.666666666666666666667     // 2/3
#define GLM2_E              2.71828182845904523536      // e
#define GLM2_EULER          0.577215664901532860606     // euler constant
#define GLM2_PI             3.14159265358979323846      // pi
#define GLM2_2PI            6.28318530717958647692      // 2*pi
#define GLM2_4PI            12.5663706143591729538      // 4*pi
#define GLM2_PI_2           1.57079632679489661923      // pi/2
#define GLM2_PI_4           0.785398163397448309616     // pi/4
#define GLM2_PI_180         0.017453292519943295769     // pi/180
#define GLM2_3PI_2          4.712388980384689857693     // (3*pi)/2
#define GLM2_1_PI           0.318309886183790671538     // 1/pi
#define GLM2_2_PI           0.636619772367581343076     // 2/pi
#define GLM2_4_PI           1.27323954473516268615      // 4/pi
#define GLM2_180_PI         57.2957795130823208767      // 180/pi
#define GLM2_1_2PI          0.159154943091895335768     // 1/(2*pi)
#define GLM2_SQRT2          1.41421356237309504880      // sqrt(2)
#define GLM2_SQRT3          1.73205080756887729352      // sqrt(3)
#define GLM2_SQRT5          2.23606797749978969640      // sqrt(5)
#define GLM2_SQRTPI         1.77245385090551602729      // sqrt(pi)
#define GLM2_SQRT2PI        2.50662827463100050241      // sqrt(2*pi)
#define GLM2_SQRTPI_2       1.25331413731550025120      // sqrt(pi/2)
#define GLM2_1_SQRT2        0.707106781186547524401     // 1/sqrt(2)
#define GLM2_2_SQRTPI       1.12837916709551257390      // 2/sqrt(pi)
#define GLM2_SQRT_LN4       1.17741002251547469101      // sqrt(ln(4))
#define GLM2_LN2            0.693147180559945309417     // ln(2)
#define GLM2_LN10           2.30258509299404568402      // ln(10)
#define GLM2_LN_LN2         -0.366512920581664327012    // ln(ln(2))
#define GLM2_LOG2E          1.44269504088896340736      // log2(e)
#define GLM2_LOG10E         0.434294481903251827651     // log10(e)
#define GLM2_GOLDEN_RATIO   1.61803398874989484820      // golden ratio

// Component constants
#define GLM2_X  0
#define GLM2_Y  1
#define GLM2_Z  2
#define GLM2_W  3
#define GLM2_R  GLM2_X
#define GLM2_G  GLM2_Y
#define GLM2_B  GLM2_Z
#define GLM2_A  GLM2_W

/// Swizzle constants
#define GLM2_SWIZZLE_X  GLM2_X
#define GLM2_SWIZZLE_Y  GLM2_Y
#define GLM2_SWIZZLE_Z  GLM2_Z
#define GLM2_SWIZZLE_W  GLM2_W
#define GLM2_SWIZZLE_R  GLM2_R
#define GLM2_SWIZZLE_G  GLM2_G
#define GLM2_SWIZZLE_B  GLM2_B
#define GLM2_SWIZZLE_A  GLM2_A

/// Boolean constants
/// bool uses in GLSL 32 bits
#define GLM2_FALSE  0x00000000
#define GLM2_TRUE   0xFFFFFFFF
