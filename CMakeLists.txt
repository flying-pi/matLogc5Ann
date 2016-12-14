cmake_minimum_required(VERSION 3.6)
project(matLogic5_Ann)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp PredicatParser.cpp PredicatParser.h Predicat.cpp Predicat.h PredicatProccessor.cpp PredicatProccessor.h)
add_executable(matLogic5_Ann ${SOURCE_FILES})