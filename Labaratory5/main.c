#include"Box.h"
#include"Snake.h"
#include"Random.h"
#include"GameRule.h"
#include"Game.h"
#include<Windows.h>
#include<stdio.h>
int main() {
	hidecursor();
	printf("Write size box, Number of String and Number of Column (this numbers >= 10 and <= 30)\n");
	int NumberOfString;
	int NumberOfColumn;
	scanf_s("%d %d", &NumberOfString, &NumberOfColumn);
	printf("Write speed of snake (this numbers >=20 ans <= 100)\n");
	int Time;
	scanf_s("%d", &Time);
	printf("Write ProgrammSnake, Number 1 = StupidSnake, Number 2 = AdvancedSnake, Number 3 = UserSnake, Number 4 = AdvancedBrainSnakeAndBarrier, Number 5 = TwoAdvancedBrainSnake, Number 6 = TwoAdvancedBrainSnakeAndBarriers\n");
	int NumberExc;
	scanf_s("%d", &NumberExc);
	if (NumberOfString > 30 && NumberOfString < 10 || NumberOfColumn>30 && NumberOfColumn < 10 || Time>100 && Time < 20 || NumberExc < 1 && NumberExc>6) {
		printf("YOU LIE");
		return 0;
	}
	system("cls");
	if (NumberExc == 1) {
		StupidBrainSnake(NumberOfString, NumberOfColumn, Time);
	}
	if (NumberExc == 2) {
		AdvancedBrainSnake(NumberOfString, NumberOfColumn, Time);
	}
	if (NumberExc == 3) {
		UserPlaySnake(NumberOfString, NumberOfColumn, Time);
	}
	if (NumberExc == 4) {
		AdvancedBrainSnakeAndBarrier(NumberOfString, NumberOfColumn, Time);
	}
	if (NumberExc == 5) {
		TwoAdvancedBrainSnake(NumberOfString, NumberOfColumn, Time);
	}
	if (NumberExc == 6) {
		TwoAdvancedBrainSnakeAndBarriers(NumberOfString, NumberOfColumn, Time);
	}
	system("pause");
	return 0;
}