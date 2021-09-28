//AC
//BOJ 2156 포도주 시식
// https://www.acmicpc.net/problem/2156
#include <iostream>
using namespace std;
int main(){
	int n;
	int arr[10000];
	int dp[10000];
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	dp[0] = arr[0];
	dp[1] = max(arr[0]+arr[1], arr[1]);
	dp[2] = max(arr[0]+arr[1],max(arr[2],max(arr[0]+arr[2], arr[1]+arr[2])));
	int temp;
	for(int i=3; i<n; i++){
		dp[i] = max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
		if(dp[i]<dp[i-1])	dp[i] = dp[i-1];
		if(dp[i]<dp[i-2])	dp[i] = dp[i-2];
	}
	printf("%d",dp[n-1]);
	return 0;
}
