#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

int ind[1001] = { 0, }, result[1001] = { 0, };
int d[1001];
int n, k, w, ans = 0;
vector<int> v[1001];
queue<int> q;

void init() {
	memset(ind, 0, sizeof(ind));
	memset(d, 0, sizeof(ind));
	memset(v, 0, sizeof(v));
	memset(result, 0, sizeof(result));
	n = 0; k = 0; w = 0;  ans = 0;
}

void topology() {
	for (int i = 1; i <= n; i++) {
		int node = q.front();
		q.pop();
		for (int j = 0; j < v[node].size(); j++) {
			int next = v[node][j];
			ind[next]--;
			result[next] = max(result[next], result[node] + d[next]);
			//cout << "next: " << next << "result :" << result[next] << endl;
			if (ind[next] == 0) {
				q.push(next);
			}
		}
	}
	cout << result[w] << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		init();
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> d[i];
			result[i] = d[i];
		}
		for (int i = 1; i <= k; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			ind[b]++;
		}
		cin >> w;
		for (int i = 1; i <= n; i++) {
			if (ind[i] == 0) q.push(i);
		}
		topology();
		
	}
}
