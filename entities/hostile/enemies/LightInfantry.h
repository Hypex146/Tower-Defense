#ifndef TOWER_DEFENSE_LIGHTINFANTRY_H
#define TOWER_DEFENSE_LIGHTINFANTRY_H


class LightInfantry : public Enemy {
private:
    double dodge_chance_;

    bool dodged() const;

    void move();

protected:
    LightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP,
                  double regeneration_rate,
                  double speed, double damage_coefficient, double dodge_chance, EntityType type);

    LightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                  double regeneration_rate,
                  double speed, double damage_coefficient, double dodge_chance, EntityType type);

    LightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                  double regeneration_rate,
                  double speed, double damage_coefficient, double dodge_chance, EntityType type);

    LightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                  double regeneration_rate,
                  double speed, double damage_coefficient, double dodge_chance, EntityType type);

public:
    LightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double HP, double max_HP,
                  double regeneration_rate, double speed, double damage_coefficient, double dodge_chance);

    LightInfantry(TowerDefense *tower_defense, Position position, const MyString &name, double max_HP,
                  double regeneration_rate, double speed, double damage_coefficient, double dodge_chance);

    LightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double HP, double max_HP,
                  double regeneration_rate, double speed, double damage_coefficient, double dodge_chance);

    LightInfantry(TowerDefense *tower_defense, int x, int y, const MyString &name, double max_HP,
                  double regeneration_rate, double speed, double damage_coefficient, double dodge_chance);

    double getDodgeChance() const;

    void setDodgeChance(double dodge_chance);

    void takeDamage(double damage) override;

    void update() override;

};


#endif //TOWER_DEFENSE_LIGHTINFANTRY_H
