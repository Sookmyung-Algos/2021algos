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

vector<long long> num;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, k;
    
    cin >> n >> k;
    
    for(int i = 0; i < n; i++){
        long long a;
        
        cin >> a;
        
        num.push_back(a);
    }
    
    sort(num.begin(), num.end());
    
    long long max = 0;
    
    for(int i = 0; i < n-1; i++){
        long long sum = num[0] * (i + 1) + num[i+1] * (n- i - 1);
        
        if(sum > max){
            max = sum;
        }
        
    }
    
    int check = 0;
    
    if(k % max){
        check = 1;
    }
    
    cout << k /max + check;
    
}
