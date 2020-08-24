//
// Created by claul on 6/7/2020.
//

#include "../Headers/main.h"


int main() {
    main::printImage();
}

void main::printImage() {
    constexpr double aspectRatio = 16.0 / 9.0;
    constexpr int imageWidth = 1080;
    const int imageHeight = static_cast<int> (imageWidth / aspectRatio);
    constexpr int samplesPerPixel = 10;
    constexpr double viewportHeight = 2.0;
    const double viewportWidth = aspectRatio * viewportHeight;
    constexpr double focalLength = 1.0;
    constexpr int maxNumberOfSurfaceBounces = 20;

    CollidableList world ({
        std::make_shared<Sphere>(Point3(0, 0, -1), 0.5),
        std::make_shared<Sphere>(Point3(0, -100.5, -1), 100)
    });

    Camera camera(viewportHeight, viewportWidth, focalLength);

    std::ofstream out("..\\Output\\8.3-gammaCorrection.ppm");
    std::streambuf* coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf()); //redirect std::cout to out.txt!

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = imageHeight - 1; j >= 0; j--) { // top to bottom

        std::cerr << "\033[33m" << "\rScanlines remaining: " << j << ' ' << std::flush;

        for (int i = 0; i < imageWidth; i++) { // left to right

            Colour pixelColours(0, 0, 0);
            for (int s = 0; s < samplesPerPixel; s++) {
                // Step 1. Calculate the Ray from the eye to the pixel
                auto u = static_cast<double>(i + randomDouble()) / (imageWidth - 1);
                auto v = static_cast<double>(j + randomDouble()) / (imageHeight - 1);

                // Step 2. Determine which objects the Ray intersects
                Ray r = camera.getRay(u, v);
                pixelColours += rayColours(r, world, maxNumberOfSurfaceBounces);
            }
            // Step 3. Compute a colour for that intersection point
            write_colour(std::cout, pixelColours, samplesPerPixel);
        }
    }

    std::cout.rdbuf(coutbuf); //reset to standard output again
    std::cerr << "\033[32m" << "\nThe image has been produced.\n" << "\033[0m";
}