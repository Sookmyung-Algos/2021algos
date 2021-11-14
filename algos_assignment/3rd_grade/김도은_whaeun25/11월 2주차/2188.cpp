#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

#define MAX 210

using namespace std;
 
int dist[MAX];
int visited[MAX];

int answer = 0 ;

vector<int> cow[MAX];
 
int flow(int x) {
 
    for(int i = 0 ; i< cow[x].size() ; i++) {
        int y = cow[x][i];
 
        if(visited[y]) {
            continue;
        }
        
        visited[y] = 1 ;
 
        if(dist[y] == 0 || flow(dist[y]) ) {
            dist[y] = x ;
 
            return 1;
        }
    }
    
    return 0;
}
 
 
int main(){
    
    int n, m;
    
    cin >> n >> m;
 
    for(int i=1; i <= n ;i++) {
        int a;
        cin >> a;
        
        for(int j=1; j <= a; j++) {
            int b;
            cin >> b;
            
            cow[i].push_back(b);
        }
 
    }
  
    for(int i=1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
 
        if(flow(i)){
            answer++;
        }
    }
 
    cout << answer;
}
