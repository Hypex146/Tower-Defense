#include "Entity.h"
#include "gtest/gtest.h"

TEST(Constructors, PosParam_0) {
    Entity entity(Position(1, 2), EntityType::LIGHT_INFANTRY);
    Position pos = entity.getPos();
    EXPECT_EQ(pos.x_, 1);
    EXPECT_EQ(pos.y_, 2);
    EXPECT_EQ(entity.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Constructors, PosParam_1) {
    Entity entity(Position(-1, 0), EntityType::LIGHT_INFANTRY);
    Position pos = entity.getPos();
    EXPECT_EQ(pos.x_, -1);
    EXPECT_EQ(pos.y_, 0);
    EXPECT_EQ(entity.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Constructors, TwosParam_0) {
    Entity entity(1, 2, EntityType::LIGHT_INFANTRY);
    Position pos = entity.getPos();
    EXPECT_EQ(pos.x_, 1);
    EXPECT_EQ(pos.y_, 2);
    EXPECT_EQ(entity.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Constructors, TwosParam_1) {
    Entity entity(-1, 0, EntityType::LIGHT_INFANTRY);
    Position pos = entity.getPos();
    EXPECT_EQ(pos.x_, -1);
    EXPECT_EQ(pos.y_, 0);
    EXPECT_EQ(entity.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Constructors, Copy_0) {
    Entity entity1(-1, 0, EntityType::LIGHT_INFANTRY);
    Entity entity2(entity1);
    entity1.setPos(0, 0);
    Position pos = entity2.getPos();
    EXPECT_EQ(pos.x_, -1);
    EXPECT_EQ(pos.y_, 0);
    EXPECT_EQ(entity2.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Operatoors, Assigment_0) {
    Entity entity1(-1, 0, EntityType::LIGHT_INFANTRY);
    Entity entity2(0, 0, EntityType::LIGHT_INFANTRY);
    entity2 = entity1;
    entity1.setPos(0, 0);
    Position pos = entity2.getPos();
    EXPECT_EQ(pos.x_, -1);
    EXPECT_EQ(pos.y_, 0);
    EXPECT_EQ(entity2.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Methods, SetPos_0) {
    Entity entity(Position(1, 2), EntityType::LIGHT_INFANTRY);
    entity.setPos(-1, -2);
    Position pos = entity.getPos();
    EXPECT_EQ(pos.x_, -1);
    EXPECT_EQ(pos.y_, -2);
    EXPECT_EQ(entity.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Methods, SetPos_1) {
    Entity entity(Position(1, 2), EntityType::LIGHT_INFANTRY);
    entity.setPos(Position(-1, -2));
    Position pos = entity.getPos();
    EXPECT_EQ(pos.x_, -1);
    EXPECT_EQ(pos.y_, -2);
    EXPECT_EQ(entity.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Methods, Update_0) {
    Entity entity(Position(1, 2), EntityType::LIGHT_INFANTRY);
    entity.update();
    Position pos = entity.getPos();
    EXPECT_EQ(pos.x_, 1);
    EXPECT_EQ(pos.y_, 2);
    EXPECT_EQ(entity.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Methods, IsAlive_0) {
    Entity entity(Position(1, 2), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(entity.isAlive(), true);
    EXPECT_EQ(entity.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Methods, Kill_0) {
    Entity entity(Position(1, 2), EntityType::LIGHT_INFANTRY);
    entity.kill();
    EXPECT_EQ(entity.isAlive(), false);
    EXPECT_EQ(entity.getType(), EntityType::LIGHT_INFANTRY);
}

TEST(Methods, GetType_0) {
    Entity entity1(Position(1, 2), EntityType::LIGHT_INFANTRY);
    Entity entity2(Position(1, 2), EntityType::AVIATION);
    Entity entity3(Position(1, 2), EntityType::CASTLE);
    Entity entity4(Position(1, 2), EntityType::HEAVY_INFANTRY);
    Entity entity5(Position(1, 2), EntityType::HERO_AVIATION);
    Entity entity6(Position(1, 2), EntityType::HERO_HEAVY_INFANTRY);
    Entity entity7(Position(1, 2), EntityType::HERO_LIGHT_INFANTRY);
    Entity entity8(Position(1, 2), EntityType::TOWER);
    Entity entity9(Position(1, 2), EntityType::WALL);
    Entity entity10(Position(1, 2), EntityType::ENEMY_LAIR);
    EXPECT_EQ(entity1.getType(), EntityType::LIGHT_INFANTRY);
    EXPECT_EQ(entity2.getType(), EntityType::AVIATION);
    EXPECT_EQ(entity3.getType(), EntityType::CASTLE);
    EXPECT_EQ(entity4.getType(), EntityType::HEAVY_INFANTRY);
    EXPECT_EQ(entity5.getType(), EntityType::HERO_AVIATION);
    EXPECT_EQ(entity6.getType(), EntityType::HERO_HEAVY_INFANTRY);
    EXPECT_EQ(entity7.getType(), EntityType::HERO_LIGHT_INFANTRY);
    EXPECT_EQ(entity8.getType(), EntityType::TOWER);
    EXPECT_EQ(entity9.getType(), EntityType::WALL);
    EXPECT_EQ(entity10.getType(), EntityType::ENEMY_LAIR);
}
