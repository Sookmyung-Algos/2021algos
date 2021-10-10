#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int gcd(long long int a, long long int b) {
    while(b != 0) {
        long long int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long int lcm(long long int a, long long int b) {
    return a * b / gcd(a, b);
}

int main(){
    int n;
    
    cin >> n;
    
    vector<pair<long long int, long long int>> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].second;
        
        v[i].first = 1;
    }
    
    long long int a = v[0].first, b = v[0].second;
    
    for (int i = 1; i < n; i++) {
        long long int lcmv = lcm(v[i].second, b);
        
        v[i].first = lcmv / v[i].second * v[i].first;
        
        a = lcmv / b * a + v[i].first;
        b = lcmv;
    }
    
    long long int gcdv = gcd(a, b);
    
    cout << b/gcdv << "/" << a/gcdv;
}
