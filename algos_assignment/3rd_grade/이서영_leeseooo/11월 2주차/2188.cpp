#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define MAX 402
int c[MAX][MAX];
int f[MAX][MAX];
int visit[MAX];
vector<vector<int>>v;
int res = 0;
int n,m,s;
// 용량과 유량은 1
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
					if (y == end)break; //end로 갈수있는 경로를 찾았구나. 
				}
			}
		}
		if (visit[end] == -1)break; //end로 갈 수 있는 유량이 없는 경우

		for (int i = end; i != start; i = visit[i]) {
			f[visit[i]][i] += 1;// 해당 경로로 갈 수 있다. +1
			f[i][visit[i]] -= 1; //음의 유량 
		}
		res += 1;
	}
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	v.resize(m + n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> s;
		v[0].push_back(i);//start지점 0에서 n마리의 소들과 연결
		c[0][i] = 1;//최대용량도 저장
		for (int j = 1; j <= s; j++) {
			int a;
			cin >> a;
			v[i].push_back(a + n);//소랑 축사랑 연결
			v[a + n].push_back(i);//양방향으로 연결
			c[i][a + n] = 1;
			
			v[a + n].push_back(m + n + 1);//소랑 축사의 번호가 같으면 bfs돌릴 때 번호 중복돼서 오류나므로
			//소가 1번이면 축사번호는 6번으로 소 마릿수만큼 더해줘서 번호를 다르게 해준다.
			c[a + n][m + n + 1] = 1;//축사와 농장을 연결한다.
		}
	}
	maxFlow(0, m + n + 1);//0부터 소 n마리 축사 m개 농장까지
	cout << res;
}
