//
// Created by lx on 28.03.20.
//
#include <iostream>

#include "qpcpp.hpp"  // QP/C++ framework API

#include "blinky.hpp"
#include "bsp.hpp"

using namespace std;
using namespace QP;

Q_DEFINE_THIS_MODULE("blinky")

#ifdef Q_SPY
enum {
    LED = QP::QS_USER
};
#endif

Blinky::Blinky()
    : QActive(Q_STATE_CAST(&Blinky::initial))
    , m_timeEvt(this, TIMEOUT_SIG, 0U)
{

}

void Blinky::onInit()
{
    QS_FUN_DICTIONARY(&QHsm::top);

    QS_OBJ_DICTIONARY(&Blinky::inst);
    QS_OBJ_DICTIONARY(&Blinky::inst.m_timeEvt);

    QS_USR_DICTIONARY(LED);

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
    QS_BEGIN(LED, AO_Blinky)
        QS_U8(1, 0);
    QS_END()

    if(isValid())
    {
        m_bulb->CbOff();
    }
}

void Blinky::onOn()
{
    QS_BEGIN(LED, AO_Blinky)
        QS_U8(1, 1);
    QS_END()

    if(isValid())
    {
        m_bulb->CbOn();
    }
}