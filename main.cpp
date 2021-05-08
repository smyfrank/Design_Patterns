#include "AbstractFactory.h"
#include "FactoryMethod.h"
#include "Singleton.h"
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

void TestSingleton() {
    Singleton* sing1 = Singleton::GetInstance();
    for(auto i = 0; i < 5; i++) {
        sing1->SingletonOperation();
    }
    Singleton* sing2 = Singleton::GetInstance();
    for(auto i = 0; i < 3; i++) {
        sing2->SingletonOperation();
    }
}

int main() {
    TestSingleton();
    return 0;
}
