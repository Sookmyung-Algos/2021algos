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

#define MAX 1000010
#define INF 1e9
#define MOD 1e9+7

using namespace std;

vector<int>cube;
vector<int>graph[11];

int dist[404040];

int answer = -1;

int check(const vector<int> &v){
    int pos = 0;
    
    for(int i = 0;  i < v.size(); i++){
        pos = pos * 5 + v[i];
    }
    
    return pos;
}

int main(){
    int n, k;
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        int a;
        
        cin >> a;
        
        cube.push_back(a);
    }
    
    for(int i = 1; i <= k; i++){
        int num;
        
        cin >> num;
        
        for(int j = 1; j <= num; j++){
            int a;
            
            cin >> a;
            
            graph[i].push_back(a-1);
        }
    }
    
    memset(dist, -1, sizeof(dist));
    
    queue<vector<int>>q;
    
    q.push(cube);
    
    dist[check(cube)] = 0;
    
    while(q.size()){
        auto now = q.front();
        q.pop();
        
        int now_id = check(now);
        
        for(int i = 1; i <= k; i++){
            auto next = now;
            
            for(int j = 0; j < graph[i].size(); j++){
                next[graph[i][j]] += i;
            }
            
            for(int j = 0; j < graph[i].size(); j++){
                while(next[graph[i][j]] >= 5){
                    next[graph[i][j]] %= 5;
                }
            }
            
            int next_id = check(next);
            
            if(dist[next_id] != -1){
                continue;
            }
            
            dist[next_id] = dist[now_id] + 1;
            q.push(next);
        }
    }
    
    for(int i = 0; i < 5; i++){
        int now = 0;
        
        for(int j = 0; j < n; j++){
            now = now*5 + i;
        }
        
        if(dist[now] == -1){
            continue;
        }
        
        if(answer == -1 || answer > dist[now]){
            answer = dist[now];
        }
    }
    
    cout << answer;
    
}
