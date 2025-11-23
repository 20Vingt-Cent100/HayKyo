add_library(HayKyo_Core STATIC 
    src/Window.cpp

    headers/Window.h
    headers/Application.h
)

target_include_directories(HayKyo_Core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
)

add_subdirectory(external/GLFW)
find_package(Vulkan REQUIRED)
target_link_libraries(HayKyo_Core PRIVATE
     glfw
     Vulkan::Vulkan
)

