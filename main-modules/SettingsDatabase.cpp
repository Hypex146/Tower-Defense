#define ALL_INCLUDE

#include "AllHeaders.h"
#include "SettingsDatabase.h"

SettingsDatabase::SettingsDatabase() {
    readCastleSettings();
    readTowerSettings();
    readLairSettings();
    readWallSettings();
    readLightInfantrySettings();
    readHeavyInfantrySettings();
    readAviationSettings();
    readMaxHeroBuffsSettings();
}

CastleSettings SettingsDatabase::getCastleSettings() const {
    return castle_settings_;
}

TowerSettings SettingsDatabase::getTowerSettings() const {
    return tower_settings_;
}

LairSettings SettingsDatabase::getLairSettings() const {
    return lair_settings_;
}

WallSettings SettingsDatabase::getWallSettings() const {
    return wall_settings_;
}

LightInfantrySettings SettingsDatabase::getLightInfantrySettings() const {
    return light_infantry_settings_;
}

HeavyInfantrySettings SettingsDatabase::getHeavyInfantrySettings() const {
    return heavy_infantry_settings_;
}

AviationSettings SettingsDatabase::getAviationSettings() const {
    return aviation_settings_;
}

MaxHeroBuffsSettings SettingsDatabase::getMaxHeroBuffsSettings() const {
    return max_hero_buffs_settings_;
}

MyString SettingsDatabase::intToString(int a) {
    MyString res;
    bool isNegative = false;
    if (a < 0) {
        a *= -1;
        isNegative = true;
    }
    if (a == 0) { res = "0"; }
    while (a > 0) {
        char number[2];
        number[0] = a % 10 + 48;
        number[1] = '\0';
        res = number + res;
        a /= 10;
    }
    if (isNegative) { res = "-" + res; }
    return res;
}

void SettingsDatabase::readCastleSettings() {
    Configurator cfg(MyString("castle.yml"));
    int max_lvl = cfg.getInt(MyString("Max-lvl"));
    for (int i = 1; i <= max_lvl; i++) {
        LvlSpecificationsForCastle spec;
        spec.profitability_ = cfg.getDouble(MyString("Profitability-lvl-") + intToString(i));
        spec.max_HP_ = cfg.getDouble(MyString("Max-HP-lvl-") + intToString(i));
        spec.cost_ = cfg.getDouble(MyString("Cost-lvl-") + intToString(i));
        spec.repair_rate_ = cfg.getDouble(MyString("Repair-rate-lvl-") + intToString(i));
        castle_settings_.castle_table_.put(i, spec);
    }
    castle_settings_.start_gold_ = cfg.getDouble(MyString("Start-gold"));
}

void SettingsDatabase::readTowerSettings() {
    Configurator cfg(MyString("tower.yml"));
    int max_lvl = cfg.getInt(MyString("Max-lvl"));
    for (int i = 1; i <= max_lvl; i++) {
        LvlSpecificationsForTower spec;
        spec.cost_ = cfg.getDouble(MyString("Cost-lvl-") + intToString(i));
        spec.reload_time_ = cfg.getDouble(MyString("Reload-time-lvl-") + intToString(i));
        spec.damage_ = cfg.getDouble(MyString("Damage-lvl-") + intToString(i));
        spec.attack_radius_ = cfg.getDouble(MyString("Attack-radius-lvl-") + intToString(i));
        tower_settings_.tower_table_.put(i, spec);
    }
}

void SettingsDatabase::readLairSettings() {
    Configurator cfg(MyString("lair.yml"));
    lair_settings_.lair_table_.put(EntityType::LIGHT_INFANTRY, cfg.getDouble(MyString("Light-infantry")));
    lair_settings_.lair_table_.put(EntityType::HEAVY_INFANTRY, cfg.getDouble(MyString("Heavy-infantry")));
    lair_settings_.lair_table_.put(EntityType::AVIATION, cfg.getDouble(MyString("Aviation")));
    lair_settings_.lair_table_.put(EntityType::HERO_LIGHT_INFANTRY, cfg.getDouble(MyString("Hero-light-infantry")));
    lair_settings_.lair_table_.put(EntityType::HERO_HEAVY_INFANTRY, cfg.getDouble(MyString("Hero-heavy-infantry")));
    lair_settings_.lair_table_.put(EntityType::HERO_AVIATION, cfg.getDouble(MyString("Hero-aviation")));
}

void SettingsDatabase::readWallSettings() {
    Configurator cfg(MyString("wall.yml"));
    wall_settings_.max_HP_ = cfg.getDouble(MyString("Max-HP"));
    wall_settings_.cost_ = cfg.getDouble(MyString("Cost"));
    wall_settings_.fix_cost_ = cfg.getDouble(MyString("Fix-cost"));
}

void SettingsDatabase::readLightInfantrySettings() {
    Configurator cfg(MyString("light-infantry.yml"));
    light_infantry_settings_.max_HP_ = cfg.getDouble(MyString("Max-HP"));
    light_infantry_settings_.speed_ = cfg.getDouble(MyString("Speed"));
    light_infantry_settings_.regeneration_rate_ = cfg.getDouble(MyString("Regeneration-rate"));
    light_infantry_settings_.damage_coefficient_ = cfg.getDouble(MyString("Damage-coefficient"));
    light_infantry_settings_.dodge_chance_ = cfg.getDouble(MyString("Dodge-chance"));
}

void SettingsDatabase::readHeavyInfantrySettings() {
    Configurator cfg(MyString("heavy-infantry.yml"));
    heavy_infantry_settings_.damage_coefficient_ = cfg.getDouble(MyString("Damage-coefficient"));
    heavy_infantry_settings_.regeneration_rate_ = cfg.getDouble(MyString("Regeneration-rate"));
    heavy_infantry_settings_.speed_ = cfg.getDouble(MyString("Speed"));
    heavy_infantry_settings_.max_HP_ = cfg.getDouble(MyString("Max-HP"));
    heavy_infantry_settings_.wall_damage_ = cfg.getDouble(MyString("Wall-damage"));
    heavy_infantry_settings_.wall_attack_radius_ = cfg.getDouble(MyString("Wall-attack-radius"));
}

void SettingsDatabase::readAviationSettings() {
    Configurator cfg(MyString("aviation-infantry.yml"));
    aviation_settings_.wall_damage_ = cfg.getDouble(MyString("Wall-damage"));
    aviation_settings_.max_HP_ = cfg.getDouble(MyString("Max-HP"));
    aviation_settings_.speed_ = cfg.getDouble(MyString("Speed"));
    aviation_settings_.regeneration_rate_ = cfg.getDouble(MyString("Regeneration-rate"));
    aviation_settings_.damage_coefficient_ = cfg.getDouble(MyString("Damage-coefficient"));
    aviation_settings_.ammunition_ = cfg.getInt(MyString("Ammunition"));
}

void SettingsDatabase::readMaxHeroBuffsSettings() {
    Configurator cfg(MyString("max-hero-buffs.yml"));
    max_hero_buffs_settings_.damage_coefficient_ = cfg.getDouble(MyString("Damage-coefficient"));
    max_hero_buffs_settings_.regeneration_rate_ = cfg.getDouble(MyString("Regeneration-rate"));
    max_hero_buffs_settings_.speed_ = cfg.getDouble(MyString("Speed"));
    max_hero_buffs_settings_.max_HP_ = cfg.getDouble(MyString("Max-HP"));
    max_hero_buffs_settings_.damage_resist_ = cfg.getDouble(MyString("Damage-resist"));
    max_hero_buffs_settings_.radius = cfg.getDouble(MyString("Radius"));
}
