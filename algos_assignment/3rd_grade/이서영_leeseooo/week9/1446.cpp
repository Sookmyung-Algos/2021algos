#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<memory.h>
using namespace std;
int n, d;
vector<pair<int, int>>v[10001];
int dist[10001];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> d;
	for (int i = 1; i <= d; i++) {
		dist[i] = i;
	}
	for (int i = 0; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b - a <= c)continue;
		if (b > d)continue;
		v[a].push_back({ b,c });
	}
	int post = -1;
	for (int i = 0; i <= d; i++) {
		if (i == 0)post = -1;
		else post = dist[i - 1];
		dist[i] = min(dist[i], post + 1);//i까지 가는 데 드는 최소비용
		if (!v[i].empty()) {
			for (int j = 0; j < v[i].size(); j++) {
				int next = v[i][j].first;
				int cost = v[i][j].second;
				if (next > d)continue;
				if (dist[next] > dist[i] + cost) {
					dist[next] = dist[i] + cost;
				}
			}
		}
	}
	cout << dist[d];
}
