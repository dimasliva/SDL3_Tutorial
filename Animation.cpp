#include "Animation.h"
Animation::Animation()
{
}
Animation::~Animation()
{
}

void Animation::showAnimation(animationProperties animation, SDL_FRect& src, int sizeSprite)
{
	Uint64 now = SDL_GetTicks();
	int delay = now - lastUpdate;
	if (delay >= animation.animationDelay) {
		lastUpdate = now;
		currentIndex = (currentIndex + 1) % animation.frames;

		src.x = currentIndex * sizeSprite;
		src.y = sizeSprite * animation.y;
	}
}

bool Animation::reverseShowAnimation(animationProperties animation, SDL_FRect& src, int sizeSprite)
{
	Uint64 now = SDL_GetTicks();
	int delay = now - lastUpdate;
	if (currentReverseIndex == -2) {
		currentReverseIndex = animation.frames;
	}
	if (delay >= animation.animationDelay) {
		lastUpdate = now;
		currentReverseIndex--;
		if (currentReverseIndex < 0) {
			currentReverseIndex = -1;
			return true;
		}
		src.x = currentReverseIndex * sizeSprite;
		SDL_Log("src.x: %.2f\n", src.x);
		SDL_Log("src.y: %.2f\n", src.y);
		src.y = sizeSprite * animation.y;
	}
	return false;
}