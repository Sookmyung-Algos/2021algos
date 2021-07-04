#include <iostream>
using namespace std;

int main() {
	int l, p, v, exc, answer, i = 1;
	while (1) {
		cin >> l >> p >> v;
		if (!l && !p && !v) break;
		exc = (v % p) > l ? l : v % p;
		answer = v / p * l + exc;
		cout << "Case " << i++ << ": " << answer << '\n';
	}
}
