#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2e8;
int t;
int n, m;
int a[1000], b[1000];
vector<int> sumA, sumB;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> t;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        int sum = a[i];
        sumA.push_back(sum);
        for (int j = i + 1; j < n; j++) {
            sum += a[j];
            sumA.push_back(sum);
        }
    }

    for (int i = 0; i < m; i++) {
        int sum = b[i];
        sumB.push_back(sum);
        for (int j = i + 1; j < m; j++) {
            sum += b[j];
            sumB.push_back(sum);
        }
    }
    
    sort(sumB.begin(), sumB.end());

    long long ans = 0;
    for (auto item : sumA)
    {
        int diff = t - item;
        auto ub = upper_bound(sumB.begin(), sumB.end(), diff);
        auto lb = lower_bound(sumB.begin(), sumB.end(), diff);
        ans += (ub - lb);
    }
    cout << ans;

    return 0;
}
