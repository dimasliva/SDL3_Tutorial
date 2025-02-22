#include "Player.h"
#include <SDL3_image/SDL_image.h>

Player::Player(SDL_Renderer* renderer, std::string texturePath, TTF_Font* font) :
	renderer(renderer), font(font)
{
	initAnimations();
	lookAt.right = true;
	sizeSprite = 192;
	texture = IMG_LoadTexture(renderer, texturePath.c_str());
	dest = { 0, 0, sizeSprite, sizeSprite };
	src = { 0, 0, sizeSprite, sizeSprite };
	speed = 4;
	playerHUD = new PlayerHUD(renderer, font);
}

Player::~Player()
{
	SDL_DestroyTexture(texture);
}


void Player::draw() {
	SDL_RenderTextureRotated(renderer, texture, &src, &dest, 0, NULL, flip);
	playerHUD->draw();
}

void Player::addMoney(int addedMoney)
{
	money += addedMoney;
	playerHUD->setMoney(money);
}

void Player::update() {
	const bool* keys = SDL_GetKeyboardState(NULL);
	isWalk = false;
	defineLook(keys);

	if (isAttack) {
		attackHandler();
	}
	else {
		moveHandler(keys);
	}

	playerHUD->update();
}
void Player::handleEvents(SDL_Event* event) {
	switch (event->type)
	{
	case SDL_EVENT_MOUSE_BUTTON_DOWN:
		switch (event->button.button)
		{
		case SDL_BUTTON_LEFT:
			isAttack = true;
			animationHandler.setCurrentIndex(0);
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

void Player::defineLook(const bool* keys)
{
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
}

void Player::attackHandler()
{
	if (lookAt.top) {
		animationHandler.showAnimation(animations.attack_top, src, sizeSprite);
	}
	if (lookAt.down) {
		animationHandler.showAnimation(animations.attack_down, src, sizeSprite);
	}
	if (lookAt.left) {
		flip = SDL_FLIP_HORIZONTAL;
		animationHandler.showAnimation(animations.attack_horizontal, src, sizeSprite);
	}
	if (lookAt.right) {
		flip = SDL_FLIP_NONE;
		animationHandler.showAnimation(animations.attack_horizontal, src, sizeSprite);
	}
}

void Player::moveHandler(const bool* keys)
{
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
		animationHandler.showAnimation(animations.walk, src, sizeSprite);
	}
	else {
		animationHandler.showAnimation(animations.idle, src, sizeSprite);
	}
}
