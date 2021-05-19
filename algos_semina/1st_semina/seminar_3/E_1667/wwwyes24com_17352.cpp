#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> bridge[300010];
bool visit[300010] = { 0, };

void bfs(int n) {
	queue<int> search;
	int cur, next;
	visit[n] = 1;
	search.push(n);
	while (!search.empty()) {
		cur = search.front();
		search.pop();
		//cout << cur << " ";
		for (int i = 0; i < bridge[cur].size(); i++) {
			next = bridge[cur][i];
			if (visit[next] == 0) {
				visit[next] = 1;
				search.push(next);
			}
		}
	}
}

int main() {
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
		cin >> a >> b;
		bridge[a].push_back(b);
		bridge[b].push_back(a);
	}

	//bfs로 탐색
	bfs(1);
	
	//cout << "result\n";
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			cout << 1 << " " << i;
			return 0;
		}
	}
}
