//
// Created by smy19 on 2021/5/11.
//

#pragma once
#include <iostream>
#include <memory>

class Subject {
public:
    explicit Subject() = default;
    virtual ~Subject() = default;
    virtual void request() = 0;
};

class RealSubject : public Subject {
public:
    explicit RealSubject() = default;
    virtual ~RealSubject() = default;
    void request() override;
};

class Proxy : public Subject {
public:
    explicit Proxy() = default;
    virtual ~Proxy() = default;
    void request() override;
private:
    std::shared_ptr<RealSubject> realSubject;
};