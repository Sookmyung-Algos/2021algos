#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int node1, node2;
int c = 0;
int ind[32001] = { 0, };
int ans[32001];
vector <int> v[32001];
queue <int> q;

void fuct() {

	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}

	while(!q.empty()) {
		node1 = q.front();
		ans[c++] = q.front();
		q.pop();

		for (int j = 0; j < v[node1].size(); j++) {
			node2 = v[node1][j];
			ind[node2]--;

			if (ind[node2] == 0) {
				q.push(node2);
			}
		}
	}

}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		ind[b]++;
		v[a].push_back(b);
	}
	
	fuct();

	for (int l = 0; l < n; l++) {
		cout << ans[l] << " ";
	}
}
