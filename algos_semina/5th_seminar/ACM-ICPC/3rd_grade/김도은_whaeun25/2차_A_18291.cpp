#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <cstdio>
#include <set>

#define MOD 1000000007
#define INF 1e9

using namespace std;

long long answer;

long long calculate(long long x, long long y){
    if(y <= 0){
        return 1;
    }
    
    if(y % 2 == 1){
        return (x*calculate(x, y-1)) % MOD;
    }
    
    x = x * x % MOD;
    y = y / 2;
    
    return calculate(x, y) % MOD;
}

int main(){
    int testcase;
    
    cin >> testcase;
    
    for(int t = 0; t < testcase; t++){
        long long n;
        
        cin >> n;
        
        answer = calculate(2, n-2);
        
        cout << answer << "\n";
    }
    
}
