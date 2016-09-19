#include "sfwdraw.h"
#include "paddle.h"
#include "Ball.h"
#include "score.h"
#include "GameState.h"
#include "constdecl.h"
#include "Splash.h"
#include "Depart.h"
#include "Option.h"
using namespace sfw;	

void main()
{
	initContext(800,600,"NSFW");
	
	unsigned font = loadTextureMap("./res/fontmap.png", 16, 16);
	GameState gs;
	Splash splash;
	Depart depart;
	Option option;
	splash.init(font);
	depart.init(font);
	option.init(font);
	APP_STATE state = ENTER_SPLASH;

	while (stepContext())
	{	
		switch (state)
		{
		case ENTER_SPLASH:
			splash.play();
		case SPLASH:
			splash.step();
			splash.draw();
			state = splash.next();
			break;
		case ENTER_DEPART:
			depart.play();
		case DEPART:
			depart.step();
			depart.draw();
			state = depart.next();
			break;

		case ENTER_OPTION:
			option.play();
		case OPTION:
			option.step();
			option.draw();
			state = option.next();
			break;

		case ENTER_GAMESTATE:
			gs.create(loadTextureMap("./res/tonc_font.png", 16, 6),loadTextureMap("./res/fontmap.png", 16, 16), loadTextureMap("./res/bkgrnd.jpg"));
		case GAMESTATE:
			gs.draw();
			gs.update();
			state = gs.next();
			break;
		}

		
	}

	termContext();
}