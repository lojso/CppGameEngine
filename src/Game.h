#ifndef GAMEENGINE_GAME_H
#define GAMEENGINE_GAME_H

#include <SDL.h>

class Game {
private:
    bool _isRunning;
    SDL_Window *window;

public:
    static SDL_Renderer *renderer;
    void LoadLevel(int levelNumber);
    Game();
    ~Game();
    int ticksLastFrame;
    bool IsRunning() const;
    void Initialize(int width, int height);
    void ProcessInput();
    void Update();
    void Render();

    void Destroy();
};


#endif //GAMEENGINE_GAME_H
