#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m, arr[9];
bool visited[9];

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			arr[cnt] = i;
			dfs(cnt + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		memset(arr, 0, m + 1);
		memset(visited, false, n + 1);
		arr[0] = i;

		dfs(1);
	}
}
