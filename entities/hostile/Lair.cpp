#include "Lair.h"

Lair::Lair(Position position, const MyString &name, const Table<EntityType, int> &enemy_table) :
        Entity(position, EntityType::ENEMY_LAIR, name) {
    enemy_table_ = enemy_table;
}

Lair::Lair(int x, int y, const MyString &name, const Table<EntityType, int> &enemy_table) :
        Entity(x, y, EntityType::ENEMY_LAIR, name) {
    enemy_table_ = enemy_table;
}

void Lair::update() {
}


