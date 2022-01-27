#define ENTITIES_INCLUDE
#define STD_LIBS_INCLUDE
#define ALL_INCLUDE

#include "AllHeaders.h"


Wall::Wall(TowerDefense *tower_defense, Position pos, const MyString &name, double HP, double max_HP) : Entity(
        tower_defense, pos, EntityType::WALL, name) {
    if (HP > max_HP) { throw std::invalid_argument("Exceeding the maximum HP!"); }
    HP_ = HP;
    max_HP_ = max_HP;
}

Wall::Wall(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP) : Entity(
        tower_defense, x, y, EntityType::WALL, name) {
    if (HP > max_HP) { throw std::invalid_argument("Exceeding the maximum HP!"); }
    HP_ = HP;
    max_HP_ = max_HP;
}

Wall::Wall(TowerDefense *tower_defense, Position pos, const MyString &name, double max_HP) : Entity(tower_defense, pos,
                                                                                                    EntityType::WALL,
                                                                                                    name) {
    max_HP_ = max_HP;
    HP_ = max_HP;
}

Wall::Wall(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP) : Entity(tower_defense, x, y,
                                                                                                    EntityType::WALL,
                                                                                                    name) {
    max_HP_ = max_HP;
    HP_ = max_HP;
}

double Wall::getHP() const {
    return HP_;
}

double Wall::getMaxHP() const {
    return max_HP_;
}

void Wall::setHP(double HP) {
    if (HP > max_HP_) {
        throw std::invalid_argument("Exceeding the maximum HP!");
    }
    HP_ = HP;
    if (HP_ < 0) { HP_ = 0; }
    if (HP_ <= 0) { kill(); }
}

void Wall::takeDamage(double damage) {
    setHP(HP_ - damage);
    if (HP_ <= 0) { kill(); }
}

void Wall::fix(double HP) {
    if (!isAlive()) { return; }
    HP_ += HP;
    if (HP_ > max_HP_) { HP_ = max_HP_; }
}

void Wall::update() {
}

void Wall::kill() {
    if (isAlive()) { tower_defense_->getGameMap()->addRoadCell(position_, true, false); }
    Entity::kill();
}


