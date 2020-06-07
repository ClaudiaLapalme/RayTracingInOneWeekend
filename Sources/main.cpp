//
// Created by claul on 6/7/2020.
//

#include "../Headers/main.h"
#include "../Headers/Utilities/vec3.h"
#include "../Headers/Utilities/colour.h"

int main() {
    main::printImage(256, 256);
}

void main::printImage(const int image_width, const int image_height) {

    std::ofstream out("..\\Output\\helloWorld.ppm");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; j--) { // top to bottom

        std::cerr << "\033[33m";
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;

        for (int i = 0; i < image_width; i++) { // left to right

            auto r = static_cast<double>(i) / (image_width - 1);
            auto g = static_cast<double>(j) / (image_height - 1);
            auto b = 0.25;

            colour pixelColours(r, g, b);
            write_colour(std::cout, pixelColours);
        }
    }
    std::cout.rdbuf(coutbuf); //reset to standard output again
    std::cerr << "\033[32m";
    std::cerr << "\nThe image has been produced.\n";
    std::cerr << "\033[0m";
}
