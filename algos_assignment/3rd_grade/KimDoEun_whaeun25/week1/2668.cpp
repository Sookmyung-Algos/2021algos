#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>graph;
vector<int>visited;
vector<int>cycle;

int start;

void dfs(int index) {

	if (index == start && visited[index]) {
		int right = 0;
		int nextc = index;
		while (!(nextc == start && right)) {
			if (right == 0) {
				right = 1;
			}
			cycle.push_back(nextc);
			nextc = graph[nextc];
		}
	}
	else if (visited[index]) {
		return;
	}
	else {
		visited[index] = 1;
		int next = graph[index];
		dfs(next);
	}

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;

	cin >> n;

	graph.push_back(0);
	visited.push_back(1);

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		graph.push_back(a);
		visited.push_back(0);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			start = i;
			dfs(i);
			for (int j = 1; j <= n; j++) {
				visited[j] = 0;
			}
		}

	}

	sort(cycle.begin(), cycle.end());
	cycle.erase(unique(cycle.begin(), cycle.end()), cycle.end());

	cout << cycle.size() << "\n";

	for (int i = 0; i < cycle.size(); i++) {
		cout << cycle[i] << "\n";
	}

}
