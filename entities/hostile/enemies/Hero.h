#ifndef TOWER_DEFENSE_HERO_H
#define TOWER_DEFENSE_HERO_H


struct BuffsAura {
    double speed_ = 0;
    double max_HP_ = 0;
    double regeneration_rate_ = 0;
    double damage_coefficient_ = 0;
    double damage_resist_ = 0;

    BuffsAura() = default;

    BuffsAura(double speed, double max_HP, double regeneration_rate, double damage_coefficient, double damage_resist);
};


class Hero {
protected:
    BuffsAura buffs_aura_;
public:
    Hero() = default;

    BuffsAura getBuffsAura() const;
};


#endif //TOWER_DEFENSE_HERO_H
