#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[100001];
stack<int> st;
vector<int> edge[100001];

void dfs(int node) {
	visited[node] = true;
	for (auto i: edge[node]) {
		if (!visited[i])
			dfs(i);
	}
	st.push(node);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int v, e;
		scanf("%d%d", &v, &e);
		for (int i = 1; i <= v; ++i)
			edge[i].clear();
		while (e--) {
			int a, b;
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
		}
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= v; ++i)
			if (!visited[i]) dfs(i);
		memset(visited, 0, sizeof(visited));
		int num = 0;
		while (!st.empty()) {
			int node = st.top(); st.pop();
			if (!visited[node]) {
				++num;
				dfs(node);
			}
		}
		printf("%d\n", num);
	}
	return 0;
}
