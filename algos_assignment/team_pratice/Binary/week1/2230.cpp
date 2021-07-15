#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(int a, int b) {
    return a > b;
}
int main() {
    int n, m;
    int temp;
    vector<int> a;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end(), comp);
    
    int l = 0, r = 0, result = 2000000000;
    while (l < n && r < n && l <= r) {
        int dtemp = a[l] - a[r];
        if (dtemp >= m) {
            result = min(result, dtemp);
            l++;
        }
        else r++;
    }
    cout << result;
    return 0;
}
