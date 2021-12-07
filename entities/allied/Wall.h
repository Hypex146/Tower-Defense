#ifndef TOWER_DEFENSE_WALL_H
#define TOWER_DEFENSE_WALL_H

#include <iostream>
#include "Entity.h"
#include "MyString.h"

class Wall : public Entity {
private:
    double HP_;
    double max_HP_;
public:
    Wall(Position pos, const MyString &name, double HP, double max_HP);

    Wall(int x, int y, const MyString &name, double HP, double max_HP);

    Wall(Position pos, const MyString &name, double max_HP);

    Wall(int x, int y, const MyString &name, double max_HP);

    ~Wall() override = default;

    double getHP() const;

    double getMaxHP() const;

    void setHP(double HP);

    void takeDamage(double damage);

    void fix(double HP);

    void update() override;

};

#endif //TOWER_DEFENSE_WALL_H
