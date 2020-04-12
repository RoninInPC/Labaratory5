#include"Box.h"
#include"Snake.h"
#include"Random.h"
#include"GameRule.h"
#include<windows.h>
#include<stdio.h>
int main() {
	ShowCursor(FALSE);
	printf("Write size box, Number of String and Number of Column (this numbers >=10 and <=30)\n");
	int NumberOfString;
	int NumberOfColumn;
	scanf_s("%d %d", &NumberOfString, &NumberOfColumn);
	printf("Write speed of snake (this numbers>=20 ans <=100\n");
	int Time;
	scanf_s("%d", &Time);
	if (NumberOfString > 30 && NumberOfString < 10 || NumberOfColumn>30 && NumberOfColumn < 10 || Time>100 && Time < 20) {
		printf("YOU LIE");
		
		return 0;
	}
	system("cls");
	AdvancedBrainSnake(NumberOfString, NumberOfColumn, Time);
	system("pause");
	return 0;
}