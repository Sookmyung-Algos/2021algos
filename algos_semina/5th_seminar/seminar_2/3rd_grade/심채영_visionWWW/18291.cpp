#include <iostream>
#include <cmath>
using namespace std;
int MOD = 1000000007;
int cross(int n)
{

  if(n==0)return 1;
  if(n%2==0){
    long ret = cross(n/2);
    return ret * ret % MOD;
  }
  else{
    return 2*cross(n-1)%MOD;
  }
}

int main()
{
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    int ret = 0; 
    if( n <= 2){
      ret = 1;
    }
    else{
      n -=2;
      ret = cross(n);
    }
    cout << ret << "\n";
  }
  return 0;
}
