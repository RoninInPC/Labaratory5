#include"Box.h"
#include"GameRule.h"
#include"Random.h"
#include"Snake.h"
#include<Windows.h>
#include<stdio.h>
#include <conio.h>
void AdvancedBrainSnake(int NumberOfString, int NumberOfColumn, int Time) {
	Box SnakeBox = MakeSnakeBox(NumberOfString, NumberOfColumn);
	PrintSnakeBox(SnakeBox, Time);
	SnakeBox = SnakeInBox(SnakeBox);
	SnakeBox = MakeBarrierInBox(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
	Point NewApple;
	while (1) {
		NewApple = MakeRandomNotSnakePoint(SnakeBox, 1);
		SnakeBox = MakeApplePenInBox(SnakeBox, NewApple);
		PrintSnakeBox(SnakeBox, Time);
		int t = BrainMoveInBox(&SnakeBox, NewApple, Time);
		if (t == 0) break;
	}
	SnakeBox = GameOver(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
}
void StupidBrainSnake(int NumberOfString, int NumberOfColumn, int Time) {
	printf("Write Number of ApplePen\n");
	int CountOfApplePen;
	scanf_s("%d", &CountOfApplePen);
	system("cls");
	Box SnakeBox = MakeSnakeBox(NumberOfString, NumberOfColumn);
	PrintSnakeBox(SnakeBox, Time);
	SnakeBox = SnakeInBox(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
	Point NewApple;
	int CountOfApple = 0;
	while (1) {
		NewApple = MakeRandomNotSnakePoint(SnakeBox, 1);
		SnakeBox = MakeApplePenInBox(SnakeBox, NewApple);
		PrintSnakeBox(SnakeBox, Time);
		StupidMoveInBox(&SnakeBox, NewApple, Time);
		CountOfApple++;
		if (CountOfApple == CountOfApplePen) {
			break;
		}
	}
	SnakeBox = GameOver2(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
}
void UserPlaySnake(int NumberOfString, int NumberOfColumn, int Time) {
	Box SnakeBox = MakeSnakeBox(NumberOfString, NumberOfColumn);
	PrintSnakeBox(SnakeBox, Time);
	SnakeBox = SnakeInBox(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
	Time *= 3;
	Point NewApple;
	int MoveIndex = 0;
	while (1) {
		NewApple = MakeRandomNotSnakePoint(SnakeBox, 1);
		SnakeBox = MakeApplePenInBox(SnakeBox, NewApple);
		PrintSnakeBox(SnakeBox, Time);
		MoveIndex = KeyMove(&SnakeBox, NewApple, Time, MoveIndex);
		if (MoveIndex == -1)break;
	}
	SnakeBox = GameOver3(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
}
void AdvancedBrainSnakeAndBarrier(int NumberOfString, int NumberOfColumn, int Time) {
	printf("Write number, number 1 - barriers generated every generated Apple, 2 - static one Barrier\n");
	int BarriersNum;
	scanf_s("%d", &BarriersNum);
	if (BarriersNum < 1 && BarriersNum > 3) {
		printf("YOU LIE\n");
		return 0;
	}
	system("cls");
	Box SnakeBox = MakeSnakeBox(NumberOfString, NumberOfColumn);
	PrintSnakeBox(SnakeBox, Time);
	SnakeBox = SnakeInBox(SnakeBox);
	if (BarriersNum == 2)	SnakeBox = MakeBarrierInBox(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
	Point NewApple;
	while (1) {
		NewApple = MakeRandomNotSnakePoint(SnakeBox, 1);
		SnakeBox = MakeApplePenInBox(SnakeBox, NewApple);
		if (BarriersNum == 1)	SnakeBox = MakeBarrierInBox(SnakeBox);
		PrintSnakeBox(SnakeBox, Time);
		int t = BrainMoveInBox(&SnakeBox, NewApple, Time);
		if (t == 0) break;
		if (BarriersNum == 1) SnakeBox = DeleteBarrierInBox(SnakeBox);
	}
	SnakeBox = GameOver(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
}