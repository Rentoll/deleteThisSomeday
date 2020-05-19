cmake_minimum_required(VERSION 3.14)
project(SFMLProject)

set(CMAKE_CXX_STANDARD 14)

set(SFML_ROOT D:/Programming_things/vs_libs/sfmlClion)
set(SFML_STATIC_LIBRARIES TRUE)

set(SFML_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake/modules")
find_package(SFML 2 REQUIRED COMPONENTS graphics audio window system )
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()
include_directories(.)
include_directories(Fonts)
include_directories(images)

add_executable(SFMLProject
        Fonts/CyrilicOld.TTF
        images/DirtGrassWater.png
        images/Map.png
        images/map.pyxel
        images/Player.png
        images/Player.pyxel
        main.cpp
        map.h
        view.h)
