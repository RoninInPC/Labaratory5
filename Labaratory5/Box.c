#include"Box.h"
#include"Snake.h"
#include"Random.h"
#include<stdio.h>
#include<windows.h>
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
void PrintSnakeBox(Box SnakeBox) {
	ShowCursor(FALSE);
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
	PrintSnakeBox(SnakeBox);
	return SnakeBox;
}
Box GroveSnakeInBox(Box SnakeBox, Point New) {
	SnakeBox.snake = Grove(SnakeBox.snake, New);
	SnakeBox = SnakeInBox(SnakeBox);
	PrintSnakeBox(SnakeBox);
	return SnakeBox;
}
Box MakeApplePenInBox(Box SnakeBox, Point New) {
	SnakeBox.Arr[New.x][New.y] = New.Symbol;
	return SnakeBox;
}