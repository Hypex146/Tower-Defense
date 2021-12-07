#include "HeroAviation.h"

HeroAviation::HeroAviation(Position position, const MyString &name, double HP, double max_HP, double regeneration_rate,
                           double speed, double damage_coefficient, double wall_damage, int ammunition,
                           BuffsAura buffs_aura)
        : Aviation(position, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage, ammunition,
                   EntityType::HERO_AVIATION) {
    buffs_aura_ = buffs_aura;
}

HeroAviation::HeroAviation(int x, int y, const MyString &name, double HP, double max_HP, double regeneration_rate,
                           double speed, double damage_coefficient, double wall_damage, int ammunition,
                           BuffsAura buffs_aura)
        : Aviation(x, y, name, HP, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage, ammunition,
                   EntityType::HERO_AVIATION) {
    buffs_aura_ = buffs_aura;
}

HeroAviation::HeroAviation(Position position, const MyString &name, double max_HP, double regeneration_rate,
                           double speed, double damage_coefficient, double wall_damage, int ammunition,
                           BuffsAura buffs_aura)
        : Aviation(position, name, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage, ammunition,
                   EntityType::HERO_AVIATION) {
    buffs_aura_ = buffs_aura;
}

HeroAviation::HeroAviation(int x, int y, const MyString &name, double max_HP, double regeneration_rate,
                           double speed, double damage_coefficient, double wall_damage, int ammunition,
                           BuffsAura buffs_aura)
        : Aviation(x, y, name, max_HP, regeneration_rate, speed, damage_coefficient, wall_damage, ammunition,
                   EntityType::HERO_AVIATION) {
    buffs_aura_ = buffs_aura;
}

BuffsAura HeroAviation::getBuffsAura() {
    return buffs_aura_;
}

void HeroAviation::setBuffsAura(BuffsAura buffs_aura) {
    buffs_aura_ = buffs_aura;
}
