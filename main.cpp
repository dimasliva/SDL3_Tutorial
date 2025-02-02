#define SDL_MAIN_USE_CALLBACKS 1
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<iostream>
#include<stdio.h>

static SDL_Window* window;
static SDL_Renderer* renderer;

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
	case SDL_EVENT_KEY_DOWN:
		switch (event->key.scancode)
		{
		case SDL_SCANCODE_A:
			std::cout << "Key pressed A:" << std::endl;
			break;
		case SDL_SCANCODE_W:
			std::cout << "Key pressed W:" << std::endl;
			break;
		default:
			break;
		}
		break;
	case SDL_EVENT_KEY_UP:
		switch (event->key.scancode)
		{
		case SDL_SCANCODE_A:
			std::cout << "Key unpressed A:" << std::endl;
			break;
		case SDL_SCANCODE_W:
			std::cout << "Key unpressed  W:" << std::endl;
			break;
		default:
			break;
		}
		break;
	case SDL_EVENT_MOUSE_BUTTON_DOWN:
		printf("Down: %d\n", event->button.button);
		printf("X: %.2f\n", event->button.x);
		printf("Y: %.2f\n", event->button.y);
		std::cout << 1.000001f <<  std::endl;
		break;
	case SDL_EVENT_MOUSE_BUTTON_UP:
		printf("Up: %d\n", event->button.button);
		printf("X: %.2f\n", event->button.x);
		printf("Y: %.2f\n", event->button.y);
		std::cout << 1.000001f << std::endl;
		break;
	default:
		break;
	}
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppIterate(void* appstate) {
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);


	SDL_RenderPresent(renderer);
	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result) {

}