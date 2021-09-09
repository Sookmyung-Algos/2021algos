#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int p, q, a, b, c, d;
		cin >> p >> q >> a >> b >> c >> d;
		int bit=0, coin=0;
		coin = (q / c) * d;
		p += (coin / b) * a;
		coin %= b;

		int x = ((p - coin) / (a + b));
		x = max(min(p - a * x, b * x + coin), min(p - a * (x+1), b * (x+1) + coin));
		cout << x <<"\n";
	}
	return 0;
}
