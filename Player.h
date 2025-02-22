#include<SDL3/SDL.h>
#include<SDL3_ttf/SDL_ttf.h>
#include<string>
#include"Animation.h"
#include"PlayerHUD.h"
#include"structs.h"
#pragma once

typedef struct
{
	animationProperties idle;
	animationProperties walk;
	animationProperties attack_horizontal;
	animationProperties attack_top;
	animationProperties attack_down;
} animationData;

class Player
{
public:
	Player(SDL_Renderer* renderer, std::string texturePath, TTF_Font* font);
	~Player();
	void handleEvents(SDL_Event* event);
	void update();
	void draw();
	SDL_FRect getDest() { return dest; };
	void addMoney(int addedMoney);

private:
	void defineLook(const bool* keys);
	void attackHandler();
	void moveHandler(const bool* keys);
	int money;
	Animation animationHandler;
	void initAnimations();
	SDL_Renderer* renderer;
	SDL_FRect src;
	SDL_FRect dest;
	SDL_Texture* texture;
	int speed;
	animationData animations;
	float sizeSprite;
	bool isWalk;
	bool isAttack;

	TTF_Font* font;
	SDL_FlipMode flip;
	lookAt lookAt;
	PlayerHUD* playerHUD;
};
