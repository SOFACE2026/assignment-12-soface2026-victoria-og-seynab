#include "unit_selection.hpp"
#include "weapon.hpp"

void UnitSelection::addToSelection(Unit &unit)
{
    //Tager adressen på enheden for at gemme den som en pointer
    this->selected.push_back(&unit);

    /**
     * Ved at gemme pointere til 'Unit', kan UnitSelection indeholde både enkelte 'Soldier'-objekter og andre 
     * 'UnitSelection'-objekter. Det gør sådan at vi kan rekursivt genbruge. 
     * Vi genbruger eksisterende 'Unit'-objekter uden at kopiere dem, hvilket sparer hukommelse
     */
}

// Denne funktion gør det muligt for en hel samling af enheder at angribe ét mål samtidigt.
void UnitSelection::shootAt(Unit &unit)
{
    //Løber igennem alle gemte enheder i vores vektor
    //For hver enhed i udvalget kalder vi dens specifikke shootAt-metode
    for (auto &u : this->selected)
    {
        u->shootAt(unit);
    }
}

// Denne funktion gør det muligt for et projektil at ramme alle enheder i udvalget.
void UnitSelection::takeHit(Projectile &Projectile)
{
    for (auto &u : this->selected)
    {
        //Kalder takeHit på den enkelte enhed (u). 
        // Hvis 'u' er en Soldier, kører dens takeHit.
        u->takeHit(Projectile);
    }

    /**
     * Da UnitSelection arver fra Unit, kan den modtage et Projectile præcis som en enkelt soldat. 
     * Vi genbruger (delegerer til) den eksisterende takeHit() i de enkelte Unit-objekter.
     * Da hver enkelt Soldier i gruppen kalder sin egen takeHit(), vil de hver især sende en notify() besked. 
     * BattleMonitor vil derfor automatisk logge hvert enkelt hit.
     */
}
