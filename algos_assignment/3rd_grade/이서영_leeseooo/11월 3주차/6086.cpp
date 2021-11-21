#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define INF 1000000000
#define MAX 701
int c[MAX][MAX];
int f[MAX][MAX];
int visit[MAX];
vector<vector<int>>v;
int res = 0;
int n;
void maxFlow(int start, int end) {
	while (1) {
		fill(visit, visit + MAX, -1);//init
		visit[start] = start;
		queue<int>q;
		q.push(start);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int i = 0; i < v[x].size(); i++) {
				int y = v[x][i]; //next node
				if (c[x][y] - f[x][y] > 0 && visit[y] == -1) {//용량이 남아있고 방문 x
					q.push(y);
					visit[y] = x; //y는 x로부터 왔다.
					if (y == end)break; //1-2로 가는 경로를 찾았구나. 
				}
			}
		}
		if (visit[end] == -1)break; //end로 갈 수 있는 유량이 없는 경우

		int flow = INF;
		for (int i = end; i != start; i = visit[i]) {
			flow = min(flow, c[visit[i]][i] - f[visit[i]][i]);
		}
		for (int i = end; i != start; i = visit[i]) {//경로마다 더해주기
			f[visit[i]][i] += flow;// 해당 경로로 갈 수 있다.
			f[i][visit[i]] -= flow; //음의 유량 
		}
		res += flow; //최대 유량 저장
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	v.resize(MAX);
	int num;
	for (int i = 0; i < n; i++) {
		char a, b;
		cin >> a >> b >> num;
		a = a - 'A';
		b = b - 'A';
		v[a].push_back(b);
		v[b].push_back(a);
		c[a][b] += num;
		c[b][a] += num;
	}
	maxFlow('A'-'A','Z'-'A');
	cout << res;
}
