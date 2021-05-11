//
// Created by smy19 on 2021/5/11.
//

#pragma once
#include <memory>
#include <iostream>
#include <utility>

namespace decorator {
class Component {
public:
    explicit Component() = default;
    virtual ~Component() = default;
    virtual void Operation() = 0;
};

class ConcreteComponent : public Component {
public:
    explicit ConcreteComponent() = default;
    virtual ~ConcreteComponent() = default;
    void Operation() override;
};

class Decorator : public Component {
public:
    explicit Decorator(std::shared_ptr<Component> icomp);
    virtual ~Decorator() = default;
    virtual void Operation() override;
private:
    std::shared_ptr<Component> comp;
};

class ConcreteDecoratorA : public Decorator {
public:
    explicit ConcreteDecoratorA(std::shared_ptr<Component> icomp, std::string newState);
    virtual ~ConcreteDecoratorA() = default;
    virtual void Operation() override;
private:
    std::string addedState;
};


class ConcreteDecoratorB : public Decorator {
public:
    explicit ConcreteDecoratorB(std::shared_ptr<Component> icomp);
    virtual ~ConcreteDecoratorB() = default;
    virtual void AddedBehavior();
    virtual void Operation() override;
};
} // namespace decorator