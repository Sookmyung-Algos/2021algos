#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(void) { 
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

	int tc;
	cin >> tc;

	ll memo[9 + 1][64 + 1] = {0};
	for(int i = 1; i < 64 + 1; i++) {
		for(int k = 9; 0 <= k; k--) {
			if(i == 1) {
				memo[k][i] = 1;
			} else if(k == 9) {
				memo[k][i] = memo[k][i - 1];
			} else {
				memo[k][i] = memo[k + 1][i] + memo[k][i - 1];
			}
		}
	}

	while(tc--) {
		int n;
		ll sum = 0;
		cin >> n;
		for(int i = 0; i < 10; i++) sum += memo[i][n];
		cout << sum << "\n";
	}

	return 0;
}
