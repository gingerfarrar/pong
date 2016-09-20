#include "Ball.h"
#include "sfwdraw.h"
using namespace sfw;
#include <iostream>
#include <cmath>

void Ball::createBall(float a_xpos, float a_ypos, float a_radius, unsigned int a_color, float a_xvel, float a_yvel)
{
	xpos = a_xpos;
	ypos = a_ypos;
	radius = a_radius;
	color = a_color;
	xvel = a_xvel;
	yvel = a_yvel;
}


void Ball::drawBall()
{
	drawCircle(xpos, ypos, radius, 12, BLACK);
}

void Ball::updateBall(Paddle &p1, Paddle &p2)
{
	xpos += xvel;
	ypos += yvel;

	ypos += cos(xpos/10)*10; 

	if (ypos > 600 - radius)
	{
		ypos = 600 - radius;
		yvel *= -2;
	}
	if (ypos < 0 + radius)
	{
		ypos = 0 + radius;
		yvel *= -2;
	}

	if ((xpos < p1.x) && ypos > p1.y && ypos < (p1.y + p1.size))
	{
		xvel *= -2;
		xpos = p1.x + radius;
	}
	if ((xpos > p2.x) && ypos > p2.y && ypos < (p2.y + p2.size))
	{
		xvel *= -2;
		xpos = p2.x - radius;
	}

	if (xpos < 0)
	{
		p2.score++;
		printf("%d %d", p1.score, p2.score);
		xpos = 300;
	}
	if (xpos > 800)
	{
		p1.score++;
		printf("%d %d", p1.score, p2.score);
		xpos = 300;
	}
}
