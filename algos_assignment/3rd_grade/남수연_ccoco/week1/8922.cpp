#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        int cnt = 0;
        cin >> n;
        int arr[n];
        int duzzi[n];
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        for (int k = 0; k < 1000; k++) {
            cnt = 0;
            for (int j = 0; j < n; j++) {
                if (j == n - 1) {
                    duzzi[j] = abs(arr[j] - arr[0]);
                    break;
                }
                duzzi[j] = abs(arr[j] - arr[j + 1]);
            }
            for (int j = 0; j < n; j++) {
                arr[j] = duzzi[j];
                if (duzzi[j] == 0) cnt++;
            }
            if (cnt == n) {
                cout << "ZERO" << '\n';
                break;
            }
        }
        if (cnt != n) {
            cout << "LOOP" << '\n';
        }
    }
    return 0;
}
