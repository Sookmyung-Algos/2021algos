#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100001;

vector<int> tree[MAX];
bool visited[MAX];
int parent[MAX];

void find_parent(int node) {
	visited[node] = true;

	for (int i = 0; i < tree[node].size(); i++) {
		int next = tree[node][i];

		if (!visited[next]) {
			parent[next] = node;
			find_parent(next);
		}
	}
}

int main() {
	int n, node1, node2;
	cin >> n;

	for (int i = 1; i < n; i++) {
		cin >> node1 >> node2;
		tree[node1].push_back(node2);
		tree[node2].push_back(node1);
	}
	find_parent(1);

	for (int i = 2; i <= n; i++)
		cout << parent[i] << "\n";
 }
