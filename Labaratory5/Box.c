#include"Box.h"
#include"Snake.h"
#include"Random.h"
#include<stdio.h>
#include<Windows.h>
void hidecursor(){
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
Box MakeSnakeBox(int NumberString,int NumberColumn) {
	int** box = (int**)malloc(NumberString * sizeof(int*));
	for (int i = 0; i < NumberString; i++) {
		box[i] = (int*)malloc(NumberColumn * sizeof(int));
		for (int j = 0; j < NumberColumn; j++) {
			box[i][j] = 32;
		}
	}
	for (int i = 0; i < NumberString; i++) {
		box[i][0] = 42;
		box[i][NumberColumn - 1] = 42;
	}
	for (int i = 0; i < NumberColumn; i++) {
		box[0][i] = 42;
		box[NumberString - 1][i] = 42;
	}
	Box Ans;
	Ans.Arr = box;
	Ans.NumberString = NumberString;
	Ans.NumberColumn = NumberColumn;
	Ans.snake = MakeSnake();
	return Ans;
}
void PrintSnakeBox(Box SnakeBox, int Time) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = 0;
	position.Y = 0;
	SetConsoleCursorPosition(hConsole, position);
	for (int i = 0; i < SnakeBox.NumberString; i++) {
		for (int j = 0; j < SnakeBox.NumberColumn; j++) {
			printf("%c", SnakeBox.Arr[i][j]);
		}
		printf("\n");
	}
	Sleep(Time);
}
Box SnakeInBox(Box SnakeBox) {
	for (int i = 0; i < SnakeBox.snake.Size; i++) {
		SnakeBox.Arr[SnakeBox.snake.Body[i].x][SnakeBox.snake.Body[i].y] = SnakeBox.snake.Body[i].Symbol;
	}
	return SnakeBox;
}
Box MoveSnakeInBox(Box SnakeBox, Point New) {
	SnakeBox.Arr[SnakeBox.snake.Body[0].x][SnakeBox.snake.Body[0].y] = 32;
	SnakeBox.snake = Move(SnakeBox.snake, New);
	SnakeBox = SnakeInBox(SnakeBox);
	return SnakeBox;
}
Box GroveSnakeInBox(Box SnakeBox, Point New) {
	SnakeBox.snake = Grove(SnakeBox.snake, New);
	SnakeBox = SnakeInBox(SnakeBox);
	return SnakeBox;
}
Box MakeApplePenInBox(Box SnakeBox, Point New) {
	SnakeBox.Arr[New.x][New.y] = New.Symbol;
	return SnakeBox;
}
Box GameOver(Box SnakeBox) {
	SnakeBox.Arr[1][1] = 'G';
	SnakeBox.Arr[1][2] = 'a';
	SnakeBox.Arr[1][3] = 'm';
	SnakeBox.Arr[1][4] = 'e';
	SnakeBox.Arr[2][1] = 'O';
	SnakeBox.Arr[2][2] = 'v';
	SnakeBox.Arr[2][3] = 'e';
	SnakeBox.Arr[2][4] = 'r';
	SnakeBox.Arr[3][1] = 'I';
	SnakeBox.Arr[3][2] = 'I';
	SnakeBox.Arr[4][1] = 'G';
	SnakeBox.Arr[4][2] = 'i';
	SnakeBox.Arr[4][3] = 'v';
	SnakeBox.Arr[4][4] = 'e';
	SnakeBox.Arr[5][1] = 'U';
	SnakeBox.Arr[5][2] = 'p';
	return SnakeBox;
}
Box GameOver2(Box SnakeBox) {
	SnakeBox.Arr[1][1] = 'G';
	SnakeBox.Arr[1][2] = 'a';
	SnakeBox.Arr[1][3] = 'm';
	SnakeBox.Arr[1][4] = 'e';
	SnakeBox.Arr[2][1] = 'O';
	SnakeBox.Arr[2][2] = 'v';
	SnakeBox.Arr[2][3] = 'e';
	SnakeBox.Arr[3][1] = 'I';
	SnakeBox.Arr[3][2] = 'I';
	SnakeBox.Arr[4][1] = 'T';
	SnakeBox.Arr[4][2] = 'i';
	SnakeBox.Arr[4][3] = 'r';
	SnakeBox.Arr[4][4] = 'e';
	SnakeBox.Arr[4][5] = 'd';
	return SnakeBox;
}
