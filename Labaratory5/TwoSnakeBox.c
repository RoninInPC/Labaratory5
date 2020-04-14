#include"Box.h"
Box MakeTwoSnakeBox(int NumberString, int NumberColumn) {
	Box ans = MakeSnakeBox(NumberString, NumberColumn);
	ans.snake2 = MakeSnake2(NumberString, NumberColumn);
	return ans;
}
Box SecondSnakeInBox(Box SnakeBox) {
	for (int i = 0; i < SnakeBox.snake2.Size; i++) {
		SnakeBox.Arr[SnakeBox.snake2.Body[i].x][SnakeBox.snake2.Body[i].y] = SnakeBox.snake2.Body[i].Symbol;
	}
	return SnakeBox;
}
Box MoveSecondSnakeInBox(Box SnakeBox, Point New) {
	SnakeBox.Arr[SnakeBox.snake2.Body[0].x][SnakeBox.snake2.Body[0].y] = 32;
	SnakeBox.snake2 = Move(SnakeBox.snake2, New);
	SnakeBox = SecondSnakeInBox(SnakeBox);
	return SnakeBox;
}
Box GroveSecondSnakeInBox(Box SnakeBox, Point New) {
	SnakeBox.snake2 = Grove(SnakeBox.snake2, New);
	SnakeBox = SecondSnakeInBox(SnakeBox);
	return SnakeBox;
}
Box GameOverFirstSnake(Box SnakeBox) {
	SnakeBox.Arr[1][1] = 'G';
	SnakeBox.Arr[1][2] = 'a';
	SnakeBox.Arr[1][3] = 'm';
	SnakeBox.Arr[1][4] = 'e';
	SnakeBox.Arr[2][1] = 'O';
	SnakeBox.Arr[2][2] = 'v';
	SnakeBox.Arr[2][3] = 'e';
	SnakeBox.Arr[2][4] = 'r';
	SnakeBox.Arr[3][1] = 'F';
	SnakeBox.Arr[3][2] = 'i';
	SnakeBox.Arr[3][3] = 'r';
	SnakeBox.Arr[3][4] = 's';
	SnakeBox.Arr[3][5] = 't';
	SnakeBox.Arr[4][1] = 'G';
	SnakeBox.Arr[4][2] = 'i';
	SnakeBox.Arr[4][3] = 'v';
	SnakeBox.Arr[4][4] = 'e';
	SnakeBox.Arr[5][1] = 'U';
	SnakeBox.Arr[5][2] = 'p';
	return SnakeBox;
}
Box GameOverSecondSnake(Box SnakeBox) {
	SnakeBox.Arr[1][1] = 'G';
	SnakeBox.Arr[1][2] = 'a';
	SnakeBox.Arr[1][3] = 'm';
	SnakeBox.Arr[1][4] = 'e';
	SnakeBox.Arr[2][1] = 'O';
	SnakeBox.Arr[2][2] = 'v';
	SnakeBox.Arr[2][3] = 'e';
	SnakeBox.Arr[2][4] = 'r';
	SnakeBox.Arr[3][1] = 'S';
	SnakeBox.Arr[3][2] = 'e';
	SnakeBox.Arr[3][3] = 'c';
	SnakeBox.Arr[3][4] = 'o';
	SnakeBox.Arr[3][5] = 'n';
	SnakeBox.Arr[3][6] = 'd';
	SnakeBox.Arr[4][1] = 'G';
	SnakeBox.Arr[4][2] = 'i';
	SnakeBox.Arr[4][3] = 'v';
	SnakeBox.Arr[4][4] = 'e';
	SnakeBox.Arr[5][1] = 'U';
	SnakeBox.Arr[5][2] = 'p';
	return SnakeBox;
}
