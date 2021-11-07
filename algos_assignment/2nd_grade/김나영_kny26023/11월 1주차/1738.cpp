#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define MAX 101

int n, m, u, v, w, INF = 987654321;
int parent[MAX];
int dist[MAX];
vector<int> rev[MAX];
vector<pair<pair<int, int>, int> > road;
queue<int> q;
bool cycle;
bool visit[MAX];

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < road.size(); j++) {
			int from = road[j].first.first;
			int to = road[j].first.second;
			int cost = road[j].second;
			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) {
				if (i == n && visit[from]) {
					cycle = true;
				}
				dist[to] = dist[from] + cost;
				parent[to] = from;
			}
		}
	}
}

void find_route(int s) {
	if (s == 1) {
		cout << s << " ";
		return;
	}
	find_route(parent[s]);
	cout << s << " ";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		road.push_back(make_pair(make_pair(u, v), -w));
		rev[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;
	parent[1] = 1;
	
	q.push(n);
	visit[n] = true;
	while (!q.empty()) {
		int cidx = q.front();
		q.pop();
		for (int i = 0; i < rev[cidx].size(); i++) {
			int next = rev[cidx][i];
			if (!visit[next]) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	solve();
	if (cycle) {
		cout << -1 << "\n";
		return 0;
	}
	find_route(n);
}
