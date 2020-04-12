#include "Snake.h"
Point MakePoint(int x, int y, int Symbol) {
	Point ans;
	ans.x = x;
	ans.y = y;
	ans.Symbol = Symbol;
	return ans;
}
Snake MakeSnake() {
	Snake ans;
	ans.Size = 2;
	Point* snake = malloc(ans.Size * sizeof(Point));
	snake[0] = MakePoint(1, 1, 46);
	snake[1] = MakePoint(2, 1, 88);
	ans.Body = snake;
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