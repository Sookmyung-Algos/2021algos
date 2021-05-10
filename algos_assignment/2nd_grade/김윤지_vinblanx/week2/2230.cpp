#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N, M;
	int dp[100001];
	int s = 0, e = 1;
	int ans = 2000000001;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> dp[i]; //수열 입력받기
	}
	sort(dp, dp + N); //정렬

	while (s <= e && e < N) {
		int dif = dp[e] - dp[s]; //수열의 차

		if (dif >= M || e == N) { //현재 차가 M 이상이거나 e가 끝지점일 때
			ans = min(ans, dif); //최솟값을 ans에 저장
			s++; //시작지점 증가
		}
		else if (dif < M) { //차가 M보다 작을 때
			e++; //끝지점 증가
		}
	}
	cout << ans;
}
