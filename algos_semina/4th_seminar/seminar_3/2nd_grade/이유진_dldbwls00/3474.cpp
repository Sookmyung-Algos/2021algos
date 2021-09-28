#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;

    for (int i = 0; i < t; i++){
        int n;
        cin >> n;

        int a = 0, b = 0;
        for (int j = 2; j <= n; j *= 2) a += n / j;
        for (int j = 5; j <= n; j *= 5) b += n / j;
       
        cout << min(a, b) << "\n";
    }
    return 0;
}
