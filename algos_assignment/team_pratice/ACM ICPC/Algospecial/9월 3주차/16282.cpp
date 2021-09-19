#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>


using namespace std;

int main(){
    
    long long n;
    int answer = 0;
    
    cin >> n;
    
    for(long long i = 0; i <= 60; i++){\
        
        long long ans = i + (i +1)*((long long)pow(2, (i+1)) - 1);
        
        if(n <= ans){
            answer = i;
            break;
        }
        
    }
    
    cout << answer;
    
}
