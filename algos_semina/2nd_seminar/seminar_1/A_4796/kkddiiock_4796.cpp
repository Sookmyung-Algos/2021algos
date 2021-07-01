#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int l,p,v, cnt = 0, ans;
	while (1) {
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) break;
		cnt++;
		ans = (v / p)*l;
		ans += (v % p > l) ? l : v % p;
		printf("Case %d: %d\n", cnt, ans);
	}
	return 0;
}
