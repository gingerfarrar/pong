#pragma once
#include "sfwdraw.h"
#include "paddle.h"
#include "Ball.h"
#include "score.h"
using namespace sfw;

struct GameState
{
	unsigned f = loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d = loadTextureMap("./res/fontmap.png", 16, 16);
	Paddle p1 = createpaddle(100, 'W', 'S', BLACK, 10, 100, 0);
	Paddle p2 = createpaddle(700, 'I', 'K', BLACK, 10, 100, 0);
	Ball b1 = createBall(400, 300, 20, BLACK, 5, 5);
	bool gameover = false;
};

GameState createGameState(unsigned f, unsigned d, bool gameover, Paddle p1, Paddle p2, Ball b1);

void updateGameState(GameState gs);

void drawGameState(GameState &gs);