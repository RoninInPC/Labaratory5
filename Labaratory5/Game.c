#include"Box.h"
#include"GameRule.h"
#include"Random.h"
#include"Snake.h"
void AdvancedBrainSnake(int NumberOfString, int NumberOfColumn, int Time) {
	Box SnakeBox = MakeSnakeBox(NumberOfString, NumberOfColumn);
	PrintSnakeBox(SnakeBox, Time);
	SnakeBox = SnakeInBox(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
	Point NewApple;
	while (1) {
		NewApple = MakeRandomNotSnakePoint(SnakeBox);
		SnakeBox = MakeApplePenInBox(SnakeBox, NewApple);
		PrintSnakeBox(SnakeBox, Time);
		int t = BrainMoveInBox(&SnakeBox, NewApple, Time);
		if (t == 0) break;
	}
	SnakeBox = GameOver(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
}