#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>
#include <iostream>
#include <stb_image.h>
#include <stb_image_write.h>

namespace kernel
{
    struct Pixel
    {
        unsigned char r;
        unsigned char g;
        unsigned char b;
        unsigned char a;
    };

    class Image
    {
    public:
        Image(const std::string& image_name);
        Image(int width, int height, int nr_channels, const std::vector<Pixel>& image);

        Image GrayScale();
        void  Save(const std::string& image_name);

    private:
        std::vector<Pixel> image_;
        int width_; 
        int height_; 
        int nr_channels_;
    };
}


#endif