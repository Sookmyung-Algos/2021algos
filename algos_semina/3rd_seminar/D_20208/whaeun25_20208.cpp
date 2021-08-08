#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cmath>

using namespace std;

int map[11][11];
int n, m, h;

int house_x, house_y;
int answer;

vector<pair<pair<int, int>, int>>milk;

void dfs(int x, int y, int cnt, int hp){
    
    int back = abs(x - house_x) + abs(y - house_y);
    
    if(cnt > answer && hp - back >= 0){
        answer = cnt;
    }
    
    if(hp <= 0){
        return;
    }
    
    for(int i = 0; i < milk.size(); i++){
        int d = abs(milk[i].first.first - x) + abs(milk[i].first.second - y);
        
        if(d <= hp && !milk[i].second){
            milk[i].second = 1;
            dfs(milk[i].first.first, milk[i].first.second, cnt + 1, hp - d + h);
            milk[i].second = 0;
        }
        
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    cin >> n >> m >> h;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
            
            if(map[i][j] == 1){
                house_x = j;
                house_y = i;
            }
            else if(map[i][j] == 2){
                milk.push_back({{j, i}, 0});
            }
        }
    }
    
    dfs(house_x, house_y, 0, m);
    
    cout << answer;
    
}
