#include <iostream>
using namespace std;
int main(){
    long long n, k, t,a,b;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        a = n * (n + 1) * 2;
        b = (n - k) * (n - k - 1) * 2;
        if (n > k)
            cout << a - b << '\n';
        else
            cout << a << '\n';
    }
    return 0;
}
