#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<queue>
#include<vector>

using namespace std;

long long ice[4000040] = {0, };

int main(){
    int n, k;
    
    cin >>n >>k;
    
    for(int i = 0; i< n; i++){
        int g, pos;
        
        cin >> g >> pos;
        
        ice[pos] = g;
    }
    
    long long max = 0;
    long long sum = 0;
    
    for(int i =0; i <= 2 * k; i++){
        sum += ice[i];
    }
    max = sum;
    
    //cout << sum <<"\n";
    
    for(int start = 2 * k; start <=1000000; start++){
        //cout << "ice start" << ice[start] << "ice first"<< ice[start-(2*k)]<<"\n";
        sum = sum - ice[start - (2 * k)] + ice[start+1];
        //cout << sum << "\n";
        if(sum > max){
            max = sum;
        }
    }
    
    cout << max;
    
}
