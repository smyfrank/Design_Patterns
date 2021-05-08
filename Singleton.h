//
// Created by smy19 on 2021/5/8.
//

#pragma once
#include <iostream>
#include <mutex>

class Singleton {
public:
    virtual ~Singleton() = default;
    static Singleton * GetInstance();
    static void SingletonOperation();
protected:
    Singleton();  // There is only one instance in Singleton pattern, so hide the construct function
private:
    static void Create();
    static Singleton* _instance;
    static std::once_flag _flag;
    static int counter;
};
