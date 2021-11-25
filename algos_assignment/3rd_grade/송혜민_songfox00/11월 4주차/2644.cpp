#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>v;
int num1, num2;
bool visit[101];
int res = 0;

void dfs(int s, int cnt) {
	if (s == num2)
		res = cnt;

	visit[s] = true;
	for (int i = 0; i < v[s].size(); i++) {
		int nxt = v[s][i];
		if (!visit[nxt])
			dfs(nxt, cnt + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n;

	cin >> num1 >> num2;

	cin >> m;
	v.resize(n + 1);

	for(int i=0;i<m;i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(num1, 0);
	if (res != 0)
		cout << res;
	else
		cout << -1;
	return 0;
}