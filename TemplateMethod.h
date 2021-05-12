//
// Created by DELL on 2021/5/12.
//

# pragma once
# include <iostream>
namespace templateMethod {
class AbstractClass {
public:
    explicit AbstractClass() = default;
    virtual ~AbstractClass() = default;

    void TemplateMethod();
    virtual void PrimitiveOperation1() = 0;
    virtual void PrimitiveOperation2() = 0;
};

class ConcreteClassA : public AbstractClass {
public:
    void PrimitiveOperation1() final;
    void PrimitiveOperation2() final;
};

class ConcreteClassB : public AbstractClass {
public:
    void PrimitiveOperation1() final;
    void PrimitiveOperation2() final;
};
}