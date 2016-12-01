
include_directories(${PROJECT_SOURCE_DIR}/src/lib)

enable_testing()

# EXECTUABLE-MARKER-START
add_executable(image_io_load.x test_image_load.cpp)
target_link_libraries(image_io_load.x image_io)
# EXECUTABLE-MARKER-END

# TEST-MARKER-START
add_test(image_io_load.x test/image_io/image_io_load.x)
# TEST-MARKER-END
