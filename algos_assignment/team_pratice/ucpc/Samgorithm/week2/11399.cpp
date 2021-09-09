#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T,num;
    cin >> T;
    
    vector <int> v;
    for (int i=1;i<=T;i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    
    int sum=0;
    for (int i=1;i<=T;i++){
        int p = v.back();
        sum = sum + p*i;
        v.pop_back();
    }
    cout << sum;
    return 0;
}
