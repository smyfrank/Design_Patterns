//
// Created by smy19 on 2021/5/11.
//

#pragma once
#include <iostream>
#include <list>
#include <memory>

namespace composite {
class Component {
protected:
    int index;
public:
    explicit Component(int idx): index(idx) {}
    virtual ~Component() = default;
    virtual void Add(std::shared_ptr<Component> com) = 0;
    virtual void Remove(std::shared_ptr<Component> com) = 0;
    virtual void Operation() = 0;
};

class Leaf : public Component {
public:
    explicit Leaf(int idx) : Component(idx) {}
    virtual ~Leaf() = default;
    void Add(std::shared_ptr<Component> com) final {}
    void Remove(std::shared_ptr<Component> com) final {}
    void Operation() final;
};

class Composite : public Component {
private:
    std::list<std::shared_ptr<Component>> children;
public:
    explicit Composite(int idx) : Component(idx) {}
    virtual ~Composite() = default;
    void Add(std::shared_ptr<Component> com) final;
    void Remove(std::shared_ptr<Component> com) final;
    void Operation() final;
};
} // namespace composite