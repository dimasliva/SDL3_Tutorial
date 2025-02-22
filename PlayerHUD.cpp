#include "PlayerHUD.h"

PlayerHUD::PlayerHUD(SDL_Renderer* renderer, TTF_Font* font): renderer(renderer), font(font)
{
	destMoney = { 10, 10, 0,0 };
	updateMoney();
}

PlayerHUD::~PlayerHUD()
{
}

void PlayerHUD::update()
{
	updateMoney();
}

void PlayerHUD::draw()
{
	SDL_RenderTexture(renderer, moneyTexture, NULL, &destMoney);
	SDL_DestroyTexture(moneyTexture);
}

void PlayerHUD::updateMoney()
{
	moneyText = std::to_string(money) + "$";
	SDL_Surface* moneySurface = TTF_RenderText_Solid(font, moneyText.c_str(), strlen(moneyText.c_str()), moneyColor);
	moneyTexture = SDL_CreateTextureFromSurface(renderer, moneySurface);
	SDL_GetTextureSize(moneyTexture, &destMoney.w, &destMoney.h);
	SDL_DestroySurface(moneySurface);
}
