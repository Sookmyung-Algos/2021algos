#include <iostream>
using namespace std;

int dp[1001] = { 0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	dp[1] = 1;
	for (int i = 1; i <= n; i++) { //n개 만큼 반복
		int num;
		cin >> num;

		if (dp[i] == 0) { //i번째 칸에 올 수 있는 방법이 없다면 넘어감
			break;
		}

		for (int j = 1; j <= num; j++) { //1부터 num까지 모든 경우 탐색
			if (i + j > 1000) break; //맨 끝 칸을 벗어나면 넘어감

			if (dp[i + j] == 0 || dp[i + j] > dp[i] + 1) { //j만큼 이동한 칸의 dp값이 0이거나 이동하기 전의 dp보다 1이상 크다면
				dp[i + j] = dp[i] + 1; //현재 dp값에 1 더한 값을 저장함
			}
		}
	}

	if (dp[n] == 0) { //최종 n에 도착하는 방법이 없다면 
		cout << -1 << endl; //-1 출력후 종료
	}
	else { //도착하는 방법을 출력
		cout << dp[n] - 1 << endl; //마지막에 +1 한 상태로 반복문을 빠져나왔으므로 1 뺀 값을 출력
	}

	return 0;
}
