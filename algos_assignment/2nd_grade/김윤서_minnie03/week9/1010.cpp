#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m; //n과 m을 입력받음
		
		long long result = 1; //다리를 지을 수 있는 경우의 수를 1로 초기화함

		//m 콤비네이션 n 계산 방법
		int k = 1;
		for (int i = m; i > m - n; i--) {
			result *= i;
			result /= k++;
		}

		cout << result << endl; //경우의 수 출력
	}

	return 0;
}
