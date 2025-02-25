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

typedef struct
{
	animationProperties spawn;
} SpawnAnimationData;

typedef struct
{
	animationProperties idle;
	animationProperties walk;
	animationProperties attack_horizontal;
	animationProperties attack_top;
	animationProperties attack_down;
} PlayerAnimationData;