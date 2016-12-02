
include_directories(${PROJECT_SOURCE_DIR}/src/lib)

# EXECTUABLE-MARKER-START
add_executable(black_white.x test_black_white.cpp)
target_link_libraries(black_white.x ${GTEST_LIBRARIES} pthread)
target_link_libraries(black_white.x color_conversion image_io)

add_executable(cl_info.x test_cl_info.cpp)
target_link_libraries(cl_info.x ${GTEST_LIBRARIES} pthread)
target_link_libraries(cl_info.x color_conversion)

# EXECUTABLE-MARKER-END

# TEST-MARKER-START
add_test(test_black_white black_white.x)
add_test(test_cl_info cl_info.x)
# TEST-MARKER-END
