#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>
#include <iostream>
#include <stb_image.h>
#include <stb_image_write.h>
#include <pixel.hpp>
#include <kernel.hpp>

namespace kernel
{   
    class Image
    {
    public:
        Image(const std::string& image_name);
        Image(int width, int height, int nr_channels, const std::vector<Pixel<unsigned char>>& image);

        Image GrayScale() noexcept;
        Image Convolution(const Kernel& mask) noexcept;
        void  Save(const std::string& image_name);

    private:
        std::vector<Pixel<unsigned char>> image_;
        int width_; 
        int height_; 
        int nr_channels_;

        Pixel<unsigned char> Convoluted(unsigned int r, 
                                        unsigned int c, 
                                        const Kernel& kernel) noexcept;

        inline Pixel<unsigned char> Get(unsigned int i, unsigned int j)
        {
            if(i < 0 || i > width_ || j < 0 || j > height_)
                return Pixel<unsigned char>{0, 0, 0, 1};

            return image_[i * height_ + j];
        }
    };

    template<typename T>
    auto inline operator*(const Pixel<T>& pixel, int value) noexcept
    -> Pixel<decltype(pixel.r * value)>
    {
        typedef decltype(pixel.r * value) t_result;
        auto r = static_cast<t_result>(pixel.r * value);
        auto g = static_cast<t_result>(pixel.g * value);
        auto b = static_cast<t_result>(pixel.b * value);
        return Pixel<t_result>{r, g, b,1};
    }
}


#endif