#include<iostream>
#include<cmath>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;

map<long long, long long> dp;

long long n, p, q, x, y;

long long solve(long long num){
    
    if(num == 0){
        return 1;
    }
    
    if(dp[num]){
        return dp[num];
    }
    
    return dp[num] = solve(num / p) + solve(num / q);
    
}

int main(){
    
    cin >> n >> p >> q;
    
    long long result = solve(n);
    
    cout << result;
}
