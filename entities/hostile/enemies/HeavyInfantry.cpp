#include "HeavyInfantry.h"

HeavyInfantry::HeavyInfantry(Position position, const MyString &name, double HP, double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double wall_damage,
                             double wall_attack_radius)
        : Enemy(position, name, EntityType::HEAVY_INFANTRY, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate,
                             double speed, double damage_coefficient, double wall_damage, double wall_attack_radius)
        : Enemy(x, y, name, EntityType::HEAVY_INFANTRY, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(Position position, const MyString &name, double max_HP, double regeneration_rate,
                             double speed, double damage_coefficient, double wall_damage, double wall_attack_radius)
        : Enemy(position, name, EntityType::HEAVY_INFANTRY, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(int x, int y, const MyString &name, double max_HP, double regeneration_rate, double speed,
                             double damage_coefficient, double wall_damage, double wall_attack_radius)
        : Enemy(x, y, name, EntityType::HEAVY_INFANTRY, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

double HeavyInfantry::getWallDamage() const {
    return wall_damage_;
}

void HeavyInfantry::setWallDamage(double damage) {
    if (damage < 0) { damage = 0; }
    wall_damage_ = damage;
}

double HeavyInfantry::getWallAttackRadius() const {
    return wall_attack_radius_;
}

void HeavyInfantry::setWallAttackRadius(double radius) {
    if (radius < 0) { radius = 0; }
    wall_attack_radius_ = radius;
}

void HeavyInfantry::update() {
}

HeavyInfantry::HeavyInfantry(Position position, const MyString &name, double HP, double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double wall_damage,
                             double wall_attack_radius, EntityType type)
        : Enemy(position, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate,
                             double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                             EntityType type)
        : Enemy(x, y, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(Position position, const MyString &name, double max_HP, double regeneration_rate,
                             double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                             EntityType type)
        : Enemy(position, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(int x, int y, const MyString &name, double max_HP, double regeneration_rate, double speed,
                             double damage_coefficient, double wall_damage, double wall_attack_radius,
                             EntityType type)
        : Enemy(x, y, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}
