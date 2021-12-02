#include "Castle.h"


Lvl_Specifications::Lvl_Specifications(double profitability, double max_HP, double repair_speed, double cost) :
        profitability_(profitability), max_HP_(max_HP), repair_speed_(repair_speed), cost_(cost) {}


Castle::Castle(Position position, const MyString &name, int lvl, double current_HP, double current_gold,
               const Table<int, Lvl_Specifications> &specifications_table) : Entity(position, EntityType::CASTLE) {
    name_ = name;
    lvl_ = lvl;
    current_HP_ = current_HP;
    current_gold_ = current_gold;
    specifications_table_ = specifications_table;
}

Castle::Castle(int x, int y, const MyString &name, int lvl, double current_HP, double current_gold,
               const Table<int, Lvl_Specifications> &specifications_table) : Entity(x, y, EntityType::CASTLE) {
    name_ = name;
    lvl_ = lvl;
    current_HP_ = current_HP;
    current_gold_ = current_gold;
    specifications_table_ = specifications_table;
}

Castle::Castle(Position position, const MyString &name, double current_gold,
               const Table<int, Lvl_Specifications> &specifications_table)
        : Entity(position, EntityType::CASTLE) {
    name_ = name;
    current_gold_ = current_gold;
    specifications_table_ = specifications_table;
    lvl_ = 1;
    current_HP_ = specifications_table_.getInfoByIndex(lvl_ - 1).max_HP_;
}

Castle::Castle(int x, int y, const MyString &name, double current_gold,
               const Table<int, Lvl_Specifications> &specifications_table) : Entity(x, y, EntityType::CASTLE) {
    name_ = name;
    current_gold_ = current_gold;
    specifications_table_ = specifications_table;
    lvl_ = 1;
    current_HP_ = specifications_table_.getInfoByIndex(lvl_ - 1).max_HP_;
}

double Castle::getProfitability() const {
    return specifications_table_.getInfoByIndex(lvl_ - 1).profitability_;
}

double Castle::getMaxHP() const {
    return specifications_table_.getInfoByIndex(lvl_ - 1).max_HP_;
}

double Castle::getRepairSpeed() const {
    return specifications_table_.getInfoByIndex(lvl_ - 1).repair_speed_;
}

MyString Castle::getName() const {
    return name_;
}

int Castle::getLvl() const {
    return lvl_;
}

double Castle::getCurrentHP() const {
    return current_HP_;
}

double Castle::getCurrentGold() const {
    return current_gold_;
}

Lvl_Specifications Castle::getLvlSpecByLvl(int lvl) const {
    return specifications_table_.getInfoByIndex(lvl - 1);
}

void Castle::setCurrentGold(double current_gold) {
    current_gold_ = current_gold;
}

void Castle::setCurrentHP(double current_HP) {
    current_HP_ = current_HP;
}

void Castle::setLvl(int lvl) {
    lvl_ = lvl;
}
