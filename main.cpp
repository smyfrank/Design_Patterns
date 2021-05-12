#include "AbstractFactory.h"
#include "FactoryMethod.h"
#include "Singleton.h"
#include "Adapter.h"
#include "Composite.h"
#include "Decorator.h"
#include "Proxy.h"
#include "Observer.h"
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
        Singleton::SingletonOperation();
    }
    Singleton* sing2 = Singleton::GetInstance();
    for(auto i = 0; i < 3; i++) {
        Singleton::SingletonOperation();
    }
}

void TestAdapter() {
    std::shared_ptr<Adaptee> adaptee = std::make_shared<Adaptee>();
    std::shared_ptr<Adapter> adapter = std::make_shared<Adapter>(adaptee);
    adapter->Request();
}

void TestComposite() {
    std::shared_ptr<composite::Composite> composite = std::make_shared<composite::Composite>(0);
    std::shared_ptr<composite::Leaf> leaf1 = std::make_shared<composite::Leaf>(1);
    std::shared_ptr<composite::Leaf> leaf2 = std::make_shared<composite::Leaf>(2);
    std::shared_ptr<composite::Leaf> leaf3 = std::make_shared<composite::Leaf>(3);
    composite->Add(leaf1);
    composite->Add(leaf2);
    composite->Add(leaf3);
    composite->Operation();
    leaf2->Operation();
    composite->Remove(leaf2);
    composite->Operation();
}

void TestDecorator() {
    // original concrete component
    auto conComp = std::make_shared<decorator::ConcreteComponent>();
    conComp->Operation();
    // add state
    auto conDec1 = std::make_shared<decorator::ConcreteDecoratorA>(conComp, "state1");
    conDec1->Operation();
    // add behavior
    auto conDec2 = std::make_shared<decorator::ConcreteDecoratorB>(conComp);
    conDec2->Operation();
}

void TestProxy() {
    std::cout << "Beginning of instantiation of Proxy" << std::endl;
    auto proxyIns = std::make_shared<Proxy>();  // instantiate Proxy but RealSubject has not been instantiated yet
    std::cout << "End of instantiation of Proxy" << std::endl;
    proxyIns->request();
}

void TestObserver() {
    std::shared_ptr<observer::Subject> sub = std::make_shared<observer::ConcreteSubject>();
    std::shared_ptr<observer::Observer> ob1 = std::make_shared<observer::ConcreteObserver>("ob1");
    std::shared_ptr<observer::Observer> ob2 = std::make_shared<observer::ConcreteObserver>("ob2");
    sub->Attach(ob1);
    sub->Attach(ob2);
    sub->Attach(ob1); // Repeatedly attach test

    sub->setState(1);
    sub->Notify();

    sub->Detach(ob1);

    sub->setState(2);
    sub->Notify();
}

int main() {
    TestObserver();
    return 0;
}
