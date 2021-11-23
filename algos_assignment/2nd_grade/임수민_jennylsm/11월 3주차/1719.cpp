#include<bits/stdc++.h>
using namespace std;
int house[202][202],n;

int FindFirst(int from, int to, int mid) {
	if (mid == from || mid == to) { return mid; }
	return FindFirst(from, mid, house[from][mid]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int m; cin >> n >> m; 
	int minTime[202][202];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j) minTime[i][j] = 0;
			else minTime[i][j] = 1e9;
		}
	}

	int a, b, time;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> time;
		minTime[a][b] = time;
		minTime[b][a] = time;
		house[a][b] = b;
		house[b][a] = a;
	}

	
	for (int i = 1; i <= n; i++) {
		for (int from = 1; from <= n; from++) {
			for (int to = 1; to <= n; to++) {
				if (minTime[from][to] > minTime[from][i] + minTime[i][to]) {
					minTime[from][to]=minTime[from][i] + minTime[i][to];
					house[from][to] = i;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (house[i][j] != i && house[i][j]!=j) {
				house[i][j]=FindFirst(i, j, house[i][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << house[i][j] << " ";
		}
		cout << "\n";
	}
}
