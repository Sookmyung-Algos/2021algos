#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
vector <pair<int, int>> v;
int a[9], n, m;
bool chk[9];

void dfs(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++)
			cout << a[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++) {
		a[k] = i;
		dfs(k + 1);
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	dfs(0);
}
