#pragma once
#include <SDL3/SDL.h>
class Resource
{
public:
	Resource(SDL_Renderer* ren, SDL_FPoint pos, const char* pathTexture);
	~Resource();
	void update();
	void draw();
	int getMoney() { return money; };
	SDL_FRect getHoverTextureSize() { return hoverTextureSize; };
	SDL_FRect getDest() { return dest; };

private:
	int money = 50;
	SDL_Texture* texture;
	SDL_FRect dest;
	SDL_FRect hoverTextureSize = {0, 0, 128, 125};
	SDL_Renderer* renderer;
};

