//코드 참고 https://debuglog.tistory.com/78

#include <iostream>
using namespace std;

int main() {

	int i, j, n, k;
	int dp[10001] = { 0, }; //경우의 수 배열

	cin >> n >> k;

	int coin[101]; //동전 배열

	for (i = 0; i < n; i++) { //동전 입력
		cin >> coin[i];
	}

	dp[0] = 1;
	for (i = 0; i < n; i++) { //첫번째 동전에서 n번째 동전까지
		for (j = coin[i]; j <= k; j++) { //각 k값마다 가능한 경우의 수 찾기
			if (j - coin[i] >= 0) { 
				dp[j] += dp[j - coin[i]]; //경우의 수 배열에 각 loop마다 동전의 경우의 수 중첩하여 저장
			}
		}
	} 

	cout << dp[k];
	return 0;
}
