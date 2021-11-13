#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define MAX 53
#define INF 987654321

using namespace std;

int c[MAX][MAX] ={ 0, };	//최대 유량
int f[MAX][MAX] = { 0, };	//실제 유량
int visit[MAX];	//방문확인
vector<vector<int>> v;
int res = 0;
int n;

void maxFlow(int start, int end) {
	while (true) {
		fill(visit, visit + MAX, -1);
		queue<int>q;
		q.push(start);

		while (!q.empty()) {	// 갈 수 있는 경로로 먼저 가기
			int x = q.front();
			q.pop();

			for (int i = 0; i < v[x].size(); i++) {
				int y = v[x][i];

				if (c[x][y] - f[x][y] > 0 && visit[y] == -1) {	//용량이 남아있고 방문하지 않음
					q.push(y);
					visit[y] = x;	//x에서 y로 간 경로 기억

					if (y == end)
						break;
				}
			}
		}

		if (visit[end] == -1)	//더 이상 end로 갈 유량이 없음
			break;

		int flow = INF;
		for (int i = end; i != start; i = visit[i]) {
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		}

		for (int i = end; i != start; i = visit[i]) {	//경로마다 더해주기
			f[visit[i]][i] += flow;
			f[i][visit[i]] -= flow;
		}
		res += flow;	//최대 유량 저장
	}
}

int ctoi(char c) {
	if (c <= 'Z')
		return c - 'A';
	return c - 'a' + 26;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> n;

	v.resize(MAX);

	int num;
	for (int i = 1; i <= n; i++) {
		char a, b;
		cin >> a >> b >> num;
		a = ctoi(a);
		b = ctoi(b);
		
		v[a].push_back(b);
		v[b].push_back(a);
		c[a][b] += num; 
		c[b][a] += num;
	}

	maxFlow(ctoi('A'),ctoi('Z'));

	cout << res << '\n';
	return 0;
}