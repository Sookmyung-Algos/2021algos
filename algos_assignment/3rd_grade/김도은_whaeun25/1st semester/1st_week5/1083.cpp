#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int>num;

int main(){
    
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    
    int n, s;
    
    cin >> n;
    
    for(int i =0; i<n;i++){
        int a;
        
        cin >>a;
        
        num.push_back(a);
    }
    
    cin >> s;
    
    for(int i = 0; i < n; i++){
        if(s == 0){
            break;
        }
        
        int max = num[i];
        int max_index = i;
        
        for(int j = i+1; (j < n) && (j <= i + s); j++){
            if(max < num[j]){
                max = num[j];
                max_index = j;
            }
        }
        
        s -= (max_index - i);
        
        for(int k = max_index; k > i; k--){
            num[k] = num[k - 1];
        }
        
        num[i] = max;
    }
    
    for(int i = 0; i < n; i++){
        cout << num[i] << " ";
    }
    
}
