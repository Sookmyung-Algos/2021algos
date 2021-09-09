#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, a;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int cnt=0, val;
    for (int i = 0; i < N; i++) {
        val = v[i]; 
        int l = 0, r = N - 1, sum;
        while (l < r) {
            sum = v[l] + v[r];
            if (sum == val) {
                if (l != i && r != i) {
                    cnt++;
                    break;
                }
                else if (l == i) l++;
                else if (r == i) r--;
            }
            else if (sum < val) l++;
            else r--;
        }
    }
    cout << cnt << "\n";
    return 0;
}
