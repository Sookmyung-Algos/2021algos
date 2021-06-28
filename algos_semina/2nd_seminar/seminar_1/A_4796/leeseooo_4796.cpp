#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<algorithm>
using namespace std;
int L, P, V;
int main() {
	int P, L, V;
	int idx = 1;
	while (1) {
		cin >> L >> P >> V;
		if (!L && !P && !V) {
			break;
		}
		int ans = 0;
		ans += (V / P) * L;
		if (V % P < L) ans += V % P;
		else ans += L;
		printf("Case %d: %d\n", idx++, ans);
	}
}
