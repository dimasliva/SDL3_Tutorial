#pragma once
#include <SDL3/SDL.h>
#include"Animation.h"



class Resource
{
public:
	Resource(SDL_Renderer* ren, SDL_FPoint pos, const char* pathTexture, const char* pathSpawnTexture);
	~Resource();
	void update();
	void draw();
	void setPickuped(bool pickup) { pickuped = pickup; };
	bool pickupAnimPlay();
	int getMoney() { return money; };
	SDL_FRect getHoverTextureSize() { return hoverTextureSize; };
	SDL_FRect getDest() { return dest; };

private:
	int money = 50;
	bool pickuped;
	const char* pathSpawnTexture;
	Animation animationHandler;
	SpawnAnimationData animations;
	SDL_Texture* texture;
	SDL_Texture* textureSpawn;
	SDL_FRect dest;
	SDL_FRect srcSpawn;
	int spriteSize;
	SDL_FRect hoverTextureSize = {0, 0, 128, 125};
	SDL_Renderer* renderer;
};

