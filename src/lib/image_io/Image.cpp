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


/// @param path filepath, that will be forwarded to stbi_image
/// @param channels number of channels, 1 = gray, 2 = gray_alpha, 3 = rgb, 4 = rgba
void Image::load(std::string const& path, int channels)
{
    // interfacing c library
    int img_width, img_height, img_channels;
    auto* pixel_data =
        stbi_load(path.c_str(), &img_width, &img_height, &img_channels, channels);

    // loading failed
    if(pixel_data == nullptr)
        throw std::runtime_error{"Could not load image, check the path!"};

    // we didnt get what we want
    if(img_channels != channels) {
        stbi_image_free(pixel_data);
        throw std::runtime_error{"Image channelcount does not match!"};
    }

    // converting to cpp, basically copying the data into a vector
    auto byte_count = img_width * img_height * img_channels;

    // make space for the data we need, clear old image if existing
    _raw_data.clear();
    _raw_data.reserve(byte_count);

    // copy unsigned char to byte, typesafety :) 
    for(auto byte: gsl::span<unsigned char>(pixel_data, byte_count))
        _raw_data.push_back(gsl::to_byte(byte));

    // clean up, what c left behind
    stbi_image_free(pixel_data);

    // setting the property values correctly
    _width = img_width;
    _height = img_height;
    _channels = img_channels;
}

void Image::save(std::string const& path)
{
    throw std::runtime_error{"Not implemented yet!"};
}
