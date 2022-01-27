#include "gtest/gtest.h"
#include "HeroHeavyInfantry.h"

TEST(Constructors, PosFull_0) {
    HeroHeavyInfantry enemy(Position(1, 2), MyString("MyHero"), 90, 100, 3, 4, 5, 20, 30, BuffsAura());
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_HEAVY_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHero"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
    EXPECT_EQ(enemy.getBuffsAura().damage_resist_, 0);
    EXPECT_EQ(enemy.getBuffsAura().damage_coefficient_, 0);
    EXPECT_EQ(enemy.getBuffsAura().regeneration_rate_, 0);
    EXPECT_EQ(enemy.getBuffsAura().max_HP_, 0);
    EXPECT_EQ(enemy.getBuffsAura().speed_, 0);
}

TEST(Constructors, XYFull_0) {
    HeroHeavyInfantry enemy(1, 2, MyString("MyHero"), 90, 100, 3, 4, 5, 20, 30, BuffsAura());
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_HEAVY_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHero"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
    EXPECT_EQ(enemy.getBuffsAura().damage_resist_, 0);
    EXPECT_EQ(enemy.getBuffsAura().damage_coefficient_, 0);
    EXPECT_EQ(enemy.getBuffsAura().regeneration_rate_, 0);
    EXPECT_EQ(enemy.getBuffsAura().max_HP_, 0);
    EXPECT_EQ(enemy.getBuffsAura().speed_, 0);
}

TEST(Constructors, PosNotFull_0) {
    HeroHeavyInfantry enemy(Position(1, 2), MyString("MyHero"), 100, 3, 4, 5, 20, 30, BuffsAura());
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_HEAVY_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHero"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
    EXPECT_EQ(enemy.getBuffsAura().damage_resist_, 0);
    EXPECT_EQ(enemy.getBuffsAura().damage_coefficient_, 0);
    EXPECT_EQ(enemy.getBuffsAura().regeneration_rate_, 0);
    EXPECT_EQ(enemy.getBuffsAura().max_HP_, 0);
    EXPECT_EQ(enemy.getBuffsAura().speed_, 0);
}

TEST(Constructors, XYNotFull_0) {
    HeroHeavyInfantry enemy(1, 2, MyString("MyHero"), 100, 3, 4, 5, 20, 30, BuffsAura());
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_HEAVY_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHero"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
    EXPECT_EQ(enemy.getBuffsAura().damage_resist_, 0);
    EXPECT_EQ(enemy.getBuffsAura().damage_coefficient_, 0);
    EXPECT_EQ(enemy.getBuffsAura().regeneration_rate_, 0);
    EXPECT_EQ(enemy.getBuffsAura().max_HP_, 0);
    EXPECT_EQ(enemy.getBuffsAura().speed_, 0);
}

TEST(Constructors, XYNotFullWithBuffs_0) {
    HeroHeavyInfantry enemy(1, 2, MyString("MyHero"), 100, 3, 4, 5, 20, 30, BuffsAura(1, 2, 3, 4, 5));
    EXPECT_EQ(enemy.getWallDamage(), 20);
    EXPECT_EQ(enemy.getWallAttackRadius(), 30);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_HEAVY_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHero"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
    EXPECT_EQ(enemy.getBuffsAura().damage_resist_, 5);
    EXPECT_EQ(enemy.getBuffsAura().damage_coefficient_, 4);
    EXPECT_EQ(enemy.getBuffsAura().regeneration_rate_, 3);
    EXPECT_EQ(enemy.getBuffsAura().max_HP_, 2);
    EXPECT_EQ(enemy.getBuffsAura().speed_, 1);
}

TEST(Methods, Setters_0) {
    HeroHeavyInfantry enemy(1, 2, MyString("MyHero"), 100, 3, 4, 5, 20, 30, BuffsAura(1, 2, 3, 4, 5));
    enemy.setBuffsAura(BuffsAura(6, 7, 8, 9, 10));
    EXPECT_EQ(enemy.getBuffsAura().damage_resist_, 10);
    EXPECT_EQ(enemy.getBuffsAura().damage_coefficient_, 9);
    EXPECT_EQ(enemy.getBuffsAura().regeneration_rate_, 8);
    EXPECT_EQ(enemy.getBuffsAura().max_HP_, 7);
    EXPECT_EQ(enemy.getBuffsAura().speed_, 6);
}
