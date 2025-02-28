#pragma once
#include<SDL3/SDL.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<string>

class PlayerMoneyUI
{
public:
	PlayerMoneyUI(SDL_Renderer* renderer, TTF_Font* font);
	~PlayerMoneyUI();

	void setMoney(int newMoney) { money = newMoney; };
	void update();
	void draw();

private:
	void updateText();
	SDL_Renderer* renderer;
	TTF_Font* font;
	int money;
	std::string text;
	SDL_Color color = { 255, 255 ,255, 255 };
	SDL_Texture* texture;
	SDL_FRect dest;
};
