//
// Created by DELL on 2021/5/12.
//

#include "Strategy.h"

#include <utility>

using namespace strategy;

void ConcreteStrategyA::AlgorithmInterface() {
    std::cout << "Strategy A" << std::endl;
}

void ConcreteStrategyB::AlgorithmInterface() {
    std::cout << "Strategy B" << std::endl;
}

void Context::SetStrategy(std::shared_ptr<Strategy> str) {
    strategy = std::move(str);
}

void Context::Algorithm() {
    strategy->AlgorithmInterface();
}
