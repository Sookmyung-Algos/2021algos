#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, t, profit;
int ans = 0;
vector<pair<int, int>>v;
void maxProfit(int day,int profit, int add) {
	if (day == n + 1) {
		ans = max(ans, profit);
		return;
	}
	else if (day > n + 1) {
		ans = max(ans, profit - add);
		return;
	}
	for (int i = day+ v[day - 1].first; i <= n + v[day - 1].first; i++) {
		maxProfit(i, profit + v[day - 1].second, v[day - 1].second);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> profit;
		v.push_back({ t,profit });
	}
	for (int i = 1; i <= n; i++) {
		maxProfit(i, 0, 0);
	}
	cout << ans;
}
