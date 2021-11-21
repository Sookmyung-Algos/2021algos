#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int w[5001];
int v[5001];
int dp[10010] = { 0, };

int main() {
	while (1) {
		memset(w, -1, sizeof(w));
		memset(v, -1, sizeof(v));
		memset(dp, 0, sizeof(dp));
		int n, k;
		float tmp;
		cin >> n >> tmp;
		k = (int)(tmp * 100 + 0.5);

		if (n == 0 && k == 0.00) break;
		int c; float p;
		for (int i = 1; i <= n; i++) {
			cin >> c >> p;
			v[i] = c;
			w[i] = (int)(p * 100 + 0.5);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = w[i]; j <= k; j++) {
				dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
			}
		}
		cout << dp[k] << endl;
	}
}
