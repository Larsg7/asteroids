cmake_minimum_required(VERSION 3.14)
project(asteroids)

set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_executable(asteroids src/main.cpp src/Asteroids.cpp src/Asteroids.h src/GameState.h src/Player.cpp src/Player.h src/MoveAble.cpp src/MoveAble.h src/Bullet.cpp src/Bullet.h src/Helper.h src/Asteroid.cpp src/Asteroid.h src/Hud.cpp src/Hud.h src/MainMenu.cpp src/MainMenu.h src/GameO.cpp src/GameO.h)

target_link_libraries(asteroids sfml-graphics sfml-audio)
