#include "HeroHeavyInfantry.h"

HeroHeavyInfantry::HeroHeavyInfantry(Position position, const MyString &name, double HP, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double wall_damage, double wall_attack_radius, BuffsAura buffs_aura)
        : HeavyInfantry(position, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage,
                        wall_attack_radius, EntityType::HERO_HEAVY_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

HeroHeavyInfantry::HeroHeavyInfantry(int x, int y, const MyString &name, double HP, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double wall_damage, double wall_attack_radius, BuffsAura buffs_aura)
        : HeavyInfantry(x, y, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage,
                        wall_attack_radius, EntityType::HERO_HEAVY_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

HeroHeavyInfantry::HeroHeavyInfantry(Position position, const MyString &name, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double wall_damage, double wall_attack_radius, BuffsAura buffs_aura)
        : HeavyInfantry(position, name, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage,
                        wall_attack_radius, EntityType::HERO_HEAVY_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

HeroHeavyInfantry::HeroHeavyInfantry(int x, int y, const MyString &name, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double wall_damage, double wall_attack_radius, BuffsAura buffs_aura)
        : HeavyInfantry(x, y, name, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage,
                        wall_attack_radius, EntityType::HERO_HEAVY_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

BuffsAura HeroHeavyInfantry::getBuffsAura() {
    return buffs_aura_;
}

void HeroHeavyInfantry::setBuffsAura(BuffsAura buffs_aura) {
    buffs_aura_ = buffs_aura;
}
