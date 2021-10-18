#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;


int N;
int arr[11], A[11][11];
bool visited[11];

int dfs(int v, vector<int>& perm, int type) {
	int cnt = 1;
	visited[v] = true;

	for (int i = 1; i<=N; i++) {
		if (perm[i-1] == type && A[v][i] == 1 && visited[i] == false)
			cnt += dfs(i, perm, type); 
	}
	return cnt;
}

int main() {
// 지역구 수 N
// arr에 지역 인원 수 넣음
// A에 연결되는 지역구 넣음
	cin >> N;
	for (int i = 1; i<=N; i++)
		cin >> arr[i];

	for (int i = 1, n; i<=N; i++) {
		cin >> n;
		for (int j = 0, v; j<n; j++) {
			cin >> v;
			A[i][v] = 1;
		}
	}
	int ans = 987654321;
	for (int k = 1; k<= N-1; k++) {
		vector<int> perm(k, 0);
		for (int i=k+1; i<=N; i++)
			perm.push_back(1);

		while (next_permutation(perm.begin(), perm.end())) {
			int area0_idx = -1, area1_idx = -1;
			for (int i = 0; i<N; i++) {
				if (perm[i] == 0) area0_idx = i;
				else area1_idx = i;

				if (area0_idx != -1 && area1_idx != -1)
					break;
			}
			int a0_cnt, a1_cnt, res0, res1;
			a0_cnt = a1_cnt = res0 = res1 = 0;

			memset(visited, 0, sizeof(visited));
			a0_cnt = dfs(area0_idx+1, perm, 0);
			memset(visited, 0, sizeof(visited));
			a1_cnt = dfs(area1_idx+1, perm, 1);

			if (a0_cnt == k && a1_cnt == N-k) {
				for (int i=0; i<N; i++) {
					if (perm[i] == 0) res0 += arr[i+1];
					else res1+= arr[i+1];
				}

				int sub = abs(res0-res1);
				if (ans > sub)
					ans = sub;
			}
		} 
	}
	if (ans == 987654321)
		printf("%d", -1);
	else
		printf("%d", ans);
	return 0;
}
