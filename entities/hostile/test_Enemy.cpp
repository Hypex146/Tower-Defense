#include "gtest/gtest.h"
#include "Enemy.h"

TEST(Constructors, PosFull_0) {
    Enemy enemy(Position(1, 2), MyString("MyEnemy"), EntityType::LIGHT_INFANTRY, 90, 100, 3, 4, 5);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyEnemy"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, XYFull_0) {
    Enemy enemy(1, 2, MyString("MyEnemy"), EntityType::LIGHT_INFANTRY, 90, 100, 3, 4, 5);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyEnemy"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, PosNotFull_0) {
    Enemy enemy(Position(1, 2), MyString("MyEnemy"), EntityType::LIGHT_INFANTRY, 100, 3, 4, 5);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyEnemy"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Constructors, XYNotFull_0) {
    Enemy enemy(1, 2, MyString("MyEnemy"), EntityType::LIGHT_INFANTRY, 100, 3, 4, 5);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyEnemy"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
}

TEST(Methods, SetHP_0) {
    Enemy enemy(1, 2, MyString("MyEnemy"), EntityType::LIGHT_INFANTRY, 100, 3, 4, 5);
    enemy.setHP(95);
    EXPECT_EQ(enemy.getHP(), 95);
    enemy.setHP(500);
    EXPECT_EQ(enemy.getHP(), 100);
    enemy.setHP(-500);
    EXPECT_EQ(enemy.getHP(), 0);
    EXPECT_EQ(enemy.isAlive(), false);
}

TEST(Methods, AddHP_0) {
    Enemy enemy(1, 2, MyString("MyEnemy"), EntityType::LIGHT_INFANTRY, 90, 100, 3, 4, 5);
    enemy.addHP(5);
    EXPECT_EQ(enemy.getHP(), 95);
    enemy.addHP(50);
    EXPECT_EQ(enemy.getHP(), 100);
    enemy.takeDamage(55);
    EXPECT_EQ(enemy.getHP(), 45);
    enemy.takeDamage(500);
    EXPECT_EQ(enemy.getHP(), 0);
    EXPECT_EQ(enemy.isAlive(), false);
}

TEST(Methods, Buffs_0) {
    Enemy enemy(1, 2, MyString("MyEnemy"), EntityType::LIGHT_INFANTRY, 90, 100, 3, 4, 5);
    enemy.addDamageCoefficientBuff(0.2);
    enemy.addDamageResistBuff(0.3);
    enemy.addMaxHPBuff(0.4);
    enemy.addRegenerationRateBuff(0.5);
    enemy.addSpeedBuff(0.6);
    EXPECT_EQ(enemy.getDamageCoefficientBuff(), 1.2);
    EXPECT_EQ(enemy.getDamageResistBuff(), 1.3);
    EXPECT_EQ(enemy.getMaxHPBuff(), 1.4);
    EXPECT_EQ(enemy.getRegenerationRateBuff(), 1.5);
    EXPECT_EQ(enemy.getSpeedBuff(), 1.6);
    enemy.addDamageCoefficientBuff(0.2);
    enemy.addDamageResistBuff(0.3);
    enemy.addMaxHPBuff(0.5);
    enemy.addRegenerationRateBuff(0.5);
    enemy.addSpeedBuff(0.6);
    EXPECT_EQ(enemy.getDamageCoefficientBuff(), 1.4);
    EXPECT_EQ(enemy.getDamageResistBuff(), 1.6);
    EXPECT_EQ(enemy.getMaxHPBuff(), 1.9);
    EXPECT_EQ(enemy.getRegenerationRateBuff(), 2);
    EXPECT_EQ(enemy.getSpeedBuff(), 2.2);
    enemy.resetBuffs();
    EXPECT_EQ(enemy.getDamageCoefficientBuff(), 1);
    EXPECT_EQ(enemy.getDamageResistBuff(), 1);
    EXPECT_EQ(enemy.getMaxHPBuff(), 1);
    EXPECT_EQ(enemy.getRegenerationRateBuff(), 1);
    EXPECT_EQ(enemy.getSpeedBuff(), 1);
}
