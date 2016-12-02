#include <CL/cl.hpp>
#include <gtest/gtest.h>
#include <iostream>
#include <vector>


TEST(OpenClInfo, BasicFunctionality)
{
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    EXPECT_TRUE(platforms.size() > 0);
}

TEST(OpenClInfo, DefaultPlatform)
{
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    ASSERT_GT(platforms.size(), 0) << "No platforms available";

    cl::Platform default_platform = platforms[0];
    std::string default_plat_name = default_platform.getInfo<CL_PLATFORM_NAME>();
    std::cout << "Default Platform is: " << default_plat_name << std::endl;

    std::vector<cl::Device> all_devices;
    default_platform.getDevices(CL_DEVICE_TYPE_ALL, &all_devices);

    ASSERT_GT(all_devices.size(), 0) << "No devices on the platform available";
}

TEST(OpenClInfo, Devices)
{
    std::vector<cl::Platform> platforms;
    cl::Platform::get(&platforms);

    ASSERT_GT(platforms.size(), 0) << "No platforms available";
    std::cout << "Number of Platforms " << platforms.size() << std::endl;
    cl::Platform default_platform = platforms[0];
    std::cout << "Default Platform is: " << default_platform.getInfo<CL_PLATFORM_NAME>()
              << std::endl;

    std::vector<cl::Device> all_cpus;
    platforms[1].getDevices(CL_DEVICE_TYPE_CPU, &all_cpus);
    ASSERT_GT(all_cpus.size(), 0) << "No CPUs on the platform available";

    std::vector<cl::Device> all_gpus;
    platforms[0].getDevices(CL_DEVICE_TYPE_GPU, &all_gpus);
    ASSERT_GT(all_gpus.size(), 0) << "No CPUs on the platform available";
}


int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
