#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
int dp[10001][2], w[10001] = { 0, }, n;
bool chk[10001] = { 0, };
vector<int>v[10001];
int dfs(int now, int isinclude) {
	int& res = dp[now][isinclude];//dp배열을 근본적으로 변경해주어야하기 때문에 참조형 변수
	if (res != -1)return res;
	chk[now] = true;//방문표시
	if (!isinclude) res = 0;
	else res = w[now];
	for (int next = 0; next < v[now].size(); next++) {
		if (chk[v[now][next]])continue;//부모노드, 무시
		if (isinclude) res += dfs(v[now][next], 0);
		else res += max(dfs(v[now][next], 0), dfs(v[now][next], 1));
	}
	chk[now] = false;
	return res;
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> w[i];
	for (int i = 0,a,b; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(dp, -1, sizeof(dp));
	dfs(1, 0);
	dfs(1, 1);
	cout << max(dp[1][0], dp[1][1]) << '\n';
	return 0;
}
