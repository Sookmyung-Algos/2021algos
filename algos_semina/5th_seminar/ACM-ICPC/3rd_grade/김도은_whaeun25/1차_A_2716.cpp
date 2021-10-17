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

int main(){
    
    int testcase;
    
    cin >> testcase;
    
    string str;
    
    cin.get();
        
    for(int t = 0; t < testcase; t++){
        long long answer = 1;
        int depth = 0;
        
        
        stack<char> monkey;
        
        getline(cin, str);
        
        for(int i = 0; i < str.length(); i++){
            if(str[i] == '['){
                monkey.push('[');
                depth = max(depth, (int)monkey.size());
            }
            else{
                monkey.pop();
            }
        }
        
        for(int i = 0; i < depth; i++){
            answer *= 2;
        }
        
        cout << answer << "\n";
        
    }
    
}
