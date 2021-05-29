#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> v[100001], result;
int dp[100001] = { 0, };
bool visit[100001] ;

int dpDfs(int x) {
	
	if (dp[x] != 0) return dp[x];
	int cnt = 1;
	visit[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (!visit[next]) {
			cnt += dpDfs(next);
		}
	}
	dp[x] = cnt;
	return cnt;
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	int n, r, q;
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	memset(visit, false, sizeof(visit));

	dp[r] = dpDfs(r);
	for (int i = 0; i < q; i++) {
		int k;
		cin >> k;
		cout << dp[k] << '\n';
	}
	return 0;
}
