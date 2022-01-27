#ifndef TOWER_DEFENSE_HEROAVIATION_H
#define TOWER_DEFENSE_HEROAVIATION_H


class HeroAviation : public Aviation, public Hero {
public:
    HeroAviation(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP,
                 double regeneration_rate,
                 double speed, double damage_coefficient, double wall_damage, int ammunition, BuffsAura buffs_aura);

    HeroAviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                 double regeneration_rate,
                 double speed, double damage_coefficient, double wall_damage, int ammunition, BuffsAura buffs_aura);

    HeroAviation(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                 double regeneration_rate,
                 double speed, double damage_coefficient, double wall_damage, int ammunition, BuffsAura buffs_aura);

    HeroAviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                 double regeneration_rate,
                 double speed, double damage_coefficient, double wall_damage, int ammunition, BuffsAura buffs_aura);

    BuffsAura getBuffsAura();

    void setBuffsAura(BuffsAura buffs_aura);

};


#endif //TOWER_DEFENSE_HEROAVIATION_H
