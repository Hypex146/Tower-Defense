#define ALL_INCLUDE
#include "AllHeaders.h"

HeroAviation::HeroAviation(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP, double regeneration_rate,
                           double speed, double damage_coefficient, double wall_damage, int ammunition,
                           BuffsAura buffs_aura)
        : Aviation(tower_defense, position, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage, ammunition,
                   EntityType::HERO_AVIATION) {
    buffs_aura_ = buffs_aura;
}

HeroAviation::HeroAviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate,
                           double speed, double damage_coefficient, double wall_damage, int ammunition,
                           BuffsAura buffs_aura)
        : Aviation(tower_defense, x, y, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage, ammunition,
                   EntityType::HERO_AVIATION) {
    buffs_aura_ = buffs_aura;
}

HeroAviation::HeroAviation(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP, double regeneration_rate,
                           double speed, double damage_coefficient, double wall_damage, int ammunition,
                           BuffsAura buffs_aura)
        : Aviation(tower_defense, position, name, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage, ammunition,
                   EntityType::HERO_AVIATION) {
    buffs_aura_ = buffs_aura;
}

HeroAviation::HeroAviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP, double regeneration_rate,
                           double speed, double damage_coefficient, double wall_damage, int ammunition,
                           BuffsAura buffs_aura)
        : Aviation(tower_defense, x, y, name, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage, ammunition,
                   EntityType::HERO_AVIATION) {
    buffs_aura_ = buffs_aura;
}

BuffsAura HeroAviation::getBuffsAura() {
    return buffs_aura_;
}

void HeroAviation::setBuffsAura(BuffsAura buffs_aura) {
    buffs_aura_ = buffs_aura;
}
