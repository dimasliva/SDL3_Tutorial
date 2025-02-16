#pragma once
#include"structs.h"
#include<SDL3/SDL.h>
class Animation
{
public:
	Animation();
	~Animation();
	void showAnimation(animationProperties animation, SDL_FRect& src, int sizeSprite);
	void setCurrentIndex(int index) { currentIndex = index; };
private:
	int currentIndex;
	Uint64 lastUpdate;
};

