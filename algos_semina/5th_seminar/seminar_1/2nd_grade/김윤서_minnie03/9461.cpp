#include <iostream>
using namespace std;

int t, k;
long long dp[101] = { 0, };


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	// 처음 세개 dp값 1로 설정
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;

	// 4부터는 그 전 dp값 두개를 더한 값 저장
	for (int i = 4; i < 101; i++) {
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	cin >> t; // 테스트케이스 입력
	for (int i = 0; i < t; i++) {
		cin >> k;
		cout << dp[k] << endl; // 입력받은 k에 대한 dp값을 출력
	}

	return 0;
}
