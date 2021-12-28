#include "EntitiesManager.h"

EntitiesManager::EntitiesManager(Castle *castle) {
    castle_ = castle;
}

bool EntitiesManager::matchesFilter(const Entity &entity, const List<EntityType> &filter) const {
    if (filter.getLen() == 0) { return true; }
    if (filter.getValueIndex(entity.getType()) != -1) { return true; }
    return false;
}

List<Entity *> EntitiesManager::getNearbyEntities(Position center, double radius, const List<EntityType> &filter) {
    List<Entity *> list;
    entities_.resetCurrent();
    while (entities_.hasNext()) {
        entities_.next();
        if (matchesFilter(*entities_.getCurrent(), filter)
            && entities_.getCurrent()->getDistance(center) <= radius) {
            list.insert(entities_.getCurrent(), 0);
        }
    }
    return list;
}

List<Entity *> EntitiesManager::getNearbyEntities(const Entity &center, double radius, const List<EntityType> &filter) {
    return getNearbyEntities(center.getPos(), radius, filter);
}

Entity *EntitiesManager::getNearbyEntity(Position center, const List<EntityType> &filter) {
    Entity *res = nullptr;
    entities_.resetCurrent();
    while (entities_.hasNext()) {
        entities_.next();
        if (matchesFilter(*entities_.getCurrent(), filter)
            && (res == nullptr || entities_.getCurrent()->getDistance(center) < res->getDistance(center))) {
            res = entities_.getCurrent();
        }
    }
    return res;
}

Entity *EntitiesManager::getNearbyEntity(const Entity &center, const List<EntityType> &filter) {
    return getNearbyEntity(center.getPos(), filter);
}

Castle *EntitiesManager::getCastle() {
    return castle_;
}
