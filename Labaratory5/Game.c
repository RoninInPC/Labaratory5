#include"Box.h"
#include"GameRule.h"
#include"Random.h"
#include"Snake.h"
#include"TwoSnakeBox.h"
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
int GameLevelComplexity(int* Time, int* MoveIndex) {
	printf("Choose Level Of Complexity, print 1 2 or 3\n");
	int LC;
	scanf_s("%d", &LC);
	system("cls");
	if (LC < 1 || LC>3) {
		for (int i = 0; i < 100; i++) {
			if (i % 2 == 0) {
				printf("YOU LIE, I CHOOSE YOUR DESTINY!\n");
				printf("******\n");
				printf("*0**0*\n");
				printf("******\n");
				printf(" *##* \n");
				printf(" **** \n");
				printf("      \n");
			}
			else
			{
				printf("YOU LIE, I CHOOSE YOUR DESTINY!\n");
				printf("******\n");
				printf("*1**1*\n");
				printf("******\n");
				printf(" *##* \n");
				printf(" *##* \n");
				printf(" **** \n");
			}
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD position;
			position.X = 0;
			position.Y = 0;
			SetConsoleCursorPosition(hConsole, position);
			Sleep(50);
		}
		LC = 3;
		Sleep(*Time * 10);
		*Time /= 3;
		*MoveIndex = 3;
		system("cls");
	}
	if (LC > 0 && LC < 4) {
		*Time *= 10;
		*Time /= 15;
	}
	return LC;
}
void AdvancedBrainSnake(int NumberOfString, int NumberOfColumn, int Time) {
	Box SnakeBox = MakeSnakeBox(NumberOfString, NumberOfColumn);
	PrintSnakeBox(SnakeBox, Time);
	SnakeBox = SnakeInBox(SnakeBox);
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
	Time *= 2;
	int MoveIndex = 0;
	int HardIndex = GameLevelComplexity(&Time, &MoveIndex);
	Box SnakeBox = MakeSnakeBox(NumberOfString, NumberOfColumn);
	PrintSnakeBox(SnakeBox, Time);
	SnakeBox = SnakeInBox(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
	if(HardIndex == 2) SnakeBox = MakeBarrierInBox(SnakeBox);
	Point NewApple;
	while (1) {
		NewApple = MakeRandomNotSnakePoint(SnakeBox, 1);
		SnakeBox = MakeApplePenInBox(SnakeBox, NewApple);
		if (HardIndex == 3) SnakeBox = MakeBarrierInBox(SnakeBox);
		PrintSnakeBox(SnakeBox, Time);
		MoveIndex = KeyMove(&SnakeBox, NewApple, Time, MoveIndex);
		if (MoveIndex == -1)break;
		if (HardIndex == 3) SnakeBox = DeleteBarrierInBox(SnakeBox);
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
void TwoAdvancedBrainSnake(int NumberOfString, int NumberOfColumn, int Time) {
	Box SnakeBox = MakeTwoSnakeBox(NumberOfString, NumberOfColumn);
	PrintSnakeBox(SnakeBox, Time);
	SnakeBox = SnakeInBox(SnakeBox);
	SnakeBox = SecondSnakeInBox(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
	Point NewApple;
	int t = 0;
	while (1) {
		NewApple = MakeRandomNotSnakePoint(SnakeBox, 1);
		SnakeBox = MakeApplePenInBox(SnakeBox, NewApple);
		PrintSnakeBox(SnakeBox, Time);
		t = BrainMoveTwoSnakeInBox(&SnakeBox, NewApple, Time);
		if (t <= 0) break;
	}
	if (t == 0) {
		SnakeBox = GameOverFirstSnake(SnakeBox);
	}
	if (t == -1) {
		SnakeBox = GameOverSecondSnake(SnakeBox);
	}
	PrintSnakeBox(SnakeBox, Time);
}
void TwoAdvancedBrainSnakeAndBarriers(int NumberOfString, int NumberOfColumn, int Time) {
	printf("Write number, number 1 - barriers generated every generated Apple, 2 - static one Barrier\n");
	int BarriersNum;
	scanf_s("%d", &BarriersNum);
	if (BarriersNum < 1 && BarriersNum > 3) {
		printf("YOU LIE\n");
		return 0;
	}
	system("cls");
	Box SnakeBox = MakeTwoSnakeBox(NumberOfString, NumberOfColumn);
	PrintSnakeBox(SnakeBox, Time);
	SnakeBox = SnakeInBox(SnakeBox);
	SnakeBox = SecondSnakeInBox(SnakeBox);
	if (BarriersNum == 2)	SnakeBox = MakeBarrierInBox(SnakeBox);
	PrintSnakeBox(SnakeBox, Time);
	Point NewApple;
	int t = 0;
	while (1) {
		NewApple = MakeRandomNotSnakePoint(SnakeBox, 1);
		SnakeBox = MakeApplePenInBox(SnakeBox, NewApple);
		if (BarriersNum == 1)	SnakeBox = MakeBarrierInBox(SnakeBox);
		PrintSnakeBox(SnakeBox, Time);
		t = BrainMoveTwoSnakeInBox(&SnakeBox, NewApple, Time);
		if (t <= 0) break;
		if (BarriersNum == 1) SnakeBox = DeleteBarrierInBox(SnakeBox);
	}
	if (t == 0) {
		SnakeBox = GameOverFirstSnake(SnakeBox);
	}
	if (t == -1) {
		SnakeBox = GameOverSecondSnake(SnakeBox);
	}
	PrintSnakeBox(SnakeBox, Time);
}