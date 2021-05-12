//
// Created by DELL on 2021/5/12.
//

#include "Observer.h"
#include <utility>
using namespace observer;

ConcreteObserver::ConcreteObserver(std::string iname)
: obName(std::move(iname))
{

}

// cal subject function getState() to update observer's state
void ConcreteObserver::Update(std::shared_ptr <Subject> sub) {
    observerState = sub -> getState();
    std::cout << "Observer " << obName << " updates state to " << observerState << std::endl;
}

std::string ConcreteObserver::getName() {
    return obName;
}

void Subject::Attach(std::shared_ptr<Observer> ob) {
    if(std::find(obList.begin(), obList.end(), ob) == obList.end()) {
        obList.push_back(ob);
        std::cout << "register new observer " << ob->getName() << std::endl;
    }
    else {
        std::cout << "observer " << ob->getName() << " has already been registered" << std::endl;
    }
}

void Subject::Detach(std::shared_ptr<Observer> ob) {
    if(std::find(obList.begin(), obList.end(), ob) != obList.end()) {
        obList.remove(ob);
        std::cout << "Remove observer " << ob->getName() << std::endl;
    }
    else {
        std::cout << "Can not remove observer" << ob->getName() << " because it has not been registered" << std::endl;
    }
}

// Notify all observers to update
void Subject::Notify() {
    for(const auto& i : obList) {
        i->Update(shared_from_this());
    }
}

int ConcreteSubject::getState() {
    return m_state;
}

void ConcreteSubject::setState(int s) {
    m_state = s;
}
