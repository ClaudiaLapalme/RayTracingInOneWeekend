//
// Created by claul on 6/7/2020.
//

#include "../Headers/main.h"

int main() {
    main::printImage(256, 256);
}

void main::printImage(const int image_width, const int image_height) {

    std::ofstream out("..\\Output\\helloWorld.ppm");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; j--) { // top to bottom
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; i++) { // left to right
            auto r = static_cast<double>(i) / (image_width - 1);
            auto g = static_cast<double>(j) / (image_height - 1);
            auto b = 0.25;

            int ir = static_cast<int> (255.999 * r);
            int ig = static_cast<int> (255.999 * g);
            int ib = static_cast<int> (255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
        }
    }
    std::cout.rdbuf(coutbuf); //reset to standard output again
    std::cerr << "\nThe image has been produced.\n";
}
