#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct map
{
	int y;
	int x;
	bool checked;
}val;

int n = 0, m = 0, h = 0;
int result = 0;
int arr[10][10] = { 0, };
val home;
vector <val> mint;

// 좌표들간의 거리로 탐색
void dfs(int y, int x, int cur, int cnt, int hp) {
	if (cnt > result) { // 방문횟수가 더 많음
		if (abs(y - home.y) + abs(x - home.x) <= hp)
			result = cnt;
	}
	if (hp <= 0)
		return;

	for (int i = 0; i < mint.size(); i++) {

		int len = abs(mint[i].y - y) + abs(mint[i].x - x);
		if (len <= hp && mint[i].checked == 0) {
			mint[i].checked = 1;
			dfs(mint[i].y, mint[i].x, i + 1, cnt + 1, hp - len + h);
			mint[i].checked = 0;
		}

	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> h;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp = 0;
			cin >> temp;
			if (temp == 1)	// 집의 위치
				home.y = i, home.x = j;
			else if (temp == 2)	// 민트초코의 위치
				mint.push_back({ i,j,0 });
		}
	}

	dfs(home.y, home.x, 0, 0, m);

	cout << result << endl;
	return 0;
}
