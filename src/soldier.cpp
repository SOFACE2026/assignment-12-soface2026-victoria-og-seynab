#include "soldier.hpp"
#include "weapon.hpp"

#include <sstream>
#include <iostream>

Soldier::Soldier(std::string name, Weapon *weapon) : weapon(weapon), name(name)
{

}

void Soldier::shootAt(Unit &unit)
{
    // We delegate the action to the equipped weapon, 
    // We use '&unit' to pass the memory address of the target unit to the weapon.
    this->weapon->shootAt(&unit);
}

void Soldier::takeHit(Projectile &projectile)
{
    // Using a stringstream to create the message, this is more efficient
    std::stringstream ss;
    // Create the message, this is where the damage is calculated and the message is created
    ss << this->name << " got hit for " << projectile.damage << " damage";
    
    // Create a new UnitEvent and store the message in it, this is where the event is created and the message is stored in it
    UnitEvent event;
    event.message = ss.str();

    // Notify the observers of the event, this is where the message is sent to the observers
    this->notify(event);

}


