add_library(HayKyo_Core STATIC 
    src/Window.cpp
    src/Application.cpp

    headers/Window.h
    headers/Application.h
 "headers/Renderer.h" "src/Renderer.cpp")

add_subdirectory(external/GLFW)
find_package(Vulkan REQUIRED)

target_link_libraries(HayKyo_Core PRIVATE
     glfw
     Vulkan::Vulkan
)

target_include_directories(HayKyo_Core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/headers
    ${CMAKE_CURRENT_SOURCE_DIR}/external/GLFW/include
    ${Vulkan_INCLUDE_DIRS}
    ${Vulkan_LIBRAIRIES}
)
