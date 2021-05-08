//
// Created by smy19 on 2021/5/8.
//

#include "AbstractFactory.h"

void MotifWidgetFactory::CreateScrollBar() {
    std::cout << "Create Motif scroll bar." << std::endl;
}

void MotifWidgetFactory::CreateWindow() {
    std::cout << "Create Motif window." << std::endl;
}

void PMWidgetFactory::CreateScrollBar() {
    std::cout << "Create PW scroll bar." << std::endl;
}

void PMWidgetFactory::CreateWindow() {
    std::cout << "Create PW window." << std::endl;
}