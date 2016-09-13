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
	
	GameState gs;

	gs.create(loadTextureMap("./res/tonc_font.png", 16, 6),
			  loadTextureMap("./res/fontmap.png", 16, 16));

	while (stepContext())
	{	
		gs.update();
		gs.draw();
	}

	termContext();
}