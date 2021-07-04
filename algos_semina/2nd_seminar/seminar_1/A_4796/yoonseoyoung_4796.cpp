#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int l, p, v, i = 1;
	cin >> l >> p >> v;
	while (l != 0 && p != 0 && v != 0) {
		int n = v / p;
		int k = v%p;
		printf("Case %d: %d\n", i, l*n + min(k,l));
		i++;
		cin >> l >> p >> v;
	}

}
