#include <iostream>
#include "battle_monitor.hpp"

void BattleMonitor::do_update(void *event)
{
    // 1. Cast the generic event pointer to a UnitEvent pointer.
    // We do this because we know the event is actually a unit broadcasting its status.
    UnitEvent *e = static_cast<UnitEvent *>(event);

    // Add the message to the list of messages, this allows the test file to check all recorded messages (m.messages).
    this->messages.push_back(e->message);


    // 2. Add the unit's message to our internal list of messages.
    // This allows the test file to check all recorded messages (m.messages).
    std::cout << e->message << std::endl;
}












