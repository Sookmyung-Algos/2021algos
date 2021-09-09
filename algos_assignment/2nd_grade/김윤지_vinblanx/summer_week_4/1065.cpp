#include <iostream>

using namespace std;

int check(int n){
    int cnt = 0, hund, ten, one;
    if (n < 100)
        return n;
    else{
        for(int i = 100; i <= n; i++){
            hund = i / 100;
            ten = (i % 100) / 10;
            one = (i % 100) % 10;
            if (hund - ten == ten - one)
            cnt++;
        }
        
        return 99 + cnt;
    }
}

int main(){
    int input = 0;
    cin >> input;
    cout << check(input) << "\n";
    
    return 0;
}
