add_library(HayKyo_Core STATIC 
    src/Window.cpp

    headers/Window.h
    headers/Application.h
)

target_include_directories(HayKyo_Core PUBLIC include)