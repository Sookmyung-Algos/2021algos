#include<iostream>
#include<algorithm>
#include<deque>
#include<vector>

using namespace std;

vector<vector<int>> edge;
vector<int> v;
vector<bool> visited;

void dfs(int node, int parent) {
	visited[node] = 1;

	for (int i = 0; i < edge[node].size(); i++) {

		if (edge[node][i] == parent) {
			continue;
		}

		dfs(edge[node][i], node);

	}
}

int main() {
	int n;

	cin >> n;

	visited.push_back(1);
	edge.push_back(v);

	for (int i = 1; i <= n; i++) {
		visited.push_back(0);
		edge.push_back(v);
	}

	for (int i = 1; i <= n-2; i++) {
		int a, b;

		cin >> a >> b;

		edge[a].push_back(b);
		edge[b].push_back(a);
	}

	dfs(1, -1);

	int a1 = 1, a2 = 0;

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			a2 = i;
			break;
		}
	}

	cout << a1 << " " << a2;

}
