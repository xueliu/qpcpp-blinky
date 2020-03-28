//
// Created by lx on 28.03.20.
//
#include <iostream>

#include "qpcpp.hpp"

using namespace std;
using namespace QP;

extern "C" void Q_onAssert(char const * const module, int loc) {
    cout << "Assertion failed in " << module << ':' << loc << endl;
    exit(-1);
}
void QF::onStartup(void) {}
void QF::onCleanup(void) {}
void QP::QF_onClockTick(void) {
    QF::TICK_X(0U, (void *)0);  // perform the QF clock tick processing
}
