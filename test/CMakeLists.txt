
# bundles exectuables for all subprojects/sublibs, will be modified with a script
# do not modify markers!

enable_testing()

# testing only for the library atm
include_directories(${PROJECT_SOURCE_DIR}/src/lib)

# SUBDIR-MARKER-START
add_subdirectory(image_io)
# SUBDIR-MARKER-END
