#include "gtest/gtest.h"
#include "LightInfantry.h"

TEST(Constructors, PosFull_0) {
    LightInfantry enemy(Position(1, 2), MyString("MyLight"), 90, 100, 3, 4, 5, 0.2);
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyLight"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, XYFull_0) {
    LightInfantry enemy(1, 2, MyString("MyLight"), 90, 100, 3, 4, 5, 0.2);
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyLight"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, PosNotFull_0) {
    LightInfantry enemy(Position(1, 2), MyString("MyLight"), 100, 3, 4, 5, 0.2);
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyLight"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, XYNotFull_0) {
    LightInfantry enemy(1, 2, MyString("MyLight"), 100, 3, 4, 5, 0.2);
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyLight"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Methods, SetDodgeChance_0) {
    LightInfantry enemy(1, 2, MyString("MyLight"), 100, 3, 4, 5, 0.2);
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    enemy.setDodgeChance(0.5);
    EXPECT_EQ(enemy.getDodgeChance(), 0.5);
    enemy.setDodgeChance(0);
    EXPECT_EQ(enemy.getDodgeChance(), 0);
    enemy.setDodgeChance(2);
    EXPECT_EQ(enemy.getDodgeChance(), 1);
    enemy.setDodgeChance(-2);
    EXPECT_EQ(enemy.getDodgeChance(), 0);
}

TEST(Methods, TakeDamage_0) {
    LightInfantry enemy(1, 2, MyString("MyLight"), 100, 3, 4, 5, 0.2);
    enemy.setDodgeChance(0);
    for (int i = 0; i < 100; i++) {
        enemy.takeDamage(50);
        EXPECT_EQ(enemy.getHP(), 50);
        enemy.setHP(100);
        EXPECT_EQ(enemy.getHP(), 100);
    }
    enemy.setDodgeChance(1);
    for (int i = 0; i < 50; i++) {
        enemy.takeDamage(50);
        EXPECT_EQ(enemy.getHP(), 100);
    }
}
