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
Snake MakeSnake2(int NumberOfString, int NumberOfColumn);
Snake Move(Snake snake, Point New);
Snake Grove(Snake snake, Point New);
#endif