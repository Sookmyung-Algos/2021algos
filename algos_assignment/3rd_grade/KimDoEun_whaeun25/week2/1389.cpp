#include<iostream>
#include<algorithm>
#include<vector>;

using namespace std;

int kevin[110][110];
int n;

vector<pair<int, int>>result;

void floyd() {
	//중간
	for (int i = 1; i <= n; i++) {
		//시작
		for (int t = 1; t <= n; t++) {
			//도착
			for (int j = 1; j <= n; j++) {
				//관계 연결 작업
				kevin[t][j] = min(kevin[t][j], kevin[t][i] + kevin[i][j]);
			}
		}
	}
}

int main() {
	int m;

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				kevin[i][j] = 0;
				continue;
			}
			kevin[i][j] = 10000;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;

		kevin[a][b] = 1;
		kevin[b][a] = 1;
	}

	floyd();

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += kevin[i][j];
		}
		result.push_back(make_pair(sum, i));
	}

	sort(result.begin(), result.end());

	cout << result[0].second;

}
