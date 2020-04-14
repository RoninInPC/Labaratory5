#include"Box.h"
#ifndef H_TWOSNAKEBOX
#define H_TWOSNAKEBOX
Box MakeTwoSnakeBox(int NumberString, int NumberColumn);
Box SecondSnakeInBox(Box SnakeBox);
Box MoveSecondSnakeInBox(Box SnakeBox, Point New);
Box GroveSecondSnakeInBox(Box SnakeBox, Point New);
Box GameOverFirstSnake(Box SnakeBox);
Box GameOverSecondSnake(Box SnakeBox);
#endif