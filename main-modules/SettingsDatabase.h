#ifndef TOWER_DEFENSE_SETTINGSDATABASE_H
#define TOWER_DEFENSE_SETTINGSDATABASE_H


struct LvlSpecificationsForCastle;
struct LvlSpecificationsForTower;
enum class EntityType;

struct CastleSettings {
    Table<int, LvlSpecificationsForCastle> castle_table_;
    double start_gold_;
};

struct TowerSettings {
    Table<int, LvlSpecificationsForTower> tower_table_;
};

struct LairSettings {
    Table<EntityType, double> lair_table_;
};

struct WallSettings {
    double max_HP_;
    double cost_;
    double fix_cost_;
};

struct LightInfantrySettings {
    double max_HP_;
    double regeneration_rate_;
    double speed_;
    double damage_coefficient_;
    double dodge_chance_;
};

struct HeavyInfantrySettings {
    double max_HP_;
    double regeneration_rate_;
    double speed_;
    double damage_coefficient_;
    double wall_damage_;
    double wall_attack_radius_;
};

struct AviationSettings {
    double max_HP_;
    double regeneration_rate_;
    double speed_;
    double damage_coefficient_;
    double wall_damage_;
    int ammunition_;
};

struct MaxHeroBuffsSettings {
    double speed_;
    double max_HP_;
    double regeneration_rate_;
    double damage_coefficient_;
    double damage_resist_;
    double radius;
};

class SettingsDatabase {
private:
    CastleSettings castle_settings_;
    TowerSettings tower_settings_;
    LairSettings lair_settings_;
    WallSettings wall_settings_;
    LightInfantrySettings light_infantry_settings_;
    HeavyInfantrySettings heavy_infantry_settings_;
    AviationSettings aviation_settings_;
    MaxHeroBuffsSettings max_hero_buffs_settings_;

    MyString intToString(int a);

    void readCastleSettings();

    void readTowerSettings();

    void readLairSettings();

    void readWallSettings();

    void readLightInfantrySettings();

    void readHeavyInfantrySettings();

    void readAviationSettings();

    void readMaxHeroBuffsSettings();

public:
    SettingsDatabase();

    CastleSettings getCastleSettings() const;

    TowerSettings getTowerSettings() const;

    LairSettings getLairSettings() const;

    WallSettings getWallSettings() const;

    LightInfantrySettings getLightInfantrySettings() const;

    HeavyInfantrySettings getHeavyInfantrySettings() const;

    AviationSettings getAviationSettings() const;

    MaxHeroBuffsSettings getMaxHeroBuffsSettings() const;

};


#endif //TOWER_DEFENSE_SETTINGSDATABASE_H
