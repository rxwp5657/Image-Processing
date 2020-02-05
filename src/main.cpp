#include <iostream>
#include <vector>
#include <chrono>
#include <image.hpp>
#include <kernel.hpp>

int main()
{
    kernel::Image  lenna_s{"../resources/lenna-small.jpg"};
    kernel::Image  lenna_m{"../resources/lenna-medium.jpeg"};
    kernel::Image  lenna_l{"../resources/lenna-large.jpg"};

    auto lenna_s_g = lenna_s.GrayScale();
    auto lenna_m_g = lenna_m.GrayScale();
    auto lenna_l_g = lenna_l.GrayScale();

    kernel::Kernel edge{kernel::Kernels::EDGE};

    auto start = std::chrono::steady_clock::now();
    auto lenna_s_e = lenna_s_g.Convolution(edge);
    auto end = std::chrono::steady_clock::now();

    std::cout << "Lenna small elapsed time : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
    << "ms\n";

    start = std::chrono::steady_clock::now();
    auto lenna_m_e = lenna_m_g.Convolution(edge);
    end = std::chrono::steady_clock::now();

    std::cout << "Lenna medium elapsed time : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
    << "ms\n";

    start = std::chrono::steady_clock::now();
    auto lenna_l_e = lenna_l_g.Convolution(edge);
    end = std::chrono::steady_clock::now();

    std::cout << "Lenna large elapsed time : " << 
    std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
    << "ms\n";

    lenna_s_e.Save("../resources/lenna_s_edge.jpg");
    lenna_m_e.Save("../resources/lenna_m_edge.jpg");
    lenna_l_e.Save("../resources/lenna_l_edge.jpg");

    return 0;
}