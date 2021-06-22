#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int parent[100001];
bool dvisit[100001];
vector <int> v[100001];
void dfs(int start) {
	dvisit[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		int next = v[start][i];
		if (dvisit[next] == false) {
			parent[next] = start;    //부모노드를 저장
			dfs(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, k;
		cin >> u >> k;
		v[u].push_back(k);
		v[k].push_back(u);
	}
	for (int z = 1; z < n + 1; z++)
		sort(v[z].begin(), v[z].end());
	dfs(1);     //어차피 1번 노드가 root이므로 미리
	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";
}
