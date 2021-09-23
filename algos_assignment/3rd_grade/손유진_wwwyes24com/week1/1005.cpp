#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int n, k, w;
vector<int> build[1001];
int in[1001] = { 0, };
int d[1001]; // 건물별 건설 시간
int tm[1001] = { 0, }; // 건물별 최소 건설완료시간
void topol();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	
	cin >> t;
	while (t--) { // 각 테스트케이스
		
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> d[i];
		while (k--) { // 건설규칙 입력받기
			int x, y;
			cin >> x >> y;
			build[x].push_back(y);
			in[y]++;
		}
		cin >> w;

		topol();
		cout << tm[w] << "\n";

		memset(d, 0, sizeof(d));
		memset(in, 0, sizeof(in));
		memset(tm, 0, sizeof(tm));
		for (int i = 1; i <= n;i++)
			build[i].erase(build[i].begin(), build[i].end());
	}
}

void topol() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (!in[i]) {
			q.push(i);
		}
		tm[i] = d[i];
	}
	while (!q.empty()) {
		int first = q.front();
		q.pop();
		for (int i = 0; i < build[first].size(); i++) { // 간선 제거과정
			int next = build[first][i];
			in[next]--;
			tm[next] = (tm[first] + d[next]) < tm[next] ? tm[next] : (tm[first] + d[next]);
			
			if (!in[next])
				q.push(next);
		}
	}
}
