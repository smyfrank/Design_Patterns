//
// Created by smy19 on 2021/5/11.
//

#include "Adapter.h"
void Adaptee::SpecifiecRequest() {
    std::cout << "Specific request from Adaptee" << std::endl;
}

void Target::Request() {
    std::cout << "Target request" << std::endl;
}

Adapter::Adapter(std::shared_ptr<Adaptee> iadaptee):adaptee(iadaptee){

}

void Adapter::Request() {
    adaptee->SpecifiecRequest();
}