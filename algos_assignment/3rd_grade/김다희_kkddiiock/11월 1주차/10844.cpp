#include<iostream>
#include<cstring>
using namespace std;

int v[1001];
bool visited[1001] = { 0, };
bool finished[1001] = { 0, };
int cnt = 0;
void dfs(int n);
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
        int n;
		cin >> n;
		for (int j = 1; j <= n; j++) {
			cin >> v[j];
		}
		for (int j = 1; j <= n; j++) {
			if (!visited[j])dfs(j);
		}
		cout << cnt << "\n";
		cnt = 0;
		memset(v, 0, 1001);
		memset(visited, false, 1001);
		memset(finished, false, 1001);
	}
}
void dfs(int n) {//n은 시작 노드
	visited[n] = true;//방문표시
	int next = v[n];
	if (!visited[next])
		dfs(next);
	else if (!finished[next])cnt++;//사이클 발생
	finished[n] = true;
}
