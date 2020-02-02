#include <iostream>
#include <image.hpp>

int main()
{
    kernel::Image lenna{"../resources/lenna.jpeg"};
    kernel::Image gray_lenna = lenna.GrayScale();
    gray_lenna.Save("../resources/gray_lenna.jpg");
    lenna.Save("../resources/gray_lenna3.jpg");
    return 0;
}