#include<SDL3/SDL.h>
#include<string>
#include"Animation.h"
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
	Player(SDL_Renderer* renderer, std::string texturePath);
	~Player();
	void handleEvents(SDL_Event* event);
	void update();
	void draw();

private:
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
	SDL_FlipMode flip;
	lookAt lookAt;
};
