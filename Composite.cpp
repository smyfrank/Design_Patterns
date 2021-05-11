//
// Created by smy19 on 2021/5/11.
//

#include "Composite.h"

void Leaf::Operation() {
    std::cout << "Index " << index << "'s operation" << std::endl;
}

void Composite::Add(std::shared_ptr<Component> com) {
    children.emplace_back(com);
}

void Composite::Remove(std::shared_ptr <Component> com) {
    children.remove(com);
}

void Composite::Operation() {
    for(const auto& i : children) {
        i->Operation();
    }
}
