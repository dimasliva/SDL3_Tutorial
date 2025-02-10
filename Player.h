#include<SDL3/SDL.h>
#include<string>
#pragma once


typedef struct
{
	int frames;
	int animationDelay;
	int y;
} animation;

typedef struct
{
	bool top;
	bool down;
	bool left;
	bool right;
} lookAt;

typedef struct
{
	animation idle;
	animation walk;
	animation attack_horizontal;
	animation attack_top;
	animation attack_down;
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
	void initAnimations();
	void showAnimation(animation animation, int now, int delay);
	SDL_Renderer* renderer;
	SDL_FRect src;
	SDL_FRect dest;
	SDL_Texture* texture;
	int speed;
	animationData animations;
	int currentIndex;
	int lastUpdate;
	float sizeSprite;
	bool isWalk;
	bool isAttack;
	SDL_FlipMode flip;
	lookAt lookAt;
};
