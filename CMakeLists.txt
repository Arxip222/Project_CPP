cmake_minimum_required(VERSION 3.30)
project(HSEPROJECT)

set(CMAKE_CXX_STANDARD 20)

add_executable(HSEPROJECT
        geometry_main.cpp
        src/vector.cpp
        vector.h
        IShape.h
        src/point.cpp
        point.h
        src/segment.cpp
        segment.h
        src/line.cpp
        line.h
        src/ray.cpp
        ray.h
        src/polygon.cpp
        polygon.h
        src/circle.cpp
        circle.h
)
