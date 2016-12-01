#ifndef IMAGE_H_BH2ZALMC
#define IMAGE_H_BH2ZALMC


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
    void load(std::string const& path);

    /// store the image in the file \var path, will overwrite
    void save(std::string const& path);


private:
    std::vector<byte> _raw_data; ///< byte data, representing the image pixels
};

#endif /* end of include guard: IMAGE_H_BH2ZALMC */
