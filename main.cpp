#define SDL_MAIN_USE_CALLBACKS 1
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>

static SDL_Window* window;
static SDL_Renderer* renderer;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("SDL3 Game", 800, 640, 0, &window, &renderer);
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
	if (event->type == SDL_EVENT_QUIT)
	{
		return SDL_APP_SUCCESS;
	}
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppIterate(void* appstate) {
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 100, 30, 200, 255);
	SDL_FRect rect;

	rect.w = 100;
	rect.h = 100;
	rect.x = 100;
	rect.y = 100;
	SDL_RenderFillRect(renderer, &rect);

	SDL_FRect rectBorder;
	rectBorder.w = 100;
	rectBorder.h = 100;
	rectBorder.x = 300;
	rectBorder.y = 100;
	SDL_RenderRect(renderer, &rectBorder);

	SDL_RenderLine(renderer, 450, 100, 500, 200);

	SDL_FPoint lines[] = {
		{100, 250}, {200, 350}, {300, 400}, {100, 450}
	};
	SDL_FPoint points[] = {
	{200, 350}, {300, 450}, {400, 500}, {200, 550}
	};
	SDL_RenderLines(renderer, lines, SDL_arraysize(lines));

	SDL_RenderPoint(renderer, 50, 50);
	SDL_RenderPoints(renderer, points, SDL_arraysize(points));

	SDL_RenderPresent(renderer);
	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result) {

}