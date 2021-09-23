#include <iostream>
#include<algorithm>
using namespace std;

void dfs(int node);
int N, cnt = 0;
int v[101];
bool visited[101] = { false, };
bool finished[101] = { false, };
int cycled[101];
int main() {

	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> v[i];
	}

	for (int i = 1;i <= N;i++) {
		if (!visited[i]) {
			dfs(i);
		}
	}
	sort(cycled, cycled + cnt);
	cout << cnt << "\n";
	for (int i = 0;i < cnt;i++)
		cout << cycled[i] << "\n";

	return 0;
}

void dfs(int node) {
	visited[node] = true;

	int next = v[node];
	if (!visited[next])
		dfs(next);
	else if (!finished[next]) {//사이클이 생겼다
		cycled[cnt++] = node;
		for (int i = v[node]; i != node; i = v[i]) {//사이클부분만 돌면서 추가
			cycled[cnt++] = i;
		}
	}

	finished[node] = true;
}
