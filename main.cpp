#define SDL_MAIN_USE_CALLBACKS 1
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<iostream>
#include<stdio.h>

static SDL_Window* window;
static SDL_Renderer* renderer;
int posX = 0;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("SDL3 Game", 800, 640, 0, &window, &renderer);
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
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppIterate(void* appstate) {
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 30, 200, 30, 255);
	posX++;
	if (posX == 800 - 100) {
		posX = 0;
	}
	SDL_FRect rect;
	rect.x = posX;
	rect.y = 0;
	rect.w = 100;
	rect.h = 100;
	SDL_RenderFillRect(renderer, &rect);
	SDL_Delay(16);
	SDL_RenderPresent(renderer);
	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result) {

}