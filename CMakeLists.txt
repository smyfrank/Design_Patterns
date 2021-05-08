cmake_minimum_required(VERSION 3.19)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 20)

add_executable(Design_Patterns main.cpp AbstractFactory.h AbstractFactory.cpp FactoryMethod.cpp FactoryMethod.h Singleton.cpp Singleton.h)