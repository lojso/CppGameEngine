#include "Game.h"
#include "Constants.h"
#include "iostream"

Game::Game() {
    _isRunning = false;
}

Game::~Game() {

}

bool Game::IsRunning() const {
    return _isRunning;
}

float projectionPosX = 0.0f;
float projectionPosY = 0.0f;
float projectileVelX = 0.1f;
float projectileVelY = 0.1f;

void Game::Initialize(int width, int height) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "Error initializing SDL" << std::endl;
        return;
    }

    window = SDL_CreateWindow(
            NULL,
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            WINDOW_WIDTH,
            WINDOW_HEIGHT,
            SDL_WINDOW_BORDERLESS);

    if (!window) {
        std::cerr << "Error creating SDL window" << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);

    if (!renderer) {
        std::cerr << "Error creating SDL renderer" << std::endl;
    }

    _isRunning = true;
}

void Game::ProcessInput() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT: {
            _isRunning = false;
            break;
        }
        case SDL_KEYDOWN: {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                _isRunning = false;
            }
        }
        default: {
            break;
        }
    }
}

void Game::Update() {
    projectionPosX += projectileVelX;
    projectionPosY += projectileVelY;
}

void Game::Render() {
    SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
    SDL_RenderClear(renderer);

    SDL_Rect projectile{
            (int) projectionPosX,
            (int) projectionPosY,
            10,
            10
    };

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &projectile);

    SDL_RenderPresent(renderer);
}

void Game::Destroy() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}