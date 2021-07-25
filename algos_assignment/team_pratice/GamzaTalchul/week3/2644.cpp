#include <iostream>
#include <algorithm>
#include <vector>
/*#include <deque>
deque <char> d;*/
using namespace std;
vector <int> v[101];
bool visit[101];
int ans = -1;

void dfs(int a, int b, int count) {
	visit[a] = true;
	if (a == b)
		ans = count;
	for (int i = 0; i < v[a].size(); i++) {
		int next = v[a][i];
		if (visit[next] == false)
			dfs(next, b, count + 1);
	}
}

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, x, y;
	cin >> n;
	cin >> a >> b;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(a, b, 0);
	cout << ans;
}
