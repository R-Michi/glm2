# requiered CMAKE version to build the project
cmake_minimum_required (VERSION 3.8)

# current project
project ("glm2")

# set comiler flags
set(CMAKE_CXX_STANDARD 17)
add_compile_options(-save-temps -mfma -mavx2)

# add subdirectories
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test")
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/benchmark")

# compile and link final executable
add_executable(glm2 "main.cpp")

# additional work
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
