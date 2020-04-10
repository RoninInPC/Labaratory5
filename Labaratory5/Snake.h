#ifndef H_SNAKE
#define H_SNAKE
typedef struct point {
	int x;
	int y;
	int Symbol;
} Point;
typedef struct snake {
	Point* Body;
	int Size;
} Snake;
Snake MakeSnake();
Snake Move(Snake snake, Point New);
Snake Grove(Snake snake, Point New);
#endif