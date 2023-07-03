cmake_minimum_required(VERSION 3.10)
project(LivingWorld)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(LivingWorld
        src/Animal.cpp
        src/Animal.h
        src/LivingWorld.cpp
        src/Organism.cpp
        src/Organism.h
        src/Plant.cpp
        src/Plant.h
        src/Position.cpp
        src/Position.h
        src/World.cpp
        src/World.h
        src/Grass.cpp
        src/Grass.h
        src/Sheep.cpp
        src/Sheep.h
        src/Dandelion.cpp
        src/Dandelion.h
        src/Wolf.cpp
        src/Wolf.h
        src/Toadstool.cpp
        src/Toadstool.h
        src/OrganismCreator.h
        src/OrganismCreator.cpp)
