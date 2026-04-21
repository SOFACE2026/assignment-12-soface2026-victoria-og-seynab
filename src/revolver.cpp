#include "revolver.hpp"

// Change the constructor from 0 to 1, this is where the damage of the projectile is set
Revolver::Revolver() : projectile(1)
{
}

Projectile &Revolver::get_projectile()
{
    // Return a reference to the projectile, this allows the weapon to be reused
    return this->projectile;
}

