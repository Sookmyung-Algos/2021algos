#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

bool mark[1001] = { false, };
vector<int> a[1001];
queue<int> q;
int n, m, v; //n: 정점, m: 간선, v: 탐색 시작 정점 번호

void bfs(int k);
void dfs(int k);

int main() {
	cin >> n >> m >> v;
	
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}

	for (int i = 1; i <= n; i++)	sort(a[i].begin(), a[i].end());

	dfs(v);
	cout << "\n";
	memset(mark, false, sizeof(mark)); //초기화
	bfs(v);
	return 0;
}
void bfs(int k) {//너비우선탐색
	int temp, next;
	mark[k] = true;//정점 방문 mark
	q.push(k);//정점을 큐 push

	while (!q.empty()) {
		temp = q.front();
		q.pop();//큐 pop
		cout << temp << " "; //방문하면 출력
		for (int i = 0; i < a[temp].size(); i++) {
			next = a[temp][i];
			if (!mark[next]) {//방문하지 않은 노드들에 대하여
				mark[next] = true;
				q.push(next);//큐 push, 반복
			}
		}
	}
}
void dfs(int k) {//깊이우선탐색: 특정 경로를 따라 가능한 멀리 있는 정점을 재귀적으로 먼저 방문
	int next;
	mark[k] = true;//방문 mark
	cout << k << " ";//방문하면 출력
	for (int i = 0; i < a[k].size(); i++) {
		next = a[k][i];
		if (!mark[next]) {//방문하지 않은 노드
			dfs(next); //재귀적으로 방문
		}
	}
}
