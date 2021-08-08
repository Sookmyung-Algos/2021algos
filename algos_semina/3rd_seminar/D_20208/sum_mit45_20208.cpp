// 20208

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct s
{
	int y; 
	int x;
	bool checked;
};

int N, M, H;
int result = 0;
int arr[10][10] = { 0, };
struct s house;
vector <s> mint;

// dfs
void dfs(int y, int x, int cur, int cnt, int hp) {
	if (cnt > result) {// 방문횟수가 더 많은 경우
		if (abs(y - house.y) + abs(x - house.x) <= hp)
			result = cnt;
	}

	if (hp <= 0)
		return;
	for (int i = 0; i < mint.size(); i++) {
		int len = abs(mint[i].y - y) + abs(mint[i].x - x);
		if (len <= hp && mint[i].checked == 0) {
			mint[i].checked = 1;
			dfs(mint[i].y, mint[i].x, i + 1, cnt + 1, hp - len + H);
			mint[i].checked = 0;
		}

	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> N >> M >> H;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tmp; cin >> tmp;
			if (tmp == 1)
				house.y = i, house.x = j;
			else if (tmp == 2)
				mint.push_back({ i,j,0 });
		}
	}

	dfs(house.y, house.x, 0, 0, M);
	cout << result << endl;
	return 0;
}
