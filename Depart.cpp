#include "Depart.h"
#include "sfwdraw.h"
#include <iostream>
using namespace sfw;

void Depart::init(int a_font)
{
	font = a_font;
}

void Depart::play() { timer = 3.f; }

void Depart::draw()
{
	char buffer[64];
	sprintf_s(buffer, "Splash Time: %f", timer);
	drawString(font, "Press P to play", 100, 100, 20, 20);
}

void Depart::step() { timer -= getDeltaTime(); }

APP_STATE Depart::next()
{
	if (getKey('O'))
	{
		return ENTER_OPTION;
	}
	if (getKey('P'))
	{
		return ENTER_GAMESTATE;
	}
	return DEPART;
}