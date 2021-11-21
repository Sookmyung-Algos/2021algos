#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

vector<long long> milk;

int main(){
    
    int n;
    
    cin >> n;
    
    for(int i =0; i < n; i++){
        long long a;
        
        cin >> a;
        
        milk.push_back(a);
    }
    
    sort(milk.begin(), milk.end(), greater<>());
    
    long long sum = 0;
        
    for(int i = 0; i < n; i++){
        
        if(i%3 == 2){
            continue;
        }
        sum += milk[i];
    }
    
    cout << sum;
    
}
