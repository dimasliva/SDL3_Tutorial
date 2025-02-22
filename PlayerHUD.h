#pragma once
#include<SDL3/SDL.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<string>
class PlayerHUD
{
public:
	PlayerHUD(SDL_Renderer* renderer, TTF_Font* font);
	~PlayerHUD();

	void setMoney(int newMoney) { money = newMoney; };
	void update();
	void draw();

private:
	void updateMoney();
	SDL_Renderer* renderer;
	TTF_Font* font;
	int money;
	std::string moneyText;
	SDL_Color moneyColor = { 255, 255 ,255, 255 };
	SDL_Texture* moneyTexture;
	SDL_FRect destMoney;
};

