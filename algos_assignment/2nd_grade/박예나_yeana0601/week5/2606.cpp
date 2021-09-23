//https://guiyum.tistory.com/40 코드참고

#include<iostream>
#include<vector>
using namespace std;
vector<int> a[101]; // 인접 리스트
bool check[101];
int cnt = 0;

void DFS(int x) {
	check[x] = true;
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (!check[y]) {
		DFS(y);
			cnt++;
		}
	}
}
int main() {
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(false);
  
	int n, m; // n : 정점 개수, m : 간선 개수
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	} // edge 연결해줬음
	DFS(1);
	cout << cnt << '\n';
}
