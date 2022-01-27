#include "gtest/gtest.h"
#include "HeavyInfantry.h"

TEST(Constructors, PosFull_0) {
    HeavyInfantry enemy(Position(1, 2), MyString("MyHeavy"), 90, 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HEAVY_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHeavy"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, XYFull_0) {
    HeavyInfantry enemy(1, 2, MyString("MyHeavy"), 90, 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HEAVY_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHeavy"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, PosNotFull_0) {
    HeavyInfantry enemy(Position(1, 2), MyString("MyHeavy"), 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HEAVY_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHeavy"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, XYNotFull_0) {
    HeavyInfantry enemy(1, 2, MyString("MyHeavy"), 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HEAVY_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHeavy"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Methods, Setters_0) {
    HeavyInfantry enemy(1, 2, MyString("MyHeavy"), 100, 3, 4, 5, 20, 30);
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    enemy.setWallAttackRadius(20);
    enemy.setWallDamage(30);
    EXPECT_EQ(enemy.getWallDamage(), 30);
    EXPECT_EQ(enemy.getWallAttackRadius(), 20);
    enemy.setWallAttackRadius(-20);
    enemy.setWallDamage(-30);
    EXPECT_EQ(enemy.getWallDamage(), 0);
    EXPECT_EQ(enemy.getWallAttackRadius(), 0);
}
