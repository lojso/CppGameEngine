#ifndef GAMEENGINE_ENTITY_H
#define GAMEENGINE_ENTITY_H

#include <vector>
#include <string>
#include "Component.h"
#include "EntityManager.h"

class Component;
class EntityManager;

class Entity {
private:
    EntityManager& _manager;
    bool _isActive;
    std::vector<Component*>
    _components;

public:
    bool IsActive() const;
    std::string name;
    Entity(EntityManager& manager);
    Entity(EntityManager& manager, std::string name);
    void Update(float deltaTime);
    void Render();
    void Destroy();
};

#endif //GAMEENGINE_ENTITY_H
