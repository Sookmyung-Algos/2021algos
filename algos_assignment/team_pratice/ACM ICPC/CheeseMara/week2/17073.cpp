#include <iostream>
#include <vector>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main() {
    int u, v, n;
    double cnt = 0, w;
    cin >> n >> w;
    vector<int>arr(n+1, 0);
    for (int i = 0; i < n - 1; i++){
        scanf("%d %d", &u, &v);
        arr[u]++;
        arr[v]++;
    }
    for (int i = 2; i <= n; i++)
        if (arr[i] == 1) cnt++;
    printf("%.10f", w / cnt);
    return 0;
}
