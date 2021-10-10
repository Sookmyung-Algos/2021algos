#include<iostream>

using namespace std;

int main(void) {

	int testcase;
	
	long long dp[101] = { 1, 1, 1, 1, 2, 2, };

	cin >> testcase;

	for (int i = 6; i <= 100; i++){
		dp[i] = dp[i - 1] + dp[i - 5];
    }
    
	while (testcase--) {

		int n;
		
        cin >> n;
		
        cout << dp[n] << "\n";
	
	}

}
