#include <kernel.hpp>

namespace kernel
{
    Kernel::Kernel(unsigned int width,
                   const std::vector<int>& mask,
                   float factor)
    : width_{width},
      mask_{mask},
      factor_{factor}
    {
    }

    Kernel::Kernel(Kernels kernel_type)
    {
        switch (kernel_type)
        {
        case Kernels::BLUR:
            width_ = 3;
            mask_  = std::vector<int>{ 1,  2, 1, 2, 4, 2, 1, 2, 1};
            factor_ = 1.0f / 16.0f;
          break;
        case Kernels::EDGE:
            width_  = 3;
            mask_   = std::vector<int>{0, 1, 0, 1, -4, 1, 0, 1, 0};
            factor_ = 1;
          break;
        default:
            width_  = 3;
            mask_   = std::vector<int>{0, 0, 0, 0, 1, 0, 0, 0, 0};
            factor_ = 1;
          break;
        }
    }
}