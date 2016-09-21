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
	drawString(font, "LUCKY SEVEN!", 200, 300, 40, 40);
	drawString(font, "Press E to exit", 250, 150, 20, 20);
	drawString(font, "OR Press V for next level", 200, 100, 20, 20);
}

void win2(unsigned font)
{
	drawString(font, "Game Over Player 2 wins", 200, 500, 20, 20);
	drawString(font, "LUCKY SEVEN!", 200, 300, 40, 40);
	drawString(font, "Press E to exit", 250, 150, 20, 20);
	drawString(font, "OR Press V for next level", 200, 100, 20, 20);
}

void win3(unsigned font)
{
	drawString(font, "Game Over Player 1 wins", 200, 500, 20, 20);
	drawString(font, "LUCKY SEVEN!", 200, 300, 40, 40);
	drawString(font, "Press E to exit", 250, 100, 20, 20);
}

void win4(unsigned font)
{
	drawString(font, "Game Over Player 2 wins", 200, 500, 20, 20);
	drawString(font, "LUCKY SEVEN!", 200, 300, 40, 40);
	drawString(font, "Press E to exit", 250, 100, 20, 20);
}
