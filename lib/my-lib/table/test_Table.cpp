#include "Table.h"
#include "gtest/gtest.h"

TEST(Constructors, ZeroParams_0) {
    Table<int, int> table;
}

TEST(Constructors, Assignment_0) {
    Table<int, int> table;
    table.put(0, 0);
    table.put(1, -1);
    table.put(2, -2);
    Table<int, int> table2(table);
    table.remove(0);
    table.remove(1);
    EXPECT_EQ(table2.getInfo(0), 0);
    EXPECT_EQ(table2.getInfo(1), -1);
    EXPECT_EQ(table2.getInfo(2), -2);
}

TEST(Operators, Assignment_0) {
    Table<int, int> table;
    table.put(0, 0);
    table.put(1, -1);
    table.put(2, -2);
    Table<int, int> table2;
    table2.put(0, 0);
    table2.put(1, 1);
    table2 = table;
    table.remove(0);
    table.remove(1);
    EXPECT_EQ(table2.getInfo(0), 0);
    EXPECT_EQ(table2.getInfo(1), -1);
    EXPECT_EQ(table2.getInfo(2), -2);
}

TEST(Methods, Put_0) {
    Table<int, int> table;
    table.put(0, 0);
    table.put(1, -1);
    table.put(-2, 2);
    EXPECT_EQ(table.getInfo(0), 0);
    EXPECT_EQ(table.getInfo(1), -1);
    EXPECT_EQ(table.getInfo(-2), 2);
}

TEST(Methods, HasKey_0) {
    Table<int, int> table;
    table.put(0, 0);
    table.put(1, -1);
    table.put(-2, 2);
    EXPECT_EQ(table.hasKey(0), true);
    EXPECT_EQ(table.hasKey(-2), true);
    EXPECT_EQ(table.hasKey(2), false);
}

TEST(Methods, Remove_0) {
    Table<int, int> table;
    table.put(0, 0);
    table.put(1, -1);
    table.put(-2, 2);
    EXPECT_EQ(table.hasKey(0), true);
    EXPECT_EQ(table.hasKey(-2), true);
    EXPECT_EQ(table.hasKey(1), true);
    table.remove(0);
    table.remove(-2);
    EXPECT_EQ(table.hasKey(0), false);
    EXPECT_EQ(table.hasKey(-2), false);
    EXPECT_EQ(table.hasKey(1), true);
}

TEST(Methods, GetInfoByIndex_0) {
    Table<int, int> table;
    table.put(0, 0);
    table.put(1, -1);
    table.put(-2, 2);
    EXPECT_EQ(table.getInfoByIndex(0), 0);
    EXPECT_EQ(table.getInfoByIndex(1), -1);
    EXPECT_EQ(table.getInfoByIndex(2), 2);
}
