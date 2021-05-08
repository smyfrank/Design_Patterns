//
// Created by smy19 on 2021/5/8.
//
#ifndef DESIGN_PATTERNS_ABSTRACTFACTORY_H
#define DESIGN_PATTERNS_ABSTRACTFACTORY_H

#include <iostream>

class WidgetFactory {
public:
    WidgetFactory();
    virtual ~WidgetFactory();
    virtual void CreateScrollBar() = 0;
    virtual void CreateWindow() = 0;
};

class MotifWidgetFactory : public WidgetFactory {
public:
    MotifWidgetFactory();
    ~MotifWidgetFactory() override;
    void CreateScrollBar() override;
    void CreateWindow() override;
};

class PMWidgetFactory : public WidgetFactory {
public:
    PMWidgetFactory();
    ~PMWidgetFactory() override;
    void CreateScrollBar() override;
    void CreateWindow() override;
};

#endif //DESIGN_PATTERNS_ABSTRACTFACTORY_H
