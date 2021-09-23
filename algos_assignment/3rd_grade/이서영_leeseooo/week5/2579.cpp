#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<memory.h>
#include<tuple>
#include<queue>
using namespace std;
int dp[300][2]; // d[i][0]은 계단을 연속해서 밟지 않는 경우, d[i][1]은 연속해서 밟는경우
int st[300]; //계단 저장
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> st[i];
	}
	dp[0][0] = st[0]; //0번째 계단은 연속해서 밟을 수 없으므로 0번째 계단점수 저장
	dp[1][0] = st[1]; //1번째 계단 연속x => 한번에 두칸간거니까 1번째 계단점수 저장
	dp[1][1] = st[0] + st[1]; //1번째 계단 연속o => 아래 두 계단점수 저장
	for (int i = 2; i < n; i++) {
		dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + st[i];
		//dp[i][0]은 연속x이므로 i-2계단에서 얻을수있는 점수 중 큰 값 + 현재 계단점수
		dp[i][1] = dp[i - 1][0] + st[i];
		//dp[i][1]은 연속o이므로 이전 계단 + 현재계단 점수
		//연속3개 못밟으므로 dp[i-1][1] 선택불가능. dp[i-1][1]도 연속으로 올라온거기때문
	}
	cout << max(dp[n - 1][0], dp[n - 1][1]);
}
