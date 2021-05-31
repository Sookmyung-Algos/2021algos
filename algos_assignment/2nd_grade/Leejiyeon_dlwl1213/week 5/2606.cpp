#include<iostream>
#include<vector>

//연결된 애들끼리 감염되는데 1번을 통해서 바이러스에 걸리니까 DFS나 BFS를 반복문을 따로 할 필요 없이 1번에서 호출

using namespace std;

vector<int> a[101]; // 인접 리스트(컴퓨터 수)
bool check[101]; //인접 여부 저장
int cnt = 0;

void dfs(int x) { //dfs해주는 함수
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (!check[y]) {
			dfs(y);
			cnt++;
		}
	}
}

int main() {
	int n, m; // n : 노드 개수, m : 엣지 개수
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	} 
	dfs(1);
	cout << cnt << '\n';
  return 0;
}
