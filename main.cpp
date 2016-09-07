
#include "sfwdraw.h"

using namespace sfw;

struct Paddle
{
	float x, y = 100;
	char up, down;
	unsigned int color;
	float speed;
	float size;
};

struct WallTop
{
	float x1 = 0;
	float y1= 600;
	float x2 = 800;
	float y2 = 600;
};
	
struct Ball
{
	float xpos, ypos;
	float xvel, yvel;
	float radius;
	unsigned int color;
};

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

Paddle createpaddle(float x, char up, char down,unsigned int color, float speed, float size)
{
	Paddle retval;
	retval.x = x;
	retval.up = up;
	retval.down = down;
	retval.color = color;
	retval.speed = speed;
	retval.size = size;
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
	drawLine(p.x,p.size + p.y, p.x, p.y, MAGENTA);
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
		// then flip the xvelocity reset the ball's xposition to the paddle's xposition.



		if (b.xpos < 0 || b.xpos > 800)
		{
			b.xpos = 300;
		}
}


void main()
{
	initContext(800,600,"NSFW");

	unsigned f = loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = loadTextureMap("./res/fontmap.png",16,16);
	unsigned r = loadTextureMap("./res/background.jpg");
	
	Paddle p1 = createpaddle(100, 'W', 'S', MAGENTA, 10, 100);
	Paddle p2 = createpaddle(700, 'I', 'K', MAGENTA, 10, 100);
	Ball b1 = createBall(400, 300, 20, BLACK, 5, 5);
	setBackgroundColor(WHITE);
	
	WallTop wall;

	while (stepContext())
	{	
		drawString(f, "fucking bullshit", 0, 600, 48, 48, 0, ' ');
		
		
		updatePaddle(p1);
		drawPaddle(p1);
		updatePaddle(p2);
		drawPaddle(p2);
		drawBall(b1);

		updateBall(b1, p1, p2);
		
	}

	termContext();
}