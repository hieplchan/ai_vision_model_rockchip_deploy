cmake_minimum_required(VERSION 3.10)
project(face_detector)

find_package(OpenCV REQUIRED)

file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    "*.hpp"
    "*.cpp")

# MNN
set(MNN_LIBRARY_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/mnn/lib)
set(MNN_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/../../3rdparty/mnn/include)

include_directories(
        ${OpenCV_INCLUDE_DIRS}
        ${MNN_INCLUDE_DIRS}
)

link_directories(
        ${MNN_LIBRARY_DIRS}
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME}
        MNN
        MNN_CL
        ${OpenCV_LIBS}
)