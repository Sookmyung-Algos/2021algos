#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
using namespace std;

bool visited[102] = {false};
vector<int> edge[102];

void dfs(int node) {
	visited[node] = true;
	for (auto i: edge[node]) {
		if (!visited[i])
			dfs(i);
	}
}

int dist(pair<int,int> i, pair<int, int> j) {
	return abs(i.first - j.first) + abs(i.second - j.second);
}
#define MAX 102
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		for (int i = 0; i < MAX; i++)
			edge[i].clear();
		memset(visited, false, sizeof(visited));
		int n;
		vector<pair<int, int>> node;
		scanf("%d", &n);
		for (int i = 0; i < n + 2; ++i) {
			int x, y;
			scanf("%d%d", &x, &y);
			node.push_back({x, y});
		}
		for (int i = 0; i < n + 2; ++i)
			for (int j = i + 1; j < n + 2; ++j)
				if (dist(node[i], node[j]) <= 1000) {
					edge[i].push_back(j);
					edge[j].push_back(i);
				}
		dfs(0);
		if (visited[n + 1])
			printf("happy\n");
		else
			printf("sad\n");
	}
	return 0;
}
