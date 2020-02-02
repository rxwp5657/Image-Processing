#include <image.hpp>

namespace kernel
{
    Image::Image(const std::string& image_name)
    {
        unsigned char *data = stbi_load(image_name.c_str(), &width_, &height_, &nr_channels_, 0);
        
        if(!data)
            throw std::runtime_error("Unable to load image \n");
        
        int img_size = width_ * height_ * nr_channels_;

        for(unsigned char *img = data; img != data + img_size; img += nr_channels_)
        {
            unsigned char r = static_cast<unsigned char>(*img);
            unsigned char g = static_cast<unsigned char>(*(img + 1));
            unsigned char b = static_cast<unsigned char>(*(img + 2));
            unsigned char a = nr_channels_ == 4 ? static_cast<int>(*(img + 3)) : 1;

            Pixel pixel{r, g, b, a};

            image_.push_back(pixel);
        }

        stbi_image_free(data);
    }

    Image::Image(int width, int height, int nr_channels, const std::vector<Pixel>& image)
    : image_{image},
      width_{width},
      height_{height},
      nr_channels_{nr_channels}
    {

    }

    Image Image::GrayScale()
    {
        std::vector<Pixel> gray_image;
        int num_chan = nr_channels_ == 4 ? 2 : 1;

        for(auto& pixel : image_)
        {
            // Luminous algorithm :
            // Gray = (Red * 0.3 + Green * 0.59 + Blue * 0.11)

            auto r = static_cast<unsigned char>(0.4  * pixel.r);  
            auto g = static_cast<unsigned char>(0.59 * pixel.g);
            auto b = static_cast<unsigned char>(0.11 * pixel.b);
            auto a = static_cast<unsigned char>(1.0);
            auto gray = static_cast<unsigned char>(r + g + b);

            Pixel gray_pixel{gray, gray, gray, a};

            gray_image.push_back(gray_pixel);
        }

        return Image{width_, height_, num_chan, gray_image};
    }

    void Image::Save(const std::string& image_name)
    {
        std::vector<unsigned char> temp_image;
        
        for(auto& pixel : image_)
        {
            temp_image.push_back(pixel.r);
            if(nr_channels_ >= 3)
            {
                temp_image.push_back(pixel.g);
                temp_image.push_back(pixel.b);
            }
            if(nr_channels_ == 4 || nr_channels_ == 2)
                temp_image.push_back(pixel.a); 
        }
        
        stbi_write_jpg(image_name.c_str(), width_, height_, nr_channels_, &temp_image[0], 100);
    }
}