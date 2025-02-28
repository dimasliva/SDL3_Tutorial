#include "PlayerHealthUI.h"

PlayerHealthUI::PlayerHealthUI(SDL_Renderer* renderer, TTF_Font* font, int currentHealth, int totalHealth) 
	: renderer(renderer), font(font), health(currentHealth), totalHealth(totalHealth)
{
	destBorderHealthRect = { 10, 10, 300, 50 };
	destCurrentHealthRect = { 12, 12, 297, 47 };
	destTotalHealthRect = { 12, 12, 297, 47 };

	float healhPercent = static_cast<float>(health) / totalHealth;
	destCurrentHealthRect.w = static_cast<int> (destCurrentHealthRect.w * healhPercent);
	updateText();
}

PlayerHealthUI::~PlayerHealthUI()
{
}

void PlayerHealthUI::update()
{

}

void PlayerHealthUI::draw()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &destBorderHealthRect);

	SDL_SetRenderDrawColor(renderer, 35, 35, 35, 255);
	SDL_RenderFillRect(renderer, &destTotalHealthRect);

	SDL_SetRenderDrawColor(renderer, 235, 0, 0, 255);
	SDL_RenderFillRect(renderer, &destCurrentHealthRect);

	SDL_RenderTexture(renderer, texture, NULL, &destText);
}
void PlayerHealthUI::updateText()
{
	text = std::to_string(health) + "/" + std::to_string(totalHealth);
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), strlen(text.c_str()), color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_GetTextureSize(texture, &destText.w, &destText.h);

	destText.x = destBorderHealthRect.x + (destBorderHealthRect.w - destText.w) / 2;
	destText.y = destBorderHealthRect.y + (destBorderHealthRect.h - destText.h) / 2;

	SDL_DestroySurface(surface);
}
