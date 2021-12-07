#ifndef TOWER_DEFENSE_HEAVYINFANTRY_H
#define TOWER_DEFENSE_HEAVYINFANTRY_H

#include <iostream>
#include "Enemy.h"
#include "MyString.h"

class HeavyInfantry : public Enemy {
private:
    double wall_damage_;
    double wall_attack_radius_;
protected:
    HeavyInfantry(Position position, const MyString &name, double HP, double max_HP, double regeneration_rate,
                  double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                  EntityType type);

    HeavyInfantry(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate,
                  double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                  EntityType type);

    HeavyInfantry(Position position, const MyString &name, double max_HP, double regeneration_rate,
                  double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                  EntityType type);

    HeavyInfantry(int x, int y, const MyString &name, double max_HP, double regeneration_rate,
                  double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                  EntityType type);

public:
    HeavyInfantry(Position position, const MyString &name, double HP, double max_HP, double regeneration_rate,
                  double speed, double damage_coefficient, double wall_damage, double wall_attack_radius);

    HeavyInfantry(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate, double speed,
                  double damage_coefficient, double wall_damage, double wall_attack_radius);

    HeavyInfantry(Position position, const MyString &name, double max_HP, double regeneration_rate, double speed,
                  double damage_coefficient, double wall_damage, double wall_attack_radius);

    HeavyInfantry(int x, int y, const MyString &name, double max_HP, double regeneration_rate, double speed,
                  double damage_coefficient, double wall_damage, double wall_attack_radius);

    double getWallDamage() const;

    void setWallDamage(double damage);

    double getWallAttackRadius() const;

    void setWallAttackRadius(double radius);

    void update() override;

};


#endif //TOWER_DEFENSE_HEAVYINFANTRY_H
