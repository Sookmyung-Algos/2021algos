#include <iostream>
#include <algorithm>
using namespace std;

struct point {
	int x, y, idx;
};

bool cmp1(point a, point b) {
	if (a.x - a.y == b.x - b.y)
		return a.x < b.x;
	return a.x - a.y < b.x - b.y;
}

bool cmp2(point a, point b) {
	if (a.x + a.y == b.x + b.y)
		return a.x < b.x;
	return a.x + a.y < b.x + b.y;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	string jump_dir;
	cin >> jump_dir;
	pair<int,int> idx[100001];
	point cp[100001];
	for (int i = 0; i < n; ++i) {
		cin >> idx[i].first >> idx[i].second;
		cp[i].x = idx[i].first; cp[i].y = idx[i].second; cp[i].idx = i;
	}
	int edge[100001][4] = {0};
	sort(cp, cp + n, cmp1);
	for (int i = 0; i < n - 1; ++i)
		if (cp[i].x - cp[i].y == cp[i + 1].x - cp[i + 1].y) {
			edge[cp[i].idx][0] = cp[i + 1].idx;
			edge[cp[i + 1].idx][3] = cp[i].idx;
		}
	sort(cp, cp + n, cmp2);
	// for (auto i: cp) {if(!i.x)break; cout << i.x << "," << i.y << " "; } cout << endl;
	for (int i = 0; i < n - 1; ++i)
		if (cp[i].x + cp[i].y == cp[i + 1].x + cp[i + 1].y) {
			edge[cp[i].idx][1] = cp[i + 1].idx;
			edge[cp[i + 1].idx][2] = cp[i].idx;
		}
	int cur = 0, next;
	for (int i = 0; i < k; ++i) {
		// cout << idx[cur].first << " " << idx[cur].second << endl;
		next = edge[cur][jump_dir[i] - 'A'];
		if (next) {
			if (edge[cur][0]) edge[edge[cur][0]][3] = edge[cur][3];
			if (edge[cur][3]) edge[edge[cur][3]][0] = edge[cur][0];
			if (edge[cur][1]) edge[edge[cur][1]][2] = edge[cur][2];
			if (edge[cur][2]) edge[edge[cur][2]][1] = edge[cur][1];
			cur = next;
		}
	}
	cout << idx[cur].first << " " << idx[cur].second;
	return 0;
}
