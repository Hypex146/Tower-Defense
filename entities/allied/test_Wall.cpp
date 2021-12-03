#include "Wall.h"
#include "gtest/gtest.h"

TEST(Constructors, PosFull_0) {
    Wall wall(Position(1, 2), MyString("MyWall"), 90, 100);
    EXPECT_EQ(wall.getHP(), 90);
    EXPECT_EQ(wall.getMaxHP(), 100);
    EXPECT_EQ(wall.getName() == MyString("MyWall"), true);
    EXPECT_EQ(wall.getPos().x_, 1);
    EXPECT_EQ(wall.getPos().y_, 2);
}

TEST(Constructors, XYFull_0) {
    Wall wall(1, 2, MyString("MyWall"), 90, 100);
    EXPECT_EQ(wall.getHP(), 90);
    EXPECT_EQ(wall.getMaxHP(), 100);
    EXPECT_EQ(wall.getName() == MyString("MyWall"), true);
    EXPECT_EQ(wall.getPos().x_, 1);
    EXPECT_EQ(wall.getPos().y_, 2);
}

TEST(Constructors, PosNotFull_0) {
    Wall wall(Position(1, 2), MyString("MyWall"), 100);
    EXPECT_EQ(wall.getHP(), 100);
    EXPECT_EQ(wall.getMaxHP(), 100);
    EXPECT_EQ(wall.getName() == MyString("MyWall"), true);
    EXPECT_EQ(wall.getPos().x_, 1);
    EXPECT_EQ(wall.getPos().y_, 2);
}

TEST(Constructors, XYNotFull_0) {
    Wall wall(1, 2, MyString("MyWall"), 100);
    EXPECT_EQ(wall.getHP(), 100);
    EXPECT_EQ(wall.getMaxHP(), 100);
    EXPECT_EQ(wall.getName() == MyString("MyWall"), true);
    EXPECT_EQ(wall.getPos().x_, 1);
    EXPECT_EQ(wall.getPos().y_, 2);
}

TEST(Methods, GetName_0) {
    Wall wall(Position(1, 2), MyString("MyWall"), 90, 100);
    EXPECT_EQ(wall.getName() == MyString("MyWall"), true);
}

TEST(Methods, GetName_1) {
    Wall wall(Position(1, 2), MyString(""), 90, 100);
    EXPECT_EQ(wall.getName() == MyString(""), true);
}

TEST(Methods, GetHP_0) {
    Wall wall(Position(1, 2), MyString("MyWall"), 90, 100);
    EXPECT_EQ(wall.getHP(), 90);
}

TEST(Methods, GetMaxHP_0) {
    Wall wall(Position(1, 2), MyString("MyWall"), 90, 100);
    EXPECT_EQ(wall.getMaxHP(), 100);
}

TEST(Methods, SetHP_0) {
    Wall wall(Position(1, 2), MyString("MyWall"), 90, 100);
    wall.setHP(50);
    EXPECT_EQ(wall.getHP(), 50);
}

TEST(Methods, TakeDamage_0) {
    Wall wall(Position(1, 2), MyString("MyWall"), 90, 100);
    wall.takeDamage(40);
    EXPECT_EQ(wall.getHP(), 50);
    EXPECT_EQ(wall.isAlive(), true);
    wall.takeDamage(55);
    EXPECT_EQ(wall.getHP(), 0);
    EXPECT_EQ(wall.isAlive(), false);
}

TEST(Methods, Fix_0) {
    Wall wall(Position(1, 2), MyString("MyWall"), 90, 100);
    wall.takeDamage(50);
    EXPECT_EQ(wall.getHP(), 40);
    wall.fix(40);
    EXPECT_EQ(wall.getHP(), 80);
    wall.fix(100);
    EXPECT_EQ(wall.getHP() == wall.getMaxHP(), true);
    EXPECT_EQ(wall.getHP(), 100);
    wall.takeDamage(999);
    EXPECT_EQ(wall.getHP(), 0);
    wall.fix(50);
    EXPECT_EQ(wall.getHP(), 0);
    EXPECT_EQ(wall.isAlive(), false);
}
