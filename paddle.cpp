#include "paddle.h"
#include "sfwdraw.h"
using namespace sfw;

Paddle createpaddle(float x, char up, char down, unsigned int color, float speed, float size, int score)
{
	Paddle retval;
	retval.x = x;
	retval.up = up;
	retval.down = down;
	retval.color = color;
	retval.speed = speed;
	retval.size = size;
	retval.score = score;
	return retval;
}

void updatePaddle(Paddle &p)
{
	if (getKey(p.up) && p.y < 450)
	{
		p.y += p.speed;
	}

	if (getKey(p.down) && p.y > 0)
	{
		p.y -= p.speed;
	}
}

void drawPaddle(const Paddle &p)
{
	drawLine(p.x, p.size + p.y, p.x, p.y, BLACK);
}