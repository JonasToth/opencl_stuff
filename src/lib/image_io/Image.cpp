#include "Image.h"

// include stb files, taken from here:
// https://github.com/nothings/stb/blob/master/stb_image.h
// https://github.com/serge-rgb/TinyJPEG/blob/master/tiny_jpeg.h


#define TJE_IMPLEMENTATION
#include "tiny_jpeg.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


#include <stdexcept>


// ============================= CLASS IMPLEMENTATION ====================================


Image::Image(std::string const& path)
    : _raw_data()
{
    load(path);
}


void Image::load(std::string const& path)
{
    throw std::runtime_error{"Not implemented yet!"};
}

void Image::save(std::string const& path)
{
    throw std::runtime_error{"Not implemented yet!"};
}
