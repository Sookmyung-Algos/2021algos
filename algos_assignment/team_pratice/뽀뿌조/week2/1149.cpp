#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][3];
int dp[1001][3];

int main() {
  int n, ans;

  cin>>n;

  for(int i = 0; i<n; i++){
    for(int j = 0; j < 3; j++){
      cin>>arr[i][j];
    }
  }
  //0번째 집을 각각 RGB로 색칠했을 때의 값
  dp[0][0] = arr[0][0];
  dp[0][1] = arr[0][1];
  dp[0][2] = arr[0][2];

  for(int i = 1; i<n; i++){
    dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
    dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
    dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
  }


  ans = min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

  cout<<ans;

}
