#include<iostream>
#include<vector>

// dfs나 bfs로 그래프를 순회하고 나서 방문되지 않은 vertex가 있으면 끊어진 그래프 -> 새로운 dfs(bfs)가 몇 번 다시 시작됐는지만 찾아보면 됨

using namespace std;

vector<int> a[1001]; 
bool check[1001];

void dfs(int x) {
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (check[y] == false) {
			dfs(y);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	int cnt = 0; //새로운 dfs가 시작된 개수=연결 요소의 개수
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			cnt++; // 새로운 dfs가 시작될때마다 1씩 증가
			dfs(i);
		}
	}
	cout << cnt << endl;
  return 0;
}
