#include <iostream>
using namespace std;

int arr[4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;

    arr[0] = a * x1 + b * y1 + c,
    arr[1] = a * x1 + b * y2 + c,
    arr[2] = a * x2 + b * y1 + c,
    arr[3] = a * x2 + b * y2 + c;

    int m = 0, n = 0;
    for (int i = 0; i < 4; i++) {
        if (arr[i] <= 0) m++;
        if (arr[i] >= 0) n++;
    }
    
    if (m == 4 || n == 4) cout << "Lucky\n";
    else cout << "Poor\n";

    return 0;
}
