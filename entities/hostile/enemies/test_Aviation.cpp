#include "gtest/gtest.h"
#include "Aviation.h"

TEST(Constructors, PosFull_0) {
    Aviation enemy(Position(1, 2), MyString("MyAviation"), 90, 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getAmmunition(), 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::AVIATION);
    EXPECT_EQ(enemy.getName() == MyString("MyAviation"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, XYFull_0) {
    Aviation enemy(1, 2, MyString("MyAviation"), 90, 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getAmmunition(), 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::AVIATION);
    EXPECT_EQ(enemy.getName() == MyString("MyAviation"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, PosNotFull_0) {
    Aviation enemy(Position(1, 2), MyString("MyAviation"), 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getAmmunition(), 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::AVIATION);
    EXPECT_EQ(enemy.getName() == MyString("MyAviation"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, XYNotFull_0) {
    Aviation enemy(1, 2, MyString("MyAviation"), 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getAmmunition(), 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::AVIATION);
    EXPECT_EQ(enemy.getName() == MyString("MyAviation"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Methods, Setters_0) {
    Aviation enemy(1, 2, MyString("MyAviation"), 90, 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getAmmunition(), 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    enemy.setWallDamage(30);
    enemy.setAmmunition(20);
    EXPECT_EQ(enemy.getAmmunition(), 20);
    EXPECT_EQ(enemy.getWallDamage(), 30);
    enemy.setWallDamage(-30);
    enemy.setAmmunition(-20);
    EXPECT_EQ(enemy.getAmmunition(), 0);
    EXPECT_EQ(enemy.getWallDamage(), 0);
}
