#include <iostream>
using namespace std;
int a[200001], cnt[200001];
int main() {

    int n, k, max = 0, front = 0, back = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (; back < n; back++) {
        cnt[a[back]]++;
        if (cnt[a[back]] > k) {
            while (a[front] != a[back])
                cnt[a[front++]]--;
            cnt[a[front]]--;
            front++;
        }
        else {
            if (back - front + 1 > max)
                max = back - front + 1;
        }
    }
    cout << max << '\n';
}
