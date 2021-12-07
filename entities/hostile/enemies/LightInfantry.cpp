#include "LightInfantry.h"

LightInfantry::LightInfantry(Position position, const MyString &name, double HP, double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double dodge_chance)
        : Enemy(position, name, EntityType::LIGHT_INFANTRY, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

LightInfantry::LightInfantry(Position position, const MyString &name, double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double dodge_chance)
        : Enemy(position, name, EntityType::LIGHT_INFANTRY, max_HP, regeneration_rate, speed, damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

LightInfantry::LightInfantry(int x, int y, const MyString &name, double HP, double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double dodge_chance)
        : Enemy(x, y, name, EntityType::LIGHT_INFANTRY, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

LightInfantry::LightInfantry(int x, int y, const MyString &name, double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double dodge_chance)
        : Enemy(x, y, name, EntityType::LIGHT_INFANTRY, max_HP, regeneration_rate, speed, damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

double LightInfantry::getDodgeChance() const {
    return dodge_chance_;
}

void LightInfantry::setDodgeChance(double dodge_chance) {
    if (dodge_chance > 1) { dodge_chance = 1; }
    if (dodge_chance < 0) { dodge_chance = 0; }
    dodge_chance_ = dodge_chance;
}

bool LightInfantry::dodged() const {
    srand(time(nullptr));
    int random_number = 1 + rand() % 100;
    if (random_number <= (dodge_chance_ * 100)) { return true; }
    return false;
}

void LightInfantry::takeDamage(double damage) {
    if (dodged()) { return; }
    Enemy::takeDamage(damage);
}

void LightInfantry::update() {
}


