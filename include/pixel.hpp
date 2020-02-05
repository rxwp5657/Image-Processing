#ifndef PIXEL_H
#define PIXEL_H

namespace kernel
{
    template<typename T>
    struct Pixel
    {
        T r;
        T g;
        T b;
        T a;

        inline Pixel<T>& operator+=(const Pixel<T>& a) noexcept
        {
            r = static_cast<T>(r + a.r);
            g = static_cast<T>(g + a.g);
            b = static_cast<T>(b + a.b);

            return *this;
        }


        inline Pixel<T>& operator*=(const float val) noexcept
        {
            r = static_cast<T>(r * val);
            g = static_cast<T>(g * val);
            b = static_cast<T>(b * val);

            return *this;
        }
    };

    template <typename T>
    unsigned char Truncate(T val)
    {   
        if(val > 255)
            return 255;
        else if(val < 0)
            return 0;
        
        return val;
    }

    template<typename T>
    Pixel<unsigned char> ToPixel(const Pixel<T>& pixel)
    {
        return Pixel<unsigned char>{Truncate(pixel.r), Truncate(pixel.g), Truncate(pixel.b), 1};
    }
}

#endif