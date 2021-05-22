#include <iostream>
#include <algorithm>
using namespace std;
int a[1000010];
int n, m;
int maxsnow = 0;
int dfs(int time, int cur, int size) {
	maxsnow = max(maxsnow, size);
	if (time == m || cur == n) {
		
		return maxsnow;
	}
	
	dfs(time + 1, cur + 1, size + a[cur + 1]);
	dfs(time + 1, cur + 2, size / 2 + a[cur + 2]);
	return maxsnow;
}

int main() {
	int ans;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ans = dfs(0, 0, 1);
	cout << ans;
}

