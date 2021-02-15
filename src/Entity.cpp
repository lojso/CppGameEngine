#include "Entity.h"

Entity::Entity(EntityManager &manager) : _manager(manager){
    _isActive = true;
}

Entity::Entity(EntityManager &manager, std::string name) : _manager(manager), name(name){
    _isActive = true;
}

void Entity::Update(float deltaTime) {
    for(auto& component: _components){
        component->Update(deltaTime);
    }
}

void Entity::Render() {
    for(auto& component: _components){
        component->Render();
    }
}

void Entity::Destroy() {
    _isActive = true;
}

bool Entity::IsActive() const {
    return _isActive;
}