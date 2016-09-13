#pragma once
#include "paddle.h"

class Ball
{
	float xpos, ypos;
	float xvel, yvel;
	float radius;
	unsigned int color;

public:
	void createBall(float xpos, float ypos, float radius, unsigned int color, float xvel, float yvel);

	void drawBall();

	void updateBall(Paddle &p1, Paddle &p2);
};

