#include"Snake.h"
#ifndef H_BOX
#define H_BOX
typedef struct box {
	int** Arr;
	int NumberString;
	int NumberColumn;
	Snake snake;
} Box;
Box MakeSnakeBox(int NumberString, int NumberColumn);
void PrintSnakeBox(Box SnakeBox);
Box SnakeInBox(Box SnakeBox);
Box MoveSnakeInBox(Box SnakeBox, Point New);
Box GroveSnakeInBox(Box SnakeBox, Point New);
Box MakeApplePenInBox(Box SnakeBox, Point New);
Box GameOver(Box SnakeBox);
#endif