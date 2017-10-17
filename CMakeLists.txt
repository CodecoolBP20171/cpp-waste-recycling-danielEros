cmake_minimum_required(VERSION 3.8)
project(cpp_waste_recycling_danielEros)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES wasteRecycling.cpp Garbages/Garbage.cpp Garbages/Garbage.h Garbages/PaperGarbage.cpp Garbages/PaperGarbage.h)
add_executable(cpp_waste_recycling_danielEros ${SOURCE_FILES} Garbages/Garbage.cpp Garbages/Garbage.h Garbages/PaperGarbage.cpp Garbages/PaperGarbage.h)