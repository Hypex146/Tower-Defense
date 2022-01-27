#define ALL_INCLUDE

#include "AllHeaders.h"
#include "Enemy.h"


Enemy::Enemy(TowerDefense *tower_defense, Position position, const MyString &name, EntityType type, double HP,
             double max_HP,
             double regeneration_rate, double speed, double damage_coefficient) : Entity(tower_defense, position, type,
                                                                                         name) {
    HP_ = HP;
    max_HP_ = max_HP;
    regeneration_rate_ = regeneration_rate;
    speed_ = speed;
    damage_coefficient_ = damage_coefficient;
}

Enemy::Enemy(TowerDefense *tower_defense, int x, int y, const MyString &name, EntityType type, double HP, double max_HP,
             double regeneration_rate,
             double speed, double damage_coefficient) : Entity(tower_defense, x, y, type, name) {
    HP_ = HP;
    max_HP_ = max_HP;
    regeneration_rate_ = regeneration_rate;
    speed_ = speed;
    damage_coefficient_ = damage_coefficient;
}

Enemy::Enemy(TowerDefense *tower_defense, Position position, const MyString &name, EntityType type, double max_HP,
             double regeneration_rate,
             double speed, double damage_coefficient) : Entity(tower_defense, position, type, name) {
    HP_ = max_HP;
    max_HP_ = max_HP;
    regeneration_rate_ = regeneration_rate;
    speed_ = speed;
    damage_coefficient_ = damage_coefficient;
}

Enemy::Enemy(TowerDefense *tower_defense, int x, int y, const MyString &name, EntityType type, double max_HP,
             double regeneration_rate, double speed,
             double damage_coefficient) : Entity(tower_defense, x, y, type, name) {
    HP_ = max_HP;
    max_HP_ = max_HP;
    regeneration_rate_ = regeneration_rate;
    speed_ = speed;
    damage_coefficient_ = damage_coefficient;
}

double Enemy::getHP() const {
    return HP_;
}

double Enemy::getMaxHP() const {
    return max_HP_;
}

double Enemy::getRegenRate() const {
    return regeneration_rate_;
}

double Enemy::getSpeed() const {
    return speed_;
}

double Enemy::getDamageCoeff() const {
    return damage_coefficient_;
}

void Enemy::setHP(double HP) {
    if (HP > max_HP_ * buffs_.max_HP_) { HP = max_HP_ * buffs_.max_HP_; }
    HP_ = HP;
    if (HP_ < 0) { HP_ = 0; }
    if (HP_ <= 0) {
        tower_defense_->getEntitiesManager()->getCastle()->addKill();
        kill();
    }
}

void Enemy::addHP(double HP) {
    setHP(HP_ + HP);
}

void Enemy::takeDamage(double damage) {
    damage -= (damage * (buffs_.damage_resist_ - 1));
    if (damage < 0) { damage = 0; }
    setHP(HP_ - damage);
}

void Enemy::addSpeedBuff(double add_buff) {
    buffs_.speed_ += add_buff;
}

void Enemy::addMaxHPBuff(double add_buff) {
    buffs_.max_HP_ += add_buff;
}

void Enemy::addRegenerationRateBuff(double add_buff) {
    buffs_.regeneration_rate_ += add_buff;
}

void Enemy::addDamageCoefficientBuff(double add_buff) {
    buffs_.damage_coefficient_ += add_buff;
}

void Enemy::addDamageResistBuff(double add_buff) {
    buffs_.damage_resist_ += add_buff;
}

void Enemy::resetBuffs() {
    buffs_.max_HP_ = 1;
    buffs_.damage_resist_ = 1;
    buffs_.damage_coefficient_ = 1;
    buffs_.regeneration_rate_ = 1;
    buffs_.speed_ = 1;
}

double Enemy::getSpeedBuff() const {
    return buffs_.speed_;
}

double Enemy::getMaxHPBuff() const {
    return buffs_.max_HP_;
}

double Enemy::getRegenerationRateBuff() const {
    return buffs_.regeneration_rate_;
}

double Enemy::getDamageCoefficientBuff() const {
    return buffs_.damage_coefficient_;
}

double Enemy::getDamageResistBuff() const {
    return buffs_.damage_resist_;
}

void Enemy::update() {
    resetBuffs();
    double radius = tower_defense_->getSettingsDatabase()->getMaxHeroBuffsSettings().radius;
    List<Entity *> heroes = tower_defense_->getEntitiesManager()->getNearbyHeroEntities(position_, radius);
    ListIterator<Entity *> iterator = heroes.createIterator();
    while (iterator.hasNext()) {
        iterator.next();
        Entity *entity = iterator.getCurrent();
        Hero *hero = nullptr;
        if (entity->getType() == EntityType::HERO_LIGHT_INFANTRY) {
            hero = static_cast<Hero *>(dynamic_cast<HeroLightInfantry *>(iterator.getCurrent()));
        } else if (entity->getType() == EntityType::HERO_HEAVY_INFANTRY) {
            hero = static_cast<Hero *>(dynamic_cast<HeroHeavyInfantry *>(iterator.getCurrent()));
        } else {
            hero = static_cast<Hero *>(dynamic_cast<HeroAviation *>(iterator.getCurrent()));
        }
        buffs_.max_HP_ += hero->getBuffsAura().max_HP_;
        buffs_.damage_resist_ += hero->getBuffsAura().damage_resist_;
        buffs_.damage_coefficient_ += hero->getBuffsAura().damage_coefficient_;
        buffs_.speed_ += hero->getBuffsAura().speed_;
        buffs_.regeneration_rate_ += hero->getBuffsAura().regeneration_rate_;
    }
}

void Enemy::tryAttackCastle() {
    if (tower_defense_->getEntitiesManager()->getCastle()->getPos() == position_) {
        tower_defense_->getEntitiesManager()->getCastle()->takeDamage(
                HP_ * damage_coefficient_ * buffs_.damage_coefficient_);
        kill();
    }
}
