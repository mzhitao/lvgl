cmake_minimum_required(VERSION 3.16)

project(lvgldemo)

set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_subdirectory(lvgl)
target_include_directories(lvgl PUBLIC ${CMAKE_SOURCE_DIR})

fine(GLOB_RECURSE SOURCES ./lv_cpp/*.cpp ./lv_cpp/custom/*.c)
add_library(lv_cpp STATIC ${SOURCES})
target_include_directories(lv_cpp PUBLIC ${CMAKE_SOURCE_DIR})

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_image REQUIRED SDL2_image)
target_include_directories(lvgl PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2_image_INCLUDE_DIRS})

add_executable(lvgldemo src/main.cpp)
target_include_directories(lvgldemo PUBLIC ${PROJECT_SOURCE_DIR} ${PROJECT_SOURCE_DIR}/lv_cpp)
target_link_libraries(lvgldemo lvgl lv_cpp lvgl::examples lvgl::demos lvgl::thorvg ${SDL2_LIBRARIES} ${SDL2_image_LIBRARIES} m pthread)

add_custom_target (run COMMAND ${EXECUTABLE_OUTPUT_PATH}/lvgldemo DEPENDS lvgldemo)