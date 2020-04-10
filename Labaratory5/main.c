#include"Box.h"
#include"Snake.h"
#include"Random.h"
#include"GameRule.h"
int main() {
	Box SnakeBox = MakeSnakeBox(15, 15);
	PrintSnakeBox(SnakeBox);
	Snake Snake1 = MakeSnake();
	SnakeBox = SnakeInBox(SnakeBox,Snake1);
	PrintSnakeBox(SnakeBox);
	Point NewApple = MakeApplePen(Snake1, SnakeBox);
	SnakeBox = MakeApplePenInBox(SnakeBox, Snake1, NewApple);
	PrintSnakeBox(SnakeBox);
	return 0;
}