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

#define MAX 11
#define INF 1e9

using namespace std;

int map[129][129];

int white =  0, blue = 0;

void check(int x1, int y1, int x2, int y2){
    int a = map[x1][y1];
    
    for(int i = x1; i < x2; i++){
        for(int j = y1; j < y2; j++){
            if(a != map[i][j]){
                a = 2;
            }
            
            if(a == 2){
                check(x1, y1, (x1 + x2)/2, (y1 + y2)/2);
                check((x1 + x2)/2, (y1 + y2)/2, x2, y2);
                check(x1, (y1 + y2)/2, (x1 + x2)/2, y2);
                check((x1 + x2)/2, y1, x2, (y1 + y2)/2);
                return;
            }
        }
    }
    
    if(a == 0){
        white++;
    }else if(a == 1){
        blue++;
    }
    
    return;
}

int main(){
    
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    
    check(0,0,n,n);
    
    cout << white << "\n";
    cout << blue;
    
}
