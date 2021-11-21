#include<bits/stdc++.h>
using namespace std;
int arr[257][257], N, M, s, e, l, r;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> s >> e;
		if (arr[s][e] == -1 || arr[e][s] == 1) {
			cout << "-1";
			return 0;
		}
		arr[s][e] = 1;
		arr[e][s] = -1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				if (arr[i][j] != 0) {
					if ((arr[i][j] == arr[j][i]) || (arr[i][k] == 1 && arr[k][j] == 1 && (arr[i][j] == -1 || arr[j][i] == 1)) || (arr[i][k] == -1 && arr[k][j] == -1 && (arr[i][j] == 1 || arr[j][i] == -1))) {
						cout << "-1";
						return 0;
					}
				}
				if (arr[i][j] == 0) {
					if (arr[i][k] == arr[k][j]) {
						arr[i][j] = arr[i][k];
						arr[j][i] = -arr[i][j];
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		l = 1, r = N;
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1) r--;
			else if (arr[i][j] == -1) l++;
		}
		cout << l << " " << r << "\n";
	}
}
