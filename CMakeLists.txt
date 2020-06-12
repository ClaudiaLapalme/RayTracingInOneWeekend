cmake_minimum_required(VERSION 3.13)
project(RayTracingInOneWeekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        main
        Sources/main.cpp
        Headers/Utilities/vec3.h
        Headers/Utilities/colour.h
        Sources/ray.cpp
        Headers/Utilities/ray.h
)