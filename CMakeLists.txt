cmake_minimum_required(VERSION 3.7)

# Project
project(Algorithms-and-Data-Structures)

# C++ version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include self
include_directories("src")

# Create library for the main files
add_library(Algorithms-and-Data-Structures
	"src/list.hpp"
	"src/array_list.hpp"
	"src/array_list.imp.hpp"
	"src/binary_search.cpp"
)

# Create examples
add_executable(Array-List "examples/array_list.cpp")
target_link_libraries(Array-List Algorithms-and-Data-Structures)
add_dependencies(Array-List Algorithms-and-Data-Structures)