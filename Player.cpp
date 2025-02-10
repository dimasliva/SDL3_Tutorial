#include "Player.h"
#include <SDL3_image/SDL_image.h>

void Player::draw() {
	SDL_RenderTexture(renderer, texture, &src, &dest);
}
void Player::update() {
	const bool* keys = SDL_GetKeyboardState(NULL);

	if (keys[SDL_SCANCODE_W]) {
		dest.y -= speed;
	}
	if (keys[SDL_SCANCODE_S]) {
		dest.y += speed;
	}
	if (keys[SDL_SCANCODE_A]) {
		dest.x -= speed;
	}
	if (keys[SDL_SCANCODE_D]) {
		dest.x += speed;
	}
}
void Player::handleEvents() {

}

Player::Player(SDL_Renderer* renderer) : renderer(renderer)
{
	texture = IMG_LoadTexture(renderer, "assets/Prototype_Character/Prototype_Character.png");
	dest = { 0, 0, 32 * 4, 32 * 4 };
	src = { 0, 0, 32, 32 };
	speed = 10;
}

Player::~Player()
{
	SDL_DestroyTexture(texture);
}

