#ifndef TOWER_DEFENSE_TOWER_H
#define TOWER_DEFENSE_TOWER_H


struct LvlSpecificationsForTower {
    double attack_radius_;
    double damage_;
    double reload_time_;
    double cost_;

    LvlSpecificationsForTower();

    LvlSpecificationsForTower(double attack_radius, double damage, double fire_rate, double cost);
};

class Tower : public Entity {
private:
    int lvl_;
    Table<int, LvlSpecificationsForTower> specifications_table_;
    double timeToFire_;
    List<EntityType> enemy_filter_;

    bool canFire() const;

    List<EntityType> createEnemyFilter();

public:
    Tower(TowerDefense *tower_defense, Position position, const MyString &name, int lvl,
          const Table<int, LvlSpecificationsForTower> &specifications_table);

    Tower(TowerDefense *tower_defense, int x, int y, const MyString &name, int lvl,
          const Table<int, LvlSpecificationsForTower> &specifications_table);

    Tower(TowerDefense *tower_defense, Position position, const MyString &name,
          const Table<int, LvlSpecificationsForTower> &specifications_table);

    Tower(TowerDefense *tower_defense, int x, int y, const MyString &name,
          const Table<int, LvlSpecificationsForTower> &specifications_table);

    ~Tower() override = default;

    double getAttackRadius() const;

    double getDamage() const;

    double getFireRate() const;

    double getLvlCost(int lvl) const;

    int getLvl() const;

    LvlSpecificationsForTower getLvlSpec(int lvl) const;

    void setLvl(int lvl);

    void lvlUp();

    bool possibleUpLvl() const;

    bool canUpLvl() const;

    void update() override;

};


#endif //TOWER_DEFENSE_TOWER_H
