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

#define MOD 1000000007
#define INF 1e9

using namespace std;

vector<pair<int, pair<int, int>>> score;

int main(){
    int n;
    
    cin >> n;
    
    for(int i = 0; i<n; i++){
        int back_number;
        
        cin >> back_number;
        
        int a, b, c;
        
        cin >> a >> b >> c;
        
        score.push_back({a*b*c,{a+b+c, back_number}});
    }
    
    sort(score.begin(), score.end());
    
    for(int i = 0; i< 3; i++){
        cout << score[i].second.second << " ";
    }
    
}
