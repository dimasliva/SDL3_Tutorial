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
	Uint64 now = SDL_GetTicks();
	int delay = now - lastUpdate;
	if (keys[SDL_SCANCODE_W]) {
		lookAt.top = true;
		lookAt.down = false;
		lookAt.left = false;
		lookAt.right = false;
	}
	if (keys[SDL_SCANCODE_S]) {
		lookAt.down = true;
		lookAt.top = false;
		lookAt.left = false;
		lookAt.right = false;
	}
	if (keys[SDL_SCANCODE_A]) {
		lookAt.left = true;
		lookAt.top = false;
		lookAt.down = false;
		lookAt.right = false;
	}
	if (keys[SDL_SCANCODE_D]) {
		lookAt.right = true;
		lookAt.top = false;
		lookAt.down = false;
		lookAt.left = false;
	}
	if (isAttack) {
		if (lookAt.top) {
			showAnimation(animations.attack_top, now, delay);
		}
		if (lookAt.down) {
			showAnimation(animations.attack_down, now, delay);
		}
		if (lookAt.left) {
			flip = SDL_FLIP_HORIZONTAL;
			showAnimation(animations.attack_horizontal, now, delay);
		}
		if (lookAt.right) {
			flip = SDL_FLIP_NONE;
			showAnimation(animations.attack_horizontal, now, delay);
		}

	}
	else {
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

		if (isWalk) {
			showAnimation(animations.walk, now, delay);
		}
		else {
			showAnimation(animations.idle, now, delay);
		}
	}




}
void Player::handleEvents(SDL_Event* event) {
	switch (event->type)
	{
	case SDL_EVENT_MOUSE_BUTTON_DOWN:
		switch (event->button.button)
		{
		case SDL_BUTTON_LEFT:
			isAttack = true;
			currentIndex = 0;
			break;
		default:
			break;
		}
		break;

	case SDL_EVENT_MOUSE_BUTTON_UP:
		switch (event->button.button)
		{
		case SDL_BUTTON_LEFT:
			isAttack = false;
			break;
		default:
			break;
		}
		break;

	default:
		break;
	}
}

void Player::initAnimations() {
	animations.idle = { 6, 100, 0 };
	animations.walk = { 6, 100, 1 };
	animations.attack_horizontal = { 6, 100, 2 };
	animations.attack_down = {6, 100, 4};
	animations.attack_top = { 6, 100, 6 };
}

Player::Player(SDL_Renderer* renderer, std::string texturePath) : renderer(renderer)
{
	initAnimations();
	lookAt.right = true;
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

