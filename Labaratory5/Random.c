#include "Snake.h"
#include "Box.h"
#include<time.h>
Point MakeRandomNotSnakePoint(Snake snake, Box box) {
	srand(time(NULL));
	Point point;
	while (1) {
		point.x = rand() % (box.NumberString - 2) + 1;
		point.y = rand() % (box.NumberColumn - 2) + 1;
		int f = 0;
		for (int i = 0; i < snake.Size; i++) {
			if (point.x == snake.Body[i].x && point.y == snake.Body[i].y) {
				f == 1;
				break;
			}
		}
		if (f==0) {
			break;
		}
	}
	return point;
}
Point MakeApplePen(Snake snake, Box box) {
	Point Ans = MakeRandomNotSnakePoint(snake, box);
	Ans.Symbol = 48;
	return Ans;	
}