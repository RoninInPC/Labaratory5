#include"Box.h"
#include"Snake.h"
#ifndef H_GAMERULE
#define H_GAMERULE
int BrainMoveInBox(Box* box, Point New, int Time);
void StupidMoveInBox(Box* box, Point New, int Time);
#endif