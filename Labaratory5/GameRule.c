#include"Box.h"
#include"Snake.h"
#include<math.h>
#include<windows.h>
Point FreePoint(Box box, Point Head) {
	int Sy = 1;
	int Sx = 1;
	Point P;
	P.x = 0;
	P.y = 0;
	if (box.Arr[Head.x + Sx][Head.y] != 46 && box.Arr[Head.x + Sx][Head.y] != 42) {
		P.x = Head.x + Sx;
		P.y = Head.y;
		return P;
	}
	if (box.Arr[Head.x - Sx][Head.y] != 46 && box.Arr[Head.x - Sx][Head.y] != 42) {
		P.x = Head.x - Sx;
		P.y = Head.y;
		return P;
	}
	if (box.Arr[Head.x][Head.y + Sy] != 46 && box.Arr[Head.x][Head.y + Sy] != 42) {
		P.x = Head.x;
		P.y = Head.y + Sy;
		return P;
	}
	if (box.Arr[Head.x][Head.y - Sy] != 46 && box.Arr[Head.x][Head.y - Sy] != 42) {
		P.x = Head.x;
		P.y = Head.y - Sy;
		return P;
	}
	return P;
}
int BrainMoveInBox(Box* box, Point New) {
	int ans = 1;
	while (1) {
		Point Head = box->snake.Body[box->snake.Size - 1];
		int DifX = New.x - Head.x;
		int DifY = New.y - Head.y;
		int Sy = 1;
		int Sx = 1;
		if (DifX < 0) {
			Sx *= (-1);
		}
		if (DifY < 0) {
			Sy *= (-1);
		}
		if (DifX == 0) {
			Sx = 0;
		}
		if (DifY == 0) {
			Sy = 0;
		}
		if ((box->Arr[Head.x + Sx][Head.y] == 46 || box->Arr[Head.x + Sx][Head.y] == 42) && (box->Arr[Head.x][Head.y + Sy] == 46 || box->Arr[Head.x][Head.y + Sy] == 42)) {
			Point FP = FreePoint(*box, box->snake.Body[box->snake.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = 0;
				break;
			}
			*box = MoveSnakeInBox(*box, FP);
			Sleep(100);
		}
		if (DifY == 0 && (box->Arr[Head.x + Sx][Head.y] == 46 || box->Arr[Head.x + Sx][Head.y] == 42)) {
			Point FP = FreePoint(*box, box->snake.Body[box->snake.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = 0;
				break;
			}
			*box = MoveSnakeInBox(*box, FP);
			Sleep(100);
		}
		if (DifX == 0 && (box->Arr[Head.x][Head.y + Sy] == 46 || box->Arr[Head.x][Head.y + Sy] == 42)) {
			Point FP = FreePoint(*box, box->snake.Body[box->snake.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = 0;
				break;
			}
			*box = MoveSnakeInBox(*box, FP);
			Sleep(100);
		}
		if (abs(DifX) == 1 && DifY == 0) {
			*box = GroveSnakeInBox(*box, New);
			Sleep(100);
			break;
		}
		if (DifX == 0 && abs(DifY) == 1) {
			*box = GroveSnakeInBox(*box, New);
			Sleep(100);
			break;
		}
		if (DifX == 0 && DifY == 0) break;
		if (box->Arr[Head.x][Head.y + Sy] != 46 && box->Arr[Head.x][Head.y + Sy] != 42) {
			if (DifY != 0) {
				Point P;
				P.x = Head.x;
				P.y = Head.y + Sy;
				*box = MoveSnakeInBox(*box, P);
				Sleep(100);
				Head = box->snake.Body[box->snake.Size - 1];
			}
		}
		if (box->Arr[Head.x + Sx][Head.y] != 46 && box->Arr[Head.x + Sx][Head.y] != 42) {
			if (DifX != 0) {
				Point P1;
				P1.x = Head.x + Sx;
				P1.y = Head.y;
				*box = MoveSnakeInBox(*box, P1);
				Sleep(100);
				Head = box->snake.Body[box->snake.Size - 1];
			}
		}
	}
	return ans;
}