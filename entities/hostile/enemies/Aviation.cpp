#include "Aviation.h"

Aviation::Aviation(Position position, const MyString &name, double HP, double max_HP, double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition)
        : Enemy(position, name, EntityType::AVIATION, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate, double speed,
                   double damage_coefficient, double wall_damage, int ammunition)
        : Enemy(x, y, name, EntityType::AVIATION, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(Position position, const MyString &name, double max_HP, double regeneration_rate, double speed,
                   double damage_coefficient, double wall_damage, int ammunition)
        : Enemy(position, name, EntityType::AVIATION, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(int x, int y, const MyString &name, double max_HP, double regeneration_rate, double speed,
                   double damage_coefficient, double wall_damage, int ammunition)
        : Enemy(x, y, name, EntityType::AVIATION, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

double Aviation::getWallDamage() const {
    return wall_damage_;
}

void Aviation::setWallDamage(double damage) {
    if (damage < 0) { damage = 0; }
    wall_damage_ = damage;
}

int Aviation::getAmmunition() const {
    return ammunition_;
}

void Aviation::setAmmunition(int ammunition) {
    if (ammunition < 0) { ammunition = 0; }
    ammunition_ = ammunition;
}

void Aviation::update() {
}

Aviation::Aviation(Position position, const MyString &name, double HP, double max_HP, double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition, EntityType type)
        : Enemy(position, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition, EntityType type)
        : Enemy(x, y, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(Position position, const MyString &name, double max_HP, double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition, EntityType type)
        : Enemy(position, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(int x, int y, const MyString &name, double max_HP, double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition, EntityType type)
        : Enemy(x, y, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}
