#pragma once
#include "weapon.hpp"
#include "projectile.hpp"
class Revolver : public Weapon
{
public:
    Revolver();

private:
    virtual Projectile &get_projectile() override; //gemmer projektilet som en del af objektet

    Projectile projectile;
};