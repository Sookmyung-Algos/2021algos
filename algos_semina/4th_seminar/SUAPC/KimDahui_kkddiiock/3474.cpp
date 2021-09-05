#include<iostream>
#include<cstdio>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int main() {
    int t, n, cnt;
    scanf("%d",&t);
    while (t--) {
        cnt = 0;
        scanf("%d",&n);
        for (int i = 5; i <= n; i *= 5) 
            cnt += (n / i);
        printf("%d\n", cnt);
    }
    return 0;
}
