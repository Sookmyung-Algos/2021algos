#include <iostream>
#include <cmath>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int curR=0, curC=0,nextR,nextC, n,tmpR, tmpC, tmpV,ans=0;
int a[500][500] = { 0, };
struct coor {
	int x, y;//x,y 좌표, 비율
	float rat;
};
struct xy {
	int x, y;
};
enum face {
	l,r,u,d
};

coor dir[4][9] = {
	{{-2,-1,0.02},{-1,-2,0.1},{-1,-1,0.07},{-1,0,0.01},{0,-3,0.05},{1,-2,0.1},{1,-1,0.07},{1,0,0.01},{2,-1,0.02} },//left
	{{-2,1,0.02},{-1,0,0.01},{-1,1,0.07},{-1,2,0.1},{0,3,0.05},{1,0,0.01},{1,1,0.07},{1,2,0.1},{2,1,0.02} },//right
	{{-3,0,0.05},{-2,-1,0.1},{-2,1,0.1},{-1,-2,0.02},{-1,-1,0.07},{-1,1,0.07},{-1,2,0.02},{0,-1,0.01},{0,1,0.01}},//up
	{{0,-1,0.01},{0,1,0.01},{1,-2,0.02},{1,-1,0.07},{1,1,0.07},{1,2,0.02},{2,-1,0.1},{2,1,0.1},{3,0,0.05}}//down
};
xy last[4] = { {0,-2},{0,2},{-2,0},{2,0} };
bool isExist(int x,int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) {
		return false;
	}
	return true;
}
string direction[4] = { "left","right","up","down" };
int dx[2][4] = { { 0,0,-1,1 },{ -1,1,0,0 } };
void move(int k) {
	int sum = 0;
	nextR = curR+dx[0][k];
	nextC = curC+dx[1][k];
	for (int i = 0; i < 9; i++) {
		tmpV = (int)floor(a[nextR][nextC] * dir[k][i].rat);
		tmpR = curR + dir[k][i].x;
		tmpC = curC + dir[k][i].y;
        //해당 좌표가 존재하면 비율만큼의 모래를 해당 좌표에 더하고 y위치에서 빼준다
		if (isExist(tmpR, tmpC)) a[tmpR][tmpC] += tmpV;
        //존재하지 않으면 밖으로 나간 것, 답에 더해준다
	    else ans += tmpV;
		sum += tmpV;
	}
	a[nextR][nextC] -= sum;
	tmpR = curR + last[k].x;
	tmpC = curC + last[k].y;
	if (isExist(tmpR, tmpC)) {
		a[tmpR][tmpC] += a[nextR][nextC];
	}
	else ans += a[nextR][nextC];
	a[nextR][nextC] = 0;
	curR = nextR;
	curC = nextC;
	return;
}
int main() {
	int idx = l, newi = 1, newj;
	scanf("%d", &n);
	//시작 위치; 중간
	curR = curC = n / 2;
	//격자의 각 칸에 있는 모래 입력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	while (newi < n) {
		if(idx==l){
			for (int i = 0; i < newi; i++) move(0);
			for (int i = 0; i < newi; i++) move(3);
			idx = r;
        }
		else{
			for (int i = 0; i < newi; i++) move(1);
			for (int i = 0; i < newi; i++) move(2);
			idx = l;
		}
		newi++;
	}
	for (int i = 0; i < newi; i++) move(0);
	cout << ans << '\n';
	return 0;
}
