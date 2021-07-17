#include <iostream>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

//dp[200][200]이 시작지점.
int sx, sy, t, hx, hy, n; //현재 위치 : (sx,sy), 버틸 수 있는 시간 : t, 집 위치 : (hx, hy) 
long long dp[401][401][201]; // (x, y, 그 좌표까지 가는데 걸린 시간)
int dx[] = { 0,1,0,-1 }, dy[] = { 1,0,-1,0 };
map<pair<int, int>, bool> chk; //장애물 위치만 넣어주는 map
const int MOD = 1e9 + 7;

long long go(int x, int y, int sec) { //시작점으로부터의 이동거리 x,y. 이동시간 sec.
	
	int cx = sx + x, cy = sy + y; //현재 좌표 (cx,cy)
	if (cx == hx && cy == hy) { return 1;  } //(cx,cy)가 집이라면 return 1
	if (abs(hx - cx) + abs(hy - cy) > t - sec) return 0; // 이동 시간이 t보다 오래 걸리면 return 0

	long long &ans = dp[x + 200][y + 200][sec]; //ans : dp[x+200][y+200][sec]의 값을 저장한 주소
	if (ans != -1) return ans;
	ans = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		cx = sx + nx, cy = sy + ny;
		if (!chk[{cx, cy}]) //장애물이 아니라면
			ans = (ans + go(nx, ny, sec + 1) % MOD) % MOD;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> sx >> sy >> t >> hx >> hy >> n;
	sx += 100000;
	sy += 100000;
	hx += 100000;
	hy += 100000;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		chk[{x + 100000, y + 100000}] = true; //장애물 위치만 true값 저장
	}

	cout << go(0, 0, 0) % MOD;
}
