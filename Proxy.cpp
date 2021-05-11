//
// Created by smy19 on 2021/5/11.
//

#include "Proxy.h"

#include <utility>

void RealSubject::request() {
    std::cout << "Request for real subject" << std::endl;
}

void Proxy::request() {
    if(realSubject == nullptr) {
        realSubject = std::make_shared<RealSubject>();
    }
    realSubject->request();
}


