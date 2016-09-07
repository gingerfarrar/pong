#pragma once
#include "paddle.h"

struct Ball
{
	float xpos, ypos;
	float xvel, yvel;
	float radius;
	unsigned int color;
};

Ball createBall(float xpos, float ypos, float radius, unsigned int color, float xvel, float yvel);

void drawBall(const Ball &b);

void updateBall(Ball &b, Paddle &p1, Paddle &p2);