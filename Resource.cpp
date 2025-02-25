#include "Resource.h"
#include<SDL3_image/SDL_image.h>

Resource::Resource(SDL_Renderer* ren, SDL_FPoint pos, const char* pathTexture, const char* pathTextureSpawn)
{
	pathSpawnTexture = pathTextureSpawn;
	renderer = ren;
	texture = IMG_LoadTexture(renderer, pathTexture);
	dest = { pos.x, pos.y, 0, 0 };
	SDL_GetTextureSize(texture, &dest.w, &dest.h);
	animations.spawn = { 7, 100, 0 };
	spriteSize = dest.w;
	textureSpawn = IMG_LoadTexture(renderer, pathSpawnTexture);
	srcSpawn = { 0, 0, static_cast<float>(spriteSize), static_cast<float>(spriteSize) };
}

Resource::~Resource()
{
}

void Resource::update()
{

}

void Resource::draw()
{
	if (pickuped) {
		SDL_RenderTexture(renderer, textureSpawn, &srcSpawn, &dest);
	}
	else {
		SDL_RenderTexture(renderer, texture, NULL, &dest);
	}
}

bool Resource::pickupAnimPlay()
{
	if (pickuped == true) {
		if (texture) {
			SDL_DestroyTexture(texture);
		}
		return animationHandler.reverseShowAnimation(animations.spawn, srcSpawn, spriteSize);
	}
	return false;
}
