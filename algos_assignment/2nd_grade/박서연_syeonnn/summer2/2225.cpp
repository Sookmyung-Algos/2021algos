// 2225 합분해

#include<iostream>

using namespace std;


long long ksumn[201][201];	// 0부터 n까지의 정수 k개를 더해 합이 n이 되는 경우의 수

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k;

	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		ksumn[1][i] = 1;
		ksumn[2][i] = i+1;
	}

	for (int i = 3; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k <= j; k++) {
				ksumn[i][j] = (ksumn[i][j] + ksumn[i - 1][j - k]) % 1000000000;
			}	// i개로 j만들기 = i-1개로 (j,j-1,j-2,...,0) 만들기. 나머지 1개는 각각 0,1,2,...,j가 됨.
		}
	}

	cout << ksumn[k][n]<< '\n';

	return 0;
