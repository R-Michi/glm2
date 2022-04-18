# description
This library is an performance-improved version of glm, completely written from scratch, named glm2.
It's aim is to implement all GLSL functions as performance optimized as possible.
As this library is header only, it allowes the compiler to inline very aggressively.
Nearly all functions combute faster then the glm counterparts (NOTE: all benchmarks were only run on my PC !!!).

# building
This library is header only, so it doesn't have to be built.
All the sources, as well as the main include file, are located inside the "./glm2" folder.
The main include file is also named "glm2".
If you want to run the test or benchmark, you have to install the glm and google benchmark library.
1) Download the glm library and google benchmark library from github:
    - https://github.com/g-truc/glm
    - https://github.com/google/benchmark
2) Build both libraries to a static library.
3) Crate a folder called "lib" inside the glm2 project.
4) You must create folling structure inside the "lib" folder:
    ./lib
     +- benchmark
     |   +- include
     |   |   +- benchmark.h
     |   |   +- export.h
     |   +- lib
     |       +- benchmark.lib
     +- glm
         +- glm
             +- <all glm source and header files>
5) Open the project in VisualStudio as CMAKE project and run build.
   NOTE: The benchmark requieres realease mode.
6) Run benchmark.exe or run test.exe.

# version
Version: 1.0.0-dev-1
NOTE: This library hasn't been completed yet, not even it's core functionality!

# requirements
- To run this library your CPU must at least be capable of AVX2 and FMA!
  If your CPU does not support AVX2 or FMA you will not be able to execute every function.
- For compilation you must enable AVX2 and FMA via the compiler flags "-mavx2" and "-mfma"!

# TODO
- implement all functions that require integer vectors
- implement transpose of 2x3-, 2x4-, 3x2-, 3x4-, 4x2-, 4x3 matrix
- implement matrix transformation functions (perspective, lookAt, etc.)
- implement packing functions
- implement vector relational functions
- implement extended features (for example: noise and intersect functions)
