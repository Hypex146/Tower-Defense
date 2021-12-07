#ifndef TOWER_DEFENSE_CASTLE_H
#define TOWER_DEFENSE_CASTLE_H

#include <iostream>
#include "Entity.h"
#include "Table.h"
#include "MyString.h"

struct LvlSpecificationsForCastle {
    double profitability_;
    double max_HP_;
    double repair_rate_;
    double cost_;

    LvlSpecificationsForCastle();

    LvlSpecificationsForCastle(double profitability, double max_HP, double repair_speed, double cost);
};

class Castle : public Entity {
private:
    int lvl_;
    double HP_;
    double gold_;
    Table<int, LvlSpecificationsForCastle> specifications_table_;
public:
    Castle(Position position, const MyString &name, int lvl, double current_HP, double current_gold,
           const Table<int, LvlSpecificationsForCastle> &specifications_table);

    Castle(int x, int y, const MyString &name, int lvl, double current_HP, double current_gold,
           const Table<int, LvlSpecificationsForCastle> &specifications_table);

    Castle(Position position, const MyString &name, double current_gold,
           const Table<int, LvlSpecificationsForCastle> &specifications_table);

    Castle(int x, int y, const MyString &name, double current_gold,
           const Table<int, LvlSpecificationsForCastle> &specifications_table);

    ~Castle() override = default;

    double getProfitability() const;

    double getMaxHP() const;

    double getRepairSpeed() const;

    int getLvl() const;

    double getHP() const;

    double getGold() const;

    double getLvlCost(int lvl) const;

    LvlSpecificationsForCastle getLvlSpec(int lvl) const;

    void setGold(double current_gold);

    void addGold(double gold);

    void setHP(double current_HP);

    void setLvl(int lvl);

    void lvlUp();

    bool possibleUpLvl() const;

    bool canUpLvl() const;

    void takeDamage(double damage);

    void update() override;

};

#endif //TOWER_DEFENSE_CASTLE_H
