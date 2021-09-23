#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n, dp[1000001][2];
bool chk[1000001];
vector<int>v[1000001];

int dfs(int now, int isinclude) {
	int& result = dp[now][isinclude];
	if (result != -1)
		return result;
	chk[now] = true;
	result = isinclude;

	for (int next = 0; next < v[now].size(); next++) {
		if (chk[v[now][next]])
			continue;
		if (isinclude == 0)
			result += dfs(v[now][next], 1);
		else
			result += min(dfs(v[now][next], 0), dfs(v[now][next], 1));
	}
	chk[now] = false;
	return result;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	cout << min(dfs(1, 0), dfs(1, 1));

	return 0;
}
