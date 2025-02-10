#include "Player.h"
#include <SDL3_image/SDL_image.h>
#include<stdio.h>

void Player::draw() {
	SDL_RenderTextureRotated(renderer, texture, &src, &dest, 0, NULL, flip);
}
void Player::showAnimation(animation animation, int now, int delay) {
	if (delay >= animation.animationDelay) {
		lastUpdate = now;
		currentIndex = (currentIndex + 1) % animation.frames;

		src.x = currentIndex * sizeSprite;
		src.y = sizeSprite * animation.y;
	}
}
void Player::update() {
	const bool* keys = SDL_GetKeyboardState(NULL);
	isWalk = false;
	if (keys[SDL_SCANCODE_W]) {
		dest.y -= speed;
		isWalk = true;
	}
	if (keys[SDL_SCANCODE_S]) {
		dest.y += speed;
		isWalk = true;
	}
	if (keys[SDL_SCANCODE_A]) {
		dest.x -= speed;
		flip = SDL_FLIP_HORIZONTAL;
		isWalk = true;
	}
	if (keys[SDL_SCANCODE_D]) {
		dest.x += speed;
		isWalk = true;
		flip = SDL_FLIP_NONE;
	}
	Uint64 now = SDL_GetTicks();
	int delay = now - lastUpdate;
	if (isWalk) {
		showAnimation(animations.walk, now, delay);
	}
	else {
		showAnimation(animations.idle, now, delay);
	}



}
void Player::handleEvents() {

}

void Player::initAnimations() {
	animations.idle = { 6, 100, 0 };
	animations.walk = {6, 100, 1};
}

Player::Player(SDL_Renderer* renderer, std::string texturePath) : renderer(renderer)
{
	initAnimations();

	sizeSprite = 192;
	texture = IMG_LoadTexture(renderer, texturePath.c_str());
	dest = { 0, 0, sizeSprite, sizeSprite };
	src = { 0, 0, sizeSprite, sizeSprite };
	speed = 4;
}

Player::~Player()
{
	SDL_DestroyTexture(texture);
}

