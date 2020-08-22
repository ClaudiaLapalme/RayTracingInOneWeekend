cmake_minimum_required(VERSION 3.13)
project(RayTracingInOneWeekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        main
        Sources/main.cpp
        Headers/Utilities/Vec3.h
        Headers/Utilities/Colour.h
        Sources/Utilities/Ray.cpp
        Headers/Utilities/Ray.h
        Headers/Assets/Collidables.h Headers/Utilities/HitRecord.h Sources/Assets/Sphere.cpp Headers/Assets/Sphere.h Sources/Containers/CollidableList.cpp Headers/Containers/CollidableList.h)