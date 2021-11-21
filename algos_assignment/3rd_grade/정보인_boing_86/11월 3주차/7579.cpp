#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int sum = 0;
int M[101];
int C[101];
int dp[101][10001];

int main() {
	cin>>n>>m;
	for(int i = 1; i<=n; i++){
		cin>>M[i];
	}
	for(int i = 1; i<=n; i++){
		cin>>C[i];
		sum+=C[i];
	}

	for(int i = 1; i<=n; i++){
		for(int j = 0; j<=sum; j++){
			if(j - C[i] >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j-C[i]] + M[i]);
			}
			dp[i][j] = max(dp[i][j], dp[i-1][j]);
		}
	}

	for(int i = 0; i<=sum; i++){
			if(dp[n][i] >= m){
				cout<<i;
				break;
			}
	}

} 
