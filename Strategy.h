//
// Created by DELL on 2021/5/12.
//

#pragma once
#include <iostream>
#include <memory>

namespace strategy {
    class Strategy {
    public:
        explicit Strategy() = default;

        virtual ~Strategy() = default;

        virtual void AlgorithmInterface() = 0;
    };

    class ConcreteStrategyA : public Strategy {
    public:
        explicit ConcreteStrategyA() = default;

        virtual ~ConcreteStrategyA() = default;

        void AlgorithmInterface() override;
    };

    class ConcreteStrategyB : public Strategy {
    public:
        explicit ConcreteStrategyB() = default;

        virtual ~ConcreteStrategyB() = default;

        void AlgorithmInterface() override;
    };

    class Context {
    public:
        explicit Context() = default;

        virtual ~Context() = default;

        void SetStrategy(std::shared_ptr<Strategy> str);

        void Algorithm();

    private:
        std::shared_ptr<Strategy> strategy;
    };

} // namespace strategy