#include <iostream>
using namespace std;

int n, map[30][30];
double sum, dir[4];

void find(int x, int y, int level, double p) {
	if (level < 0) {
		sum += p;
		return;
	}
	if (map[x][y])
		return;
	map[x][y] = 1;
	find(x, y + 1, level - 1, p * dir[0]);
	find(x, y - 1, level - 1, p * dir[1]);
	find(x + 1, y, level - 1, p * dir[2]);
	find(x - 1, y, level - 1, p * dir[3]);
	map[x][y] = 0;
}

int main() {
	scanf("%d%lf%lf%lf%lf", &n, &dir[0], &dir[1], &dir[2], &dir[3]);
	for (int i = 0; i < 4; ++i)
		dir[i] /= 100;
	map[15][15] = 1;
	find(15,16,n-1,dir[0]);
	find(15,14,n-1,dir[1]);
	find(16,15,n-1,dir[2]);
	find(14,15,n-1,dir[3]);
	printf("%.9lf", sum);
	return 0;
}
