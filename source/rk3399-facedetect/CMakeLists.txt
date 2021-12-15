cmake_minimum_required(VERSION 3.10)
project(rk3399-facedetect)

find_package(OpenCV REQUIRED)

file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    src/*
    inc/*)

# MNN
set(MNN_LIBRARY_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/mnn/lib)
set(MNN_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/mnn/include)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
        ${MNN_INCLUDE_DIRS}
)

link_directories(
        ${MNN_LIBRARY_DIRS}
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
        MNN
        MNN_CL
        ${OpenCV_LIBS})