/**
* @file     main.cpp
* @brief    main file
* @author   Github: R-Michi
* Copyright (c) 2022 by R-Michi
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#define GLM2_IMPLEMENTATION
#define GLM2_FORCE_INLINE
#include "glm2/glm2.h"

int main()
{
    float i;
    float fract = std::modff(6.879f, &i);
    std::cout << fract << "   " << i << std::endl;
    return 0;
}
