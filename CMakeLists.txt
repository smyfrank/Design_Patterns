cmake_minimum_required(VERSION 3.19)
project(Design_Patterns)

set(CMAKE_CXX_STANDARD 20)

add_executable(Design_Patterns main.cpp AbstractFactory.h AbstractFactory.cpp FactoryMethod.cpp FactoryMethod.h Singleton.cpp Singleton.h Adapter.cpp Adapter.h Composite.cpp Composite.h Decorator.cpp Decorator.h Proxy.cpp Proxy.h Observer.cpp Observer.h Strategy.cpp Strategy.h TemplateMethod.cpp TemplateMethod.h)