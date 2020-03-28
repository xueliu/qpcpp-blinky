//
// Created by lx on 28.03.20.
//

#ifndef BLINKY_LED_HPP
#define BLINKY_LED_HPP

#include <iostream>

#include <bulb.hpp>

class LED : public Bulb
{
public:
    LED()
    {
        std::cout << "LED construct" << std::endl;
    };

    ~LED() override
    {
        std::cout << "LED destruct" << std::endl;
    };

    void CbOn() override
    {
        std::cout << "LED on" << std::endl;
    };

    void CbOff() override
    {
        std::cout << "LED off"<< std::endl;
    }
};

#endif //BLINKY_LED_HPP
