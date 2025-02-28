#pragma once
#include<SDL3/SDL.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<string>
#include "PlayerMoneyUI.h"
#include "PlayerHealthUI.h"

class PlayerHUD
{
public:
	PlayerHUD(SDL_Renderer* renderer, TTF_Font* font, int currentHelth, int totalHelth);
	~PlayerHUD();

	void setMoney(int newMoney);
	void update();
	void draw();

private:
	PlayerMoneyUI* playerMoneyUI;
	PlayerHealthUI* playerHealthUI;
	SDL_Renderer* renderer;
	TTF_Font* font;
};

