#include <CL/cl.hpp>
#include <iostream>
#include <vector>


int main() { 
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);
    return 0; 
}
