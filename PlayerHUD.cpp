#include "PlayerHUD.h"

PlayerHUD::PlayerHUD(SDL_Renderer* renderer, TTF_Font* font, int currentHelth, int totalHelth): renderer(renderer), font(font)
{
	playerMoneyUI = new PlayerMoneyUI(renderer, font);
	playerHealthUI = new PlayerHealthUI(renderer, font, currentHelth, totalHelth);
}

PlayerHUD::~PlayerHUD()
{
}

void PlayerHUD::setMoney(int newMoney)
{
	playerMoneyUI->setMoney(newMoney);

}

void PlayerHUD::update()
{
	playerMoneyUI->update();
	playerHealthUI->update();
}

void PlayerHUD::draw()
{
	playerMoneyUI->draw();
	playerHealthUI->draw();
}


