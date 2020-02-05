#ifndef KERNEL_H
#define KERNEL_H

#include <vector>

namespace kernel
{
    enum class Kernels
    {
        EDGE,
        BLUR
    };

    class Kernel
    {
    public:
        Kernel(unsigned int width,
               const std::vector<int>& mask, 
               float factor = 1);
        
        Kernel(Kernels kernel_type);
               
        inline int Get(unsigned int i, unsigned int j) const
        {
            assert(i < width_ && j < width_);
            return mask_[i * width_ + j];
        }

        inline unsigned int Size() const noexcept
        {
            return width_;
        }

        inline float Factor() const noexcept
        {
            return factor_;
        }

    private:
        unsigned int width_;
        std::vector<int> mask_;
        float factor_;
    };
}

#endif