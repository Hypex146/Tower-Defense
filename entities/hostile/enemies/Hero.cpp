#define ALL_INCLUDE
#include "AllHeaders.h"
#include "Hero.h"


BuffsAura::BuffsAura(double speed, double max_HP, double regeneration_rate, double damage_coefficient,
                     double damage_resist) {
    speed_ = speed;
    max_HP_ = max_HP;
    regeneration_rate_ = regeneration_rate;
    damage_coefficient_ = damage_coefficient;
    damage_resist_ = damage_resist;
}

BuffsAura Hero::getBuffsAura() const {
    return buffs_aura_;
}
