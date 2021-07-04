#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;
bool visit[103];
vector <int> q[103];

int distance(pair<int, int> p1, pair<int, int> p2) {
	int d;
	d = abs(p1.first - p2.first) + abs(p1.second - p2.second);
	return d;
}

void dfs(int node) {
	visit[node] = true;

	for (int i = 0; i < q[node].size(); i++) {
		int next = q[node][i];
		if (visit[next] == false) {
			dfs(next);
		}
	}
}

int main() {
	int t, n;

	cin >> t;
	
	for (int i = 0; i < t; i++) {
		memset(visit, false, sizeof(visit));
		memset(q, 0, sizeof(q));
		cin >> n;

		pair<int, int> p[103];

		for (int j = 0; j < n+2; j++) {
			cin >> p[j].first >> p[j].second;
		}

		for (int j = 0; j < n + 2; j++) {
			for (int k = 0; k < n + 2; k++) {
				if (j == k) continue;
				else {
					int d;
					d = distance(p[j], p[k]);
					if (d <= 1000) {
						q[j].push_back(k);
						q[k].push_back(j);
					}

				}

			}

		}
		dfs(0);
			
		if (visit[n + 1]) {
			/*for (int a = 0; a < 5; a++) {
				cout << visit[a] << " ";
			}*/
			cout << "happy\n";
		}

		else {
			cout << "sad\n";
		}

		
	}
}
