//
// Created by smy19 on 2021/5/8.
//

#include "FactoryMethod.h"

void ConcreteProduct1::use() {
    std::cout << "Use ConcreteProduct1" << std::endl;
}

void ConcreteProduct2::use() {
    std::cout << "Use ConcreteProduct2" << std::endl;
}

std::shared_ptr<Product> ConcreteCreator1::CreateProduct() {
    auto product1 = std::make_shared<ConcreteProduct1>();
    return product1;
}

std::shared_ptr<Product> ConcreteCreator2::CreateProduct() {
    auto product2 = std::make_shared<ConcreteProduct2>();
    return product2;
}