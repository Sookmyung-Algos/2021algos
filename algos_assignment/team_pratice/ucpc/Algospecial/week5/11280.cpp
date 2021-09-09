#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int op(int i) {
	if (i & 1) // 홀수
		return i - 1;
	return i + 1;
}

int set[20002];

vector<int> edge[2][20002];
bool visited[20002];
stack<int> st;

void dfs(int node) {
	visited[node] = true;
	for (auto i: edge[0][node]) {
		if (!visited[i])
			dfs(i);
	}
	st.push(node);
}

void re_dfs(int node, int num) {
	visited[node] = true;
	set[node] = num;
	for (auto i: edge[1][node]) {
		if (!visited[i]) {
			re_dfs(i, num);
		}
	}
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int i, j;
		scanf("%d%d", &i, &j);
		i = i < 0 ? -i * 2 + 1 : 2 * i;
		j = j < 0 ? -j * 2 + 1 : 2 * j; // 노드 번호 지정
		edge[0][op(i)].push_back(j);
		edge[0][op(j)].push_back(i); // not j -> i
		edge[1][j].push_back(op(i));
		edge[1][i].push_back(op(j));
	}
	for (int i = 2; i <= 2 * n + 1; ++i)
		if (!visited[i]) dfs(i);
	memset(visited, 0, sizeof(visited));
	int num = 0;
	while (!st.empty()) {
		++num;
		int cur = st.top(); st.pop();
		if (!visited[cur]) re_dfs(cur, num);
	}
	for (int i = 1; i <= n; ++i)
		if (set[2 * i] == set[2 * i + 1]) {
			printf("0");
			return 0;
		}
	printf("1");
	return 0;
}
