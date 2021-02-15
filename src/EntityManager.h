#ifndef GAMEENGINE_ENTITYMANAGER_H
#define GAMEENGINE_ENTITYMANAGER_H

#include "Entity.h"
#include "Component.h"

class EntityManager {
private:
    std::vector<Entity*> entites;
public:
    void ClearData();
    void Update(float deltaTime);
    void Render();
    bool HasNoEntites();
    Entity& AddEntity(std::string entityName);
    std::vector<Entity*> GetEntites() const;
    unsigned int GetEntityCount();
};


#endif //GAMEENGINE_ENTITYMANAGER_H
