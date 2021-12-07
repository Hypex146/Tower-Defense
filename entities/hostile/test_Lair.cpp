#include "gtest/gtest.h"
#include "Lair.h"

void initTable(Table<EntityType, int> *enemy_table_) {
    Table<EntityType, int> table;
    table.put(EntityType::LIGHT_INFANTRY, 5);
    table.put(EntityType::HEAVY_INFANTRY, 10);
    table.put(EntityType::AVIATION, 15);
    *enemy_table_ = table;
}

TEST(Constructors, Pos_0) {
    Table<EntityType, int> table;
    initTable(&table);
    Lair lair(Position(1, 2), MyString("MyLair"), table);
    EXPECT_EQ(lair.getPos().x_, 1);
    EXPECT_EQ(lair.getPos().y_, 2);
    EXPECT_EQ(lair.getName() == MyString("MyLair"), true);
}

TEST(Constructors, XY_0) {
    Table<EntityType, int> table;
    initTable(&table);
    Lair lair(1, 2, MyString("MyLair"), table);
    EXPECT_EQ(lair.getPos().x_, 1);
    EXPECT_EQ(lair.getPos().y_, 2);
    EXPECT_EQ(lair.getName() == MyString("MyLair"), true);
}
