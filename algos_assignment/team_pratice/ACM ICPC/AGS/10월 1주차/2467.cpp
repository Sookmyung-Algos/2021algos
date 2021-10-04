#include <iostream>
using namespace std;
int liq[100002];
int main() {
    int n, front, back, resultFront, resultBack, closest = 2000000000;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> liq[i];
    }
    front = 0, back = n - 1;
    while (front < back) {
        if (liq[front] + liq[back] > 0) {
            if (liq[front] + liq[back] < closest) {
                closest = liq[front] + liq[back];
                resultFront = front;
                resultBack = back;
            }
            back--;
        }
        else if (liq[front] + liq[back] < 0) {
            if ((liq[front] + liq[back]) * -1 < closest) {
                closest = (liq[front] + liq[back]) * -1;
                resultFront = front;
                resultBack = back;
            }
            front++;
        }
        else {
            resultFront = front;
            resultBack = back;
            break;
        }
    }
    cout << liq[resultFront] << " " << liq[resultBack] << '\n';
}
