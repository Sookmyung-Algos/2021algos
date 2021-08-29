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

vector<pair<int, int>>cal;
int sum[380];

int answer = 0;

bool cmp(const pair<int, int>& a, const pair<int, int>& b){
    if (a.first == b.first) {
        return a.second > b.second;
    }
    
    return a.first < b.second;
}

int main(){
    int n, h = 0, len = 0;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int s, e;
        
        cin >> s >> e;
        
        cal.push_back({s, e});
        sum[s]++;
        sum[e+1]--;
    }
    
    sort(cal.begin(), cal.end(), cmp);
    
    for(int i = 1; i <= 366; i++){
        sum[i]+= sum[i-1];
        
        if(sum[i] == 0){
            if(len == 0){
                continue;
            }
            
            answer += len * h;
            
            len = 0;
            h = 0;
        }
        else{
            if(len == 0){
                len = 1;
                h = sum[i];
            }
            else{
                len++;
                h = max(h, sum[i]);
            }
        }
    }
    
    cout << answer;
}
