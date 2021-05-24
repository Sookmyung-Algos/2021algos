//5월 24일 2학년 스터디 문제 풀이

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool mark[101] = { false, };
vector <int> a[101];
queue <int> q;

int n, m, from, to;
int ans = 0;

void dfs(int x) {
	int next;
	mark[x] = true; //방문 mark
	for (int i = 0; i < a[x].size(); i++) {
		next = a[x][i];
		if (!mark[next]) { //방문하지 않은 노드들에 대하여
			dfs(next); //재귀적으로 방문
			ans++;
		}
	}
}

void bfs(int x) {
	int temp, next;

	mark[x] = true; //정점 방문 mark
	q.push(x); //정점 push

	while (!q.empty()) {
		temp = q.front();
		q.pop(); //큐 pop
		for (int i = 0; i < a[temp].size(); i++) {
			next = a[temp][i];

			if (!mark[next]) { //방문하지 않은 노드들에 대하여
				mark[next] = true;
				ans++;
				q.push(next); //큐 push -> 반복
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	//dfs(1);
	bfs(1);
	cout << ans;
}
