#include <iostream>
using namespace std;

int main() {
    int x, l = 64, cnt = 0;
    cin >> x;
    while (x > 0) {
        if (x < l) {
            l /= 2;
        }
        else {
            x -= l;
            cnt++;
        }
    }
    cout << cnt << endl;
}
