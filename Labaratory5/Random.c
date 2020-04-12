#include "Snake.h"
#include "Box.h"
#include<time.h>
Point MakeRandomNotSnakePoint(Box box) {
	srand(box.snake.Size*time(NULL));
	Point point;
	int f = 0;
	while (1) {
		point.x = (rand() % (box.NumberString - 2)) + 1;
		point.y = (rand() % (box.NumberColumn - 2)) + 1;
		for (int i = 0; i < box.snake.Size; i++) {
			if ((point.x == box.snake.Body[i].x) && (point.y == box.snake.Body[i].y)) {
				f == 1;
			}
		}
		if (f == 1) {
			f = 0;
		}
		else
			break;
	}
	point.Symbol = 48;
	return point;
}