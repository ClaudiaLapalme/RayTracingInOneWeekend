//
// Created by claul on 6/7/2020.
//

#include "../Headers/main.h"

int main() {
    main::printImage();
}

void main::printImage() {
    constexpr int imageWidth = 1080;
    const double aspectRatio = 16.0 / 9.0;
    const int imageHeight = static_cast<int> (imageWidth / aspectRatio);

    std::ofstream out("..\\Output\\simplifiedHitSphere.ppm");
    std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = imageHeight - 1; j >= 0; j--) { // top to bottom

        std::cerr << "\033[33m" << "\rScanlines remaining: " << j << ' ' << std::flush;

        for (int i = 0; i < imageWidth; i++) { // left to right

            // Step 1. Calculate the ray from the eye to the pixel
            auto u = static_cast<double>(i) / (imageWidth - 1);
            auto v = static_cast<double>(j) / (imageHeight - 1);

            // Step 2. Determine which objects the ray intersects
            ray r = ray::raySetup(aspectRatio, u, v);
            colour pixelColours = rayColours(r);

            // Step 3. Compute a colour for that intersection point
            write_colour(std::cout, pixelColours);
        }
    }

    std::cout.rdbuf(coutbuf); //reset to standard output again
    std::cerr << "\033[32m" << "\nThe image has been produced.\n" << "\033[0m";
}
