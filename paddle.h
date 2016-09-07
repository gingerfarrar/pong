#pragma once

struct Paddle
{
	float x, y = 100;
	char up, down;
	unsigned int color;
	float speed;
	float size;
	int score = 0;
};

Paddle createpaddle(float x, char up, char down, unsigned int color, float speed, float size, int score);

void updatePaddle(Paddle &p);

void drawPaddle(const Paddle &p);