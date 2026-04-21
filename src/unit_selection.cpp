#include "unit_selection.hpp"
#include "weapon.hpp"

void UnitSelection::addToSelection(Unit &unit)
{
    // Store the memory address of the unit in the selected vector, this allows us to treat multiple units as one
    this->selected.push_back(&unit);
}

void UnitSelection::shootAt(Unit &unit)
{
    // Loop through all selected units and have them shoot at the target unit, this is where the composite pattern is implemented
    for (auto &u : this->selected)
    {
        // Issue the shoot command to each selected unit, this is where the shoot command is issued to each selected unit
        u->shootAt(unit);
    }
}

void UnitSelection::takeHit(Projectile &Projectile)
{
    // Loop through every unit currently in the selection
    for (auto &u : this->selected)
    {
        // Apply the incoming damage to each unit, this is where the damage is applied to each unit
        u->takeHit(Projectile);
    }
}


