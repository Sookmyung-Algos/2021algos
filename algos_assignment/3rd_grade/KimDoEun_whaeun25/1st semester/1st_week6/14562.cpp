#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int bfs(int a, int b){
    int cnt = 0;
    queue<pair<pair<int, int>, int>> q;
    
    if(a == b){
        return cnt;
    }
    
    q.push({{a, b}, cnt});
    
    while(!q.empty()){
        int x = q.front().first.first;
        //cout << "\n x: " << x << "\n";
        int y = q.front().first.second;
        int x_cnt = q.front().second;
        q.pop();
        
        if(x == y){
            return x_cnt;
        }
        else{
            if(2*x <= y+3){
                q.push({{2*x, y+3}, x_cnt+1});
            }
            //cout << "q size: " << q.size() << "\n";
            q.push({{x+1, y}, x_cnt + 1});
        }
    }
    
    return cnt;
}

int main(){
    
    int testcase;
    
    cin >> testcase;
    
    for(int t = 0; t < testcase; t++){
        int s, k;
        
        cin >> s >> k;
        
        int ans = bfs(s, k);
        
        cout << ans << "\n";
    }
    
}
