cmake_minimum_required(VERSION 3.5)



add_definitions("--std=c++14")


# this file bundles are subdirectories and parts of the project
#
# it provides common build targets

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(benchmark)
