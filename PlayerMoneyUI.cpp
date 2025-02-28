#include "PlayerMoneyUI.h"

PlayerMoneyUI::PlayerMoneyUI(SDL_Renderer* renderer, TTF_Font* font) : renderer(renderer), font(font)
{
	dest = { 320, 10, 0,0 };
	updateText();
}

PlayerMoneyUI::~PlayerMoneyUI()
{
}

void PlayerMoneyUI::update()
{
	updateText();
}

void PlayerMoneyUI::draw()
{
	SDL_RenderTexture(renderer, texture, NULL, &dest);
	SDL_DestroyTexture(texture);
}

void PlayerMoneyUI::updateText()
{
	text = std::to_string(money) + "$";
	SDL_Surface* moneySurface = TTF_RenderText_Solid(font, text.c_str(), strlen(text.c_str()), color);
	texture = SDL_CreateTextureFromSurface(renderer, moneySurface);
	SDL_GetTextureSize(texture, &dest.w, &dest.h);
	SDL_DestroySurface(moneySurface);
}
