#include <iostream>
#include <vector>
#include <image.hpp>
#include <kernel.hpp>

int main()
{
    kernel::Image  lenna{"../resources/lenna.jpeg"};
    kernel::Kernel edge{kernel::Kernels::EDGE};
    kernel::Kernel blur{kernel::Kernels::BLUR};

    kernel::Image gray_lenna    = lenna.GrayScale();
    kernel::Image edge_lenna    = gray_lenna.Convolution(edge);
    kernel::Image blurred_lenna = lenna.Convolution(blur);
    
    gray_lenna.Save("../resources/gray_lenna.jpg");
    edge_lenna.Save("../resources/edge_lenna.jpg");
    blurred_lenna.Save("../resources/blurred_lenna.jpg");

    return 0;
}