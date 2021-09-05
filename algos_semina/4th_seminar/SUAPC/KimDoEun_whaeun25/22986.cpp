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

using namespace std;

int main(){
    
    int testcase;
    
    cin >> testcase;
    
    for(int t = 0; t < testcase; t++){
        unsigned long long n, k, answer = 0;
        
        cin >> n >> k;
        
        if(n < k){
            k = n;
        }
        
        answer += (((2 * n * (k + 1) - (k * (k + 1)))) * 2);
        
        cout << answer << "\n";
    }
    
}
