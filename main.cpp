#include "AbstractFactory.h"
#include "FactoryMethod.h"
#include <memory>

void TestAbstractFactory() {
    std::shared_ptr<WidgetFactory> motifPtr(new MotifWidgetFactory());
    std::shared_ptr<WidgetFactory> pwPtr(new PMWidgetFactory());
    motifPtr->CreateWindow();
    motifPtr->CreateScrollBar();
    pwPtr->CreateScrollBar();
    pwPtr->CreateWindow();
}

void TestFactoryMethod() {
    std::shared_ptr<AbstractCreator> creator1(new ConcreteCreator1);
    std::shared_ptr<Product> product1 = creator1->CreateProduct();
    product1->use();

    std::shared_ptr<AbstractCreator> creator2(new ConcreteCreator2);
    std::shared_ptr<Product> product2 = creator2->CreateProduct();
    product2->use();
}

int main() {
    TestFactoryMethod();
    return 0;
}
