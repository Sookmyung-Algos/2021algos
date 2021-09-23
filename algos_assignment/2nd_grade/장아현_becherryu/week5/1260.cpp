#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

bool mark[1001] = { false, };
vector <int> a[1001];
queue <int> q;

int n, m, v;

void bfs(int x) { //x = 시작노드
	int temp, next;

	mark[x] = true; //정점 방문 마크
	q.push(x); //정점 push

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		cout << temp << " "; //방문 할 때마다 출력
		for (int i = 0; i < a[temp].size(); i++) {
			next = a[temp][i];

			if (!mark[next]) { //방문하지 않은 노드에 대해
				mark[next] = true;
				q.push(next); //q push -> 반복
			}
		}
	}
}

void dfs(int x) {
	int next;

	mark[x] = true; //정점 방문 마크
	cout << x << " "; //방문 할 떄마다 출력
	for (int i = 0; i < a[x].size(); i++) {
		next = a[x][i];

		if (!mark[next]) { //방문하지 않은 노드에 대해
			dfs(next); //재귀적으로 방문
		}
	}
}

int main()
{
	int from, to;

	cin >> n >> m >> v;

	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;
		a[from].push_back(to); //위치 설정
		a[to].push_back(from);
	}

	for (int i = 1; i <= n; i++)
	{
		sort(a[i].begin(), a[i].end());
	}

	dfs(v);
	cout << "\n";
	memset(mark, false, sizeof(mark)); //메모리 재설정
	bfs(v);
}
