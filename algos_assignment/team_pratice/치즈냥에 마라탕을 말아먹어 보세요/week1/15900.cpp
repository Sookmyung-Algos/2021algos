#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool check[500001] = { 0, };
vector<int>graph[500001];
int cnt = 0;

void dfs(int start, int depth) {
	check[start] = true;

	if (start != 1 && graph[start].size() == 1) {//리프노드
		if (depth % 2 == 1)cnt++;//홀수면 증가
		return;
	}

	for (int i = 0; i < graph[start].size(); i++) {
		int next = graph[start][i];
		// 방문하지 않았다면
		if (check[next] == false) {
			// 재귀함수를 호출한다.
			dfs(next, depth + 1);
			check[start] = false;
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int a, b;
	string ans = "";

	cin >> N;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b;
		graph[b].push_back(a);
		graph[a].push_back(b);
	}
	dfs(1, 0);
	ans = (cnt % 2 == 1) ? "Yes" : "No";
	cout << ans << endl;
	return 0;
}
