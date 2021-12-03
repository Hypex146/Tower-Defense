#ifndef TOWER_DEFENSE_WALL_H
#define TOWER_DEFENSE_WALL_H

#include <iostream>
#include "Entity.h"
#include "MyString.h"

class Wall : public Entity {
private:
    MyString name_;
    double HP_;
    double max_HP_;
public:
    Wall(Position pos, const MyString &name, double HP, double max_HP);

    Wall(int x, int y, const MyString &name, double HP, double max_HP);

    Wall(Position pos, const MyString &name, double max_HP);

    Wall(int x, int y, const MyString &name, double max_HP);

    ~Wall() override = default;

    MyString getName() const;

    double getHP() const;

    double getMaxHP() const;

    void setHP(double HP);

    void takeDamage(double damage);

    void fix(double HP);

};

#endif //TOWER_DEFENSE_WALL_H
