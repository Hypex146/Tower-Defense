#include "HeroLightInfantry.h"

HeroLightInfantry::HeroLightInfantry(Position position, const MyString &name, double HP, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double dodge_chance, BuffsAura buffs_aura)
        : LightInfantry(position, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, dodge_chance,
                        EntityType::HERO_LIGHT_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

HeroLightInfantry::HeroLightInfantry(int x, int y, const MyString &name, double HP, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double dodge_chance, BuffsAura buffs_aura)
        : LightInfantry(x, y, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, dodge_chance,
                        EntityType::HERO_LIGHT_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

HeroLightInfantry::HeroLightInfantry(Position position, const MyString &name, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double dodge_chance, BuffsAura buffs_aura)
        : LightInfantry(position, name, max_HP, regeneration_rate, speed, damage_coefficient, dodge_chance,
                        EntityType::HERO_LIGHT_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

HeroLightInfantry::HeroLightInfantry(int x, int y, const MyString &name, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double dodge_chance, BuffsAura buffs_aura)
        : LightInfantry(x, y, name, max_HP, regeneration_rate, speed, damage_coefficient, dodge_chance,
                        EntityType::HERO_LIGHT_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

BuffsAura HeroLightInfantry::getBuffsAura() {
    return buffs_aura_;
}

void HeroLightInfantry::setBuffsAura(BuffsAura buffs_aura) {
    buffs_aura_ = buffs_aura;
}
