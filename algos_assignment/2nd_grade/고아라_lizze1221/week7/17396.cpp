#include<iostream>
#include<queue>
#include<vector>
#include<utility>
using namespace std;

int N, M, a, b, c;
long long INF = 9223372036854775807;
long long dis[100001];

vector<pair<long long, long long> > vec[100001];
priority_queue<pair<long long, long long> > pq;
pair<long long, long long> p;
bool cango[100001] = { false };
bool visited[100001] = { false };

void solve() {
	for (int i = 0; i < vec[0].size(); i++) pq.push(make_pair(-vec[0][i].first, vec[0][i].second));
	while (!pq.empty()) {
		p = pq.top();
		pq.pop();
		if (!visited[p.second]) {
			visited[p.second] = true;
			for (int i = 0; i < vec[p.second].size(); i++) {
				if (dis[vec[p.second][i].second] > dis[p.second] + vec[p.second][i].first) {
					dis[vec[p.second][i].second] = dis[p.second] + vec[p.second][i].first;
					pq.push(make_pair(-dis[vec[p.second][i].second], vec[p.second][i].second));
				}
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a == 0) cango[i] = true;
	}
	cango[N - 1] = true;

	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		if (!cango[a] || !cango[b]) continue;
		vec[a].push_back(make_pair(c, b));
		vec[b].push_back(make_pair(c, a));
		if (a == 0) dis[b] = c;
		if (b == 0) dis[a] = c;
	}

	for (int i = 1; i < N; i++) {
		if (dis[i] == 0) dis[i] = INF;
	}
	solve();

	if (dis[N - 1] == INF)cout << "-1\n";
	else cout << dis[N - 1] << "\n";

}
