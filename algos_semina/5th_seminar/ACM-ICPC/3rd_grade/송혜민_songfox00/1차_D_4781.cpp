#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

vector<pair<int, int>>candy;
int dp[10001] = { 0, };

int main() {
	int n;
	double m;

	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0.00)
			break;

		int money = (int)(m * 100+0.5); //실수를 정수로 바꿔줄 때 오차가 있을 수 있기 때문에 0.5를 더해줘야 함

		candy.clear();
		for (int i = 0; i < n; i++) {
			int a;
			double b;
			cin >> a >> b;
			candy.push_back({ a,(int)(b * 100 + 0.5) });
		}

		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++) {
			for (int j = candy[i].second; j <= money; j++) {	
				dp[j] = max(dp[j], dp[j - candy[i].second] + candy[i].first);	//현재 칼로리합과 돈을 j원 소비했을 경우 가질 수 있는 최대 칼로리
			}
		}
		cout << dp[money] << '\n';
	}
	return 0;
}