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
