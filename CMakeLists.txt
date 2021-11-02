#
# Project settings
#
cmake_minimum_required(VERSION 3.16)
project(engine VERSION 150721)

set (CMAKE_CXX_STANDARD 17)

#
# Libraries check
#
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/.cmake/FindSDL2")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(
    ${SDL2_INCLUDE_DIR}
    ${SDL2_IMAGE_INCLUDE_DIR}
    ${SDL2_TTF_INCLUDE_DIR}
)

#
# Include dirs
#
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")

include_directories(
    "${INCLUDE_DIR}"
    "${SRC_DIR}"
    "${SRC_DIR}/objects"
)

#
# Add files
#
set(
    CPP_FILES
    ${SRC_DIR}/gui/font.cpp
    ${SRC_DIR}/gui/text.cpp
    ${SRC_DIR}/input/keyboard.cpp
    ${SRC_DIR}/input/mouse.cpp
    ${SRC_DIR}/objects/textureManager.cpp
    ${SRC_DIR}/renderable/rectangle.cpp
    ${SRC_DIR}/renderable/texture.cpp
    ${SRC_DIR}/wrapper/engineWrapper.cpp
    ${SRC_DIR}/wrapper/eventWrapper.cpp
    ${SRC_DIR}/wrapper/mouseWrapper.cpp
    ${SRC_DIR}/engine.cpp
    ${SRC_DIR}/exception.cpp
    ${SRC_DIR}/event.cpp
    ${SRC_DIR}/handler.cpp
    ${SRC_DIR}/global.cpp
    ${SRC_DIR}/scene.cpp
)

set(
    HPP_FILES
    ${INCLUDE_DIR}/common.hpp
    ${INCLUDE_DIR}/exception.hpp
    ${INCLUDE_DIR}/geometry.hpp
    ${INCLUDE_DIR}/gui.hpp
    ${INCLUDE_DIR}/handler.hpp
    ${INCLUDE_DIR}/primitive.hpp
    ${INCLUDE_DIR}/scene.hpp
    ${INCLUDE_DIR}/texture.hpp
    ${INCLUDE_DIR}/type.hpp
    ${SRC_DIR}/objects/textureManager.hpp
    ${SRC_DIR}/wrapper/wrapper.hpp
    ${SRC_DIR}/engine.hpp
    ${SRC_DIR}/event.hpp
    ${SRC_DIR}/global.hpp
)

#
# Create library
#
add_library(
    engine 
    SHARED
    ${HPP_FILES} 
    ${CPP_FILES}
)

target_link_libraries(
    engine 
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    ${SDL2_TTF_LIBRARIES}
)

#
# Testing
#

enable_testing()

set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")

# ExceptionTest
add_executable(
    exceptionTest
    ${TEST_DIR}/exception.cpp
)

target_link_libraries(
    exceptionTest
    engine
)

add_test(
    exception
    exceptionTest
)

set_tests_properties(
    exception PROPERTIES
    PASS_REGULAR_EXPRESSION "Several objects of the class Handler have been initialized"
    FAIL_REGULAR_EXPRESSION "DoubleInitException not work!"
)

# SceneTest
add_executable(
    sceneTest
    ${TEST_DIR}/scene.cpp
)

target_link_libraries(
    sceneTest
    engine
)

add_test(
    scene
    sceneTest
)

set_tests_properties(
    scene PROPERTIES
    TIMEOUT 10
    PASS_REGULAR_EXPRESSION "Scenes succesfully rendered!"
)

# TextureTest
add_executable(
    textureTest
    ${TEST_DIR}/texture.cpp
)

target_link_libraries(
    textureTest
    engine
)

add_test(
    texture
    textureTest
)

set_tests_properties(
    texture PROPERTIES
    TIMEOUT 60
    PASS_REGULAR_EXPRESSION "success!"
)

# TilingTest
add_executable(
    tilingTest
    ${TEST_DIR}/tiling.cpp
)

target_link_libraries(
    tilingTest
    engine
)

add_test(
    tiling
    tilingTest
)

set_tests_properties(
    tiling PROPERTIES
    TIMEOUT 60
    PASS_REGULAR_EXPRESSION "success!"
)