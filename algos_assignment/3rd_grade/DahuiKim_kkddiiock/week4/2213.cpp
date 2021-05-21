#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, w[10001], dp[10001][2];
vector<int>v[10001], res;
void dpDfs(int now, int parent);
void trace(int now, int isinclude, int parent);
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	for (int i = 0, a, b; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dpDfs(1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
	if (dp[1][0] < dp[1][1]) {
		trace(1, 1, 0);
	}
	else
		trace(1, 0, 0);
	sort(res.begin(), res.end());
	for (int i = 0; i < (int)res.size(); i++)
		cout << res[i] << " ";
	return 0;
}
void dpDfs(int now, int parent) {
	for (int i = 0; i < v[now].size(); i++) {
		if (v[now][i] == parent) continue;
		else dpDfs(v[now][i], now);
	}
	dp[now][0] = 0;
	dp[now][1] = w[now];
	for (int i = 0; i < v[now].size(); i++) {
		if (v[now][i] == parent) continue;
		dp[now][0] += max(dp[v[now][i]][0], dp[v[now][i]][1]);
		dp[now][1] += dp[v[now][i]][0];
	}
}
void trace(int now, int isinclude, int parent) {
	if (isinclude == 1) {
		res.push_back(now);
		for (int i = 0; i < v[now].size(); i++) {
			if (v[now][i] == parent)continue;
			trace(v[now][i], 0, now);
		}
	}
	else {
		for (int i = 0; i < v[now].size(); i++) {
			if (v[now][i] == parent)continue;
			if (dp[v[now][i]][0] < dp[v[now][i]][1])
				trace(v[now][i], 1, now);
			else trace(v[now][i], 0, now);
		}
	}
}
