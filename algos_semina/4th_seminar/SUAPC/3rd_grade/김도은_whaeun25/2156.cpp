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
#include <map>

#define MAX 10010
#define INF 1e9
#define MOD 1e9+7

using namespace std;

vector<int> wine;
int dp[MAX];

int main(){
    
    int n;
    
    cin >> n;
    
    wine.push_back(0);
    
    for(int i = 0; i < n; i++){
        int a;
        
        cin >> a;
        
        wine.push_back(a);
    }
    
    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[1]+wine[2];
    
    for(int i = 3; i<= n; i++){
        dp[i] = max(dp[i-3]+wine[i-1]+wine[i], max(dp[i-2] + wine[i], dp[i-1]));
    }
    
    cout << dp[n];
    
}
