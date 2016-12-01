#ifndef IMAGE_H_BH2ZALMC
#define IMAGE_H_BH2ZALMC


#include <gsl/gsl>
#include <string>
#include <vector>


class Image
{
public:
    // ===================================================================================
    // _________________________________ CONSTRUCTORS ____________________________________
    // ===================================================================================


    /// empty image, no allocation whatsoever
    Image() = default;

    /// load image from diskspace
    Image(std::string const& path);

    // ___________________________________ COPY __________________________________________

    // ___________________________________ MOVE __________________________________________

    // ___________________________________ DESTRUCT ______________________________________

    ~Image() = default;


    // ===================================================================================
    // ____________________________________ INTERFACE ____________________________________
    // ===================================================================================

    /// load a jpg from path specified in \var path
    void load(std::string const& path, int channels = 3);

    /// store the image in the file \var path, will overwrite
    void save(std::string const& path);

    /// return pixel value of width, 0 for not existing image
    std::size_t width() const noexcept { return _width; }

    /// return pixel value of height, 0 for not existing image
    std::size_t height() const noexcept { return _height; }


private:
    std::size_t _width;  ///< width of the image, returned by load function
    std::size_t _height; ///< height of the image, returned by load function
    short _channels;     ///< number of channels (1-gray,2-grayalpha,3-rgb,4-rgba)
    std::vector<gsl::byte> _raw_data; ///< byte data, representing the image pixels
};

#endif /* end of include guard: IMAGE_H_BH2ZALMC */
