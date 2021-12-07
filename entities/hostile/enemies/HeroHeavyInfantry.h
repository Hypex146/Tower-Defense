#ifndef TOWER_DEFENSE_HEROHEAVYINFANTRY_H
#define TOWER_DEFENSE_HEROHEAVYINFANTRY_H

#include <iostream>
#include "MyString.h"
#include "HeavyInfantry.h"

class HeroHeavyInfantry : public HeavyInfantry {
private:
    BuffsAura buffs_aura_;
public:
    HeroHeavyInfantry(Position position, const MyString &name, double HP, double max_HP, double regeneration_rate,
                      double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                      BuffsAura buffs_aura);

    HeroHeavyInfantry(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate,
                      double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                      BuffsAura buffs_aura);

    HeroHeavyInfantry(Position position, const MyString &name, double max_HP, double regeneration_rate,
                      double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                      BuffsAura buffs_aura);

    HeroHeavyInfantry(int x, int y, const MyString &name, double max_HP, double regeneration_rate,
                      double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                      BuffsAura buffs_aura);

    BuffsAura getBuffsAura();

    void setBuffsAura(BuffsAura buffs_aura);

};


#endif //TOWER_DEFENSE_HEROHEAVYINFANTRY_H
