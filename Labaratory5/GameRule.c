#include"Box.h"
#include"Snake.h"
#include<math.h>
#include<windows.h>
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