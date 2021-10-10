#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int N;
int num[101];
int visit[101];
vector<int> cycle;

void dfs(int start, int cur) {
	if (visit[cur] == 0) {
		visit[cur] = start;
		dfs(start, num[cur]);
	}
	else if (cur == start) {
		cycle.push_back(start);
		return;
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> num[i];

	for (int i = 1; i <= N; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i, i);
	}

	cout << cycle.size() << "\n";
	for (int i = 0; i < cycle.size(); i++) {
		cout << cycle[i] << "\n";
	}
}
