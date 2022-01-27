#define ALL_INCLUDE

#include "AllHeaders.h"
#include "LightInfantry.h"


LightInfantry::LightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double HP,
                             double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double dodge_chance)
        : Enemy(tower_defense, position, name, EntityType::LIGHT_INFANTRY, HP, max_HP, regeneration_rate, speed,
                damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

LightInfantry::LightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double dodge_chance)
        : Enemy(tower_defense, position, name, EntityType::LIGHT_INFANTRY, max_HP, regeneration_rate, speed,
                damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

LightInfantry::LightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double dodge_chance)
        : Enemy(tower_defense, x, y, name, EntityType::LIGHT_INFANTRY, HP, max_HP, regeneration_rate, speed,
                damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

LightInfantry::LightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double dodge_chance)
        : Enemy(tower_defense, x, y, name, EntityType::LIGHT_INFANTRY, max_HP, regeneration_rate, speed,
                damage_coefficient) {
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

LightInfantry::LightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double HP,
                             double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double dodge_chance,
                             EntityType type)
        : Enemy(tower_defense, position, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

LightInfantry::LightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                             double regeneration_rate,
                             double speed, double damage_coefficient, double dodge_chance, EntityType type)
        : Enemy(tower_defense, x, y, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

LightInfantry::LightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                             double regeneration_rate,
                             double speed, double damage_coefficient, double dodge_chance, EntityType type)
        : Enemy(tower_defense, position, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

LightInfantry::LightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                             double regeneration_rate, double speed,
                             double damage_coefficient, double dodge_chance, EntityType type)
        : Enemy(tower_defense, x, y, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    dodge_chance_ = dodge_chance;
}

void LightInfantry::move() {
    count_of_steps_ += speed_ * buffs_.speed_;
    while (count_of_steps_ >= 1 && isAlive()) {
        if (tower_defense_->getGameMap()->getRoadGraph()->hasWay(position_,
                                                                 tower_defense_->getEntitiesManager()->getCastle()->getPos())) {
            int next_step = tower_defense_->getGameMap()->getRoadGraph()->getNextStep(position_,
                                                                                      tower_defense_->getEntitiesManager()->getCastle()->getPos());
            if (next_step == -1) { return; }
            Position next_position = tower_defense_->getGameMap()->getRoadGraph()->getVertexByIndex(next_step).id_;
            position_ = next_position;
        } else {
            int next_step = tower_defense_->getGameMap()->getRoadGraphWithWall()->getNextStep(position_,
                                                                                              tower_defense_->getEntitiesManager()->getCastle()->getPos());
            if (next_step == -1) { return; }
            Position next_position = tower_defense_->getGameMap()->getRoadGraphWithWall()->getVertexByIndex(
                    next_step).id_;
            List<EntityType> filter;
            filter.insert(EntityType::WALL, 0);
            if (!tower_defense_->getEntitiesManager()->hasEntityHere(next_position,
                                                                     filter)) { position_ = next_position; }
        };
        count_of_steps_--;
        tryAttackCastle();
    }
}

void LightInfantry::update() {
    Enemy::update();
    addHP(regeneration_rate_ * buffs_.regeneration_rate_);
    move();
}
