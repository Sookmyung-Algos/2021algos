#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

vector<int> num;

int main(){
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        int a;
        
        cin >> a;
        
        num.push_back(a);
    }
    
    if(next_permutation(num.begin(), num.end())){
        for(int i = 0; i< n; i++){
            cout << num[i] << " ";
        }
    }
    else{
        cout << "-1";
    }
    
}
