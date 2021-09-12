#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define M 1000000003
using namespace std;
int dp[1005][1005];  //dp[i][j]는 i개중에 j개를 선택하는 경우의 수 저장

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {  //기저조건
		dp[i][1] = i;   //i개 중 1개를 고르는 경우는 i
		dp[i][0] = 1;   //i개 중 하나도 안 고르는 경우는 1
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % M;
		}
	}
	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % M;  //선형이 아니라 원형이면 양쪽을 모두 신경써야 하므로 다음과 같이 나옴
}
