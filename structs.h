#pragma once
typedef struct
{
	bool top;
	bool down;
	bool left;
	bool right;
} lookAt;

typedef struct
{
	int frames;
	int animationDelay;
	int y;
} animationProperties;