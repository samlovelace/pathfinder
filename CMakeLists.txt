cmake_minimum_required(VERSION 3.8)
project(pathfinder)

find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

set(SOURCES
    ${CMAKE_CURRENT_LIST_DIR}/src/Agent.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/AstarPathFinder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/BfsPathFinder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Grid.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/Renderer.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${PROJECT_NAME} 
        ${CMAKE_CURRENT_LIST_DIR}/include)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)