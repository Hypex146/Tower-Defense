#ifndef TOWER_DEFENSE_HEROLIGHTINFANTRY_H
#define TOWER_DEFENSE_HEROLIGHTINFANTRY_H


class HeroLightInfantry : public LightInfantry, public Hero {
public:
    HeroLightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP,
                      double regeneration_rate,
                      double speed, double damage_coefficient, double dodge_chance, BuffsAura buffs_aura);

    HeroLightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                      double regeneration_rate,
                      double speed, double damage_coefficient, double dodge_chance, BuffsAura buffs_aura);

    HeroLightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                      double regeneration_rate,
                      double speed, double damage_coefficient, double dodge_chance, BuffsAura buffs_aura);

    HeroLightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                      double regeneration_rate,
                      double speed, double damage_coefficient, double dodge_chance, BuffsAura buffs_aura);

    BuffsAura getBuffsAura();

    void setBuffsAura(BuffsAura buffs_aura);

};


#endif //TOWER_DEFENSE_HEROLIGHTINFANTRY_H
