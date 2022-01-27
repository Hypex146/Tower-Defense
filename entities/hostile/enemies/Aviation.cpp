#define ALL_INCLUDE

#include "AllHeaders.h"
#include "Aviation.h"


Aviation::Aviation(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP,
                   double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition)
        : Enemy(tower_defense, position, name, EntityType::AVIATION, HP, max_HP, regeneration_rate, speed,
                damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                   double regeneration_rate, double speed,
                   double damage_coefficient, double wall_damage, int ammunition)
        : Enemy(tower_defense, x, y, name, EntityType::AVIATION, HP, max_HP, regeneration_rate, speed,
                damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                   double regeneration_rate, double speed,
                   double damage_coefficient, double wall_damage, int ammunition)
        : Enemy(tower_defense, position, name, EntityType::AVIATION, max_HP, regeneration_rate, speed,
                damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                   double regeneration_rate, double speed,
                   double damage_coefficient, double wall_damage, int ammunition)
        : Enemy(tower_defense, x, y, name, EntityType::AVIATION, max_HP, regeneration_rate, speed, damage_coefficient) {
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

Aviation::Aviation(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP,
                   double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition, EntityType type)
        : Enemy(tower_defense, position, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                   double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition, EntityType type)
        : Enemy(tower_defense, x, y, name, type, HP, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                   double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition, EntityType type)
        : Enemy(tower_defense, position, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

Aviation::Aviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                   double regeneration_rate,
                   double speed, double damage_coefficient, double wall_damage, int ammunition, EntityType type)
        : Enemy(tower_defense, x, y, name, type, max_HP, regeneration_rate, speed, damage_coefficient) {
    wall_damage_ = wall_damage;
    ammunition_ = ammunition;
}

void Aviation::tryAttackWall() {
    List<EntityType> filter;
    filter.insert(EntityType::WALL, 0);
    Wall *wall = (Wall *) (tower_defense_->getEntitiesManager()->getNearbyEntity(position_, filter));
    if (wall != nullptr && ammunition_ > 0) {
        wall->takeDamage(wall_damage_ * buffs_.damage_coefficient_);
        ammunition_--;
    }
}

void Aviation::move() {
    count_of_steps_ += speed_ * buffs_.speed_;
    while (count_of_steps_ >= 1 && isAlive()) {
        int dx = tower_defense_->getEntitiesManager()->getCastle()->getPos().x_ - position_.x_;
        int dy = tower_defense_->getEntitiesManager()->getCastle()->getPos().y_ - position_.y_;
        Position next_position = position_;
        if (dx != 0 && dy != 0) {
            if (tower_defense_->random(1, 2) == 1) {
                if (dx > 0) { next_position.x_ += 1; }
                else { next_position.x_ -= 1; }
            } else {
                if (dy > 0) { next_position.y_ += 1; }
                else { next_position.y_ -= 1; }
            }
        } else if (dx != 0) {
            if (dx > 0) { next_position.x_ += 1; }
            else { next_position.x_ -= 1; }
        } else {
            if (dy > 0) { next_position.y_ += 1; }
            else { next_position.y_ -= 1; }
        }
        position_ = next_position;
        count_of_steps_--;
        tryAttackWall();
        tryAttackCastle();
    }
}

void Aviation::update() {
    Enemy::update();
    addHP(regeneration_rate_ * buffs_.regeneration_rate_);
    move();
}
