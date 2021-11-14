#include <iostream>
#include <numeric>
using namespace std;
int t, a, b;

int gcd(int a, int b)
{
	if (b == 0) return a;
	else {
		return gcd(b, a % b); //유클리드 호제법
	}
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> a >> b;
		cout << lcm(a, b) << "\n";
	}
}
