// 21738.cpp (G5)

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, s, p;
// n: 얼음 블록의 개수 (3 <= n <= 238,000)
// s: 지지대 얼음 개수 (2 <= s <= n - 1), 1번 ~ s번 : 지지대 얼음
// p: 펭귄 위치 (s < p <= n)

vector<int> v[328001];
queue<int> q;
int visit[328001];

int ans[2] = { 328001, 328001 };

void bfs() { // 가장 가까이 있는 지지대 얼음 까지 거리 찾기
	memset(visit, -1, sizeof(visit));

	q.push(p);
	visit[p] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (1 <= cur && cur <= s) {
			if (ans[1] > visit[cur]) {
				if (ans[0] > visit[cur]) ans[0] = visit[cur];
				else ans[1] = visit[cur];
			}
		}

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visit[next] == -1) {
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> s >> p;

	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	bfs();
	cout << n - ans[0] - ans[1] - 1 << '\n';
	
	return 0;
}
