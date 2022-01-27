#define ALL_INCLUDE

#include "AllHeaders.h"
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
    ListIterator<Entity*> iterator = entities_.createIterator();
    while (iterator.hasNext()) {
        iterator.next();
        if (matchesFilter(*iterator.getCurrent(), filter)
            && iterator.getCurrent()->getDistance(center) <= radius) {
            list.insert(iterator.getCurrent(), 0);
        }
    }
    return list;
}

List<Entity *> EntitiesManager::getNearbyEntities(const Entity &center, double radius, const List<EntityType> &filter) {
    return getNearbyEntities(center.getPos(), radius, filter);
}

Entity *EntitiesManager::getNearbyEntity(Position center, const List<EntityType> &filter) {
    Entity *res = nullptr;
    ListIterator<Entity*> iterator = entities_.createIterator();
    while (iterator.hasNext()) {
        iterator.next();
        if (matchesFilter(*iterator.getCurrent(), filter)
            && (res == nullptr || iterator.getCurrent()->getDistance(center) < res->getDistance(center))) {
            res = iterator.getCurrent();
        }
    }
    return res;
}

Entity *EntitiesManager::getNearbyEntity(const Entity &center, const List<EntityType> &filter) {
    return getNearbyEntity(center.getPos(), filter);
}

List<Entity *> EntitiesManager::getNearbyHeroEntities(Position center, double radius, const List<EntityType> &filter) {
    List<Entity *> list;
    ListIterator<Entity*> iterator = hero_entities_.createIterator();
    while (iterator.hasNext()) {
        iterator.next();
        if (matchesFilter(*iterator.getCurrent(), filter)
            && iterator.getCurrent()->getDistance(center) <= radius) {
            list.insert(iterator.getCurrent(), 0);
        }
    }
    return list;
}

List<Entity *>
EntitiesManager::getNearbyHeroEntities(const Entity &center, double radius, const List<EntityType> &filter) {
    return getNearbyHeroEntities(center.getPos(), radius, filter);
}

bool EntitiesManager::hasEntityHere(Position pos, const List<EntityType> &filter) const {
    ListIterator<Entity*> iterator = entities_.createIterator();
    while (iterator.hasNext()) {
        iterator.next();
        if (matchesFilter(*iterator.getCurrent(), filter) && iterator.getCurrent()->getPos() == pos) {
            return true;
        }
    }
    return false;
}

Castle *EntitiesManager::getCastle() {
    return castle_;
}

List<Entity *> EntitiesManager::getEntities() const {
    return entities_;
}

void EntitiesManager::registerEntity(Entity *entity) {
    entities_.insert(entity, 0);
}

void EntitiesManager::registerHeroEntity(Entity *entity) {
    hero_entities_.insert(entity, 0);
}

void EntitiesManager::updateAll() {
    if (castle_->getHP() <= 0) { return; }
    ListIterator<Entity*> iterator = entities_.createIterator();
    while (iterator.hasNext()) {
        iterator.next();
        iterator.getCurrent()->update();
    }
    castle_->update();
    removeDead();
}

void EntitiesManager::removeDead() {
    for (int i = hero_entities_.getLen() - 1; i >= 0; i--) {
        Entity *entity = hero_entities_.take(i);
        if (!entity->isAlive()) {
            hero_entities_.remove(i);
        }
    }
    for (int i = entities_.getLen() - 1; i >= 0; i--) {
        Entity *entity = entities_.take(i);
        if (!entity->isAlive()) {
            entities_.remove(i);
            delete entity;
        }
    }
}

void EntitiesManager::deleteAllEntities() {
    ListIterator<Entity*> iterator = entities_.createIterator();
    while(iterator.hasNext()) {
        iterator.next();
        delete iterator.getCurrent();
    }
}

EntitiesManager::~EntitiesManager() {
    deleteAllEntities();
    delete castle_;
}
