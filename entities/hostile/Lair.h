#ifndef TOWER_DEFENSE_LAIR_H
#define TOWER_DEFENSE_LAIR_H

#include <iostream>
#include "Entity.h"
#include "Table.h"
#include "MyString.h"

class Lair : public Entity {
private:
    Table<EntityType, int> enemy_table_;
public:
    Lair(Position position, const MyString &name, const Table<EntityType, int> &enemy_table);

    Lair(int x, int y, const MyString &name, const Table<EntityType, int> &enemy_table);

    ~Lair() override = default;

    void forcedSpawnEnemy(EntityType enemy);

    void spawnEnemyIfNeed();

    void update() override;

};


#endif //TOWER_DEFENSE_LAIR_H
