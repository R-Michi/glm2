# requiered CMAKE version to build the project
cmake_minimum_required (VERSION 3.8)

# current project
project ("glm2_benchmark")

# set comiler flags
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-save-temps -mfma -mavx2 -mf16c)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/glm)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/benchmark/include)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/glm/glm/lib)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../lib/benchmark/lib)

# compile and link final executable
add_executable(glm2_benchmark
    "main.cpp" 
)

target_link_libraries(glm2_benchmark PRIVATE "-lglm_static")
target_link_libraries(glm2_benchmark PRIVATE "-lbenchmark")

# additional work
set(CMAKE_EXPORT_COMPILE_COMMANDS on)