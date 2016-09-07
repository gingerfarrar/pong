#include "Ball.h"
#include "sfwdraw.h"
using namespace sfw;
#include <iostream>

Ball createBall(float xpos, float ypos, float radius, unsigned int color, float xvel, float yvel)
{
	Ball retval;
	retval.xpos = xpos;
	retval.ypos = ypos;
	retval.radius = radius;
	retval.color = color;
	retval.xvel = xvel;
	retval.yvel = yvel;
	return retval;
}


void drawBall(const Ball &b)
{
	drawCircle(b.xpos, b.ypos, b.radius, 12, BLACK);
}

void updateBall(Ball &b, Paddle &p1, Paddle &p2)
{
	b.xpos += b.xvel;
	b.ypos += b.yvel;

	if (b.ypos > 600 - b.radius)
	{
		b.ypos = 600 - b.radius;
		b.yvel *= -1;
	}
	if (b.ypos < 0 + b.radius)
	{
		b.ypos = 0 + b.radius;
		b.yvel *= -1;
	}

	if ((b.xpos < p1.x) && b.ypos > p1.y && b.ypos < (p1.y + p1.size))
	{
		b.xvel *= -1;
		b.xpos = p1.x + b.radius;
	}
	if ((b.xpos > p2.x) && b.ypos > p2.y && b.ypos < (p2.y + p2.size))
	{
		b.xvel *= -1;
		b.xpos = p2.x - b.radius;
	}

	if (b.xpos < 0)
	{
		p2.score++;
		printf("%d %d", p1.score, p2.score);
		b.xpos = 300;
	}
	if (b.xpos > 800)
	{
		p1.score++;
		printf("%d %d", p1.score, p2.score);
		b.xpos = 300;
	}
}
