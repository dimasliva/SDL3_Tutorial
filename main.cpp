#define SDL_MAIN_USE_CALLBACKS 1
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<iostream>
#include<stdio.h>

static SDL_Window* window;
static SDL_Renderer* renderer;
SDL_FRect rect = { 0, 0, 100, 100 };
bool turnRect = false;
bool turnRectY = false;

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
	if (rect.x >= 700 || rect.x <= 0) {
		turnRect = !turnRect;
	}
	if (turnRect == true) {
		rect.x = rect.x + 5;
	}
	if (turnRect == false) {
		rect.x = rect.x - 5;
	}

	if (rect.y >= 540 || rect.y <= 0) {
		turnRectY = !turnRectY;
	}
	if (turnRectY == true) {
		rect.y = rect.y + 5;
	}
	if (turnRectY == false) {
		rect.y = rect.y - 5;
	}
	SDL_SetRenderDrawColor(renderer, 30, 200, 30, 255);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
	SDL_Delay(16);
	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result) {

}