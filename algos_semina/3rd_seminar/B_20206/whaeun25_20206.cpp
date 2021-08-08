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

int main(){
    int a, b, c;
    
    cin >> a >> b >> c;
    
    int x1, x2, y1, y2;
    
    int check1 = 0, check2 = 0;
    
    cin >> x1 >> x2 >> y1 >> y2;
    
    vector<pair<int, int>>coord;
    
    coord.push_back({x1, y1});
    coord.push_back({x1, y2});
    coord.push_back({x2, y1});
    coord.push_back({x2, y2});
    
    for(int i = 0; i < 4; i++){
        if(coord[i].first * a + coord[i].second * b + c <= 0){
            check1++;
        }
        if(coord[i].first * a + coord[i].second * b + c >= 0){
            check2++;
        }
    }
    
    if(check1 == 4 || check2 == 4){
        cout << "Lucky";
    }
    else{
        cout << "Poor";
    }
}
