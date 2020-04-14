#include"Box.h"
#include"Random.h"
#include<stdlib.h>
Point** MakeBarriers(Box box) {
	int X = (box.NumberColumn * box.NumberString) / 200 + 1;
	int Y = (box.NumberColumn * box.NumberString) / 200 + 1;
	Point** Ans = (Point**)malloc(X * sizeof(Point*));
	for (int i = 0; i < X; i++) {
		Ans[i] = (Point*)malloc(Y * sizeof(Point));
		Ans[i][0] = MakeRandomNotSnakePoint(box, i + 1);
		for (int j = 1; j < Y; j++) {
			Ans[i][j].x = (Ans[i][j - 1].x + 1) % box.NumberString;
			Ans[i][j].y = Ans[i][0].y;
		}
	}
	return Ans;
}
