#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    
    int n;
    
    cin >> n;
    
    if((n % 5) % 2 == 0){
        cout << n / 5 + n % 5 / 2;
    }
    else if(n / 5 == 0){
        cout << "-1";
    }
    else{
        cout << n / 5 + (n % 5 + 5) / 2 - 1;
    }
    
}
