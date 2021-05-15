#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector <int> p;
    for (int i=0;i<n;i++){
        int a;
        cin >> a;
        p.push_back(a);
    }
    sort(p.begin(),p.end());
    
    int sum=0;
    for (int i=0;i<n;i++){
        sum = sum+p[i]*(n-i);
    }
    cout << sum;
    return 0;
}
