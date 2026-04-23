#include <iostream>
#include "battle_monitor.hpp"

/**
 * Denne metode kaldes automatisk via notify() fra Soldier-klassen
 * Ved at gemme beskeden i 'messages' kan vi efterfølgende analysere eller få vist kampforløbet uden at påvirke selve kampen
 */

void BattleMonitor::do_update(void *event)
{
    UnitEvent *e = static_cast<UnitEvent *>(event);
    std::cout << e->message << std::endl; //Printer beskeden til konsollen

    // Vi gemmer beskeden i klassens medlemsvariabel 'messages', så 'test_wargame.cpp' kan verificere logikken.
    this->messages.push_back(e->message);
    
}