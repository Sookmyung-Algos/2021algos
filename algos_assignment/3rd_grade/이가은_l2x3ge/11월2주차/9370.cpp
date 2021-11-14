#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define MAX 1e9
using namespace std;
void dijkstra(int s, int dis[]);
void init(int V);

int n, m, t, s, g, h, gtoh;
int sto[2021];
int gto[2021];
int hto[2021];
vector<pair<int, int>> adj[2021];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while (T--){
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		init(n);

		for (int i = 0;i < m;i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if ((a == g && b == h) || (a == h && b == g)) gtoh = c;
			adj[a].push_back({ b,c });
			adj[b].push_back({ a,c });
		}

		dijkstra(s, sto);
		dijkstra(g, gto);
		dijkstra(h, hto);

		vector<int>ans;
		for (int i = 0; i < t; i++) {
			int a;
			cin >> a;
			if (sto[g] + gtoh + hto[a] == sto[a]) {
				ans.push_back(a);
			}
			else if (sto[h] + gtoh + gto[a] == sto[a]) {
				ans.push_back(a);
			}
		}

		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}

void init(int V) {
	fill(sto, sto + V + 1, MAX);
	fill(gto, gto + V + 1, MAX);
	fill(hto, hto + V + 1, MAX);
	for (int i = 0;i <= n;i++)
		adj[i].clear();
}

void dijkstra(int s, int dis[]) {
	priority_queue<pair<int, int>> pq;//{cost, start}
	dis[s] = 0;
	pq.push({ 0,s });
	while (!pq.empty()) {
		int d = -pq.top().first; //cost
		int u = pq.top().second; //from정점
		pq.pop();

		if (d > dis[u]) //cost가 (시작~from)보다 더 크면 가지 않는다
			continue;
		for (int i = 0; i < adj[u].size();i++) {
			int v = adj[u][i].first; //to정점
			int c = adj[u][i].second; //(from~to cost)
			if (dis[v] > dis[u] + c) {
				dis[v] = dis[u] + c;
				pq.push({ -dis[v], v });
			}
		}
	}
}
