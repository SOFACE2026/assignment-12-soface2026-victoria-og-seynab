#include "soldier.hpp"
#include "weapon.hpp"

#include <sstream>

Soldier::Soldier(std::string name, Weapon *weapon) : weapon(weapon), name(name)
{
}

void Soldier::shootAt(Unit &unit)
{
    //Tjekker ikke for nullptr her, da Soldier-constructoren forventer et våben.
    //Kalder weapon-objektets shootAt-metode og sender målet videre.
    this->weapon->shootAt(unit);

    /**
    * Denne metode kalder Weapon::shootAt for at udføre selve angrebet.
    * Ved at lade Soldier delegere skyde-logikken til Weapon-klassen, opnår vi brug af Software Reuse
    * Vi kan ændre våbenets funktionalitet (f.eks. præcision) uden at skulle rette i Soldier-klassen.
    * Da 'weapon' er en pointer til den abstrakte klasse Weapon, 
    * kan Soldier skyde med ethvert våben (hvis flere våben implementeres), der kommer fra Weapon-interface
    */

}

void Soldier::takeHit(Projectile &projectile)
{
}