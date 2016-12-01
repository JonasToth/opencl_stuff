#include "image_io/Image.h"
#include <iostream>

/// testload of an jpg
int main()
{
    // everything alright for the moment
    int error_code = 0;

    // ======================== Load over constructor ====================================
    try {
        auto img = Image("test_load.jpg");
        std::cout << "Success from constructor!" << std::endl;

        if(img.width() != 172) {
            std::cout << "Width is wrong" << std::endl;
            error_code = 1;
        }
        if(img.height() != 178) {
            std::cout << "Height is wrong" << std::endl;
            error_code = 1;
        }
    } catch(std::runtime_error& e) {
        std::cout << "Failed to load image!" << std::endl;
        std::cout << e.what() << std::endl;
        error_code = 1;
    }


    // ====================== Load with member function ==================================
    try {
        auto img = Image();
        img.load("test_load.jpg");
        std::cout << "Success from member function!" << std::endl;

        if(img.width() != 172) {
            std::cout << "Width is wrong" << std::endl;
            error_code = 1;
        }
        if(img.height() != 178) {
            std::cout << "Height is wrong" << std::endl;
            error_code = 1;
        }
    } catch(std::runtime_error& e) {
        std::cout << "Failed to load image over member function!" << std::endl;
        std::cout << e.what() << std::endl;
        error_code = 1;
    }

    return error_code;
}
