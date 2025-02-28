#pragma once
#include<SDL3/SDL.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<string>

class PlayerHealthUI
{
public:
	PlayerHealthUI(SDL_Renderer* renderer, TTF_Font* font, int currentHealth, int totalHealth);
	~PlayerHealthUI();

	void setHealth(int newHealth) { health = newHealth; };
	void update();
	void draw();

private:
	void updateText();
	SDL_Renderer* renderer;
	TTF_Font* font;
	int health;
	int totalHealth;
	SDL_FRect destCurrentHealthRect;
	SDL_FRect destTotalHealthRect;
	SDL_FRect destBorderHealthRect;
	std::string text;
	SDL_Color color = { 255, 255 ,255, 255 };
	SDL_Texture* texture;
	SDL_FRect destText;
};
