#define ALL_INCLUDE
#include "AllHeaders.h"

HeroHeavyInfantry::HeroHeavyInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double wall_damage, double wall_attack_radius, BuffsAura buffs_aura)
        : HeavyInfantry(tower_defense, position, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage,
                        wall_attack_radius, EntityType::HERO_HEAVY_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

HeroHeavyInfantry::HeroHeavyInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double wall_damage, double wall_attack_radius, BuffsAura buffs_aura)
        : HeavyInfantry(tower_defense, x, y, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage,
                        wall_attack_radius, EntityType::HERO_HEAVY_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

HeroHeavyInfantry::HeroHeavyInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double wall_damage, double wall_attack_radius, BuffsAura buffs_aura)
        : HeavyInfantry(tower_defense, position, name, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage,
                        wall_attack_radius, EntityType::HERO_HEAVY_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

HeroHeavyInfantry::HeroHeavyInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                                     double regeneration_rate, double speed, double damage_coefficient,
                                     double wall_damage, double wall_attack_radius, BuffsAura buffs_aura)
        : HeavyInfantry(tower_defense, x, y, name, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage,
                        wall_attack_radius, EntityType::HERO_HEAVY_INFANTRY) {
    buffs_aura_ = buffs_aura;
}

BuffsAura HeroHeavyInfantry::getBuffsAura() {
    return buffs_aura_;
}

void HeroHeavyInfantry::setBuffsAura(BuffsAura buffs_aura) {
    buffs_aura_ = buffs_aura;
}
