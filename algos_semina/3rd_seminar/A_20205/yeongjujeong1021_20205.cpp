#include <iostream>
using namespace std;

int arr[111][111];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];

    for (int i = 0; i < n; i++) {
        for (int p = 0; p < m; p++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < m; k++)
                    cout << arr[i][j] << ' ';
            } cout << '\n';
        }
    }

    return 0;
}
