#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n, x, cnt = 0;
    cin >> n;
    int arr[n];
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cin >> x;
    
    sort(arr, arr + n);
    
    int l = 0, r = n - 1;
    
    while (l < r) {
        if (arr[l] + arr[r] == x) {
            r--; cnt++;
        } else if (arr[l] + arr[r] < x) {
            l++;
        } else {
            r--;
        }
    }
    
    cout << cnt << '\n';
    return 0;
}
