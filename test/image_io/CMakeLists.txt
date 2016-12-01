
include_directories(${PROJECT_SOURCE_DIR}/src/lib)


# EXECTUABLE-MARKER-START
add_executable(image_io_load.x test_image_load.cpp)
target_link_libraries(image_io_load.x image_io)
# EXECUTABLE-MARKER-END

# TEST-MARKER-START

# TEST-MARKER-END
