#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    vector<pair<int, int>> arr;
    int now;
    int next;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.push_back(make_pair(tmp, i + 1));
    }
    now = 0;
    while (arr.empty() != true) {
        cout << arr[now].second;
        next = arr[now].first;
        if (next > 0) {
            next -= 1;
        }
        arr.erase(arr.begin() + now);
        now += next;
        n--;
        if (n <= 0) break;
        now = (now >= 0 ? now : n + now % n);
        now %= n;
        cout << " ";
    }
    return 0;
}
