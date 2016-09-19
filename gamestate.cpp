#include "sfwdraw.h"
#include "GameState.h"
#include "paddle.h"
#include "Ball.h"
#include "score.h"

void GameState::create(unsigned a_f, unsigned a_d, unsigned a_g)
{
	f = a_f;
	d = a_d;
	g = a_g;
	gameover = false;

	p1.createpaddle(100, 'W', 'S', BLACK, 10, 100, 0);

	p2.createpaddle(700, 'I', 'K', BLACK, 10, 100, 0);

	b1.createBall(400, 300, 20, BLACK, 5, 5);
}

void GameState::update()
{
	if (!gameover)
	{
		p1.updatePaddle();
		p1.drawPaddle();
		p2.updatePaddle();
		p2.drawPaddle();		
		b1.drawBall();
		b1.updateBall(p1,p2);
	}
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

void GameState::draw()
{
	drawTexture(g, 0, 600, 800, 600, 0, false);
	drawString(f, "fucking bullshit", 0, 600, 48, 48, 0, ' ');	
	drawScore(d, p1.score, p2.score);
}

APP_STATE GameState::next()
{
	if (getKey('V'))
	{
		return ENTER_OPTION;
	}
	if (getKey('E'))
	{
		return ENTER_DEPART;
	}
	return GAMESTATE;
}