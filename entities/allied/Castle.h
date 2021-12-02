#ifndef TOWER_DEFENSE_CASTLE_H
#define TOWER_DEFENSE_CASTLE_H

#include <iostream>
#include "Entity.h"
#include "Table.h"
#include "MyString.h"

struct Lvl_Specifications {
    double profitability_;
    double max_HP_;
    double repair_speed_;
    double cost_;

    Lvl_Specifications(double profitability, double max_HP, double repair_speed, double cost);
};

class Castle : public Entity {
private:
    MyString name_;
    int lvl_;
    double current_HP_;
    double current_gold_;
    Table<int, Lvl_Specifications> specifications_table_;
public:
    Castle(Position position, const MyString &name, int lvl, double current_HP, double current_gold,
           const Table<int, Lvl_Specifications> &specifications_table);

    Castle(int x, int y, const MyString &name, int lvl, double current_HP, double current_gold,
           const Table<int, Lvl_Specifications> &specifications_table);

    Castle(Position position, const MyString &name, double current_gold,
           const Table<int, Lvl_Specifications> &specifications_table);

    Castle(int x, int y, const MyString &name, double current_gold,
           const Table<int, Lvl_Specifications> &specifications_table);

    ~Castle() override = default;

    double getProfitability() const;

    double getMaxHP() const;

    double getRepairSpeed() const;

    MyString getName() const;

    int getLvl() const;

    double getCurrentHP() const;

    double getCurrentGold() const;

    Lvl_Specifications getLvlSpecByLvl(int lvl) const;

    void setCurrentGold(double current_gold);

    void setCurrentHP(double current_HP);

    void setLvl(int lvl);

};

#endif //TOWER_DEFENSE_CASTLE_H
