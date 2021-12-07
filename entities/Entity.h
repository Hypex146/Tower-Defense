#ifndef TOWER_DEFENSE_ENTITY_H
#define TOWER_DEFENSE_ENTITY_H

#include <iostream>
#include "MyString.h"

enum class EntityType {
    CASTLE,
    WALL,
    TOWER,
    LIGHT_INFANTRY,
    HEAVY_INFANTRY,
    AVIATION,
    HERO_LIGHT_INFANTRY,
    HERO_HEAVY_INFANTRY,
    HERO_AVIATION,
    ENEMY_LAIR
};

struct Position {
    int x_;
    int y_;

    Position(int x, int y);
};

class Entity {
private:
    Position position_;
    EntityType type_;
    bool is_alive_;
    MyString name_;
public:
    explicit Entity(Position position, EntityType type, const MyString &name);

    Entity(int x, int y, EntityType type, const MyString &name);

    Entity(const Entity &obj) = default;

    Entity &operator=(const Entity &obj) = default;

    virtual ~Entity() = default;

    virtual EntityType getType() const;

    virtual Position getPos() const;

    virtual MyString getName() const;

    virtual void setPos(Position position);

    virtual void setPos(int x, int y);

    virtual void update();

    virtual bool isAlive() const;

    virtual void kill();

};

#endif //TOWER_DEFENSE_ENTITY_H
