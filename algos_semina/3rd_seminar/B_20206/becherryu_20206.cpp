#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
int result[5];
int main() {

    pair <int, int>p[5];
    int a, b, c;
    int x1, x2, y1, y2;
    cin >> a >> b >> c;
    cin >> x1 >> x2 >> y1 >> y2;

    p[0] = { x1, y1 };
    p[1] = { x1, y2 };
    p[2] = { x2, y1 };
    p[3] = { x2, y2 };

    int x, y, res, zero = 0, sum = 0;
    for (int i = 0; i < 4; i++) {
        res = a * p[i].first + b * p[i].second + c;
        if (res > 0)
            result[i] = 1;
        else if (res < 0)
            result[i] = -1;

        if (result[i] == 0)
            zero = 1;
        sum += result[i];
    }
    if (zero == 1 && sum == 0)
        cout << "Poor" << '\n';
    else if (zero == 1 && sum != 0)
        cout << "Lucky" << '\n';

    else if (zero == 0 && (sum == 4 || sum == -4))
        cout << "Lucky" << '\n';
    else if (zero == 0)
        cout << "Poor" << '\n';
}
