//.$file${generate::blinky.cpp} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//
// Model: blinky.qm
// File:  ${generate::blinky.cpp}
//
// This code has been generated by QM 5.0.0 <www.state-machine.com/qm/>.
// DO NOT EDIT THIS FILE MANUALLY. All your changes will be lost.
//
// This program is open source software: you can redistribute it and/or
// modify it under the terms of the GNU General Public License as published
// by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
// for more details.
//
//.$endhead${generate::blinky.cpp} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
#include <iostream>
#include <stdlib.h> // for exit()

#include "blinky.hpp"

using namespace std;
using namespace QP;

static Blinky l_blinky;
Blinky * const AO_Blinky = &l_blinky;

//================ ask QM to define the Blinky class ==================
//.$skip${QP_VERSION} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//. Check for the minimum required QP version
#if (QP_VERSION < 670U) || (QP_VERSION != ((QP_RELEASE^4294967295U) % 0x3E8U))
#error qpcpp version 6.7.0 or higher required
#endif
//.$endskip${QP_VERSION} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//.$define${AOs::Blinky} vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
//.${AOs::Blinky} ............................................................
//.${AOs::Blinky::SM} ........................................................
Q_STATE_DEF(Blinky, initial) {
    //.${AOs::Blinky::SM::initial}
    onInit();

    QS_FUN_DICTIONARY(&off);
    QS_FUN_DICTIONARY(&on);

    return tran(&off);
}
//.${AOs::Blinky::SM::off} ...................................................
Q_STATE_DEF(Blinky, off) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::Blinky::SM::off}
        case Q_ENTRY_SIG: {
            onOff();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::Blinky::SM::off::TIMEOUT}
        case TIMEOUT_SIG: {
            status_ = tran(&on);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}
//.${AOs::Blinky::SM::on} ....................................................
Q_STATE_DEF(Blinky, on) {
    QP::QState status_;
    switch (e->sig) {
        //.${AOs::Blinky::SM::on}
        case Q_ENTRY_SIG: {
            onOn();
            status_ = Q_RET_HANDLED;
            break;
        }
        //.${AOs::Blinky::SM::on::TIMEOUT}
        case TIMEOUT_SIG: {
            status_ = tran(&off);
            break;
        }
        default: {
            status_ = super(&top);
            break;
        }
    }
    return status_;
}
//.$enddef${AOs::Blinky} ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
