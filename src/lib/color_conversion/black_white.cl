// convert an image from rgb to grayscale
__kernel void convert_rgb2bw(__read_only image2d_t src, __write_only image2d_t dest)
{
    const int2 pos = {get_global_id(0), get_global_id(1)};

    uint4 pixel_color = read_imageui(src, pos);

    // https://en.wikipedia.org/wiki/Grayscale#Colorimetric_.28luminance-preserving.29_conversion_to_grayscale
    uint4 gray = {0.2126 * pixel_color.x + 0.7152 * pixel_color.y
                  + 0.0722 * pixel_color.z,
                  0, 0, 0};

    write_imageui(dest, pos, gray);
}
