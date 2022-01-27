#ifndef TOWER_DEFENSE_TOWERDEFENSE_H
#define TOWER_DEFENSE_TOWERDEFENSE_H


struct Result {
    bool completed_;
    int error_code_;
    MyString message_;

    explicit Result(bool completed = true, int error_code = 0, const MyString &message = MyString("Action completed"));
};


class TowerDefense {
private:
    EntitiesManager *entities_manager_ = nullptr;
//    Renderer *renderer_ = nullptr;
    GameMap *game_map_ = nullptr;
    SettingsDatabase *settings_database_ = nullptr;
    int tick_ = 0;
public:
    TowerDefense() = default;

    bool isReady() const;

    void registerEntitiesManager(EntitiesManager *entities_manager);

//    void registerRenderer(Renderer *renderer);

    void registerGameMap(GameMap *game_map);

    void registerSettingsDatabase(SettingsDatabase *settings_database);

    EntitiesManager *getEntitiesManager() const;

//    Renderer *getRenderer() const;

    GameMap *getGameMap() const;

    SettingsDatabase *getSettingsDatabase() const;

    int getTick() const;

    Result moveEntities();

    Result buildTower(Position position);

    Result buildWall(Position position);

    Result castleLvlUp();

    Result towerLvlUp(Position position);

    Result fixWall(Position position);

    int random(int min, int max);

    void initModulesDefault();

    void deleteAllModules();

    bool correctPositions(Position pos) const;

};

#endif //TOWER_DEFENSE_TOWERDEFENSE_H
