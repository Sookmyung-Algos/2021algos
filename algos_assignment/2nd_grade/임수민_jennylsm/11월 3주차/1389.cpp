#include<bits/stdc++.h>
#define MAX 102
#define MAXN 1000000010
using namespace std;

int N, M;
int adj[MAX][MAX];

int main() {
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);
	cin >> N >> M;
	int a, b;

	for (int i = 1; i <= 101; i++) {
		for (int j = 1; j <= 101; j++) {
			if (i == j) adj[i][j] = 0;
			else adj[i][j] = MAXN;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		adj[a][b] = 1;
		adj[b][a] = 1;
	}
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	int min = MAXN;
	int idx = -2;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) sum += adj[i][j];
		if (min > sum) {
			min = sum;
			idx = i;
		}
	}
	cout << idx;
}
