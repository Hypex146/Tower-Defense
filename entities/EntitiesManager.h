#ifndef TOWER_DEFENSE_ENTITIESMANAGER_H
#define TOWER_DEFENSE_ENTITIESMANAGER_H

#include <iostream>
#include "Lists_collection.h"
#include "AllEntities.h"

class EntitiesManager {
private:
    Castle *castle_;
    List<Entity *> entities_;
public:
    EntitiesManager() = default;

    EntitiesManager(Castle *castle);

    List<Entity *> getNearby(Position center, double radius);

    List<Entity *> getNearby(const Entity &center, double radius);

    Castle *getCastle();

    void registerEntity(Entity *entity);

    void removeDead();

};


#endif //TOWER_DEFENSE_ENTITIESMANAGER_H
