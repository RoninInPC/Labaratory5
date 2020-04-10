#include"Box.h"
#include"Snake.h"
Point* BrainMoveInBox(Box* box, Snake* snake, Point New) {
	Point Head = snake->Body[snake->Size - 1];
	int DifX = Head.x - New.x;
	int DifY = Head.y - New.y;
	int Sy = 1;
	int Sx = 1;
	if (DifX < 0) {
		Sx *= (-1);
	}
	if (DifY < 0) {
		Sy *= (-1);
	}
	int size = 0;
	Point* Arr = (Point*)malloc(size * sizeof(Point));
	while (1) {
		if(Head.x==)

	}
}