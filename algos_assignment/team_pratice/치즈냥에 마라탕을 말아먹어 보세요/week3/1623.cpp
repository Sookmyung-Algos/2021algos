#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
long long int dp[200001][2] = { 0, }, w[200001] = { 0, }, n;
vector<int>v[200001], res;
void dfs(int now) {
	dp[now][1]= w[now];
	dp[now][0]= 0;
	for (int i = 0; i < v[now].size(); i++) {
		dfs(v[now][i]);
		dp[now][1] +=dp[v[now][i]][0];
		dp[now][0] += max(dp[v[now][i]][0], dp[v[now][i]][1]);
	}
}
void trace(int now, int isinclude, int parent) {
	if (isinclude) {
		res.push_back(now);
		for (int i = 0; i < v[now].size(); i++) {
			trace(v[now][i], 0, now);
		}
	}
	else {
		for (int i = 0; i < v[now].size(); i++) {
			if (dp[v[now][i]][0] < dp[v[now][i]][1]) {
				trace(v[now][i], 1, now);
			}
			else {
				trace(v[now][i], 0, now);
			}
		}
	}
}
int main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &w[i]);
	for (int i = 2, a; i < n + 1; i++) {
		cin >> a;
		v[a].push_back(i);
	}
	dfs(1);
	printf("%lld %lld\n", dp[1][1], dp[1][0]);
	trace(1, 1, 0);
	sort(res.begin(), res.end());
	for (int i = 0; i < (int)res.size(); i++)
		printf("%d ", res[i]);
	printf("-1\n");
	res.clear();
	trace(1, 0, 0);
	sort(res.begin(), res.end());
	for (int i = 0; i < (int)res.size(); i++)
		printf("%d ", res[i]);
	printf("-1\n");
	return 0;
}
