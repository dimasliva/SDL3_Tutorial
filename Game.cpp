#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

SDL_AppResult Game::SDL_AppInit()
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("SDL3 Game", 800, 640, 0, &window, &renderer);
	player = new Player(renderer, "assets/Tiny Swords (Update 010)/Factions/Knights/Troops/Warrior/Blue/Warrior_Blue.png");
	gold = new Resource(renderer, { 300, 300 }, "assets/Tiny Swords (Update 010)/Resources/Resources/G_Idle.png");
	return SDL_AppResult();
}

SDL_AppResult Game::SDL_AppEvent(SDL_Event* event)
{
	switch (event->type)
	{
	case SDL_EVENT_QUIT:
		return SDL_APP_SUCCESS;
		break;

	default:
		break;
	}
	player->handleEvents(event);
	return SDL_APP_CONTINUE;
}

SDL_AppResult Game::SDL_AppIterate()
{
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);

	gold->update();
	gold->draw();

	player->update();
	player->draw();



	SDL_RenderPresent(renderer);
	SDL_Delay(16);
	return SDL_APP_CONTINUE;
}

void Game::SDL_AppQuit(SDL_AppResult result)
{
}
