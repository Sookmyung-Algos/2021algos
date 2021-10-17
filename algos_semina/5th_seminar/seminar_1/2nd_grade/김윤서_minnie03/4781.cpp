#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
double d;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> d;
	m = d * 100; // double 형의 돈을 int 형으로 변환

	while (!(n == 0 && m == 0)) {
		int dp[10001] = { 0, };
		pair<int, int> v[5001]; // 가격, 칼로리 저장 pair

		for (int i = 1; i <= n; i++) { // n개의 사탕만큼 반복
			double temp;
			cin >> v[i].second >> temp; // 칼로리와 가격 입력
			v[i].first = temp * 100; //  가격을 int 형으로 변환
		}
		sort(v + 1, v + n + 1); // v 오름차순 정렬

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (i - v[i].first <= 0) break;
				dp[i] = max(dp[i], dp[i - v[j].first] + v[j].second); // 칼로리의 최대값 저장
			}
		}
		cout << dp[m] << endl;
		
		// 입력한 가격과 칼로리 모두가 0이 아닐때까지 반복하기 위해 한번 더 입력
		cin >> n >> d;
		m = d * 100;
	}

	return 0;
}
