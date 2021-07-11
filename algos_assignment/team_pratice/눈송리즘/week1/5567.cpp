#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> graph[501];
queue<int> q;
bool visited[501] = { false, };
int time[501] = { 0, };

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	q.push(1);
	while (!q.empty()) {
		int node = q.front();
		visited[node] = true;
		q.pop();
		for (int k = 0;k < graph[node].size();k++) {
			int next = graph[node][k];
			if (visited[next] == false) {
				q.push(next);
				if(time[next]==0)
					time[next] = time[node] + 1;
			}
		}
	}
	int cnt = 0;
	for (int i = 1;i < n+1;i++) {
		if (time[i] == 1 || time[i] == 2) {
			cnt++;
		}
	}
	cout << cnt;
}
