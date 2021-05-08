//
// Created by smy19 on 2021/5/8.
//
/* TODO: thread safety and manually new and delete
 * We need to ensure thread safety when construct singleton instance.
 * If we use smart pointer, the constructor and destructor need to be exposed
 */
#include "Singleton.h"

// Initialize static class member variable here
Singleton* Singleton::_instance = nullptr;
int Singleton::counter = 0;
std::once_flag Singleton::_flag;

Singleton::Singleton()= default;

void Singleton::Create() {
    _instance = new Singleton();
}

// Ensure thread safety
Singleton* Singleton::GetInstance() {
    if(!_instance) {
        std::call_once(_flag, Singleton::Create);
    }
    return _instance;
}

void Singleton::SingletonOperation() {
    std::cout << std::to_string(counter) << "'s Operation of Singleton" << std::endl;
    counter++;
}
