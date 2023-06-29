cmake_minimum_required(VERSION 3.0)
project(Raytracer)

set(CMAKE_CXX_STANDARD 23)

add_executable(Raytracer src/main.cpp)

set(LIBRARY_NAME Raytracer)

target_include_directories(${LIBRARY_NAME} PRIVATE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}>
        $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>)

target_include_directories(${LIBRARY_NAME} PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)
