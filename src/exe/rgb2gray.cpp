#include "CL/cl.hpp"
#include "image_io/Image.h"
#include <iostream>
#include <vector>


int main(int argc, char** argv)
{
    if(argc <= 1) {
        std::cerr << "Usage: " << argv[0] << " <list-of-filenames(jpg)>" << std::endl;
        return -1;
    }

    // setup opencl
    // platform
    std::vector<cl::Platform> all_plats;
    cl::Platform::get(&all_plats);

    if(all_plats.size() == 0) {
        std::cerr << "No opencl platforms found. Check installation" << std::endl;
        return -1;
    }
    cl::Platform default_plat = all_plats[0];
    std::cout << "Using platform: " << default_plat.getInfo<CL_PLATFORM_NAME>()
              << std::endl;

    // device
    std::vector<cl::Device> all_devs;
    default_plat.getDevices(CL_DEVICE_TYPE_ALL, &all_devs);
    if(all_devs.size() == 0) {
        std::cerr << "No devices found for platform. Bad" << std::endl;
        return -1;
    }
    cl::Device dd = all_devs[0];
    std::cout << "Using device: " << dd.getInfo<CL_DEVICE_NAME>() << std::endl;
    cl::Context ctxt({dd});


    // my source code kernel
    std::string code =
        "__kernel void"
        "convert_rgb2bw(__read_only image2d_t src, __write_only image2d_t dest)"
        "{"
        "const int2 pos = {get_global_id(0), get_global_id(1)};"
        "uint4 pixel_color = read_imageui(src, pos);"
        "uint4 gray = {0.2126 * pixel_color.x + 0.7152 * pixel_color.y"
        "+ 0.0722 * pixel_color.z, 0, 0, 0};"
        "write_imageui(dest, pos, gray);"
        "}";
    cl::Program::Sources sources;
    sources.push_back({code.c_str(), code.size()});
	
    cl::Program prog(ctxt, sources);
    if(prog.build({dd}) != CL_SUCCESS){
        std::cerr << "Error on kernel build:" << std::endl;
        std::cerr << prog.getBuildInfo<CL_PROGRAMM_BUILD_LOG>(dd) << std::endl;
        return -1;
    }
}
