#include "Snake.h"
#include "Box.h"
#include<time.h>
#include<stdlib.h>
Point MakeRandomNotSnakePoint(Box box,int n) {
	srand(box.snake.Size*n*time(NULL));
	Point point;
	while (1) {
		point.x = rand() % box.NumberString;
		point.y = rand() % box.NumberColumn;
		if (box.Arr[point.x][point.y] == 32) {
			break;
		}
	}
	point.Symbol = 48;
	return point;
}