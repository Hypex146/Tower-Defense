#include "Wall.h"

Wall::Wall(Position pos, const MyString &name, double HP, double max_HP) : Entity(pos, EntityType::WALL) {
    if (HP > max_HP) { throw std::invalid_argument("Exceeding the maximum HP!"); }
    name_ = name;
    HP_ = HP;
    max_HP_ = max_HP;
}

Wall::Wall(int x, int y, const MyString &name, double HP, double max_HP) : Entity(x, y, EntityType::WALL) {
    if (HP > max_HP) { throw std::invalid_argument("Exceeding the maximum HP!"); }
    name_ = name;
    HP_ = HP;
    max_HP_ = max_HP;
}

Wall::Wall(Position pos, const MyString &name, double max_HP) : Entity(pos, EntityType::WALL) {
    name_ = name;
    max_HP_ = max_HP;
    HP_ = max_HP;
}

Wall::Wall(int x, int y, const MyString &name, double max_HP) : Entity(x, y, EntityType::WALL) {
    name_ = name;
    max_HP_ = max_HP;
    HP_ = max_HP;
}

MyString Wall::getName() const {
    return name_;
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


