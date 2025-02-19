#pragma once
#include<SDL3/SDL.h>
#include"Player.h"
#include"Resource.h"

class Game
{
public: 
	Game();
	~Game();
	SDL_AppResult SDL_AppInit();
	SDL_AppResult SDL_AppEvent(SDL_Event* event);
	SDL_AppResult SDL_AppIterate();
	void SDL_AppQuit(SDL_AppResult result);

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Player* player;
	Resource* gold;
};

