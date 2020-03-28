//
// Created by lx on 28.03.20.
//
#include <iostream>

#include "blinky.hpp"
#include "bsp.hpp"

using namespace std;

Blinky::Blinky()
    : QActive(Q_STATE_CAST(&Blinky::initial))
    , m_timeEvt(this, TIMEOUT_SIG, 0U)
{

}

void Blinky::onInit()
{
    m_timeEvt.armX(BSP_TICKS_PER_SEC/2, BSP_TICKS_PER_SEC/2);
}

bool Blinky::isValid()
{
    return !!m_bulb;
}

void Blinky::setBulb(std::unique_ptr<Bulb> bulb)
{
    m_bulb = std::move(bulb);
}

void Blinky::resetBulb()
{
    m_bulb.reset();
}

void Blinky::onOff()
{
    if(isValid())
    {
        m_bulb->CbOff();
    }
}

void Blinky::onOn()
{
    if(isValid())
    {
        m_bulb->CbOn();
    }
}