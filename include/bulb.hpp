//
// Created by lx on 28.03.20.
//

#ifndef BLINKY_BULB_HPP
#define BLINKY_BULB_HPP

#include <iostream>

class Bulb
{
public:
    Bulb()
    {
        std::cout << "Bulb construct" << std::endl;
    };

    virtual ~Bulb()
    {
        std::cout << "Bulb destruct" << std::endl;
    };

    virtual void CbOn() = 0;
    virtual void CbOff() = 0;
};

#endif //BLINKY_BULB_HPP
