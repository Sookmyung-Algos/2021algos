#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int w[101], v[101];
int dp[101][100001];//dp[n][m] n번째 물건을 확인할때 현재가방 무게는 m이고 v값을 넣어줄것
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {//무게 j까지 들수있는 가방 채우기
			if (w[i] <= j) {//현재 물건이 가방한계치보다 가볍다면
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]]+v[i]);
				//기존물건들로만 무게 j를 만드는경우 vs 기존물건들로만 무게 j-weight 만들고 현재물건 가져가는경우
			}
			else {//가방한계치보다 물건무게가 더 무겁다면 못 든다.
				dp[i][j] = dp[i - 1][j]; //기존에 넣은 물건으로만 j를 채운다.
			}
		}
	}
	cout << dp[n][k];
}
