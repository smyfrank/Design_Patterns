//
// Created by smy19 on 2021/5/11.
//

#include "Decorator.h"

#include <utility>

void decorator::ConcreteComponent::Operation() {
    std::cout << "Concrete component operation" << std::endl;
}

void decorator::Decorator::Operation() {
    comp->Operation();
}

decorator::Decorator::Decorator(std::shared_ptr<Component> icomp) : comp(std::move(icomp)){

}

decorator::ConcreteDecoratorA::ConcreteDecoratorA(std::shared_ptr<Component> icomp, std::string newState) :
Decorator(std::move(icomp)),
addedState(newState)
{

}

void decorator::ConcreteDecoratorA::Operation() {
    Decorator::Operation();
    std::cout << "New state operation by Concrete Decorator A" << std::endl;
}

decorator::ConcreteDecoratorB::ConcreteDecoratorB(std::shared_ptr<Component> icomp) : Decorator(icomp) {

}

void decorator::ConcreteDecoratorB::AddedBehavior() {
    std::cout << "Added Behavior by Concrete Decorator B" << std::endl;
}

void decorator::ConcreteDecoratorB::Operation() {
    Decorator::Operation();
    AddedBehavior();
}

