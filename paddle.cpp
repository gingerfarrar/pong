#include "paddle.h"
#include "sfwdraw.h"
using namespace sfw;

void Paddle::createpaddle(float a_x, char a_up, char a_down,
			unsigned int a_color, float a_speed, float a_size, int a_score)
{
	
	x = a_x;
	up = a_up;
	down = a_down;
	color = a_color;
	speed = a_speed;
	size = a_size;
	score = a_score;
}

void Paddle::updatePaddle()
{
	if (getKey(up) && y < 450)
	{
		y += speed;
	}

	if (getKey(down) && y > 0)
	{
		y -= speed;
	}
}

void Paddle::drawPaddle()
{
	drawLine(x, y, x, y + size, BLACK);
}