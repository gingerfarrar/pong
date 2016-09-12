#include "sfwdraw.h"
#include "paddle.h"
#include "Ball.h"
#include "score.h"
#include "GameState.h"
using namespace sfw;	

void main()
{
	initContext(800,600,"NSFW");
	setBackgroundColor(PINK);
	
	GameState gs = createGameState();

	while (stepContext())
	{	
		updateGameState(gs);
		drawGameState(gs);
	}

	termContext();
}