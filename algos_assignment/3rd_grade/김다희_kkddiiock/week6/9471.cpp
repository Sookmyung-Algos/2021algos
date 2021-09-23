#include <iostream>
#include <vector>
using namespace std;
int n,m,ans;

int main(void) {
	int p;
	cin >> p;
	while (p--) {
		cin >>n>> m;
		vector<int>dp;
		dp.push_back(0); dp.push_back(1); dp.push_back(1);
		int i = 3;
		while (1) {
			dp.push_back((dp[i - 1] + dp[i - 2]) % m);
			if (dp[i] == 1 && dp[i - 1] == 0) {
				ans = i - 1;
				break;
			}
			i++;
		}
		cout << n << " " << ans<< endl;
	}
	return 0;
}
