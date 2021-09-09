#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

int dp[16][16];
int city[1 << 16][16];
int cost = INF;
int start = 0;

int n;

int solve(int visit, int node){
    
    visit |= (1 << node);
    
    if(visit == (1 << n) - 1){
        if(dp[node][0] > 0){
            return dp[node][0];
        }
        return INF;
    }
    
    if(city[visit][node] > 0){
        return city[visit][node];
    }
    
    city[visit][node] = INF;
    
    for(int i =0; i < n; i++){
        if((visit&(1 << i)) == 0 && dp[node][i] > 0){
            int sum = solve(visit, i) + dp[node][i];
            if(city[visit][node] > sum){
                city[visit][node] = sum;
            }
        }
    }
    
    return city[visit][node];
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    
    for(int i =0; i< n; i++){
        for(int j = 0; j < n; j++){
            int a;
            
            cin >> a;
            
            dp[i][j] = a;
        }
    }
    
    cost = solve(0, 0);
    
    cout << cost;
    
}
