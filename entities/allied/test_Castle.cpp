#include "gtest/gtest.h"
#include "Castle.h"

void init(Position *position, Table<int, LvlSpecificationsForCastle> *specifications_table, int x, int y) {
    Table<int, LvlSpecificationsForCastle> table;
    LvlSpecificationsForCastle lvl1(1, 2, 3, 4);
    table.put(1, lvl1);
    LvlSpecificationsForCastle lvl2(5, 6, 7, 8);
    table.put(2, lvl2);
    LvlSpecificationsForCastle lvl3(9, 10, 11, 12);
    table.put(3, lvl3);
    *specifications_table = table;
    *position = Position(x, y);
}

TEST(Constructors, PosFull_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(pos, MyString("MyCastle"), 1, 2, 3, spec_table);
    EXPECT_EQ(castle.getLvl(), 1);
    EXPECT_EQ(castle.getHP(), 2);
    EXPECT_EQ(castle.getGold(), 3);
    EXPECT_EQ(castle.getMaxHP(), 2);
    EXPECT_EQ(castle.getName() == MyString("MyCastle"), true);
    EXPECT_EQ(castle.getProfitability(), 1);
    EXPECT_EQ(castle.getRepairSpeed(), 3);
    EXPECT_EQ(castle.getPos().x_, 1);
    EXPECT_EQ(castle.getPos().y_, 2);
}

TEST(Constructors, XYFull_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(-1, -2, MyString("MyCastle"), 1, 2, 3, spec_table);
    EXPECT_EQ(castle.getLvl(), 1);
    EXPECT_EQ(castle.getHP(), 2);
    EXPECT_EQ(castle.getGold(), 3);
    EXPECT_EQ(castle.getMaxHP(), 2);
    EXPECT_EQ(castle.getName() == MyString("MyCastle"), true);
    EXPECT_EQ(castle.getProfitability(), 1);
    EXPECT_EQ(castle.getRepairSpeed(), 3);
    EXPECT_EQ(castle.getPos().x_, -1);
    EXPECT_EQ(castle.getPos().y_, -2);
}

TEST(Constructors, PosNotFull_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, -1, -2);
    Castle castle(pos, MyString("MyCastle"), 3, spec_table);
    EXPECT_EQ(castle.getLvl(), 1);
    EXPECT_EQ(castle.getHP(), 2);
    EXPECT_EQ(castle.getGold(), 3);
    EXPECT_EQ(castle.getMaxHP(), 2);
    EXPECT_EQ(castle.getName() == MyString("MyCastle"), true);
    EXPECT_EQ(castle.getProfitability(), 1);
    EXPECT_EQ(castle.getRepairSpeed(), 3);
    EXPECT_EQ(castle.getPos().x_, -1);
    EXPECT_EQ(castle.getPos().y_, -2);
}

TEST(Constructors, XYNotFull_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    EXPECT_EQ(castle.getLvl(), 1);
    EXPECT_EQ(castle.getHP(), 2);
    EXPECT_EQ(castle.getGold(), 3);
    EXPECT_EQ(castle.getMaxHP(), 2);
    EXPECT_EQ(castle.getName() == MyString("MyCastle"), true);
    EXPECT_EQ(castle.getProfitability(), 1);
    EXPECT_EQ(castle.getRepairSpeed(), 3);
    EXPECT_EQ(castle.getPos().x_, 1);
    EXPECT_EQ(castle.getPos().y_, 2);
}

TEST(Methods, GetLvlSpec_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    EXPECT_EQ(castle.getLvlSpec(2).cost_, 8);
    EXPECT_EQ(castle.getLvlSpec(2).repair_rate_, 7);
    EXPECT_EQ(castle.getLvlSpec(2).max_HP_, 6);
    EXPECT_EQ(castle.getLvlSpec(2).profitability_, 5);
}

TEST(Methods, SetGold_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.setGold(500);
    EXPECT_EQ(castle.getGold(), 500);
}

TEST(Methods, AddGold_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.setGold(500);
    EXPECT_EQ(castle.getGold(), 500);
    castle.addGold(200);
    EXPECT_EQ(castle.getGold(), 700);
}

TEST(Methods, SetHP_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.setHP(1);
    EXPECT_EQ(castle.getHP(), 1);
    castle.setHP(-1);
    EXPECT_EQ(castle.getHP(), 0);
    EXPECT_EQ(castle.isAlive(), false);
}

TEST(Methods, SetLvl_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.setLvl(3);
    EXPECT_EQ(castle.getLvl(), 3);
}

TEST(Methods, LvlUp_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.setGold(100);
    castle.lvlUp();
    EXPECT_EQ(castle.getLvl(), 2);
    EXPECT_EQ(castle.getGold(), 92);
}

TEST(Methods, PossibleUpLvl_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    EXPECT_EQ(castle.possibleUpLvl(), true);
}

TEST(Methods, PossibleUpLvl_1) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.setLvl(3);
    EXPECT_EQ(castle.possibleUpLvl(), false);
}

TEST(Methods, CanUpLvl_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.setLvl(3);
    castle.setGold(0);
    EXPECT_EQ(castle.canUpLvl(), false);
}

TEST(Methods, CanUpLvl_1) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.setGold(0);
    castle.setLvl(2);
    EXPECT_EQ(castle.canUpLvl(), false);
}

TEST(Methods, CanUpLvl_2) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.setLvl(2);
    castle.setGold(100);
    EXPECT_EQ(castle.canUpLvl(), true);
}

TEST(Methods, TakeDamage_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.takeDamage(1);
    EXPECT_EQ(castle.getHP(), 1);
    EXPECT_EQ(castle.isAlive(), true);
}

TEST(Methods, TakeDamage_1) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.takeDamage(2);
    EXPECT_EQ(castle.getHP(), 0);
    EXPECT_EQ(castle.isAlive(), false);
}

TEST(Methods, TakeDamage_2) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    castle.takeDamage(3);
    EXPECT_EQ(castle.getHP(), 0);
    EXPECT_EQ(castle.isAlive(), false);
}

TEST(Methods, GetName_0) {
    Position pos(0, 0);
    Table<int, LvlSpecificationsForCastle> spec_table;
    init(&pos, &spec_table, 1, 2);
    Castle castle(1, 2, MyString("MyCastle"), 3, spec_table);
    EXPECT_EQ(castle.getName() == MyString("MyCastle"), true);
}
