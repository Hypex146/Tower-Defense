#ifndef TOWER_DEFENSE_ENTITIESMANAGER_H
#define TOWER_DEFENSE_ENTITIESMANAGER_H

#include <iostream>
#include "Lists_collection.h"
#include "AllEntities.h"

class EntitiesManager {
private:
    Castle *castle_ = nullptr;
    List<Entity *> entities_;

    bool matchesFilter(const Entity &entity, const List<EntityType> &filter);

public:
    EntitiesManager() = default;

    explicit EntitiesManager(Castle *castle);

    List<Entity *>
    getNearbyEntities(Position center, double radius, const List<EntityType> &filter = List<EntityType>());

    List<Entity *>
    getNearbyEntities(const Entity &center, double radius, const List<EntityType> &filter = List<EntityType>());

    Entity *getNearbyEntity(Position center, const List<EntityType> &filter = List<EntityType>());

    Entity *getNearbyEntity(const Entity &center, const List<EntityType> &filter = List<EntityType>());

    Castle *getCastle();

    void registerEntity(Entity *entity);

    void removeDead();

};


#endif //TOWER_DEFENSE_ENTITIESMANAGER_H
