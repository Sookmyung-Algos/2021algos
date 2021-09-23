#include <iostream>
#include<algorithm>
#include<cstring>
using namespace std;

void dfs(int node);
void init();
int cnt = 0;
int v[100001];
bool visited[100001];
bool finished[100001];

int main() {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int i = 1;i <= n;i++) {
			cin >> v[i];
		}
		for (int i = 1;i <= n;i++) {
			if (!visited[i]) dfs(i);
		}
		cout << n - cnt << "\n";

		init();

	}
}

void dfs(int node) {
	visited[node] = true;
	int next = v[node];
	if (!visited[next])
		dfs(next);
	else if (!finished[next]) {//사이클 발생
		cnt++;
		for (int i = next; i != node;i = v[i]) {
			cnt++;
		}
	}
	finished[node] = true;
}

void init() {
	cnt = 0;
	memset(v, 0, 100001);
	memset(visited, false, 100001);
	memset(finished, false, 100001);
}
