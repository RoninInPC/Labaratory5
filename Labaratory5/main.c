#include"Box.h"
#include"Snake.h"
#include"Random.h"
#include"GameRule.h"
#include<windows.h>
int main() {
	Box SnakeBox = MakeSnakeBox(20, 20);
	PrintSnakeBox(SnakeBox);
	Sleep(100);
	SnakeBox = SnakeInBox(SnakeBox);
	PrintSnakeBox(SnakeBox);
	Sleep(100);
	Point NewApple;
	while (1) {
		NewApple = MakeRandomNotSnakePoint(SnakeBox);
		SnakeBox = MakeApplePenInBox(SnakeBox, NewApple);
		PrintSnakeBox(SnakeBox);
		Sleep(100);
		int t = BrainMoveInBox(&SnakeBox, NewApple);
		if (t == 0) break;
	}
	return 0;
}