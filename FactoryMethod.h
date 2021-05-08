//
// Created by smy19 on 2021/5/8.
//

#pragma once
#include <iostream>
#include <memory>

class Product {
public:
    Product() = default;
    virtual ~Product() = default;
    virtual void use() = 0;
};

class ConcreteProduct1 : public Product{
public:
    ConcreteProduct1() = default;
    virtual ~ConcreteProduct1() override = default;
    virtual void use() override;
};

class ConcreteProduct2 : public Product {
public:
    ConcreteProduct2() = default;
    virtual ~ConcreteProduct2() override = default;
    virtual void use() override;
};

class AbstractCreator {
public:
    AbstractCreator() = default;
    virtual ~AbstractCreator() = default;
    virtual std::shared_ptr<Product> CreateProduct() = 0;
};

/*
 * Create concrete object in inherited class
 * */
class ConcreteCreator1 : public AbstractCreator{
public:
    ConcreteCreator1() = default;
    virtual ~ConcreteCreator1() override = default;
    virtual std::shared_ptr<Product> CreateProduct() override;
};

class ConcreteCreator2 : public AbstractCreator {
public:
    ConcreteCreator2() = default;
    virtual ~ConcreteCreator2() override = default;
    virtual std::shared_ptr<Product> CreateProduct() override;
};