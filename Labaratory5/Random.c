#include "Snake.h"
#include "Box.h"
#include<time.h>
Point MakeRandomNotSnakePoint(Box box) {
	srand(box.snake.Size*time(NULL));
	Point point;
	while (1) {
		point.x = (rand() % (box.NumberString - 2)) + 1;
		point.y = (rand() % (box.NumberColumn - 2)) + 1;
		int f = 0;
		for (int i = 0; i < box.snake.Size; i++) {
			if (point.x == box.snake.Body[i].x && point.y == box.snake.Body[i].y) {
				f == 1;
				break;
			}
		}
		if (point.x == box.snake.Body[box.snake.Size - 1].x || point.y == box.snake.Body[box.snake.Size - 1].y) {
			f == 1;
		}
		if (f==0) {
			break;
		}
	}
	point.Symbol = 48;
	return point;
}