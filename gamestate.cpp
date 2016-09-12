#include "sfwdraw.h"
#include "GameState.h"
#include "paddle.h"
GameState createGameState(unsigned f, unsigned d, bool gameover, Paddle p1, Paddle p2, Ball b1)
{
	GameState retval;
	retval.f = f;
	retval.gameover = gameover;
	retval.p1 = p1;
	retval.p2 = p2;
	retval.b1 = b1;
	
	

	return retval;
}

void updateGameState(GameState gs)
{
	if (!gs.gameover)
	{
		updatePaddle(gs.p1);
		drawPaddle(gs.p1);
		updatePaddle(gs.p2);
		drawPaddle(gs.p2);
		drawBall(gs.b1);
		updateBall(gs.b1, gs.p1, gs.p2);
	}
	if (gs.p1.score >= 5)
	{
		gs.gameover = true;
		win(gs.d);
	}
	if (gs.p2.score >= 5)
	{
		gs.gameover = true;
		win2(d);
	}

}

void drawGameState(GameState &gs)
{
	drawString(gs.f, "fucking bullshit", 0, 600, 48, 48, 0, ' ');
	drawScore(gs.d, gs.p1.score, gs.p2.score);
}