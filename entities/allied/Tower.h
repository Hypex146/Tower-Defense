#ifndef TOWER_DEFENSE_TOWER_H
#define TOWER_DEFENSE_TOWER_H

#include <iostream>
#include "MyString.h"
#include "Entity.h"
#include "Table.h"

struct LvlSpecificationsForTower {
    double attack_radius_;
    double damage_;
    double fire_rate_;
    double cost_;

    LvlSpecificationsForTower();

    LvlSpecificationsForTower(double attack_radius, double damage, double fire_rate, double cost);
};

class Tower : public Entity {
private:
    MyString name_;
    int lvl_;
    Table<int, LvlSpecificationsForTower> specifications_table_;
public:
    Tower(Position position, const MyString &name, int lvl,
          const Table<int, LvlSpecificationsForTower> &specifications_table);

    Tower(int x, int y, const MyString &name, int lvl,
          const Table<int, LvlSpecificationsForTower> &specifications_table);

    Tower(Position position, const MyString &name, const Table<int, LvlSpecificationsForTower> &specifications_table);

    Tower(int x, int y, const MyString &name, const Table<int, LvlSpecificationsForTower> &specifications_table);

    ~Tower() override = default;

    double getAttackRadius() const;

    double getDamage() const;

    double getFireRate() const;

    double getLvlCost(int lvl) const;

    MyString getName() const;

    int getLvl() const;

    LvlSpecificationsForTower getLvlSpec(int lvl) const;

    void setLvl(int lvl);

    void lvlUp();

    bool possibleUpLvl() const;

    bool canUpLvl() const;

};


#endif //TOWER_DEFENSE_TOWER_H
