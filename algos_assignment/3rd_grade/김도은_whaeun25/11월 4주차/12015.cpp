#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>

#define MAX 100010

using namespace std;

vector <int> v;

int main() {

    int n, cnt = 1;

    cin >> n;
    
    int a;
    
    cin >> a;
    
    v.push_back(a);

    for (int i = 1; i < n; i++) {
        int a;
        
        cin >> a;
        
        if (a > v.back()) {
            v.push_back(a);
            cnt++;
        }
        else {
            vector<int>::iterator low = lower_bound(v.begin(), v.end(), a);
            *low = a;
        }
    }
    
    cout << cnt;
}
