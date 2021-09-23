#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int t, n, k, w;
int ind[1001] = { 0, };
int time[1001] = { 0, };
int result[1001] = { 0, };
vector<int>v[1001];
void topology();
int main() {
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> time[i];
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			ind[y]++;
		}
		cin >> w;
		topology();
		memset(ind, 0, 1001);
		memset(time, 0, 1001);
		memset(result, 0, 1001);
		for (int i = 0; i < 1001; i++)v[i].clear();
	}
	return 0;
}

void topology() {
	queue<int>q;
	for (int i = 1; i <= n; i++) {
		if (ind[i] == 0)q.push(i);
		result[i] = time[i];
	}
	for (int i = 1; i <= n; i++) {
		int node = q.front();
		q.pop();
		for (int j = 0; j < v[node].size(); j++) {
			int next = v[node][j];
			result[next] = max(result[next], result[node] + time[next]);
			ind[next]--;
			if (ind[next] == 0)q.push(next);
		}
	}
	cout << result[w] << "\n";
}
