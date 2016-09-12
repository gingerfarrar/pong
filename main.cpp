#include "sfwdraw.h"
#include "paddle.h"
#include "Ball.h"
#include "score.h"
#include "GameState.h"
using namespace sfw;	

void main()
{
	initContext(800,600,"NSFW");

	unsigned f = loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);
	unsigned r = loadTextureMap("./res/background.jpg");
	
	Paddle p1 = createpaddle(100, 'W', 'S', BLACK, 10, 100,0);
	Paddle p2 = createpaddle(700, 'I', 'K', BLACK, 10, 100,0);
	Ball b1 = createBall(400, 300, 20, BLACK, 5, 5);
	setBackgroundColor(PINK);
	bool gameover = false;
	while (stepContext())
	{	
		drawString(f, "fucking bullshit", 0, 600, 48, 48, 0, ' ');		

		if (!gameover)
		{
			updatePaddle(p1);
			drawPaddle(p1);
			updatePaddle(p2);
			drawPaddle(p2);
			drawBall(b1);
			updateBall(b1, p1, p2);
		}
		drawScore(d, p1.score, p2.score);
		if (p1.score >= 5)
		{
			gameover = true;
			win(d);
		}
		if (p2.score >= 5)
		{
			gameover = true;
			win2(d);
		}
	}

	termContext();
}