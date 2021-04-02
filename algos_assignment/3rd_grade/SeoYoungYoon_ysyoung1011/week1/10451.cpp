#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int v[1001];
bool visit[1001] = { false, }, finish = false;
int cnt = 0;

void dfs(int x) {
	visit[x] = true;
	int next = v[x];
	//cout << "x: " << x << " next: " << next << endl;
	if (visit[next] == false) {
		visit[next] = true;
		dfs(next);
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		memset(v, 0, sizeof(v));
		memset(visit, false, sizeof(visit));
		cnt = 0; finish = false;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int k;
			cin >> k;
			v[i] = k;
		}
		for (int i = 1; i <= n; i++) {
			if (visit[i] == false) {
				dfs(i);
				cnt++;
			}
		}
		cout << cnt << endl;
	}
}
