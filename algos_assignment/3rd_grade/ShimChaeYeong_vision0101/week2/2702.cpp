#include <iostream>
using namespace std; 

int gcd(int a, int b) { 
    int r; 
    while (b != 0) { 
        r = a % b; 
        a = b; 
        b = r; 
    } 
    return a; 
} 

    
int main() { 
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;
    int a, b;

    cin >> num;

    while(num--){
        cin >> a >> b; 
        cout << (a*b)/gcd(a, b)<< " "<< gcd(a, b) << "\n" ; 
    } 
    
}

