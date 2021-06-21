#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, m;
vector<int> a[1001];
bool mark[1001];

void dfs(int x) {
	int next;
	mark[x] = true;
	
	for (int i = 0; i < a[x].size(); i++) {
		next = a[x][i];
		if (!mark[next])
			dfs(next);
	}
}

int main()
{
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int u, v;

		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	int count = 0;
	for (int i = 1; i <= n; i++) {
		if (!mark[i]) {
			dfs(i);
			count++;
		}
	}
	cout << count;
}
