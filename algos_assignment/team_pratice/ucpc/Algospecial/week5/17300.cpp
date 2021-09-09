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

#define MAX 1010
#define INF 1e9
#define MOD 1e9+7

using namespace std;

int lock[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int num[10];
int visited[10];

vector<int> pattern;



int main(){
    int l;
    
    cin >> l;
    
    for(int i = 0; i < l; i++){
        int a;
        
        cin >> a;
        
        pattern.push_back(a);
        num[a]++;
    }
    
    if(l < 3){
        cout << "NO";
        return 0;
    }
    
    for(int i = 1; i <= 9 ; i++){
        if(num[i] > 1){
            cout << "NO";
            return 0;
        }
    }
    
    visited[pattern[0]] = 1;
    
    for(int i = 1; i < l; i++){
        int check = 1;
        /*
        int past_ga, past_se;
        int cur_ga, cur_se;
        int fu_ga, fu_se;
        */
        
        visited[pattern[i]] = 1;
        
        if(pattern[i-1] == 1 || pattern[i-1] == 3 || pattern[i-1] == 7 || pattern[i-1] == 9){
            if(pattern[i] == 1 || pattern[i] == 3 || pattern[i] == 7 || pattern[i] == 9){
                
                int past_ga, past_se;
                int cur_ga, cur_se;
                
                past_se = (pattern[i-1] - 1) / 3;
                past_ga = (pattern[i-1] - 1) - (past_se * 3);
                
                cur_se = (pattern[i] - 1) / 3;
                cur_ga = (pattern[i] - 1) - (cur_se * 3);
                
                int check_num = (past_se +cur_se)/2 *3 + (past_ga + cur_ga)/2;
                
                if(!visited[check_num + 1]){
                    check  = 0;
                }
            }
        }
        
        if(pattern[i -1] == 2 || pattern[i-1] == 8){
            if(pattern[i] == 2 || pattern[i] == 8){
                
                int past_ga, past_se;
                int cur_ga, cur_se;
                
                past_se = (pattern[i-1] - 1) / 3;
                past_ga = (pattern[i-1] - 1) - (past_se * 3);
                
                cur_se = (pattern[i] - 1) / 3;
                cur_ga = (pattern[i] - 1) - (cur_se * 3);
                
                int check_num = (past_se +cur_se)/2 *3 + (past_ga + cur_ga)/2;
                
                if(!visited[check_num + 1]){
                    check  = 0;
                }
            }
        }
        
        if(pattern[i -1] == 4 || pattern[i-1] == 6){
            if(pattern[i] == 4 || pattern[i] == 6){
                
                int past_ga, past_se;
                int cur_ga, cur_se;
                
                past_se = (pattern[i-1] - 1) / 3;
                past_ga = (pattern[i-1] - 1) - (past_se * 3);
                
                cur_se = (pattern[i] - 1) / 3;
                cur_ga = (pattern[i] - 1) - (cur_se * 3);
                
                int check_num = (past_se +cur_se)/2 *3 + (past_ga + cur_ga)/2;
                
                if(!visited[check_num + 1]){
                    check  = 0;
                }
            }
        }
        
        if(!check){
            cout << "NO";
            return 0;
        }
        
        /*
        past_se = pattern[i-1] / 3;
        past_ga = pattern[i-1] - (past_se * 3);
        
        cur_se = pattern[i] / 3;
        cur_ga = pattern[i] - (cur_se * 3);
        
        fu_se = pattern[i + 1] / 3;
        fu_ga = pattern[i + 1] - (fu_se * 3);
        
        if((cur_se != (past_se + fu_se)/2) && (cur_ga != (past_ga + past_se)/2)){
            cout << "NO";
            return 0;
        }
        */
    }
    
    cout << "YES";
    
}
