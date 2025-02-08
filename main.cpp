#define SDL_MAIN_USE_CALLBACKS 1
#include<SDL3/SDL.h>
#include<SDL3/SDL_main.h>
#include<SDL3_image/SDL_image.h>
#include<iostream>
#include<stdio.h>




class Player
{
public:
	Player(SDL_Renderer* renderer);
	~Player();
	void handleEvents();
	void update();
	void draw();

private:
	SDL_Renderer* renderer;
	SDL_FRect src;
	SDL_FRect dest;
	SDL_Texture* texture;
	int speed;
};
void Player::draw() {
	SDL_RenderTexture(renderer, texture, &src, &dest);
}
void Player::update() {
	const bool* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_W]) {
		dest.y -= speed;
	}
	if (keys[SDL_SCANCODE_S]) {
		dest.y += speed;
	}
	if (keys[SDL_SCANCODE_A]) {
		dest.x -= speed;
	}
	if (keys[SDL_SCANCODE_D]) {
		dest.x += speed;
	}
}
void Player::handleEvents() {
	
}

Player::Player(SDL_Renderer* renderer): renderer(renderer)
{
	texture = IMG_LoadTexture(renderer, "assets/Prototype_Character/Prototype_Character.png");
	dest = { 0, 0, 32 * 4, 32 * 4 };
	src = { 0, 0, 32, 32 };
	speed = 10;
}

Player::~Player()
{
	SDL_DestroyTexture(texture);
}

static SDL_Window* window;
static SDL_Renderer* renderer;
Player* player = nullptr;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[]) {
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer("SDL3 Game", 800, 640, 0, &window, &renderer);
	player = new Player(renderer);
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
	player->handleEvents();
	return SDL_APP_CONTINUE;
}
SDL_AppResult SDL_AppIterate(void* appstate) {
	SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
	SDL_RenderClear(renderer);

	player->update();
	player->draw();


	


	SDL_RenderPresent(renderer);
	SDL_Delay(16);
	return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void* appstate, SDL_AppResult result) {

}