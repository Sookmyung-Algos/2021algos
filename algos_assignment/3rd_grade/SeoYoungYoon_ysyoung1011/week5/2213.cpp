#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001][2] = { 0, };
vector <int> v[10001], result;
int w[10001] = { 0, };

void dpDfs(int x, int parent) {
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (next == parent) continue;
		dpDfs(next, x);
	}
	dp[x][0] = 0;
	dp[x][1] = w[x];
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		dp[x][0] += max(dp[next][0], dp[next][1]);
		dp[x][1] += dp[next][0];
	}
}

void ans(int node, bool include, int parent) {
	if (include) {
		result.push_back(node);
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i];
			if (next == parent) continue;
			ans(next, false, node);
		}
	}
	else {
		for (int i = 0; i < v[node].size(); i++) {
			int next = v[node][i];
			if (next == parent)continue;
			if (dp[next][0] < dp[next][1]) {
				//자식을 포함 하는 것이 더 크면
				ans(next, true, node);
			}
			else{
				ans(next,false,node);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> w[i];
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dpDfs(1,0);
	if (dp[1][0] < dp[1][1]) ans(1, true, 0);
	else ans(1, false, 0);
	sort(result.begin(), result.end());
	cout << max(dp[1][0], dp[1][1]) << '\n';
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << ' ';
	return 0;
}
