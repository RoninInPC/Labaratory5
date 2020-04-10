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
	return Ans;
}
void PrintSnakeBox(Box SnakeBox) {
	system("cls");
	for (int i = 0; i < SnakeBox.NumberString; i++) {
		for (int j = 0; j < SnakeBox.NumberColumn; j++) {
			printf("%c", SnakeBox.Arr[i][j]);
		}
		printf("\n");
	}
}
Box SnakeInBox(Box SnakeBox, Snake snake) {
	for (int i = 0; i < snake.Size; i++) {
		SnakeBox.Arr[snake.Body[i].x][snake.Body[i].y] = snake.Body[i].Symbol;
	}
	return SnakeBox;
}
Box MoveSnakeInBox(Box SnakeBox, Snake* snake, Point New) {
	SnakeBox.Arr[snake->Body[0].x][snake->Body[0].y] = 32;
	*snake = Move(*snake, New);
	SnakeBox = SnakeInBox(SnakeBox, *snake);
	return SnakeBox;
}
Box GroveSnakeInBox(Box SnakeBox, Snake* snake, Point New) {
	*snake = Grove(*snake, New);
	SnakeBox = SnakeInBox(SnakeBox, *snake);
	return SnakeBox;
}
Box MakeApplePenInBox(Box SnakeBox, Snake snake, Point New) {
	SnakeBox.Arr[New.x][New.y] = New.Symbol;
	return SnakeBox;
}