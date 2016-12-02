# we want the operations fullfilled with OpenCl
find_package(OpenCL REQUIRED)
include_directories(${OPENCL_INCLUDE_DIR})

add_library(color_conversion STATIC
    BlackWhite.cpp)

target_link_libraries(color_conversion
    ${OPENCL_LIBRARIES})
