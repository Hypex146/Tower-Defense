#define ALL_INCLUDE

#include "AllHeaders.h"
#include "TowerDefense.h"


EntitiesManager *TowerDefense::getEntitiesManager() const {
    return entities_manager_;
}

/*
Renderer *TowerDefense::getRenderer() const {
    return renderer_;
}
*/
GameMap *TowerDefense::getGameMap() const {
    return game_map_;
}

int TowerDefense::random(int min, int max) {
    srand(time(nullptr));
    int random_number = min + rand() % max;
    return random_number;
}

SettingsDatabase *TowerDefense::getSettingsDatabase() const {
    return settings_database_;
}

Result TowerDefense::moveEntities() {
    entities_manager_->updateAll();
    tick_++;
    return Result();
}

int TowerDefense::getTick() const {
    return tick_;
}

Result TowerDefense::buildTower(Position position) {
    if (!correctPositions(position)) { return Result(false, 1, MyString("Incorrect position")); }
    if (game_map_->getFieldType(position) != FieldType::PLAIN) {
        return Result(false, 2, MyString("Inaccessible place for build"));
    }
    List<EntityType> filter;
    filter.insert(EntityType::ENEMY_LAIR, 0);
    filter.insert(EntityType::WALL, 0);
    filter.insert(EntityType::TOWER, 0);
    filter.insert(EntityType::CASTLE, 0);
    filter.insert(EntityType::HERO_HEAVY_INFANTRY, 0);
    filter.insert(EntityType::HERO_LIGHT_INFANTRY, 0);
    filter.insert(EntityType::HEAVY_INFANTRY, 0);
    filter.insert(EntityType::LIGHT_INFANTRY, 0);
    if (entities_manager_->hasEntityHere(position, filter)) {
        return Result(false, 3, MyString("There is already a structure or entity at this place"));
    }
    game_map_->deleteRoadCell(position, true, true);
    List<Entity *> entities = entities_manager_->getEntities();
    ListIterator<Entity *> iterator = entities.createIterator();
    while (iterator.hasNext()) {
        iterator.next();
        if (iterator.getCurrent()->getType() != EntityType::ENEMY_LAIR) { continue; }
        if (!game_map_->getRoadGraphWithWall()->hasWay(iterator.getCurrent()->getPos(),
                                                       entities_manager_->getCastle()->getPos())) {
            game_map_->addRoadCell(position, true, true);
            return Result(false, 4, MyString("The position closes the passage to the opponents"));
        }
    }
    if (entities_manager_->getCastle()->getGold() <
        settings_database_->getTowerSettings().tower_table_.getInfoByIndex(0).cost_) {
        return Result(false, 5, MyString("Not enough money"));
    }
    auto *tower = new Tower(this, position, MyString("Castle"), 1,
                            settings_database_->getTowerSettings().tower_table_);
    entities_manager_->registerEntity(tower);
    entities_manager_->getCastle()->addGold(
            settings_database_->getTowerSettings().tower_table_.getInfoByIndex(0).cost_ * (-1));
    return Result(true, 0, MyString("The tower was successfully built"));
}

Result TowerDefense::buildWall(Position position) {
    if (!correctPositions(position)) { return Result(false, 1, MyString("Incorrect position")); }
    if (game_map_->getFieldType(position) != FieldType::PLAIN) {
        return Result(false, 2, MyString("Inaccessible place for build"));
    }
    List<EntityType> filter;
    filter.insert(EntityType::ENEMY_LAIR, 0);
    filter.insert(EntityType::WALL, 0);
    filter.insert(EntityType::TOWER, 0);
    filter.insert(EntityType::CASTLE, 0);
    filter.insert(EntityType::HERO_HEAVY_INFANTRY, 0);
    filter.insert(EntityType::HERO_LIGHT_INFANTRY, 0);
    filter.insert(EntityType::HEAVY_INFANTRY, 0);
    filter.insert(EntityType::LIGHT_INFANTRY, 0);
    if (entities_manager_->hasEntityHere(position, filter)) {
        return Result(false, 3, MyString("There is already a structure or entity at this place"));
    }
    if (entities_manager_->getCastle()->getGold() <
        settings_database_->getWallSettings().cost_) {
        return Result(false, 4, MyString("Not enough money"));
    }
    Wall *wall = new Wall(this, position, MyString("Wall"), settings_database_->getWallSettings().max_HP_);
    entities_manager_->registerEntity(wall);
    entities_manager_->getCastle()->addGold(
            settings_database_->getWallSettings().cost_ * (-1));
    game_map_->deleteRoadCell(position, true, false);
    return Result(true, 0, MyString("The wall was successfully built"));
}

Result TowerDefense::castleLvlUp() {
    if (!entities_manager_->getCastle()->possibleUpLvl()) {
        return Result(false, 1, MyString("The castle is already of the highest level"));
    }
    if (!entities_manager_->getCastle()->canUpLvl()) {
        return Result(false, 2, MyString("Not enough money"));
    }
    entities_manager_->getCastle()->lvlUp();
    return Result(true, 0, MyString("The castle was successfully upgraded"));
}

Result TowerDefense::towerLvlUp(Position position) {
    List<EntityType> filter;
    filter.insert(EntityType::TOWER, 0);
    Entity *entity = entities_manager_->getNearbyEntity(position, filter);
    if (entity == nullptr || entity->getPos() != position) {
        return Result(false, 1, MyString(
                "There is no tower at this position"));
    }
    auto *tower = dynamic_cast<Tower *>(entity);
    if (!tower->possibleUpLvl()) {
        return Result(false, 2, MyString("The tower is already of the highest level"));
    }
    if (!tower->canUpLvl()) {
        return Result(false, 3, MyString("Not enough money"));
    }
    tower->lvlUp();
    return Result(true, 0, MyString("The tower was successfully upgraded"));
}

Result TowerDefense::fixWall(Position position) {
    List<EntityType> filter;
    filter.insert(EntityType::WALL, 0);
    Entity *entity = entities_manager_->getNearbyEntity(position, filter);
    if (entity == nullptr || entity->getPos() != position) {
        return Result(false, 1, MyString(
                "There is no wall at this position"));
    }
    auto *wall = dynamic_cast<Wall *>(entity);
    if (entities_manager_->getCastle()->getGold() < settings_database_->getWallSettings().fix_cost_) {
        return Result(false, 1, MyString("Not enough money"));
    }
    wall->fix(wall->getMaxHP());
    entities_manager_->getCastle()->addGold(settings_database_->getWallSettings().fix_cost_ * (-1));
    return Result(true, 0, MyString("The wall was successfully fixed"));
}

void TowerDefense::registerEntitiesManager(EntitiesManager *entities_manager) {
    entities_manager_ = entities_manager;
}

/*
void TowerDefense::registerRenderer(Renderer *renderer) {
    renderer_ = renderer;
}
*/
void TowerDefense::registerGameMap(GameMap *game_map) {
    game_map_ = game_map;
}

void TowerDefense::registerSettingsDatabase(SettingsDatabase *settings_database) {
    settings_database_ = settings_database;
}

bool TowerDefense::isReady() const {
    if (entities_manager_ != nullptr && game_map_ != nullptr && settings_database_ != nullptr) {
        return true;
    }
    return false;
}

void TowerDefense::initModulesDefault() {
    auto *game_map = new GameMap(this);
    registerGameMap(game_map);
    auto *data = new SettingsDatabase();
    registerSettingsDatabase(data);
    auto *castle = new Castle(this, game_map_->getCastlePosition(), MyString("Castle"),
                              settings_database_->getCastleSettings().start_gold_,
                              settings_database_->getCastleSettings().castle_table_);
    auto *em = new EntitiesManager(castle);
    List<Position> lairs_pos = game_map_->getLairsPositions();
    ListIterator<Position> iterator = lairs_pos.createIterator();
    while (iterator.hasNext()) {
        iterator.next();
        Lair *lair = new Lair(this, iterator.getCurrent(), MyString("Lair"),
                              settings_database_->getLairSettings().lair_table_);
        em->registerEntity(lair);
    }
    registerEntitiesManager(em);
}

void TowerDefense::deleteAllModules() {
    delete entities_manager_;
    delete game_map_;
    delete settings_database_;
}

bool TowerDefense::correctPositions(Position pos) const {
    if (pos.y_ < 0 || pos.y_ >= game_map_->getHeight()) { return false; }
    if (pos.x_ < 0 || pos.x_ >= game_map_->getWidth()) { return false; }
    return true;
}

Result::Result(bool completed, int error_code, const MyString &message) {
    completed_ = completed;
    error_code_ = error_code;
    message_ = message;
}
