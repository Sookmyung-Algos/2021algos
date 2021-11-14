#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

#define MAX 1000000000

using namespace std;

vector<long long> city;
vector<long long> dist;

int main(){
    
    long long n;
    long long answer = 0;
    
    cin >> n;
    
    for(int i = 0; i < n - 1; i++){
        long long a;
        
        cin >> a;
        
        dist.push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        long long a;
        
        cin >> a;
        
        city.push_back(a);
    }
    
    long long check = MAX;
    
    for(int i = 0; i < n-1; i++){
        if(city[i] < check){
            check = city[i];
        }
        answer += check * dist[i];
    }
    
    cout << answer;
    
}
