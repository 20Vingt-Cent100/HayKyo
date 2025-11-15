cmake_minimum_required(VERSION 3.21)
project(HayKyo VERSION 1.0 LANGUAGES CXX)
add_executable(HayKyo)
set_target_properties(HayKyo PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)
target_sources(HayKyo 
    PRIVATE
        src/main.cpp
)