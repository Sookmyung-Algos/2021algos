#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;
struct pos {
	int x;
	int y;
	bool visit;
};
int n, m, h;
int arr[11][11];
pos home;
vector<pos>v;
int ans = 0;
void solve(int x,int y,int mincho,int hp) {
	if (mincho > ans) {
		if (abs(x - home.x) + abs(y - home.y) <= hp) {
			ans = mincho;// 현 위치에서 집으로 돌아갈 수만 있으면 최대값으로 갱신
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int dis = abs(v[i].x - x) + abs(v[i].y - y);//민초 먹기 위해 가야하는 거리==깎이는 체력량
		if (dis <= hp && v[i].visit == false) {
			v[i].visit = true;
			solve(v[i].x, v[i].y, mincho + 1, hp - dis + h);
			v[i].visit = false;
		}
	}
}
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m >> h;
	int tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (tmp == 1) {
				home.x = i; home.y = j;
			}
			else if (tmp == 2) {
				v.push_back({ i,j,false });
			}
		}
	}
	solve(home.x,home.y, 0, m);
	cout << ans;
}
