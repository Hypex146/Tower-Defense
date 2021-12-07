#ifndef TOWER_DEFENSE_ENEMY_H
#define TOWER_DEFENSE_ENEMY_H

#include <iostream>
#include "Entity.h"
#include "MyString.h"

struct BuffCoefficients {
    double speed_ = 1;
    double max_HP_ = 1;
    double regeneration_rate_ = 1;
    double damage_coefficient_ = 1;
    double damage_resist_ = 1;
};

struct BuffsAura {
    double speed_ = 0;
    double max_HP_ = 0;
    double regeneration_rate_ = 0;
    double damage_coefficient_ = 0;
    double damage_resist_ = 0;

    BuffsAura() = default;

    BuffsAura(double speed, double max_HP, double regeneration_rate, double damage_coefficient, double damage_resist);
};

class Enemy : public Entity {
private:
    double HP_;
    double max_HP_;
    double regeneration_rate_;
    double speed_;
    double damage_coefficient_;
    BuffCoefficients buffs_;
public:
    Enemy(Position position, const MyString &name, EntityType type, double HP, double max_HP, double regeneration_rate,
          double speed,
          double damage_coefficient);

    Enemy(int x, int y, const MyString &name, EntityType type, double HP, double max_HP, double regeneration_rate,
          double speed,
          double damage_coefficient);

    Enemy(Position position, const MyString &name, EntityType type, double max_HP, double regeneration_rate,
          double speed,
          double damage_coefficient);

    Enemy(int x, int y, const MyString &name, EntityType type, double max_HP, double regeneration_rate,
          double speed,
          double damage_coefficient);

    virtual double getHP() const;

    virtual void setHP(double HP);

    virtual void addHP(double HP);

    virtual double getMaxHP() const;

    virtual double getRegenRate() const;

    virtual double getSpeed() const;

    virtual double getDamageCoeff() const;

    virtual void takeDamage(double damage);

    virtual void addSpeedBuff(double add_buff);

    virtual double getSpeedBuff() const;

    virtual void addMaxHPBuff(double add_buff);

    virtual double getMaxHPBuff() const;

    virtual void addRegenerationRateBuff(double add_buff);

    virtual double getRegenerationRateBuff() const;

    virtual void addDamageCoefficientBuff(double add_buff);

    virtual double getDamageCoefficientBuff() const;

    virtual void addDamageResistBuff(double add_buff);

    virtual double getDamageResistBuff() const;

    virtual void resetBuffs();

};


#endif //TOWER_DEFENSE_ENEMY_H
