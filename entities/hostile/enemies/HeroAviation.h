#ifndef TOWER_DEFENSE_HEROAVIATION_H
#define TOWER_DEFENSE_HEROAVIATION_H

#include <iostream>
#include "MyString.h"
#include "Aviation.h"

class HeroAviation : public Aviation {
private:
    BuffsAura buffs_aura_;
public:
    HeroAviation(Position position, const MyString &name, double HP, double max_HP, double regeneration_rate,
                 double speed, double damage_coefficient, double wall_damage, int ammunition, BuffsAura buffs_aura);

    HeroAviation(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate,
                 double speed, double damage_coefficient, double wall_damage, int ammunition, BuffsAura buffs_aura);

    HeroAviation(Position position, const MyString &name, double max_HP, double regeneration_rate,
                 double speed, double damage_coefficient, double wall_damage, int ammunition, BuffsAura buffs_aura);

    HeroAviation(int x, int y, const MyString &name, double max_HP, double regeneration_rate,
                 double speed, double damage_coefficient, double wall_damage, int ammunition, BuffsAura buffs_aura);

    BuffsAura getBuffsAura();

    void setBuffsAura(BuffsAura buffs_aura);

};


#endif //TOWER_DEFENSE_HEROAVIATION_H
