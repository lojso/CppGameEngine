#ifndef GAMEENGINE_COMPONENT_H
#define GAMEENGINE_COMPONENT_H

class Entity;

class Component {
public:
    Entity* owner;
    virtual ~Component() {}
    virtual void Initialize() {}
    virtual void Update(float deltaTime) {}
    virtual void Render() {}
};




#endif //GAMEENGINE_COMPONENT_H
