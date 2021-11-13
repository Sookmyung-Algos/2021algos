#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

#define MAX 402

using namespace std;

int c[MAX][MAX];	//최대 유량
int f[MAX][MAX];	//실제 유량
int visit[MAX];	//방문확인
vector<vector<int>> v;
int res = 0;

void maxFlow(int start, int end) {
	while (1) {
		fill(visit, visit + MAX, -1);
		queue<int>q;
		q.push(start);
		while (!q.empty()) {	// 갈 수 있는 경로로 먼저 가기
			int x = q.front();
			q.pop();
			
			for (int i = 0; i < v[x].size(); i++) {
				int y = v[x][i];

				if (c[x][y] - f[x][y] > 0 && visit[y]==-1) {	//용량이 남아있고 방문하지 않음
					q.push(y);
					visit[y] = x;	//x에서 y로 간 경로 기억
					
					if (y == end) //도착지 도달
						break;
					
				}
			}
		}

		if (visit[end] == -1)	//더 이상 end로 갈 유량이 없음
			break;

		for (int i = end; i != start; i = visit[i]) {	//경로마다 더해주기
			f[visit[i]][i] += 1;
			f[i][visit[i]] -= 1;
		}
		res += 1;	//최대 유량 저장
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	v.resize(m+n+2);

	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		
		v[0].push_back(i);
		c[0][i] = 1;
		for (int j = 1; j <= a; j++) {
			int b;
			cin >> b;

			v[i].push_back(b+n);
			v[b+n].push_back(i);
			c[i][b+n] = 1;

			v[b + n].push_back(m + n + 1);
			c[b+n][m+n+1] = 1;
		}
	}

	maxFlow(0, m+n+1);

	cout << res<<'\n';
	return 0;
}