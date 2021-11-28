#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int num; vector<int> dp;
	while (cin >> num) {
		dp.clear();

		for (int i = 0;i < num;i++) {
			int a;
			cin >> a;

			if (dp.empty() || dp.back()<a){
				dp.push_back(a);
			}
			else {
				int idx = lower_bound(dp.begin(), dp.end(), a) - dp.begin();
				dp[idx] = a;
			}
		}
		cout << dp.size() << "\n";
	}

	return 0;
}
