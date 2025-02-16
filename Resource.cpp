#include "Resource.h"
#include<SDL3_image/SDL_image.h>

Resource::Resource(SDL_Renderer* ren, SDL_FPoint pos, const char* pathTexture)
{
	renderer = ren;
	texture = IMG_LoadTexture(renderer, pathTexture);
	dest = { pos.x, pos.y, 0, 0 };
	SDL_GetTextureSize(texture, &dest.w, &dest.h);
}

Resource::~Resource()
{
}

void Resource::update()
{
}

void Resource::draw()
{
	SDL_RenderTexture(renderer, texture, NULL, &dest);
}
