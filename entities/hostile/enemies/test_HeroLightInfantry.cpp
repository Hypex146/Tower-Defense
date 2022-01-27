#include "gtest/gtest.h"
#include "HeroLightInfantry.h"

TEST(Constructors, PosFull_0) {
    HeroLightInfantry enemy(Position(1, 2), MyString("MyHero"), 90, 100, 3, 4, 5, 0.2, BuffsAura());
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_LIGHT_INFANTRY);
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
    HeroLightInfantry enemy(1, 2, MyString("MyHero"), 90, 100, 3, 4, 5, 0.2, BuffsAura());
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 90);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_LIGHT_INFANTRY);
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
    HeroLightInfantry enemy(Position(1, 2), MyString("MyHero"), 100, 3, 4, 5, 0.2, BuffsAura());
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_LIGHT_INFANTRY);
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
    HeroLightInfantry enemy(1, 2, MyString("MyHero"), 100, 3, 4, 5, 0.2, BuffsAura());
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_LIGHT_INFANTRY);
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
    HeroLightInfantry enemy(1, 2, MyString("MyHero"), 100, 3, 4, 5, 0.2, BuffsAura(1, 2, 3, 4, 5));
    EXPECT_EQ(enemy.getDodgeChance(), 0.2);
    EXPECT_EQ(enemy.getMaxHP(), 100);
    EXPECT_EQ(enemy.getHP(), 100);
    EXPECT_EQ(enemy.getDamageCoeff(), 5);
    EXPECT_EQ(enemy.getRegenRate(), 3);
    EXPECT_EQ(enemy.getSpeed(), 4);
    EXPECT_EQ(enemy.getType(), EntityType::HERO_LIGHT_INFANTRY);
    EXPECT_EQ(enemy.getName() == MyString("MyHero"), true);
    EXPECT_EQ(enemy.getPos().x_, 1);
    EXPECT_EQ(enemy.getPos().y_, 2);
    EXPECT_EQ(enemy.getBuffsAura().damage_resist_, 5);
    EXPECT_EQ(enemy.getBuffsAura().damage_coefficient_, 4);
    EXPECT_EQ(enemy.getBuffsAura().regeneration_rate_, 3);
    EXPECT_EQ(enemy.getBuffsAura().max_HP_, 2);
    EXPECT_EQ(enemy.getBuffsAura().speed_, 1);
}

TEST(Methods, SetBuffs_0) {
    HeroLightInfantry enemy(1, 2, MyString("MyHero"), 100, 3, 4, 5, 0.2, BuffsAura(1, 2, 3, 4, 5));
    enemy.setBuffsAura(BuffsAura(6, 7, 8, 9, 10));
    EXPECT_EQ(enemy.getBuffsAura().damage_resist_, 10);
    EXPECT_EQ(enemy.getBuffsAura().damage_coefficient_, 9);
    EXPECT_EQ(enemy.getBuffsAura().regeneration_rate_, 8);
    EXPECT_EQ(enemy.getBuffsAura().max_HP_, 7);
    EXPECT_EQ(enemy.getBuffsAura().speed_, 6);
}
