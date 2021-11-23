#include<iostream>
#include<memory.h>
using namespace std;
int n;
int graph[101][101];
bool visit[101];
void dfs(int node) {
	for (int i = 0; i < n; i++) {
		if (graph[node][i] == 1 && !visit[i]) {
			visit[i] = true;//특정 노드 탐색 후 지나는 모든 노드 방문
			dfs(i);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i); //특정 노드 탐색
		for (int j = 0; j < n; j++) {
			if (visit[j]) {//특정 노드로 인해 거쳐간 인접노드 체크
				graph[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << graph[i][j] << " ";
		}
		cout << "\n";
	}
}
