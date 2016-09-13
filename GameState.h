#pragma once
#include "sfwdraw.h"
#include "paddle.h"
#include "Ball.h"
#include "score.h"
using namespace sfw;

class GameState
{
private:

	unsigned f;// = loadTextureMap("./res/tonc_font.png", 16, 6);
	unsigned d;// = loadTextureMap("./res/fontmap.png", 16, 16);
	Paddle p1;// = createpaddle(100, 'W', 'S', BLACK, 10, 100, 0);
	Paddle p2;// = createpaddle(700, 'I', 'K', BLACK, 10, 100, 0);
	Ball b1;// = Ball::createBall(400, 300, 20, BLACK, 5, 5);
	bool gameover;// = false;

public:
	// Initialize values in the class.
	void create(unsigned f, unsigned d);
	void update();
	void draw();
};
