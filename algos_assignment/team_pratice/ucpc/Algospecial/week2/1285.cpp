#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
#include <string>
#include <iterator>

#define INF 1e9

using namespace std;

int map[25][25];
int flip[25];

int min_t = INF;
int n;

void dfs(int node){
    if(node == n){
        int sum = 0;
        
        for(int i =0; i< n; i++){
            int cnt = 0;
            
            for(int j = 0; j< n; j++){
                if(map[j][i] != flip[j]){
                    cnt++;
                }
            }
            
            sum += min(cnt, n - cnt);
        }
        
        min_t = min(min_t, sum);
        return;
    }
    
    dfs(node + 1);
    flip[node] = 1;
    dfs(node+1);
    flip[node] = 0;
    
}

int main(){
    
    cin >> n;
    
    for(int i =0; i< n; i++){
        string str;
        
        cin >> str;
        
        for(int j =0; j< n; j++){
            
            int a = 0;
            
            if(str[j] == 'T'){
                a = 1;
            }
            
            map[i][j] = a;
        }
    }
    
    dfs(0);
    
    cout << min_t;
    
}
