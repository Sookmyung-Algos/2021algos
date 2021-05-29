#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v[1000001];
int dp[10000001][2] = { 0, };

void dpDfs(int x, int parent) {

	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (next == parent) continue;
		dpDfs(next, x);
	}
	dp[x][0] = 0;
	dp[x][1] = 1;
	for (int i = 0; i < v[x].size(); i++) {
		int next = v[x][i];
		if (next == parent) continue;
		dp[x][0] += dp[next][1];
		dp[x][1] += min(dp[next][0], dp[next][1]);
	}
}

int main() {
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dpDfs(1, 0);
	cout << min(dp[1][0], dp[1][1]);
}
