#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
using namespace std;

int op(int i) {
	if (i & 1)
		return i - 1;
	return i + 1;
}

int set[200002];

vector<int> edge[2][200002];
bool visited[200002];
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
	int n, m, status[200002];
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &status[i]);
	vector<int> swtch[200002];
	for (int i = 1; i <= m; ++i) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int num;
			scanf("%d", &num);
			swtch[num].push_back(i); // num 방의 스위치 i
		}
	}
	for (int i = 1; i <= n; ++i) {
		int x = swtch[i][0] * 2, y = swtch[i][1] * 2;
		switch (status[i]) {
			case 1: // 열린 상태
				edge[0][x].push_back(y);
				edge[0][y].push_back(x);
				edge[0][op(x)].push_back(op(y));
				edge[0][op(y)].push_back(op(x));
				edge[1][y].push_back(x);
				edge[1][x].push_back(y);
				edge[1][op(y)].push_back(op(x));
				edge[1][op(x)].push_back(op(y));
				break;
			case 0: // 닫힌 상태
				edge[0][op(x)].push_back(y);
				edge[0][op(y)].push_back(x);
				edge[0][x].push_back(op(y));
				edge[0][y].push_back(op(x));
				edge[1][y].push_back(op(x));
				edge[1][x].push_back(op(y));
				edge[1][op(y)].push_back(x);
				edge[1][op(x)].push_back(y);
		}
	}
	for (int i = 2; i <= 2 * m + 1; ++i)
		if (!visited[i]) dfs(i);
	memset(visited, 0, sizeof(visited));
	int num = 0;
	while (!st.empty()) {
		++num;
		int cur = st.top(); st.pop();
		if (!visited[cur]) re_dfs(cur, num);
	}
	for (int i = 1; i <= m; ++i)
		if (set[2 * i] == set[2 * i + 1]) {
			printf("0");
			return 0;
		}
	printf("1");
	return 0;
}
