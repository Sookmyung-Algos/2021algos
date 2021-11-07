#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> num;

int main(){
    
    int n, k;
    
    cin >> n >> k;
    
    int sum = 0;
    
    for(int i = 1; i <= k; i++){
        num.push_back(i);
        sum += i;
    }
    
    if(sum > n){
        cout << -1;
    }
    else if(sum == n){
        cout << num[k-1] - num[0];
    }
    else if(sum < n){
        
        int diff = n - sum;
        int index = k-1;
        
        while(diff > 0){
            
            num[index]++;
            
            diff--;
            index--;
            
            if(index == -1){
                index = k-1;
            }
            
            if(diff == 0){
                break;
            }
        }
        
        cout << num[k-1] - num[0];
    }
}
