#define ALL_INCLUDE

#include "AllHeaders.h"
#include "HeavyInfantry.h"


HeavyInfantry::HeavyInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double HP,
                             double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double wall_damage,
                             double wall_attack_radius)
        : Enemy(tower_defense, position, name, EntityType::HEAVY_INFANTRY, HP, max_HP, regeneration_rate, speed,
                damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                             double regeneration_rate,
                             double speed, double damage_coefficient, double wall_damage, double wall_attack_radius)
        : Enemy(tower_defense, x, y, name, EntityType::HEAVY_INFANTRY, HP, max_HP, regeneration_rate, speed,
                damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                             double regeneration_rate,
                             double speed, double damage_coefficient, double wall_damage, double wall_attack_radius)
        : Enemy(tower_defense, position, name, EntityType::HEAVY_INFANTRY, max_HP, regeneration_rate, speed,
                damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                             double regeneration_rate, double speed,
                             double damage_coefficient, double wall_damage, double wall_attack_radius)
        : Enemy(tower_defense, x, y, name, EntityType::HEAVY_INFANTRY, max_HP, regeneration_rate, speed,
                damage_coefficient) {
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

HeavyInfantry::HeavyInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double HP,
                             double max_HP,
                             double regeneration_rate, double speed, double damage_coefficient, double wall_damage,
                             double wall_attack_radius, EntityType type)
        : Enemy(tower_defense, position, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                             double regeneration_rate,
                             double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                             EntityType type)
        : Enemy(tower_defense, x, y, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                             double regeneration_rate,
                             double speed, double damage_coefficient, double wall_damage, double wall_attack_radius,
                             EntityType type)
        : Enemy(tower_defense, position, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

HeavyInfantry::HeavyInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                             double regeneration_rate, double speed,
                             double damage_coefficient, double wall_damage, double wall_attack_radius,
                             EntityType type)
        : Enemy(tower_defense, x, y, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    wall_attack_radius_ = wall_attack_radius;
}

void HeavyInfantry::tryAttackWall() {
    List<EntityType> filter;
    filter.insert(EntityType::WALL, 0);
    Wall *wall = (Wall *) (tower_defense_->getEntitiesManager()->getNearbyEntity(position_, filter));
    if (wall != nullptr) {
        if (wall->getDistance(*this) <= wall_attack_radius_) {
            wall->takeDamage(wall_damage_ * buffs_.damage_coefficient_);
        }
    }
}

void HeavyInfantry::move() {
    count_of_steps_ += speed_ * buffs_.speed_;
    while (count_of_steps_ >= 1 && isAlive()) {
        int next_step = tower_defense_->getGameMap()->getRoadGraphWithWall()->getNextStep(position_,
                                                                                          tower_defense_->getEntitiesManager()->getCastle()->getPos());
        if (next_step == -1) { return; }
        Position next_position = tower_defense_->getGameMap()->getRoadGraphWithWall()->getVertexByIndex(next_step).id_;
        List<EntityType> filter;
        filter.insert(EntityType::WALL, 0);
        if (!tower_defense_->getEntitiesManager()->hasEntityHere(next_position,
                                                                 filter)) { position_ = next_position; }
        count_of_steps_--;
        tryAttackWall();
        tryAttackCastle();
    }
}

void HeavyInfantry::update() {
    Enemy::update();
    addHP(regeneration_rate_ * buffs_.regeneration_rate_);
    move();
}
