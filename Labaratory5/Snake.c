#include "Snake.h"
Snake MakeSnake() {
	Point* snake = (Point*)malloc(2 * sizeof(Point));
	snake[0].x = 1;
	snake[0].y = 1;
	snake[0].Symbol = 46;
	snake[1].x = 2;
	snake[1].y = 1;
	snake[1].Symbol = 88;
	Snake ans;
	ans.Body = snake;
	ans.Size = 2;
	return ans;
}
Snake Move(Snake snake, Point New) {
	for (int i = 0; i < snake.Size - 1; i++) {
		snake.Body[i] = snake.Body[i + 1];
	}
	snake.Body[snake.Size - 1] = New;
	snake.Body[snake.Size - 1].Symbol = 88;
	snake.Body[snake.Size - 2].Symbol = 46;
	return snake;
}
Snake Grove(Snake snake, Point New) {
	snake.Size++;
	Point* NewBody = (Point*)malloc(snake.Size * sizeof(Point));
	for (int i = 0; i < snake.Size - 1; i++) {
		NewBody[i] = snake.Body[i];
	}
	free(snake.Body);
	snake.Body = NewBody;
	snake.Body[snake.Size - 1] = New;
	snake.Body[snake.Size - 1].Symbol = 88;
	snake.Body[snake.Size - 2].Symbol = 46;
	return snake;
}