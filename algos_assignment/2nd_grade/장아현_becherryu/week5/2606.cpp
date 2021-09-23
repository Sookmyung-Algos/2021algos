#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

bool mark[1001] = { false, };
vector <int> a[1001];
queue <int> q;

int n, m, from, to;
int ans = 0;

void bfs(int x) { //x = 시작노드
	int temp, next;

	mark[x] = true; //정점 방문 마크
	q.push(x); //정점 push

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (int i = 0; i < a[temp].size(); i++) {
			next = a[temp][i];

			if (!mark[next]) { //방문하지 않은 노드에 대해
				mark[next] = true;
				ans++;
				q.push(next); //q push -> 반복
			}
		}
	}
}

void dfs(int x) {
	int next;

	mark[x] = true; //정점 방문 마크

	for (int i = 0; i < a[x].size(); i++) {
		next = a[x][i];

		if (!mark[next]) { //방문하지 않은 노드에 대해
			dfs(next); //재귀적으로 방문
			ans++;
		}
	}
}

int main()
{
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}
	dfs(1); // dfs bfs 중 1개 사용하기
	//bfs(1);
	cout << ans;
}
