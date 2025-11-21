cmake_minimum_required(VERSION 3.21)
project(HayKyo VERSION 1.0 LANGUAGES CXX)

add_subdirectory("./app")
add_subdirectory("./HayKyo_Core")

set_target_properties(HayKyo_Core PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

set_target_properties(HayKyo PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

