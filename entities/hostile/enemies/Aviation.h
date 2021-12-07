#ifndef TOWER_DEFENSE_AVIATION_H
#define TOWER_DEFENSE_AVIATION_H

#include <iostream>
#include "Enemy.h"
#include "MyString.h"

class Aviation : public Enemy {
private:
    double wall_damage_;
    int ammunition_;
protected:
    Aviation(Position position, const MyString &name, double HP, double max_HP, double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition, EntityType type);

    Aviation(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition, EntityType type);

    Aviation(Position position, const MyString &name, double max_HP, double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition, EntityType type);

    Aviation(int x, int y, const MyString &name, double max_HP, double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition, EntityType type);

public:
    Aviation(Position position, const MyString &name, double HP, double max_HP, double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition);

    Aviation(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition);

    Aviation(Position position, const MyString &name, double max_HP, double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition);

    Aviation(int x, int y, const MyString &name, double max_HP, double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition);

    double getWallDamage() const;

    void setWallDamage(double damage);

    int getAmmunition() const;

    void setAmmunition(int ammunition);

    void update() override;

};


#endif //TOWER_DEFENSE_AVIATION_H
