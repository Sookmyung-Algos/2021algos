#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> dodo;

int int_size(int num){
    int count = 0;
    for(count = 0; num > 0; count++){
        num /= 10;
    }
    return count;
}

bool cmp(const int & a, const int & b){
    long long sum1 = 0, sum2 = 0;
    
    sum1 = a * pow(10, int_size(b)) + b;
    sum2 = b * pow(10, int_size(a)) + a;
    
    if(int_size(a) == 0 || int_size(b) == 0){
        //cout << "a: " << a << " b: " << b << "\n";
        return a > b;
    }
    
    return sum1 > sum2;
}

int main(){
    int n;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int a;
        
        cin >> a;
        
        dodo.push_back(a);
    }
    
    sort(dodo.begin(), dodo.end(), cmp);
    
    int count = 0;
    
    for(int i =0; i<n; i++){
        if(dodo[i] == 0){
            count++;
        }
    }
    
    if(count == n){
        cout << "0";
        exit(0);
    }
    
    for(int i =0; i<n; i++){
        cout << dodo[i];
    }
}

