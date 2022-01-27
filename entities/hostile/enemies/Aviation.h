#ifndef TOWER_DEFENSE_AVIATION_H
#define TOWER_DEFENSE_AVIATION_H


class Aviation : public Enemy {
private:
    double wall_damage_;
    int ammunition_;

    void move();

    void tryAttackWall();

protected:
    Aviation(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP,
             double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition, EntityType type);

    Aviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
             double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition, EntityType type);

    Aviation(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
             double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition, EntityType type);

    Aviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP, double regeneration_rate,
             double speed,
             double damage_coefficient, double wall_damage, int ammunition, EntityType type);

public:
    Aviation(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP,
             double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition);

    Aviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
             double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition);

    Aviation(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
             double regeneration_rate, double speed,
             double damage_coefficient, double wall_damage, int ammunition);

    Aviation(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP, double regeneration_rate,
             double speed,
             double damage_coefficient, double wall_damage, int ammunition);

    double getWallDamage() const;

    void setWallDamage(double damage);

    int getAmmunition() const;

    void setAmmunition(int ammunition);

    void update() override;

};


#endif //TOWER_DEFENSE_AVIATION_H
