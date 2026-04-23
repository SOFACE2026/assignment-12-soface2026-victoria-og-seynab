#include "revolver.hpp"

Revolver::Revolver() : projectile(1) //initialiserer projektilet i constructor
{
}

Projectile &Revolver::get_projectile()
{
    return this->projectile; //returnerer en reference til projektilet, der er lagret i objektet
}