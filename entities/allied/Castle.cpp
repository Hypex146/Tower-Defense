#include "Castle.h"

Lvl_Specifications::Lvl_Specifications(double profitability, double max_HP, double repair_speed, double cost) :
        profitability_(profitability), max_HP_(max_HP), repair_speed_(repair_speed), cost_(cost) {}

Lvl_Specifications::Lvl_Specifications() : profitability_(-1), max_HP_(-1), repair_speed_(-1), cost_(-1) {}

Castle::Castle(Position position, const MyString &name, int lvl, double current_HP, double current_gold,
               const Table<int, Lvl_Specifications> &specifications_table) : Entity(position, EntityType::CASTLE) {
    if (lvl > specifications_table.getCurrentSize()) { throw std::invalid_argument("Exceeding the maximum level!"); }
    if (current_HP <= 0) { throw std::invalid_argument("current_HP = 0 ?!"); }
    if (current_HP > specifications_table.getInfoByIndex(lvl - 1).max_HP_) {
        throw std::invalid_argument("Exceeding the maximum HP!");
    }
    name_ = name;
    lvl_ = lvl;
    HP_ = current_HP;
    gold_ = current_gold;
    specifications_table_ = specifications_table;
}

Castle::Castle(int x, int y, const MyString &name, int lvl, double current_HP, double current_gold,
               const Table<int, Lvl_Specifications> &specifications_table) : Entity(x, y, EntityType::CASTLE) {
    if (lvl > specifications_table.getCurrentSize()) { throw std::invalid_argument("Exceeding the maximum level!"); }
    if (current_HP <= 0) { throw std::invalid_argument("current_HP = 0 ?!"); }
    if (current_HP > specifications_table.getInfoByIndex(lvl - 1).max_HP_) {
        throw std::invalid_argument("Exceeding the maximum HP!");
    }
    name_ = name;
    lvl_ = lvl;
    HP_ = current_HP;
    gold_ = current_gold;
    specifications_table_ = specifications_table;
}

Castle::Castle(Position position, const MyString &name, double current_gold,
               const Table<int, Lvl_Specifications> &specifications_table)
        : Entity(position, EntityType::CASTLE) {
    name_ = name;
    gold_ = current_gold;
    specifications_table_ = specifications_table;
    lvl_ = 1;
    HP_ = specifications_table_.getInfoByIndex(lvl_ - 1).max_HP_;
}

Castle::Castle(int x, int y, const MyString &name, double current_gold,
               const Table<int, Lvl_Specifications> &specifications_table) : Entity(x, y, EntityType::CASTLE) {
    name_ = name;
    gold_ = current_gold;
    specifications_table_ = specifications_table;
    lvl_ = 1;
    HP_ = specifications_table_.getInfoByIndex(lvl_ - 1).max_HP_;
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

double Castle::getHP() const {
    return HP_;
}

double Castle::getGold() const {
    return gold_;
}

Lvl_Specifications Castle::getLvlSpec(int lvl) const {
    return specifications_table_.getInfoByIndex(lvl - 1);
}

void Castle::setGold(double current_gold) {
    gold_ = current_gold;
}

void Castle::setHP(double current_HP) {
    if (current_HP > specifications_table_.getInfoByIndex(lvl_ - 1).max_HP_) {
        throw std::invalid_argument("Exceeding the maximum HP!");
    }
    HP_ = current_HP;
    if (HP_ <= 0) { kill(); }
}

void Castle::setLvl(int lvl) {
    if (lvl > specifications_table_.getCurrentSize()) { throw std::invalid_argument("Exceeding the maximum level!"); }
    if (lvl <= 0) { throw std::invalid_argument("Lvl <= 0 ?!"); }
    lvl_ = lvl;
}

bool Castle::possibleUpLvl() const {
    return lvl_ + 1 <= specifications_table_.getCurrentSize();
}

void Castle::lvlUp() {
    if (!canUpLvl()) { throw std::invalid_argument("You can not up lvl!"); }
    gold_ -= getLvlCost(lvl_ + 1);
    setLvl(lvl_ + 1);
}

void Castle::takeDamage(double damage) {
    setHP(HP_ - damage);
    if (HP_ <= 0) { kill(); }
}

double Castle::getLvlCost(int lvl) const {
    if (lvl > specifications_table_.getCurrentSize()) { throw std::invalid_argument("Exceeding the maximum level!"); }
    return specifications_table_.getInfoByIndex(lvl - 1).cost_;
}

bool Castle::canUpLvl() const {
    return possibleUpLvl() && gold_ >= getLvlCost(lvl_ + 1);
}

void Castle::addGold(double gold) {
    setGold(gold_ + gold);
}
