#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int arr[11][11];
    int n,k;
    cin >> n>>k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int b = 0; b < k; b++) {
            for (int j = 0; j < n; j++) {
                for (int a = 0; a < k; a++) {
                    cout << arr[i][j]<<' ';
                }
            }
            cout << "\n";
        }
    }
}
