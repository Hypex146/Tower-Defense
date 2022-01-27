#define ENTITIES_INCLUDE
#define STD_LIBS_INCLUDE
#define MY_LIBS_INCLUDE


#define ALL_INCLUDE
#include "AllHeaders.h"


Lair::Lair(TowerDefense *tower_defense, Position position, const MyString &name,
           const Table<EntityType, double> &enemy_table) :
        Entity(tower_defense, position, EntityType::ENEMY_LAIR, name) {
    enemy_table_ = enemy_table;
    time_to_spawn_ = enemy_table;
}

Lair::Lair(TowerDefense *tower_defense, int x, int y, const MyString &name,
           const Table<EntityType, double> &enemy_table) :
        Entity(tower_defense, x, y, EntityType::ENEMY_LAIR, name) {
    enemy_table_ = enemy_table;
    time_to_spawn_ = enemy_table;
}

void Lair::update() {
    spawnEnemyIfNeed();
}

void Lair::forcedSpawnEnemy(EntityType enemy_type) {
    switch (enemy_type) {
        case EntityType::LIGHT_INFANTRY: {
            LightInfantrySettings settings = tower_defense_->getSettingsDatabase()->getLightInfantrySettings();
            auto *enemy = new LightInfantry(tower_defense_, position_, MyString("Enemy"), settings.max_HP_,
                                            settings.regeneration_rate_, settings.speed_, settings.damage_coefficient_,
                                            settings.dodge_chance_);
            tower_defense_->getEntitiesManager()->registerEntity(enemy);
            break;
        }
        case EntityType::HEAVY_INFANTRY: {
            HeavyInfantrySettings settings = tower_defense_->getSettingsDatabase()->getHeavyInfantrySettings();
            auto *enemy = new HeavyInfantry(tower_defense_, position_, MyString("Enemy"), settings.max_HP_,
                                            settings.regeneration_rate_, settings.speed_, settings.damage_coefficient_,
                                            settings.wall_damage_, settings.wall_attack_radius_);
            tower_defense_->getEntitiesManager()->registerEntity(enemy);
            break;
        }
        case EntityType::AVIATION: {
            AviationSettings settings = tower_defense_->getSettingsDatabase()->getAviationSettings();
            auto *enemy = new Aviation(tower_defense_, position_, MyString("Enemy"), settings.max_HP_,
                                       settings.regeneration_rate_, settings.speed_, settings.damage_coefficient_,
                                       settings.wall_damage_, settings.ammunition_);
            tower_defense_->getEntitiesManager()->registerEntity(enemy);
            break;
        }
        case EntityType::HERO_LIGHT_INFANTRY: {
            LightInfantrySettings settings = tower_defense_->getSettingsDatabase()->getLightInfantrySettings();
            MaxHeroBuffsSettings buffs_settings = tower_defense_->getSettingsDatabase()->getMaxHeroBuffsSettings();
            BuffsAura buffs = generateBuffsAura(buffs_settings.speed_, buffs_settings.max_HP_,
                                                buffs_settings.regeneration_rate_, buffs_settings.damage_coefficient_,
                                                buffs_settings.damage_resist_);
            auto *enemy = new HeroLightInfantry(tower_defense_, position_, MyString("Enemy"), settings.max_HP_,
                                                settings.regeneration_rate_, settings.speed_,
                                                settings.damage_coefficient_,
                                                settings.dodge_chance_, buffs);
            tower_defense_->getEntitiesManager()->registerEntity(enemy);
            tower_defense_->getEntitiesManager()->registerHeroEntity(enemy);
            break;
        }
        case EntityType::HERO_HEAVY_INFANTRY: {
            HeavyInfantrySettings settings = tower_defense_->getSettingsDatabase()->getHeavyInfantrySettings();
            MaxHeroBuffsSettings buffs_settings = tower_defense_->getSettingsDatabase()->getMaxHeroBuffsSettings();
            BuffsAura buffs = generateBuffsAura(buffs_settings.speed_, buffs_settings.max_HP_,
                                                buffs_settings.regeneration_rate_, buffs_settings.damage_coefficient_,
                                                buffs_settings.damage_resist_);
            auto *enemy = new HeroHeavyInfantry(tower_defense_, position_, MyString("Enemy"), settings.max_HP_,
                                                settings.regeneration_rate_, settings.speed_,
                                                settings.damage_coefficient_,
                                                settings.wall_damage_, settings.wall_attack_radius_, buffs);
            tower_defense_->getEntitiesManager()->registerEntity(enemy);
            tower_defense_->getEntitiesManager()->registerHeroEntity(enemy);
            break;
        }
        case EntityType::HERO_AVIATION: {
            AviationSettings settings = tower_defense_->getSettingsDatabase()->getAviationSettings();
            MaxHeroBuffsSettings buffs_settings = tower_defense_->getSettingsDatabase()->getMaxHeroBuffsSettings();
            BuffsAura buffs = generateBuffsAura(buffs_settings.speed_, buffs_settings.max_HP_,
                                                buffs_settings.regeneration_rate_, buffs_settings.damage_coefficient_,
                                                buffs_settings.damage_resist_);
            auto *enemy = new HeroAviation(tower_defense_, position_, MyString("Enemy"), settings.max_HP_,
                                           settings.regeneration_rate_, settings.speed_, settings.damage_coefficient_,
                                           settings.wall_damage_, settings.ammunition_, buffs);
            tower_defense_->getEntitiesManager()->registerEntity(enemy);
            tower_defense_->getEntitiesManager()->registerHeroEntity(enemy);
            break;
        }
        default:
            break;
    }
}

void Lair::spawnEnemyIfNeed() {
    EntityType enemy_types[] = {EntityType::LIGHT_INFANTRY, EntityType::HEAVY_INFANTRY, EntityType::AVIATION,
                                EntityType::HERO_LIGHT_INFANTRY, EntityType::HERO_HEAVY_INFANTRY,
                                EntityType::HERO_AVIATION};
    for (EntityType type: enemy_types) {
        if (time_to_spawn_.getInfo(type) <= 0) {
            forcedSpawnEnemy(type);
            time_to_spawn_.changeInfo(type, enemy_table_.getInfo(type));
        } else {
            double old_time = time_to_spawn_.getInfo(type);
            time_to_spawn_.changeInfo(type, old_time - 1);
        }
    }
}

BuffsAura Lair::generateBuffsAura(double max_speed, double max_max_HP, double max_regeneration_rate,
                                  double max_damage_coefficient, double max_damage_resist) {
    BuffsAura res;
    res.speed_ = (double)tower_defense_->random(0, (int) (max_speed * 100)) / 100;
    res.max_HP_ = (double)tower_defense_->random(0, (int) (max_max_HP * 100)) / 100;
    res.regeneration_rate_ = (double)tower_defense_->random(0, (int) (max_regeneration_rate * 100)) / 100;
    res.damage_coefficient_ = (double)tower_defense_->random(0, (int) (max_damage_coefficient * 100)) / 100;
    res.damage_resist_ = (double)tower_defense_->random(0, (int) (max_damage_resist * 100)) / 100;
    return res;
}
