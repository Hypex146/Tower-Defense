#include "Entity.h"

Position::Position(int x, int y) : x_(x), y_(y) {}

Entity::Entity(Position position, EntityType type, const MyString &name) : position_(position), is_alive_(true),
                                                                           type_(type) { name_ = name; }

Entity::Entity(int x, int y, EntityType type, const MyString &name) : Entity(Position(x, y), type, name) {}

Position Entity::getPos() const { return position_; }

void Entity::update() {}

bool Entity::isAlive() const { return is_alive_; }

void Entity::kill() { is_alive_ = false; }

void Entity::setPos(Position position) { position_ = position; }

void Entity::setPos(int x, int y) { setPos(Position(x, y)); }

EntityType Entity::getType() const { return type_; }

MyString Entity::getName() const { return name_; }
