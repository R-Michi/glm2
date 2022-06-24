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
&emsp;|&emsp;&nbsp;&emsp;+- benchmark.lib  
&emsp;+- glm  
&emsp;&nbsp;&emsp;+- glm  
&emsp;&nbsp;&emsp;&emsp;+- lib  
&emsp;&nbsp;&emsp;&nbsp;&emsp;|&emsp;+- glm_static.lib  
&emsp;&nbsp;&emsp;&nbsp;&emsp;+- [all glm source and header files]  
5) Open the project in VisualStudio as CMAKE project and run build.
   NOTE: The benchmark requieres realease mode.
6) Run benchmark.exe or run test.exe.

# version
Version: 1.0.0-dev-3
NOTE: This library hasn't been completed yet, not even it's core functionality!

# v1.0.0-dev-3
- removed type-pointer assignment operator from vector and matrix
- added .load() methods for vector and matrix instead of the type-pointer assignment operator
- added .store() methods for vector and matrix, its the oppisite of .load()
- To load data via pointer into a vector or matrix, the pointer had to be aligned to some number of bytes.
  This was a bug and is now fixed. Therefore .load() and .store() don't need any specific alignment.
  Moreover .load() and .store() for matrices don't requiere padding values inbetween vectors any more (especially inbetween vec3s).
  However, at the very end of a buffer is one padding value requiered (especially for vec3, and matrices that contain vec3s).
- Made constructors explicit that are the equivalent of the .load() methods.
- Changed the function operator 'operator()', which returned the internal intrinsic value, to the method .intrinsic().
- Changed the method .si128(), which returned an __m128 for 2-component-vector-types, to .intrinsicEXT().
- Improved integer functions: findLSB(), uaddCarry(), usubBorrow()

# requirements
- To run this library your CPU must at least be capable of the AVX2, FMA and F16C instruction set!
  If your CPU does not support AVX2, FMA or F16C you will not be able to execute every function.
- For compilation you must enable AVX2, FMA and F16C via the compiler flags "-mavx2", "-mfma", "-mf16c"!

# TODO
- implement matrix transformation functions (perspective, lookAt, etc.)
- implement extended features

# functions or operations where my library performs worse:
- transpose mat3
- dmat4x3 & double add, sub, mul, div
- dmat4x3 & dmat4x3 add, sub
- dmat4x3 inc, dec, neg, pos
- ivecX div, mod
- ivec2 bitCount
- uvec2 bitCount
