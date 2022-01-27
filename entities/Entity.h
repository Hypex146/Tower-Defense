#ifndef TOWER_DEFENSE_ENTITY_H
#define TOWER_DEFENSE_ENTITY_H


class TowerDefense;

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

    Position() = default;

    friend bool operator==(const Position &pos1, const Position &pos2);
};

bool operator==(const Position &pos1, const Position &pos2);

class Entity {
protected:
    Position position_;
    EntityType type_;
    bool is_alive_;
    MyString name_;
    TowerDefense *tower_defense_;
public:
    explicit Entity(TowerDefense *tower_defense, Position position, EntityType type, const MyString &name);

    Entity(TowerDefense *tower_defense, int x, int y, EntityType type, const MyString &name);

    Entity(const Entity &obj) = default;

    Entity &operator=(const Entity &obj) = default;

    virtual ~Entity() = default;

    virtual EntityType getType() const;

    virtual Position getPos() const;

    virtual MyString getName() const;

    virtual void setPos(Position position);

    virtual void setPos(int x, int y);

    virtual void update() = 0;

    virtual bool isAlive() const;

    virtual void kill();

    virtual double getDistance(Position position);

    virtual double getDistance(const Entity &entity);

};

#endif //TOWER_DEFENSE_ENTITY_H
