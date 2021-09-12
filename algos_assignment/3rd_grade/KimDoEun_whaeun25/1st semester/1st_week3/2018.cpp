#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n;
    int count =0;
    
    cin >> n;
    
    for(int i =1; i<=n; i++){
        int sum =0;
        
        for(int j=i; j<=n; j++){
            sum += j;
            if(sum >n){
                break;
            }
            else if(sum == n){
                count++;
                break;
            }
        }
    }
    cout << count;
}
