//
// Created by DELL on 2021/5/12.
//

#include "TemplateMethod.h"
using namespace templateMethod;
void AbstractClass::TemplateMethod() {
    PrimitiveOperation1();
    PrimitiveOperation2();
}

void ConcreteClassA::PrimitiveOperation1() {
    std::cout << "Primitive operation 1 from concrete class A" << std::endl;
}

void ConcreteClassA::PrimitiveOperation2() {
    std::cout << "Primitive operation 2 from concrete class A" << std::endl;
}

void ConcreteClassB::PrimitiveOperation1() {
    std::cout << "Primitive operation 1 from concrete class B" << std::endl;
}

void ConcreteClassB::PrimitiveOperation2() {
    std::cout << "Primitive operation 2 from concrete class B" << std::endl;
}
