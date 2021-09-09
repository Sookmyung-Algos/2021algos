#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[30001];
vector<pair<int,int>> candys;
bool visited[30001];
int candy[30001], dp[3001], k;
int child;

int dfs(int node) {
	++child;
	int ret = candy[node];
	visited[node] = true;
	for (auto i: edge[node]) {
		if (visited[i]) continue;
		ret += dfs(i);
	}
	return ret;
}

void solve() {
	for (int i = k; i >= candys[0].second; --i)
		dp[i] = candys[0].first;
	for (int i = 1; i < candys.size(); ++i)
		for (int j = k; j >= candys[i].second; --j)
			dp[j] = max(dp[j], dp[j - candys[i].second] + candys[i].first);
}

int main() {
	int n, m;
	scanf("%d%d%d", &n, &m, &k); --k; // k - 1까지 가능
	for (int i = 1; i <= n; ++i)
		scanf("%d", candy + i);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i <= n; ++i) {
		child = 0;
		if (visited[i]) continue;
		int tmp = dfs(i);
		candys.push_back({tmp, child});
	}
	solve();
	printf("%d", dp[k]);
	return 0;
}
