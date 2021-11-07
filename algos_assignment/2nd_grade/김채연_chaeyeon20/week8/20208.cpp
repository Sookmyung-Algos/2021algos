#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm> 
#include <queue>
#include <math.h>
#include <time.h>
#define MAX 100001
using namespace std;
int n, m, h;  //m:초기체력 h:마실때마다 증가하는 체력
struct mincho {
	int y, x;
	bool visited;
};
vector <mincho> minn;
int arr[11][11];
int used[11][11];
int hX, hY;
int ans;

void run(int y, int x, int hh,int cnt) {
	if (abs(hX - x) + abs(hY - y) <= hh && ans < cnt) {
		ans = cnt;
	}
	if (hh <= 0) return;
	for (int i = 0; i < minn.size(); i++) {
		int dis = abs(y - minn[i].y) + abs(x - minn[i].x);
		if (hh >= dis) {
			if (minn[i].visited == true) continue;
			minn[i].visited = true;
			run(minn[i].y, minn[i].x, h+(hh-dis),cnt+1);
			minn[i].visited = false;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> h;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				hX = j, hY = i;
			}
			else if (arr[i][j] == 2) {
				minn.push_back({ i,j,false });
			}
		}
	}

	run(hY,hX,m,0);

	cout << ans;
	return 0;
}
