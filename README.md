# Goal

I study computer science and try to get an idea of gpgpu programming.
This repository is aimed at that: try it out and see what happens.

Furthermore, this might benefit myself in my bachelorthesis, since i understand things 
better after programming them.

Feel free to get inspired, if you can correct me DO IT.


## Source

This list is not comprehensive, but i used these sites and found them helpfull.

[Erik Mistad's tutorial](https://www.eriksmistad.no/gaussian-blur-using-opencl-and-the-built-in-images-textures/)

## Requirements

This is a list of tools i had to install. This is not comprehensive, but might give you nice hints :)
I am running ubuntu 16.04
### packets
- build-essential
- cmake
- libgtest-dev # googles testing framework

### libraries
- [GSL](https://github.com/Microsoft/GSL) as system library (IMPORTANT, CMake won't check for it!)
- [tiny-jpeg](https://github.com/serge-rgb/TinyJPEG) thats in the repo
- [stb-image](https://github.com/nothings/stb/blob/master/stb_image.h) in the repo as well
