//5월 24일 2학년 스터디 문제 풀이

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include<memory.h>
using namespace std;

bool mark[1001] = {false, };
vector <int> a[1001];
queue <int> q;

int n, m, v;


void bfs(int x) {
	int temp, next;

	mark[x] = true; //정점 방문 mark
	q.push(x); //정점 push

	while (!q.empty()) {
		temp = q.front(); 
		q.pop(); //큐 pop
		cout << temp << " ";
		for (int i = 0; i < a[temp].size(); i++) {
			next = a[temp][i]; 

			if (!mark[next]) { //방문하지 않은 노드들에 대하여
				mark[next] = true; 
				q.push(next); //큐 push -> 반복
			}
		}
	}
}

void dfs(int x) {
	int next;
	mark[x] = true; //방문 mark
	cout << x << " ";
	for (int i = 0; i < a[x].size(); i++) {
		next = a[x][i];
		if (!mark[next]) { //방문하지 않은 노드들에 대하여
			dfs(next); //재귀적으로 방문
		}
	}
}

int main() {
	int from, to;

	cin >> n >> m >> v;


	for (int i = 0; i < m; i++) {
		cin >> from >> to;
		a[from].push_back(to);
		a[to].push_back(from);
	}

	for (int i = 1; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}

	dfs(v);
	cout << "\n";
	memset(mark, false, sizeof(mark));
	bfs(v);
}
