#include <iostream>
#include <cstring>
using namespace std;

int v[100001], cnt = 0;
bool visit[100001] = { false, }, finished[100001];

void init() {
	memset(v, 0, sizeof(v));
	memset(visit, false, sizeof(visit));
	memset(finished, false, sizeof(finished));
	cnt = 0;

}

void dfs(int node) {
	visit[node] = true;
	int next = v[node];
	if (!visit[next]) {
		dfs(next);
	}
	else if (!finished[next]) {
		cnt++;
		for (int i = v[node]; i != node; i = v[i]) {
			cnt++;
		}
	}
	finished[node] = true;
	return;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> v[i];
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) dfs(i);
		}
		cout << n - cnt << endl;
	}
}
