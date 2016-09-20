#include "sfwdraw.h"
#include "score.h"
#include <iostream>
using namespace sfw;

void drawScore(unsigned font, int score1, int score2)
{
	char buffer[80] = {0};
	sprintf_s(buffer, "%d", score2);
	drawString(font, buffer, 700, 500, 20, 20);

	sprintf_s(buffer, "%d", score1);
	drawString(font, buffer, 100, 500, 20, 20);
}

void win(unsigned font)
{
	drawString(font, "Game Over Player 1 wins", 200, 500, 20, 20);
	drawString(font, "Press E to exit", 200, 300, 20, 20);
}

void win2(unsigned font)
{
	drawString(font, "Game Over Player 2 wins", 200, 500, 20, 20);
	drawString(font, "Press E to exit", 200, 200, 20, 20);
}