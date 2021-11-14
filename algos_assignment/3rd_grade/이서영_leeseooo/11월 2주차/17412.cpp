#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAX 401
int c[MAX][MAX];
int f[MAX][MAX];
int visit[MAX];
vector<vector<int>>v;
int res = 0;
int N, P;
//경로를 구하는 것이라서 용량과 유량은 1이다.
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

		for (int i = end; i != start; i = visit[i]) {//경로마다 더해주기
			f[visit[i]][i] += 1;// 해당 경로로 갈 수 있다. +1
			f[i][visit[i]] -= 1; //음의 유량 
		}
		res += 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> N >> P;
	v.resize(N + 1);
	for (int i = 1; i <= P; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a); //양방향
		c[a][b] = 1; //a~b로 가는 경로가 있다고 최대용량 초기화
	}
	maxFlow(1, 2);
	cout << res;
}
