#include"Snake.h"
#ifndef H_BOX
#define H_BOX
typedef struct box {
	int** Arr;
	int NumberString;
	int NumberColumn;
} Box;
Box MakeSnakeBox(int NumberString, int NumberColumn);
void PrintSnakeBox(Box SnakeBox);
Box SnakeInBox(Box SnakeBox, Snake snake);
Box MoveSnakeInBox(Box SnakeBox, Snake* snake, Point New);
Box GroveSnakeInBox(Box SnakeBox, Snake* snake, Point New);
Box MakeApplePenInBox(Box SnakeBox, Snake snake, Point New);
#endif