//
// Created by lx on 28.03.20.
//

#include "server.hpp"
#include "blinky.hpp"
#include "light.hpp"

int Server::Start()
{
    QEvt const *blinky_queueSto[10];

    QF::init(); // initialize the framework

    AO_Blinky->setBulb( std::make_unique<Light>() );

    AO_Blinky->start(1U, // priority
                     blinky_queueSto, Q_DIM(blinky_queueSto),
                     (void *)0, 0U); // no stack
    return QF::run(); // run the QF application
}