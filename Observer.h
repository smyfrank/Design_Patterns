//
// Created by DELL on 2021/5/12.
//

#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

namespace observer{
class Observer;



class Subject : public std::enable_shared_from_this<Subject>{
public:
    explicit Subject() = default;
    virtual ~Subject() = default;

    void Attach(std::shared_ptr<Observer> ob);
    void Detach(std::shared_ptr<Observer> ob);
    void Notify();

    virtual int getState() = 0;
    virtual void setState(int s) = 0;

private:
    std::list<std::shared_ptr<Observer>> obList;
};

class ConcreteSubject : public Subject {
public:
    explicit ConcreteSubject() = default;
    virtual ~ConcreteSubject() = default;
    virtual int getState();
    virtual void setState(int s);
private:
    int m_state;
};

class Observer {
public:
    explicit Observer() = default;
    virtual ~Observer() = default;
    virtual void Update(std::shared_ptr<Subject> sub) = 0;
    virtual std::string getName() = 0;
};

class ConcreteObserver : public Observer {
public:
    explicit ConcreteObserver(std::string iname);
    virtual ~ConcreteObserver() = default;
    virtual void Update(std::shared_ptr<Subject> sub) override;
    virtual std::string getName() override;
private:
    std::string obName;
    std::shared_ptr<Subject> concreteSub;
    int observerState;
};

} // namespace observer