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

//Funktionen skal sørge for, at soldaten kan give besked til observatørerne, når han bliver ramt
void Soldier::takeHit(Projectile &projectile) 
{
    //Opretter en stringstream til at bygge beskeden
    std::stringstream ss;

    //Henter navnet fra Soldier og skaden fra projektilet
    ss << this->name << " got hit for " << projectile.damage << " damage";
    
    //Pakker beskeden ind i et UnitEvent objekt
    UnitEvent event;
    event.message = ss.str();

    //Notificerer alle observatører via Subject-interface
    this->notify(event);

    /**
     * Metoden beregner ikke selv skaden, men sender en besked ud til alle observatører.
     * Ved at kalde notify() sikrer vi, at Soldier ikke behøver at vide, hvem der lytter (løs-kobling)
    */

}