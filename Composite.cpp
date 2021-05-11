//
// Created by smy19 on 2021/5/11.
//

#include "Composite.h"

void composite::Leaf::Operation() {
    std::cout << "Index " << index << "'s operation" << std::endl;
}

void composite::Composite::Add(std::shared_ptr<Component> com) {
    children.emplace_back(com);
}

void composite::Composite::Remove(std::shared_ptr <Component> com) {
    children.remove(com);
}

void composite::Composite::Operation() {
    for(const auto& i : children) {
        i->Operation();
    }
}
