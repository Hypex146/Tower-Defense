#define ALL_INCLUDE

#include "AllHeaders.h"

LvlSpecificationsForTower::LvlSpecificationsForTower() : attack_radius_(-1), damage_(-1), reload_time_(-1), cost_(-1) {}

LvlSpecificationsForTower::LvlSpecificationsForTower(double attack_radius, double damage, double fire_rate,
                                                     double cost) : attack_radius_(attack_radius), damage_(damage),
                                                                    reload_time_(fire_rate), cost_(cost) {}

Tower::Tower(TowerDefense *tower_defense, Position position, const MyString &name, int lvl,
             const Table<int, LvlSpecificationsForTower> &specifications_table) : Entity(tower_defense, position,
                                                                                         EntityType::TOWER,
                                                                                         name) {
    lvl_ = lvl;
    specifications_table_ = specifications_table;
    timeToFire_ = 0;
    enemy_filter_ = createEnemyFilter();
}

Tower::Tower(TowerDefense *tower_defense, int x, int y, const MyString &name, int lvl,
             const Table<int, LvlSpecificationsForTower> &specifications_table) : Entity(tower_defense, x, y,
                                                                                         EntityType::TOWER,
                                                                                         name) {
    lvl_ = lvl;
    specifications_table_ = specifications_table;
    timeToFire_ = 0;
    enemy_filter_ = createEnemyFilter();
}

Tower::Tower(TowerDefense *tower_defense, Position position, const MyString &name, const Table<int,
        LvlSpecificationsForTower> &specifications_table) : Entity(tower_defense, position, EntityType::TOWER, name) {
    lvl_ = 1;
    specifications_table_ = specifications_table;
    timeToFire_ = 0;
    enemy_filter_ = createEnemyFilter();
}

Tower::Tower(TowerDefense *tower_defense, int x, int y, const MyString &name,
             const Table<int, LvlSpecificationsForTower> &specifications_table)
        : Entity(tower_defense, x, y, EntityType::TOWER, name) {
    lvl_ = 1;
    specifications_table_ = specifications_table;
    timeToFire_ = 0;
    enemy_filter_ = createEnemyFilter();
}

double Tower::getAttackRadius() const {
    return specifications_table_.getInfoByIndex(lvl_ - 1).attack_radius_;
}

double Tower::getDamage() const {
    return specifications_table_.getInfoByIndex(lvl_ - 1).damage_;
}

double Tower::getFireRate() const {
    return specifications_table_.getInfoByIndex(lvl_ - 1).reload_time_;
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
    if (!canUpLvl()) { throw std::invalid_argument("You can not up lvl!"); }
    tower_defense_->getEntitiesManager()->getCastle()->addGold(getLvlCost(lvl_ + 1) * (-1));
    setLvl(lvl_ + 1);
}

bool Tower::possibleUpLvl() const {
    return lvl_ + 1 <= specifications_table_.getCurrentSize();
}

bool Tower::canUpLvl() const {
    return possibleUpLvl() && tower_defense_->getEntitiesManager()->getCastle()->getGold() >= getLvlCost(lvl_ + 1);
}

void Tower::update() {
    if (canFire()) {
        auto *enemy = (Enemy *) (tower_defense_->getEntitiesManager()->getNearbyEntity(position_, enemy_filter_));
        if (enemy == nullptr) { return; }
        if (enemy->getDistance(*this) <= specifications_table_.getInfoByIndex(lvl_ - 1).attack_radius_) {
            enemy->takeDamage(specifications_table_.getInfoByIndex(lvl_ - 1).damage_);
            timeToFire_ = specifications_table_.getInfoByIndex(lvl_ - 1).reload_time_;
        }
    } else {
        if (timeToFire_ > 0) { timeToFire_ -= 1; }
        if (timeToFire_ < 0) { timeToFire_ = 0; }
    }
}

bool Tower::canFire() const {
    return timeToFire_ <= 0;
}

List<EntityType> Tower::createEnemyFilter() {
    List<EntityType> filter;
    filter.insert(EntityType::HERO_AVIATION, 0);
    filter.insert(EntityType::HERO_HEAVY_INFANTRY, 0);
    filter.insert(EntityType::HERO_LIGHT_INFANTRY, 0);
    filter.insert(EntityType::LIGHT_INFANTRY, 0);
    filter.insert(EntityType::AVIATION, 0);
    filter.insert(EntityType::HEAVY_INFANTRY, 0);
    return filter;
}
