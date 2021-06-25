#include<iostream>
#include<algorithm>
 
using namespace std;
 
int main(){
    
    int testcase;
    
    cin >> testcase;
    
    for(int t = 0; t < testcase; t++){
        int n;
        
        cin >> n;
        
        if(n % 2 == 0){
            for(int i = 1; i <= n; i++){
                if(i % 2 == 0){
                    cout << i-1 << " ";
                }else{
                    cout << i + 1 << " ";
                }
            }
        }else{
            for(int i = 1; i <= n-3; i++){
                if(i % 2 == 0){
                    cout << i-1 << " ";
                }else{
                    cout << i + 1 << " ";
                }
            }
            cout << n << " " << n-2 << " " << n-1;
        }
        cout << "\n";
    }
}
