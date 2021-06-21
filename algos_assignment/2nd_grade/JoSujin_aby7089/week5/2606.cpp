#include <iostream>
#include <vector>
using namespace std;
bool visit[100];
vector <int> v[101];  //101로 설정해야 함.
int virus = 0;
void dfs(int start) {
	visit[start] = true;
	virus++;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];   //인접리스트
		if (visit[next] == false)
			dfs(next);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, k;
		cin >> u >> k;
		v[u].push_back(k);
		v[k].push_back(u);
	}
	dfs(1);
	cout << virus - 1;  //1번은 
}
