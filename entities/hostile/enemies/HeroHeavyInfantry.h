#ifndef TOWER_DEFENSE_HEROHEAVYINFANTRY_H
#define TOWER_DEFENSE_HEROHEAVYINFANTRY_H


class HeroHeavyInfantry : public HeavyInfantry, public Hero {
public:
    HeroHeavyInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP, double regeneration_rate,
                      double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                      BuffsAura buffs_aura);

    HeroHeavyInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate,
                      double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                      BuffsAura buffs_aura);

    HeroHeavyInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP, double regeneration_rate,
                      double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                      BuffsAura buffs_aura);

    HeroHeavyInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP, double regeneration_rate,
                      double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                      BuffsAura buffs_aura);

    BuffsAura getBuffsAura();

    void setBuffsAura(BuffsAura buffs_aura);

};


#endif //TOWER_DEFENSE_HEROHEAVYINFANTRY_H
