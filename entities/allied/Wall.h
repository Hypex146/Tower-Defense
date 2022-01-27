#ifndef TOWER_DEFENSE_WALL_H
#define TOWER_DEFENSE_WALL_H


class Wall : public Entity {
private:
    double HP_;
    double max_HP_;
public:
    Wall(TowerDefense *tower_defense, Position pos, const MyString &name, double HP, double max_HP);

    Wall(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP);

    Wall(TowerDefense *tower_defense, Position pos, const MyString &name, double max_HP);

    Wall(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP);

    ~Wall() override = default;

    double getHP() const;

    double getMaxHP() const;

    void setHP(double HP);

    void takeDamage(double damage);

    void fix(double HP);

    void update() override;

    void kill() override;

};

#endif //TOWER_DEFENSE_WALL_H
