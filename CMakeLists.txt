cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME GameEngine)
project(GameEngine)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(SDL ${PROJECT_SOURCE_DIR}/lib/SDL2-2.0.14)

include_directories(${SDL}/include)
link_directories(${SDL}/lib)

set(CMAKE_CXX_STANDARD 14)

include_directories(lib)
add_subdirectory(lib/glm)
add_executable(${PROJECT_NAME} src/main.cpp src/Game.cpp src/Game.h src/Constants.h src/Component.h src/Entity.h src/Entity.cpp src/EntityManager.cpp src/EntityManager.h src/Components/TransformComponent.cpp src/Components/TransformComponent.h)
target_link_libraries(${PROJECT_NAME} mingw32 SDL2main SDL2)