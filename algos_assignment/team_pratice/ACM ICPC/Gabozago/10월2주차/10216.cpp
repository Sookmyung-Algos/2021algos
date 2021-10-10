#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
vector<pair<pair<int, int>, pair<int, int>>> v;
int n, cnt;

//통신 가능한지 확인
bool compare(int a, int b) {
	int r = v[a].second.first + v[b].second.first;
	int x = v[a].first.first - v[b].first.first;
	int y = v[a].first.second - v[b].first.second;
	if (pow(x, 2) + pow(y, 2) <= pow(r, 2))
		return true;
	return false;
}

void dfs(int k) {
	v[k].second.second = 1;
	for (int i = 0; i < n; i++) {
		if (v[i].second.second) {
			continue;
		}
		if (compare(i, k)) {  //통신 가능하면 연결
			v[i].second.second = 1;
			dfs(i);
		}
	}
}

int main() {
	int t, x, y, R;
	cin >> t;
	while (t--) {
		v.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x >> y >> R;
			v.push_back({ {x, y }, { R, 0 } });
		}

		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].second.second)
				continue;
			else {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}
