#include "Tower.h"

LvlSpecificationsForTower::LvlSpecificationsForTower() : attack_radius_(-1), damage_(-1), fire_rate_(-1), cost_(-1) {}

LvlSpecificationsForTower::LvlSpecificationsForTower(double attack_radius, double damage, double fire_rate,
                                                     double cost) : attack_radius_(attack_radius), damage_(damage),
                                                                    fire_rate_(fire_rate), cost_(cost) {}

Tower::Tower(Position position, const MyString &name, int lvl,
             const Table<int, LvlSpecificationsForTower> &specifications_table) : Entity(position, EntityType::TOWER,
                                                                                         name) {
    lvl_ = lvl;
    specifications_table_ = specifications_table;
}

Tower::Tower(int x, int y, const MyString &name, int lvl,
             const Table<int, LvlSpecificationsForTower> &specifications_table) : Entity(x, y, EntityType::TOWER,
                                                                                         name) {
    lvl_ = lvl;
    specifications_table_ = specifications_table;
}

Tower::Tower(Position position, const MyString &name, const Table<int,
        LvlSpecificationsForTower> &specifications_table) : Entity(position, EntityType::TOWER, name) {
    lvl_ = 1;
    specifications_table_ = specifications_table;
}

Tower::Tower(int x, int y, const MyString &name, const Table<int, LvlSpecificationsForTower> &specifications_table)
        : Entity(x, y, EntityType::TOWER, name) {
    lvl_ = 1;
    specifications_table_ = specifications_table;
}

double Tower::getAttackRadius() const {
    return specifications_table_.getInfoByIndex(lvl_ - 1).attack_radius_;
}

double Tower::getDamage() const {
    return specifications_table_.getInfoByIndex(lvl_ - 1).damage_;
}

double Tower::getFireRate() const {
    return specifications_table_.getInfoByIndex(lvl_ - 1).fire_rate_;
}

double Tower::getLvlCost(int lvl) const {
    if (lvl > specifications_table_.getCurrentSize()) { throw std::invalid_argument("Exceeding the maximum level!"); }
    return specifications_table_.getInfoByIndex(lvl - 1).cost_;
}

int Tower::getLvl() const {
    return lvl_;
}

LvlSpecificationsForTower Tower::getLvlSpec(int lvl) const {
    if (lvl > specifications_table_.getCurrentSize()) { throw std::invalid_argument("Exceeding the maximum level!"); }
    return specifications_table_.getInfoByIndex(lvl - 1);
}

void Tower::setLvl(int lvl) {
    if (lvl > specifications_table_.getCurrentSize()) { throw std::invalid_argument("Exceeding the maximum level!"); }
    if (lvl <= 0) { throw std::invalid_argument("Lvl <= 0 ?!"); }
    lvl_ = lvl;
}

void Tower::lvlUp() {
    //TODO
}

bool Tower::possibleUpLvl() const {
    return lvl_ + 1 <= specifications_table_.getCurrentSize();
}

bool Tower::canUpLvl() const {
    return false; //TODO
}

void Tower::update() {
    //TODO
}
