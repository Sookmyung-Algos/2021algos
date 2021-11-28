#include<iostream>
#include<vector>
#include<queue>
#define max(a, b) (((a)>(b))?(a):(b))
using namespace std;

vector<pair<int, int>> v[1002];
int dist[1002];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1;i < n;i++) {
		int a, b, dis;
		cin >> a >> b >> dis;
		v[a].push_back({ b,dis });
		v[b].push_back({ a,dis });
	}
	for (int i = 0;i < m;i++) {
		fill(dist, dist + 1001, -1);
		int a, b;
		cin >> a >> b;

		queue<int>q;
		q.push(a);
		dist[a] = 0;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			for (int j = 0;j < v[node].size();j++) {
				int next = v[node][j].first;
				if (dist[next] == -1) {
					dist[next] = dist[node] + v[node][j].second;
					q.push(next);
				}
			} 
		}
		cout << dist[b] << "\n";
	}
}
