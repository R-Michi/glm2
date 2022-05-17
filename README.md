# description
This library is an performance-improved version of glm, completely written from scratch, named glm2.
It's aim is to implement all GLSL functions as performance optimized as possible, especially floating-point arithmetic.
As this library is header only, it allowes the compiler to inline very aggressively.
Nearly all functions combute faster then the glm counterparts (NOTE: all benchmarks were only run on my PC !!!).
You will find a list of functions that combute slower in my library at the very bottom of this file.

# building
This library is header only, so it doesn't have to be built.
All the sources, as well as the main include file, are located inside the "./glm2" folder.
The main include file is also named "glm2.h".
If you want to run the test or benchmark, you have to install the glm and google benchmark library.
1) Download the glm library and google benchmark library from github:
    - https://github.com/g-truc/glm
    - https://github.com/google/benchmark
2) Build both libraries to a static library.
3) Crate a folder called "lib" inside the glm2 project.
4) You must create folling structure inside the "lib" folder:
&emsp;./lib  
&emsp;+- benchmark  
&emsp;|&emsp;+- include  
&emsp;|&emsp;|&emsp;+- benchmark.h  
&emsp;|&emsp;|&emsp;+- export.h  
&emsp;|&emsp;+- lib  
&emsp;|&emsp;&emsp;+- benchmark.lib  
&emsp;+- glm  
&emsp;&emsp;+- glm  
&emsp;&emsp;&emsp;+- [all glm source and header files]
5) Open the project in VisualStudio as CMAKE project and run build.
   NOTE: The benchmark requieres realease mode.
6) Run benchmark.exe or run test.exe.

# version
Version: 1.0.0-dev-2
NOTE: This library hasn't been completed yet, not even it's core functionality!

# requirements
- To run this library your CPU must at least be capable of the AVX2, FMA and F16C instruction set!
  If your CPU does not support AVX2, FMA or F16C you will not be able to execute every function.
- For compilation you must enable AVX2, FMA and F16C via the compiler flags "-mavx2", "-mfma", "-mf16c"!

# TODO
- implement matrix transformation functions (perspective, lookAt, etc.)
- implement extended features (for example: noise and intersect functions)

# functions or operations where my library performs worse:
- transpose mat3
- dmat4x3 & double add, sub, mul, div
- dmat4x3 & dmat4x3 add, sub
- dmat4x3 inc, dec, neg, pos
- ivecX div, mod
- ivec2 bitCount
- uvec2 bitCount
- uvec2 findLSB
- uvec2 uaddCarry
- uvec2 usubBorrow
- ivec2 imulExtended
- uvec2 umulExtended
