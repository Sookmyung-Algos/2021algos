#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>

#define MAX 1005
#define MOD 1000000

using namespace std;

int n, money;
int check;

int visited[MAX];

vector<pair<char, int>> room;

vector<int> v[MAX];

void dfs(int node, int w){
    
    if(room[node].first == 'L' && room[node].second > money){
        money =  room[node].second;
    }
    
    if(room[node].first =='T'){
        if(money < room[node].second){
            return;
        }
        else{
            money -= room[node].second;
        }
    }
    
    if(node == n){
        check = 1;
        return;
    }
    
    visited[node] = 1;
    
    for(int i = 0; i < v[node].size(); i++){
        int next = v[node][i];
        
        if(visited[next] == 0){
            dfs(next, money);
        }
    }
    
    visited[node] = 0;
    
}

int main(){
    
    cin >> n;
    
    while(n != 0){
        
        for(int i = 0; i < MAX; i++){
            v[i].clear();
            visited[i] = 0;
        }
        
        room.clear();
        check = 0;
        
        room.push_back({0, 0});
        
        for(int i = 1; i <= n; i++){
            char a;
            int b, c;
            
            cin >> a >> b >> c;
            
            room.push_back({a, b});
            
            while( c!= 0){
                v[i].push_back(c);
                cin >> c;
            }
        }
        
        dfs(1, 0);
        
        if(check){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }
        
        cin >> n;
        
    }
    
    
}
