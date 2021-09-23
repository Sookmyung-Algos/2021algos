#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num[5];
    int n = 1;

    for(int i = 0; i < 5; i++){
        cin >> num[i];
    }

    while(1){
        int count = 0;
        for(int i=0; i<5; i++){
            if(n >= num[i] && n % num[i] == 0){
                count++;
            }
        }
        if(count >= 3){
            cout << n;
            break;
        }
        n++; 
    }  
}
