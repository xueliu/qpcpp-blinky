//
// Created by lx on 28.03.20.
//

#ifndef BLINKY_LIGHT_HPP
#define BLINKY_LIGHT_HPP

#include <iostream>

#include "bulb.hpp"

class Light : public Bulb
{
public:
    Light()
    {
        std::cout << "Light construct" << std::endl;
    };

    ~Light() override
    {
        std::cout << "Light destruct" << std::endl;
    };

    void CbOn() override
    {
        std::cout << "Light on" << std::endl;
    };

    void CbOff() override
    {
        std::cout << "Light off" << std::endl;
    };
};

#endif //BLINKY_LIGHT_HPP
