#ifndef TOWER_DEFENSE_LAIR_H
#define TOWER_DEFENSE_LAIR_H


class Lair : public Entity {
private:
    Table<EntityType, double> enemy_table_;
    Table<EntityType, double> time_to_spawn_;

    BuffsAura
    generateBuffsAura(double max_speed, double max_max_HP, double max_regeneration_rate, double max_damage_coefficient,
                      double max_damage_resist);

public:
    Lair(TowerDefense *tower_defense, Position position, const MyString &name,
         const Table<EntityType, double> &enemy_table);

    Lair(TowerDefense *tower_defense, int x, int y, const MyString &name, const Table<EntityType, double> &enemy_table);

    ~Lair() override = default;

    void forcedSpawnEnemy(EntityType enemy_type);

    void spawnEnemyIfNeed();

    void update() override;

};


#endif //TOWER_DEFENSE_LAIR_H
