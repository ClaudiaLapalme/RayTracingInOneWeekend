cmake_minimum_required(VERSION 3.13)
project(RayTracingInOneWeekend)

set(CMAKE_CXX_STANDARD 17)

add_executable(
        main
        Sources/main.cpp
        Headers/Utilities/Vec3.h
        Headers/Utilities/Colour.h
        Headers/Utilities/Ray.h
        Headers/Assets/Collidables.h Headers/Utilities/HitRecord.h Sources/Assets/Sphere.cpp Headers/Assets/Sphere.h Sources/Containers/CollidableList.cpp Headers/Containers/CollidableList.h Sources/Assets/Camera.cpp Headers/Assets/Camera.h Headers/Utilities/MathFunctions.h Headers/Materials/Materials.h Sources/Materials/Matte.cpp Headers/Materials/Matte.h Sources/Materials/Metal.cpp Headers/Materials/Metal.h)