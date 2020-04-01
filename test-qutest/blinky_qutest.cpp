
// Copyright (C) 2020 Xue Liu <liuxuenetmail@gmail.com>

#include "qpcpp.hpp"  // QP/C++ framework API
#include "blinky.hpp" // Blinky application
//#include "bsp.hpp"    // Board Support Package interface

using namespace QP;

Q_DEFINE_THIS_FILE

//............................................................................
int main(int argc, char *argv[]) {
    static QF_MPOOL_EL(QEvt) smlPoolSto[10]; // storage for small pool
    static QEvt const *blinkyQSto[10]; // event queue storage for Blinky

    QF::init();  // initialize the framework

    // initialize the QS software tracing
    Q_ALLEGE(QS_INIT(argc > 1 ? argv[1] : (void *)0));

//    BSP::init(); // initialize the BSP

    // dictionaries...
    QS_SIG_DICTIONARY(TIMEOUT_SIG, (void *)0);

    // pause execution of the test and wait for the test script to continue
    QS_TEST_PAUSE();

    // publish-subscribe not used, no call to QF_psInit()

    // initialize event pools...
    QF::poolInit(smlPoolSto, sizeof(smlPoolSto), sizeof(smlPoolSto[0]));

    // start the active objects...
    AO_Blinky->start(1U,
                     blinkyQSto, Q_DIM(blinkyQSto),
                     (void *)0, 0U, (QEvt *)0);

    return QF::run();
}

//----------------------------------------------------------------------------
void QS::onTestSetup(void) {
}
//............................................................................
void QS::onTestTeardown(void) {
}
//............................................................................
void QS::onCommand(uint8_t cmdId,
                   uint32_t param1, uint32_t param2, uint32_t param3)
{
    (void)param1;
    (void)param2;
    (void)param3;

    switch (cmdId) {
        case 0U: {
            break;
        }
        default:
            break;
    }
}

//............................................................................
// callback function to "massage" the event, if necessary
void QS::onTestEvt(QEvt *e) {
    (void)e;
#ifdef Q_HOST  // is this test compiled for a desktop Host computer?
#else // this test is compiled for an embedded Target system
#endif
}
//............................................................................
// callback function to output the posted QP events (not used here)
void QS::onTestPost(void const *sender, QActive *recipient,
                    QEvt const *e, bool status)
{
    (void)sender;
    (void)recipient;
    (void)e;
    (void)status;
}
