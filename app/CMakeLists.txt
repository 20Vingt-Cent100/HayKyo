add_executable(HayKyo WIN32
    src/main.cpp
)

set(CMAKE_WIN32_EXECUTABLE TRUE)

target_link_libraries(HayKyo PRIVATE HayKyo_Core)