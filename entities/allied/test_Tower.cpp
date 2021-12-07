#include "gtest/gtest.h"
#include "Tower.h"

void initTable(Table<int, LvlSpecificationsForTower> &specifications_table) {
    Table<int, LvlSpecificationsForTower> table;
    table.put(1, LvlSpecificationsForTower(1, 2, 3, 4));
    table.put(2, LvlSpecificationsForTower(5, 6, 7, 8));
    table.put(3, LvlSpecificationsForTower(9, 10, 11, 12));
    specifications_table = table;
}

TEST(Constructors, PosFull_0) {
    Table<int, LvlSpecificationsForTower> specifications_table;
    initTable(specifications_table);
    Tower tower(Position(1, 2), MyString("MyTower"), 2, specifications_table);
    EXPECT_EQ(tower.getLvlCost(3), 12);
    EXPECT_EQ(tower.getLvl(), 2);
    EXPECT_EQ(tower.getLvlSpec(1).attack_radius_, 1);
    EXPECT_EQ(tower.getAttackRadius(), 5);
    EXPECT_EQ(tower.getDamage(), 6);
    EXPECT_EQ(tower.getFireRate(), 7);
    EXPECT_EQ(tower.getPos().x_, 1);
    EXPECT_EQ(tower.getPos().y_, 2);
    EXPECT_EQ(tower.getName() == MyString("MyTower"), true);
    EXPECT_EQ(tower.getType(), EntityType::TOWER);
}

TEST(Constructors, XYFull_0) {
    Table<int, LvlSpecificationsForTower> specifications_table;
    initTable(specifications_table);
    Tower tower(1, 2, MyString("MyTower"), 2, specifications_table);
    EXPECT_EQ(tower.getLvlCost(3), 12);
    EXPECT_EQ(tower.getLvl(), 2);
    EXPECT_EQ(tower.getLvlSpec(1).attack_radius_, 1);
    EXPECT_EQ(tower.getAttackRadius(), 5);
    EXPECT_EQ(tower.getDamage(), 6);
    EXPECT_EQ(tower.getFireRate(), 7);
    EXPECT_EQ(tower.getPos().x_, 1);
    EXPECT_EQ(tower.getPos().y_, 2);
    EXPECT_EQ(tower.getName() == MyString("MyTower"), true);
    EXPECT_EQ(tower.getType(), EntityType::TOWER);
}

TEST(Constructors, PosNotFull_0) {
    Table<int, LvlSpecificationsForTower> specifications_table;
    initTable(specifications_table);
    Tower tower(Position(1, 2), MyString("MyTower"), specifications_table);
    EXPECT_EQ(tower.getLvlCost(3), 12);
    EXPECT_EQ(tower.getLvl(), 1);
    EXPECT_EQ(tower.getLvlSpec(3).attack_radius_, 9);
    EXPECT_EQ(tower.getAttackRadius(), 1);
    EXPECT_EQ(tower.getDamage(), 2);
    EXPECT_EQ(tower.getFireRate(), 3);
    EXPECT_EQ(tower.getPos().x_, 1);
    EXPECT_EQ(tower.getPos().y_, 2);
    EXPECT_EQ(tower.getName() == MyString("MyTower"), true);
    EXPECT_EQ(tower.getType(), EntityType::TOWER);
}

TEST(Constructors, XYNotFull_0) {
    Table<int, LvlSpecificationsForTower> specifications_table;
    initTable(specifications_table);
    Tower tower(1, 2, MyString("MyTower"), specifications_table);
    EXPECT_EQ(tower.getLvlCost(3), 12);
    EXPECT_EQ(tower.getLvl(), 1);
    EXPECT_EQ(tower.getLvlSpec(3).attack_radius_, 9);
    EXPECT_EQ(tower.getAttackRadius(), 1);
    EXPECT_EQ(tower.getDamage(), 2);
    EXPECT_EQ(tower.getFireRate(), 3);
    EXPECT_EQ(tower.getPos().x_, 1);
    EXPECT_EQ(tower.getPos().y_, 2);
    EXPECT_EQ(tower.getName() == MyString("MyTower"), true);
    EXPECT_EQ(tower.getType(), EntityType::TOWER);
}

TEST(Methods, setLvl_0) {
    Table<int, LvlSpecificationsForTower> specifications_table;
    initTable(specifications_table);
    Tower tower(Position(1, 2), MyString("MyTower"), specifications_table);
    tower.setLvl(3);
    EXPECT_EQ(tower.getLvl(), 3);
}

TEST(Methods, PossibleUpLvl_0) {
    Table<int, LvlSpecificationsForTower> specifications_table;
    initTable(specifications_table);
    Tower tower(Position(1, 2), MyString("MyTower"), specifications_table);
    EXPECT_EQ(tower.possibleUpLvl(), true);
    tower.setLvl(3);
    EXPECT_EQ(tower.possibleUpLvl(), false);
}
