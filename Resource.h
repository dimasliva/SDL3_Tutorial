#pragma once
#include <SDL3/SDL.h>
class Resource
{
public:
	Resource(SDL_Renderer* ren, SDL_FPoint pos, const char* pathTexture);
	~Resource();
	void update();
	void draw();
	SDL_FRect getDest() { return dest; };

private:
	SDL_Texture* texture;
	SDL_FRect dest;
	SDL_Renderer* renderer;
};

