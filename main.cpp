#define SDL_MAIN_USE_CALLBACKS 1
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<SDL3_image/SDL_image.h>
#include<iostream>
#include<stdio.h>

static SDL_Window* window;
static SDL_Renderer* renderer;
SDL_FRect rect = { 0, 0, 200, 100 };
SDL_FRect srcrect = { 200, 200, 100, 100 };
int speed = 10;

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

	const bool* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_W]) {
		rect.y -= speed;
	}
	if (keys[SDL_SCANCODE_S]) {
		rect.y += speed;
	}
	if (keys[SDL_SCANCODE_A]) {
		rect.x -= speed;
	}
	if (keys[SDL_SCANCODE_D]) {
		rect.x += speed;
	}

	SDL_Texture* playerTexture = IMG_LoadTexture(renderer, "assets/player.png");
	SDL_GetTextureSize(playerTexture, &rect.w, &rect.h);
	SDL_RenderTexture(renderer, playerTexture, &srcrect, &rect);
	SDL_DestroyTexture(playerTexture);

	SDL_RenderPresent(renderer);
	SDL_Delay(16);
	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result) {

}