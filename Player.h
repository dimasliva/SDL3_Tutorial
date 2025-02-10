#include<SDL3/SDL.h>
#pragma once

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
