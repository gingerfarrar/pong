#pragma once

class Paddle
{
public:
	float x, y = 100;
	char up, down;
	unsigned int color;
	float speed;
	float size;
	int score = 0;

	void createpaddle(float x, char up, char down, unsigned int color, float speed, float size, int score);

	void updatePaddle();

	void drawPaddle();
};

