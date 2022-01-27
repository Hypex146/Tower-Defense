#ifndef TOWER_DEFENSE_ENTITIESMANAGER_H
#define TOWER_DEFENSE_ENTITIESMANAGER_H


class EntitiesManager {
private:
    Castle *castle_;
    List<Entity *> entities_;
    List<Entity *> hero_entities_;

    bool matchesFilter(const Entity &entity, const List<EntityType> &filter) const;

    void deleteAllEntities();

public:
    explicit EntitiesManager(Castle *castle);

    ~EntitiesManager();

    List<Entity *>
    getNearbyEntities(Position center, double radius, const List<EntityType> &filter = List<EntityType>());

    List<Entity *>
    getNearbyEntities(const Entity &center, double radius, const List<EntityType> &filter = List<EntityType>());

    List<Entity *>
    getNearbyHeroEntities(Position center, double radius, const List<EntityType> &filter = List<EntityType>());

    List<Entity *>
    getNearbyHeroEntities(const Entity &center, double radius, const List<EntityType> &filter = List<EntityType>());

    Entity *getNearbyEntity(Position center, const List<EntityType> &filter = List<EntityType>());

    Entity *getNearbyEntity(const Entity &center, const List<EntityType> &filter = List<EntityType>());

    bool hasEntityHere(Position pos, const List<EntityType> &filter = List<EntityType>()) const;

    Castle *getCastle();

    List<Entity *> getEntities() const;

    void registerEntity(Entity *entity);

    void registerHeroEntity(Entity *entity);

    void removeDead();

    void updateAll();

};


#endif //TOWER_DEFENSE_ENTITIESMANAGER_H
