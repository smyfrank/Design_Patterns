//
// Created by smy19 on 2021/5/11.
//

#pragma once
#include<iostream>
#include<memory>

class Adaptee {
public:
    Adaptee() = default;
    virtual ~Adaptee() = default;
    void SpecifiecRequest();
};

class Target {
public:
    Target() = default;
    virtual ~Target() = default;
    virtual void Request();
};

class Adapter : Target {
private:
    std::shared_ptr<Adaptee> adaptee;
public:
    Adapter(std::shared_ptr<Adaptee> adaptee);
    virtual ~Adapter() = default;
    virtual void Request();
};
