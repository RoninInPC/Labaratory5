#include"Box.h"
#include"Snake.h"
#include"TwoSnakeBox.h"
#include<math.h>
#include<conio.h>
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
int BrainMoveInBox(Box* box, Point New, int Time) {
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
			PrintSnakeBox(*box, Time);
		}
		if (DifY == 0 && (box->Arr[Head.x + Sx][Head.y] == 46 || box->Arr[Head.x + Sx][Head.y] == 42)) {
			Point FP = FreePoint(*box, box->snake.Body[box->snake.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = 0;
				break;
			}
			*box = MoveSnakeInBox(*box, FP);
			PrintSnakeBox(*box, Time);
		}
		if (DifX == 0 && (box->Arr[Head.x][Head.y + Sy] == 46 || box->Arr[Head.x][Head.y + Sy] == 42)) {
			Point FP = FreePoint(*box, box->snake.Body[box->snake.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = 0;
				break;
			}
			*box = MoveSnakeInBox(*box, FP);
			PrintSnakeBox(*box, Time);
		}
		if (abs(DifX) == 1 && DifY == 0) {
			*box = GroveSnakeInBox(*box, New);
			PrintSnakeBox(*box, Time);
			break;
		}
		if (DifX == 0 && abs(DifY) == 1) {
			*box = GroveSnakeInBox(*box, New);
			PrintSnakeBox(*box, Time);
			break;
		}
		if (DifX == 0 && DifY == 0) break;
		if (box->Arr[Head.x][Head.y + Sy] != 46 && box->Arr[Head.x][Head.y + Sy] != 42) {
			if (DifY != 0) {
				Point P;
				P.x = Head.x;
				P.y = Head.y + Sy;
				Point PP;
				PP = FreePoint(*box, P);
				if (PP.x == 0 && PP.y == 0) {

				}
				else {
					*box = MoveSnakeInBox(*box, P);
					PrintSnakeBox(*box, Time);
					Head = box->snake.Body[box->snake.Size - 1];
				}
			}
		}
		if (box->Arr[Head.x + Sx][Head.y] != 46 && box->Arr[Head.x + Sx][Head.y] != 42) {
			if (DifX != 0) {
				Point P1;
				P1.x = Head.x + Sx;
				P1.y = Head.y;
				Point PP;
				PP = FreePoint(*box, P1);
				if (PP.x == 0 && PP.y == 0) {

				}
				else {
					*box = MoveSnakeInBox(*box, P1);
					PrintSnakeBox(*box, Time);
					Head = box->snake.Body[box->snake.Size - 1];
				}
			}
		}
	}
	return ans;
}
void StupidMoveInBox(Box* box, Point New, int Time) {
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
			PrintSnakeBox(*box, Time);
			break;
		}
		if (DifX == 0 && abs(DifY) == 1) {
			*box = GroveSnakeInBox(*box, New);
			PrintSnakeBox(*box, Time);
			break;
		}
		if (DifX == 0 && DifY == 0) break;
		if (box->Arr[Head.x][Head.y + Sy] != 42) {
			if (DifY != 0) {
				Point P;
				P.x = Head.x;
				P.y = Head.y + Sy;
				*box = MoveSnakeInBox(*box, P);
				PrintSnakeBox(*box, Time);
				Head = box->snake.Body[box->snake.Size - 1];
			}
		}
		if (box->Arr[Head.x + Sx][Head.y] != 42) {
			if (DifX != 0) {
				Point P1;
				P1.x = Head.x + Sx;
				P1.y = Head.y;
				*box = MoveSnakeInBox(*box, P1);
				PrintSnakeBox(*box, Time);
				Head = box->snake.Body[box->snake.Size - 1];
			}
		}
	}
}
int KeyMove(Box* box, Point New, int Time, int MoveIndex) {
	char c;
	while (1) {
		while (_kbhit() == 0) {
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
			Point P;
			if (abs(DifX) == 1 && DifY == 0) {
				*box = GroveSnakeInBox(*box, New);
				PrintSnakeBox(*box, Time);
				return MoveIndex;
			}
			if (DifX == 0 && abs(DifY) == 1) {
				*box = GroveSnakeInBox(*box, New);
				PrintSnakeBox(*box, Time);
				return MoveIndex;
			}
			if (DifX == 0 && DifY == 0) break;
			if (MoveIndex == 1) {
				P.x = Head.x - 1;
				P.y = Head.y;
				if (box->Arr[P.x][P.y] != 32) {
					MoveIndex = -1;
					return MoveIndex;
				}
				*box = MoveSnakeInBox(*box, P);
				PrintSnakeBox(*box, Time);
				Head = box->snake.Body[box->snake.Size - 1];
			}
			if (MoveIndex == 2) {
				P.x = Head.x;
				P.y = Head.y - 1;
				if (box->Arr[P.x][P.y] != 32) {
					MoveIndex = -1;
					return MoveIndex;
				}
				*box = MoveSnakeInBox(*box, P);
				PrintSnakeBox(*box, Time);
				Head = box->snake.Body[box->snake.Size - 1];
			}
			if (MoveIndex == 3) {
				P.x = Head.x + 1;
				P.y = Head.y;
				if (box->Arr[P.x][P.y] != 32) {
					MoveIndex = -1;
					return MoveIndex;
				}
				*box = MoveSnakeInBox(*box, P);
				PrintSnakeBox(*box, Time);
				Head = box->snake.Body[box->snake.Size - 1];
			}
			if (MoveIndex == 4) {
				P.x = Head.x;
				P.y = Head.y + 1;
				if (box->Arr[P.x][P.y] != 32) {
					MoveIndex = -1;
					return MoveIndex;
				}
				*box = MoveSnakeInBox(*box, P);
				PrintSnakeBox(*box, Time);
				Head = box->snake.Body[box->snake.Size - 1];
			}
		}
		c = _getch();
		Point Head1 = box->snake.Body[box->snake.Size - 1];
		Point SH = box->snake.Body[box->snake.Size - 2];
		int DifX1 = Head1.x - SH.x;
		int DifY1 = Head1.y - SH.y;
		if (c == 'Wc' || c == 'wc' || c == 'W' || c == 'w') {
			if (DifX1 == 1 && DifY1 == 0) {

			}
			else
				MoveIndex = 1;
		}
		if (c == 'Ac' || c == 'ac' || c == 'A' || c == 'a') {
			if (DifX1 == 0 && DifY1 == 1) {

			}
			else
				MoveIndex = 2;
		}
		if (c == 'Sc' || c == 'sc' || c == 'S' || c == 's') {
			if (DifX1 == -1 && DifY1 == 0) {

			}
			else
				MoveIndex = 3;
		}
		if (c == 'Dc' || c == 'dc' || c == 'D' || c == 'd') {
			if (DifX1 == 0 && DifY1 == -1) {

			}
			else
				MoveIndex = 4;
		}
	}
	return MoveIndex;
}
int BrainMoveTwoSnakeInBox(Box* box, Point New, int Time) {
	int ans = 1;
	while (1) {
		Point Head = box->snake.Body[box->snake.Size - 1];
		Point Head2 = box->snake2.Body[box->snake2.Size - 1];
		int DifX = New.x - Head.x;
		int DifY = New.y - Head.y;
		int DifX2 = New.x - Head2.x;
		int DifY2 = New.y - Head2.y;
		int Sy = 1;
		int Sx = 1;
		int Sy2 = 1;
		int Sx2 = 1;
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
		if (DifX2 < 0) {
			Sx2 *= (-1);
		}
		if (DifY2 < 0) {
			Sy2 *= (-1);
		}
		if (DifX2 == 0) {
			Sx2 = 0;
		}
		if (DifY2 == 0) {
			Sy2 = 0;
		}
		if ((box->Arr[Head.x + Sx][Head.y] == 46 || box->Arr[Head.x + Sx][Head.y] == 42 || box->Arr[Head.x + Sx][Head.y] == 88) && (box->Arr[Head.x][Head.y + Sy] == 46 || box->Arr[Head.x][Head.y + Sy] == 42 || box->Arr[Head.x][Head.y + Sy] == 88)) {
			Point FP = FreePoint(*box, box->snake.Body[box->snake.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = 0;
				break;
			}
			*box = MoveSnakeInBox(*box, FP);
		}
		if (DifY == 0 && (box->Arr[Head.x + Sx][Head.y] == 46 || box->Arr[Head.x + Sx][Head.y] == 42 || box->Arr[Head.x + Sx][Head.y] == 88)) {
			Point FP = FreePoint(*box, box->snake.Body[box->snake.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = 0;
				break;
			}
			*box = MoveSnakeInBox(*box, FP);
		}
		if (DifX == 0 && (box->Arr[Head.x][Head.y + Sy] == 46 || box->Arr[Head.x][Head.y + Sy] == 42 || box->Arr[Head.x][Head.y + Sy] == 88)) {
			Point FP = FreePoint(*box, box->snake.Body[box->snake.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = 0;
				break;
			}
			*box = MoveSnakeInBox(*box, FP);
		}
		if (abs(DifX) == 1 && DifY == 0) {
			*box = GroveSnakeInBox(*box, New);
			PrintSnakeBox(*box, Time);
			break;
		}
		if (DifX == 0 && abs(DifY) == 1) {
			*box = GroveSnakeInBox(*box, New);
			PrintSnakeBox(*box, Time);
			break;
		}
		if (DifX == 0 && DifY == 0) break;
		if (box->Arr[Head.x][Head.y + Sy] != 46 && box->Arr[Head.x][Head.y + Sy] != 42 && box->Arr[Head.x][Head.y + Sy] != 88) {
			if (DifY != 0) {
				Point P;
				P.x = Head.x;
				P.y = Head.y + Sy;
				Point PP;
				PP = FreePoint(*box, P);
				if (PP.x == 0 && PP.y == 0) {

				}
				else {
					*box = MoveSnakeInBox(*box, P);
					Head = box->snake.Body[box->snake.Size - 1];
				}
			}
		}
		if (box->Arr[Head.x + Sx][Head.y] != 46 && box->Arr[Head.x + Sx][Head.y] != 42 && box->Arr[Head.x + Sx][Head.y] != 88) {
			if (DifX != 0) {
				Point P1;
				P1.x = Head.x + Sx;
				P1.y = Head.y;
				Point PP;
				PP = FreePoint(*box, P1);
				if (PP.x == 0 && PP.y == 0) {

				}
				else {
					*box = MoveSnakeInBox(*box, P1);
					Head = box->snake.Body[box->snake.Size - 1];
				}
			}
		}

		if ((box->Arr[Head2.x + Sx2][Head2.y] == 46 || box->Arr[Head2.x + Sx2][Head2.y] == 42 || box->Arr[Head2.x + Sx2][Head2.y] == 88) && (box->Arr[Head2.x][Head2.y + Sy2] == 46 || box->Arr[Head2.x][Head2.y + Sy2] == 42 || box->Arr[Head2.x][Head2.y + Sy2] == 88)) {
			Point FP = FreePoint(*box, box->snake2.Body[box->snake2.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = -1;
				break;
			}
			*box = MoveSecondSnakeInBox(*box, FP);
		}
		if (DifY2 == 0 && (box->Arr[Head2.x + Sx2][Head2.y] == 46 || box->Arr[Head2.x + Sx2][Head2.y] == 42 || box->Arr[Head2.x + Sx2][Head2.y] == 88)) {
			Point FP = FreePoint(*box, box->snake2.Body[box->snake2.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = -1;
				break;
			}
			*box = MoveSecondSnakeInBox(*box, FP);
		}
		if (DifX2 == 0 && (box->Arr[Head2.x][Head2.y + Sy2] == 46 || box->Arr[Head2.x][Head2.y + Sy2] == 42 || box->Arr[Head2.x][Head2.y + Sy2] == 88)) {
			Point FP = FreePoint(*box, box->snake2.Body[box->snake2.Size - 1]);
			if (FP.x == 0 && FP.y == 0) {
				ans = -1;
				break;
			}
			*box = MoveSecondSnakeInBox(*box, FP);
		}
		if (abs(DifX2) == 1 && DifY2 == 0) {
			*box = GroveSecondSnakeInBox(*box, New);
			PrintSnakeBox(*box, Time);
			break;
		}
		if (DifX2 == 0 && abs(DifY2) == 1) {
			*box = GroveSecondSnakeInBox(*box, New);
			PrintSnakeBox(*box, Time);
			break;
		}
		if (DifX2 == 0 && DifY2 == 0) break;
		if (box->Arr[Head2.x][Head2.y + Sy2] != 46 && box->Arr[Head2.x][Head2.y + Sy2] != 42 && box->Arr[Head2.x][Head2.y + Sy2] != 88) {
			if (DifY2 != 0) {
				Point P;
				P.x = Head2.x;
				P.y = Head2.y + Sy2;
				Point PP;
				PP = FreePoint(*box, P);
				if (PP.x == 0 && PP.y == 0) {

				}
				else {
					*box = MoveSecondSnakeInBox(*box, P);
					Head2 = box->snake2.Body[box->snake2.Size - 1];
				}
			}
		}
		if (box->Arr[Head2.x + Sx2][Head2.y] != 46 && box->Arr[Head2.x + Sx2][Head2.y] != 42 && box->Arr[Head2.x + Sx2][Head2.y] != 88) {
			if (DifX2 != 0) {
				Point P1;
				P1.x = Head2.x + Sx2;
				P1.y = Head2.y;
				Point PP;
				PP = FreePoint(*box, P1);
				if (PP.x == 0 && PP.y == 0) {

				}
				else {
					*box = MoveSecondSnakeInBox(*box, P1);
					Head2 = box->snake2.Body[box->snake2.Size - 1];
				}
			}
		}
		PrintSnakeBox(*box, Time);
	}
	return ans;
}