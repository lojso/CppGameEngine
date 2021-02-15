#include "EntityManager.h"

void EntityManager::ClearData() {
    for (auto& entity: entites){
        entity->Destroy();
    }
}

bool EntityManager::HasNoEntites() {
    return entites.size() == 0;
}

void EntityManager::Update(float deltaTime) {
    for (auto& entity: entites){
        entity->Update(deltaTime);
    }
}

void EntityManager::Render() {
    for (auto& entity: entites){
        entity->Render();
    }
}

Entity& EntityManager::AddEntity(std::string entityName) {
    Entity* entity = new Entity(*this, entityName);
    entites.emplace_back(entity);
    return *entity;
}

std::vector<Entity*> EntityManager::GetEntites() const {
    return entites;
}

unsigned int EntityManager::GetEntityCount() {
    return entites.size();
}
