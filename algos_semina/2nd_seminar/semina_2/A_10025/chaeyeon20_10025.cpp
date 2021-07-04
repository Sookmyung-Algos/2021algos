#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long ice[1000002];
long long d[1000002];
int main() {
  
    long long n, k, g, x;
    long long arr = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> g >> x;
        ice[x] = g;
    }
    d[0] = ice[0];
    for (int i = 1; i <= 1000000; i++)
    {
        d[i] = d[i - 1] + ice[i];
    }
    if (k <= 1000000)
    {
        for (int i = 0; i <= 1000000; i++)
        {
            
            if (i + k <= 1000000 && i - k >= 1)
                arr = max(arr, d[i + k] - d[i - k - 1]);
        }
        cout << arr << '\n';
    }
    else
        cout << d[1000000] << '\n';
}
