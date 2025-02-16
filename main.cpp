#define SDL_MAIN_USE_CALLBACKS 1
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<SDL3_image/SDL_image.h>
#include<iostream>
#include<stdio.h>
#include"Player.h"





static SDL_Window* window;
static SDL_Renderer* renderer;
Player* player = nullptr;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("SDL3 Game", 800, 640, 0, &window, &renderer);
	player = new Player(renderer, "assets/Tiny Swords (Update 010)/Factions/Knights/Troops/Warrior/Blue/Warrior_Blue.png");
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
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
SDL_AppResult SDL_AppIterate(void* appstate) {
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);

	player->update();
	player->draw();

	SDL_Vertex vertex[4];
	vertex[0].position = {100, 100};
	vertex[0].color = { 1,0,0,1 };

	vertex[1].position = { 100, 600 };
	vertex[1].color = { 0,1,0,1 };

	vertex[2].position = { 600, 100 };
	vertex[2].color = { 0,0,1,1 };

	vertex[3].position = { 600, 600 };
	vertex[3].color = { 0,0,1,1 };


	int indices[6] = {0, 1, 2, 1, 3, 2};
	int count = sizeof(vertex) / sizeof(vertex[0]);
	int countIndices = sizeof(indices) / sizeof(indices[0]);
	SDL_RenderGeometry(renderer, NULL, vertex, count, indices, countIndices);

	SDL_RenderPresent(renderer);
	SDL_Delay(16);
	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result) {

}